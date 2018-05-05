#include "Level.h"

Level::Level()
{

}

Level::~Level()
{

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
			getline(file, strTmp);

			for (int j = 0; j < m_hBoard; ++j)
			{
				m_layout[i][j] = strTmp[j];
			}
		}

		file.close();

		m_board = new Board(m_wBoard, m_hBoard, m_layout);
	}
	else
	{
		std::cerr << "Can't load level file" << std::endl;
	}
}

void Level::draw()
{
	m_board->draw();
}

void Level::move(dir d)
{
	switch(d)
	{
	case top:
		break;
	case right:
		break;
	case bottom:
		break;
	case left:
		break;
	}
}