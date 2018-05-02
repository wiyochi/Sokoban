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
		file >> m_nLevel >> m_wBoard >> m_hBoard >> m_idk;
		file.seekg(2, std::ios::cur);
		
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
	}
	else
		std::cerr << "Can't load level file" << std::endl;
		
	m_board = new Board(m_wBoard, m_hBoard, m_layout);
}

void Level::draw()
{
	m_board->draw();
}