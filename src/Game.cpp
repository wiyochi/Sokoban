#include "Game.h"

Game::Game(int nbLevel) :
	m_nbLevel(nbLevel),
	m_nLevel(0)
{
}

Game::~Game()
{
	if(m_level != NULL)
		delete m_level;
}

void Game::loadLevel(int nLevel)
{   
	std::string path;
	std::ostringstream convert;
	convert << nLevel;
	path.append("resources/level_");
	path.append(convert.str());
	path.append(".txt");

	if (m_level == NULL)
		delete m_level;

	try
	{
		m_level = new Level(path.c_str());
	}
	catch(std::ifstream::failure e)
	{
		std::cerr << "Error while opening file" << std::endl;
	}
	
}

void Game::startLevel()
{
	std::string input;
	int moveDir;

	std::cout << "--- Level " << m_nLevel << " ---" << std::endl;

	while(!m_level->win() && !m_end)
	{
		m_level->draw();
		std::cout << "--- Moves ---" << std::endl;
		std::cout << "4:left" << std::endl;
		std::cout << "8:top" << std::endl;
		std::cout << "6:right" << std::endl;
		std::cout << "2:bottom" << std::endl;
		std::cout << "--- Actions ---" << std::endl;
		std::cout << "r:restart" << std::endl;
		std::cout << "q:quit" << std::endl;

		std::cin >> input;
		std::istringstream(input) >> moveDir;

		if(input == "r")
		{
			std::cout << "--- Restarting... ---" << std::endl;
			restartLevel();
		}
		else if(input == "q")
		{
			m_end = true;
		}
		else
		{
			switch(moveDir)
			{
			case 4:
				m_level->move(Level::left);
				break;
			case 8:
				m_level->move(Level::top);
				break;
			case 6:
				m_level->move(Level::right);
				break;
			case 2:
				m_level->move(Level::bottom);
				break;
			default:
				break;
			}
		}
	}

	if(!m_end)
	{
		m_level->draw();
		std::cout << "--- You won the level " << m_nLevel << " ---" << std::endl;
		nextLevel();
	}
	else
		menu();
}

void Game::nextLevel()
{
	m_nLevel = (m_nLevel % m_nbLevel) + 1;
	loadLevel(m_nLevel);
	startLevel();
}

void Game::restartLevel()
{
	loadLevel(m_nLevel);
}

void Game::menu()
{
	std::string input;
	int moveDir;

	while(moveDir != 1 && moveDir != 2 && moveDir != 3)
	{
		std::cout << "--- Menu ---" << std::endl;
		std::cout << "1:current game" << std::endl;
		std::cout << "2:new game" << std::endl;
		std::cout << "3:quit game" << std::endl;

		std::cin >> input;
		std::istringstream(input) >> moveDir;
	}

	switch(moveDir)
	{
	case 1:
		m_nLevel = 1;
		m_end = false;
		loadLevel(m_nLevel);
		startLevel();
		break;
	case 2:
		m_nLevel = 1;
		m_end = false;
		loadLevel(m_nLevel);
		startLevel();
		break;
	case 3:
		m_end = true;
		std::cout << "See you" << std::endl;
		break;
	default:
		break;
	}
}
