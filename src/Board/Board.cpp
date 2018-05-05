#include "Board.h"

Board::Board(int w, int h, char** layout) :
	m_width(w),
	m_height(h)
{
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
					break;
				case '$':
					m_cases[i][j] = new Case(*(new Point(i, j)));
					m_cases[i][j]->hasBox(true);
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
	for (int i = 0; i < m_width; ++i)
	{
		for (int j = 0; j < m_height; ++j)
		{
			m_cases[i][j]->draw();
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}