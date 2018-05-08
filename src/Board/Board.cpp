#include "Board.h"

Board::Board(int w, int h, int nBoxes, char** layout) :
	m_width(w),
	m_height(h),
	m_nBoxes(nBoxes)
{
	int indexBoxes(0);
	m_boxes = new Point*[m_nBoxes];

	m_cases = new Case**[m_width];
	for (int i = 0; i < m_width; ++i)
	{
		m_cases[i] = new Case*[m_height];
		for (int j = 0; j < m_height; ++j)
		{
			switch(layout[i][j])
			{
				case '.':
					m_cases[i][j] = new Case(*(new Point(i, j)));
					break;
				case '#':
					m_cases[i][j] = new Wall(*(new Point(i, j)));
					break;
				case 'o':
					m_cases[i][j] = new Target(*(new Point(i, j)));
					break;
				case '@':
					m_cases[i][j] = new Case(*(new Point(i, j)));
					m_cases[i][j]->hasPawn(true);
					m_pawn = Point(i, j);
					break;
				case '$':
					m_cases[i][j] = new Case(*(new Point(i, j)));
					m_cases[i][j]->hasBox(true);
					m_boxes[indexBoxes] = new Point(i, j);
					indexBoxes++;
					break;
				default:
					m_cases[i][j] = new Case(*(new Point(i, j)));
					break;
			}
		}
	}
}

Board::~Board()
{	
	for (int i = 0; i < m_width; ++i)
	{
		for (int j = 0; j < m_height; ++j)
		{
			delete m_cases[i][j];
		}
		delete[] m_cases[i];
	}
	delete[] m_cases;
}

void Board::draw()
{
	for (int i = 0; i < m_height; ++i)
	{
		for (int j = 0; j < m_width; ++j)
		{
			m_cases[j][i]->draw();
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}

void Board::move(int dx, int dy)
{
	Point firstNextCase(m_pawn.x + dx, m_pawn.y + dy);
	Point secondNextCase(firstNextCase.x + dx, firstNextCase.y + dy);

	/* Test si la case est un mur ou si on est sur le bord du plateau */
	if(firstNextCase.x >= 0 && firstNextCase.x < m_width
		&& firstNextCase.y >= 0 && firstNextCase.y < m_height
		&& m_cases[firstNextCase.x][firstNextCase.y]->type() != "wall")
	{
		/* Test si la case a une caisse et que la suivante est un mur ou a une caisse aussi */
		if (m_cases[firstNextCase.x][firstNextCase.y]->hasBox())
		{
			if(m_cases[secondNextCase.x][secondNextCase.y]->type() != "wall"
				&& !m_cases[secondNextCase.x][secondNextCase.y]->hasBox())
			{
				moveBox(firstNextCase, secondNextCase);
				movePawn(firstNextCase);
			}
		}
		else
		{
			movePawn(firstNextCase);
		}
	}
}

void Board::moveBox(const Point& origin, const Point& target)
{
	if(m_cases[origin.x][origin.y]->hasBox() && !m_cases[target.x][target.y]->hasBox()
		&& m_cases[target.x][target.y]->type() != "wall" && !m_cases[target.x][target.y]->hasPawn())
	{
		for (int i = 0; i < m_nBoxes; ++i)
		{
			if(*(m_boxes[i]) == origin)
			{
				*(m_boxes[i]) = target;
				break;
			}
		}
		m_cases[origin.x][origin.y]->hasBox(false);
		m_cases[target.x][target.y]->hasBox(true);
	}
}

void Board::movePawn(const Point& target)
{
	if(m_cases[target.x][target.y]->type() != "wall")
	{
		m_cases[m_pawn.x][m_pawn.y]->hasPawn(false);
		m_pawn = target;
		m_cases[m_pawn.x][m_pawn.y]->hasPawn(true);
	}
}

bool Board::win()
{
	bool boxesOnTarget(true);
	for (int i = 0; i < m_nBoxes; ++i)
	{
		boxesOnTarget = boxesOnTarget && (m_cases[m_boxes[i]->x][m_boxes[i]->y]->type() == "target");
	}
	return boxesOnTarget;
}

Case& Board::operator[](const Point& p)
{
	return *(m_cases[p.x][p.y]);
}