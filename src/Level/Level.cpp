#include "Level.h"

Level::Level(const char* path) :
	m_nMove(0),
    m_start(std::time(NULL))
{
	std::ifstream file(path, std::ios::in);
	std::string strTmp;

	if(file)
	{
		getline(file, strTmp);
		std::istringstream(strTmp) >> m_nLevel;
		getline(file, strTmp);
		std::istringstream(strTmp) >> m_wBoard;
		getline(file, strTmp);
		std::istringstream(strTmp) >> m_hBoard;
		getline(file, strTmp);
		std::istringstream(strTmp) >> m_nBox;
		
		m_layout = new char*[m_wBoard];
		for (int i = 0; i < m_wBoard; ++i)
		{
			m_layout[i] = new char[m_hBoard];
		}

		for (int i = 0; i < m_hBoard; ++i)
		{
			getline(file, strTmp);
            
			for (int j = 0; j < m_wBoard; ++j)
			{
				m_layout[j][i] = strTmp[j];
			}
		}

		file.close();

		m_board = new Board(m_wBoard, m_hBoard, m_nBox, m_layout);

		for (int i = 0; i < m_wBoard; ++i)
		{
			delete[] m_layout[i];
		}
		delete[] m_layout;
	}
	else
	{
		throw std::ifstream::failure("Can't load level file");
	}
}

Level::~Level()
{
	if(m_board != NULL)
		delete m_board;
	if(m_save == NULL)
		delete m_save;
}

void Level::draw()
{
	m_board->draw();


	std::cout << "Moves: " << m_nMove << std::endl;
    std::cout << "Time: " << (int)(std::difftime(std::time(NULL), m_start)) / 60 << ":" << (int) (std::difftime(std::time(NULL), m_start)) % 60 << std::endl;
}

void Level::move(Dir d)
{
	bool hasMoved(false);
	switch(d)
	{
	case top:
		hasMoved = m_board->move(0, -1);
		break;
	case right:
		hasMoved = m_board->move(1, 0);
		break;
	case bottom:
		hasMoved = m_board->move(0, 1);
		break;
	case left:
		hasMoved = m_board->move(-1, 0);
		break;
	}
	if(hasMoved)
		m_nMove++;
}

bool Level::win()
{
	return m_board->win();
}

void Level::save()
{
	if(m_save == NULL)
		delete m_save;

	Point* boxes = m_board->getBoxes();

	m_save = new Save(m_nLevel);
	m_save->addPawn(m_board->getPawn());
	m_save->addBoxes(boxes, m_board->getNbBoxes());

	m_save->writeSave();
}
