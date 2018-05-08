#include "Level.h"

Level::Level()
{

}

Level::~Level()
{
	if(m_board != NULL)
		delete m_board;
}

void Level::load(const char* path)
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
		std::cerr << "Can't load level file" << std::endl;
	}
}

void Level::update()
{
	std::string input;
	int moveDir;

	draw();
	std::cout << "-- MOVE --" << std::endl;
	std::cout << "4:left" << std::endl;
	std::cout << "8:top" << std::endl;
	std::cout << "6:right" << std::endl;
	std::cout << "2:bottom" << std::endl;

	std::cin >> input;
	std::istringstream(input) >> moveDir;

	switch(moveDir)
	{
	case 4:
		move(left);
		break;
	case 8:
		move(top);
		break;
	case 6:
		move(right);
		break;
	case 2:
		move(bottom);
		break;
	default:
		break;
	}
}

void Level::draw()
{
	m_board->draw();
}

void Level::move(Dir d)
{
	switch(d)
	{
	case top:
		m_board->move(0, -1);
		break;
	case right:
		m_board->move(1, 0);
		break;
	case bottom:
		m_board->move(0, 1);
		break;
	case left:
		m_board->move(-1, 0);
		break;
	}
}

bool Level::win()
{
	return m_board->win();
}