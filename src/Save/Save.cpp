#include "Save.h"

Save::Save(int level) :
	m_nLevel(level), m_nbMove(0), m_timer(0)
{
    m_input = new Stack();
}

Save::~Save()
{
}

void Save::setNbMove(int nbMove)
{
    m_nbMove = nbMove;
}

int Save::getNbMove()
{
    return m_nbMove;
}

void Save::setTimer(std::time_t timer)
{
    m_timer = timer;
}

std::time_t Save::getTimer() 
{
    return m_timer;
}

void Save::addInput(char c)
{
	m_input->push(c);
}

void Save::removeInput()
{
	m_input->pull();
}

int Save::getNbInput()
{
	return m_input->size();
}

char Save::getInput(int i)
{
	return m_input->getI(i);
}

void Save::writeSave()
{
	std::string path = getPath();

	std::ofstream file(path.c_str(), std::ios::out | std::ios::trunc);

	if(file)
	{
        file << m_nbMove << std::endl;
        file << m_timer << std::endl;

        std::cout << "m_input->size(): " << m_input->size() << std::endl;

        for (int i = 0; i < m_input->size(); i++)
        {
        	std::cout << "m_input " << i << ": " << m_input->getI(i) << std::endl;
            file << m_input->getI(i) << std::endl;
        }
        
		file.close();
        
	}
	else
		throw std::ifstream::failure("Can't write save file");
}

void Save::readSave()
{
	std::string path = getPath();

	std::ifstream file(path.c_str(), std::ios::in);
	std::string line;

	if(file)
	{
        getline(file, line);
		std::istringstream(line) >> m_nbMove;
        
        getline(file, line);
		std::istringstream(line) >> m_timer;
        
		delete m_input;
		m_input = new Stack();

		while (getline(file, line))
            m_input->push(line[0]);
		file.close();
	}
	else
		throw std::ifstream::failure("Can't read save file");
}

std::string Save::getPath()
{
	std::string path;
	std::ostringstream convert;
	convert << m_nLevel;

	path.append("resources/saves/Level_");
	path.append(convert.str());
	path.append(".txt");

	return path;
}
