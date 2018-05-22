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
	path.append("resources/levels/level_");
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
		std::cout << "s:save" << std::endl;
		std::cout << "l:load save" << std::endl;

		std::cin >> input;
		std::istringstream(input) >> moveDir;

		if(input == "r")
		{
			std::cout << "--- Restarting... ---" << std::endl;
			restartLevel();
		}
		else if(input == "q")
			m_end = true;
		else if(input == "s")
			m_level->save();
		else if(input == "l")
			m_level->load();
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
	{
		try {
			saveNLevel();
		} catch (std::ifstream::failure e) {
			std::cerr << "Error while saving current level save file" << std::endl;
		}
	}
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
	int choice;

	while(!m_quit)
	{
		choice = 0;

		while(choice != 1 && choice != 2 && choice != 3 && choice != 4)
		{
			std::cout << "--- Menu ---" << std::endl;
			std::cout << "1:current game" << std::endl;
			std::cout << "2:new game" << std::endl;
			std::cout << "3:level menu" << std::endl;
			std::cout << "4:quit game" << std::endl;

			std::cin >> input;
			std::istringstream(input) >> choice;
		}

		switch(choice)
		{
		case 1:
			try {
				m_nLevel = getNLevel();
			} catch(std::ifstream::failure e) {
				std::cerr << "Error while loading current level save file" << std::endl;
				m_nLevel = 1;
			}
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
			m_nLevel = levelMenu();
			if(m_nLevel != -1)
			{
				m_end = false;
				loadLevel(m_nLevel);
				startLevel();
			}
			break;
		case 4:
			m_quit = true;
			std::cout << "See you" << std::endl;
			break;
		}
	}
}

int Game::levelMenu()
{
	std::string input;
	int choice;

	do
	{
		std::cout << "--- Level menu ---" << std::endl;
		for (int i = 0; i < m_nbLevel; ++i)
		{
			std::cout << "Level " << i + 1 << std::endl;
		}
		std::cout << "b:back to main menu" << std::endl;

		std::cin >> input;

		if(input == "b")
			return -1;

		std::istringstream(input) >> choice;
	} while(choice < 0 || choice > m_nbLevel);

	return choice - 1;
}

void Game::saveNLevel()
{
	std::ofstream file("resources/currentLevel.txt", std::ios::out | std::ios::trunc);

	if(file)
	{
		file << m_nLevel << std::endl;
		file.close();
	}
	else
		throw std::ifstream::failure("Can't write current level save file");
}

int Game::getNLevel()
{
	std::ifstream file("resources/currentLevel.txt", std::ios::in);
	std::string line;
	int nLevel;

	if(file)
	{
		getline(file, line);
		std::istringstream(line) >> nLevel;
		file.close();
	}
	else
		throw std::ifstream::failure("Can't read current level save file");

	return nLevel;
}