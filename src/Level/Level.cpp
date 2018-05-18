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

		
	}
	else
	{
		throw std::ifstream::failure("Can't load level file");
	}

	m_save = new Save(m_nLevel);
}

Level::~Level()
{
    for (int i = 0; i < m_wBoard; ++i)
		{
			delete[] m_layout[i];
		}
    delete[] m_layout;
    
	if(m_board != NULL)
		delete m_board;
	if(m_save != NULL)
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
	switch(d)
	{
	case top:
		m_board->move(0, -1);
        m_save->addInput(d);
		break;
	case right:
		m_board->move(1, 0);
        m_save->addInput(d);
		break;
	case bottom:
		m_board->move(0, 1);
        m_save->addInput(d);
		break;
	case left:
		m_board->move(-1, 0);
		m_save->addInput(d);
        break;
    case back:
        m_save->removeInput();
        break;
	}
	
    m_nMove++;
}

bool Level::win()
{
	return m_board->win();
}

void Level::save()
{
    m_save->setNbMove(m_nMove);
    m_save->setTimer(std::difftime(std::time(NULL), m_start));
	try
	{
		m_save->writeSave();
	}
	catch(std::ifstream::failure e)
	{
		std::cerr << "Error while saving level" << std::endl;
	}
}

void Level::load()
{
	try
	{
		m_save->readSave();

        m_nMove = m_save->getNbMove();
        m_start = std::difftime(m_start, std::time(NULL));
	}
	catch(std::ifstream::failure e)
	{
		std::cerr << "Error while loading save level" << std::endl;
	}

}
