#include "Save.h"

Save::Save(int level) :
	m_nLevel(level)
{
    m_input = new Stack();
}

Save::~Save()
{
	if(m_saveBoxes != NULL)
		delete[] m_saveBoxes;
}

void Save::addInput(char c)
{
	m_input->push(c);
}

void Save::writeSave()
{
	std::string path = getPath();

	std::ofstream file(path.c_str(), std::ios::out | std::ios::trunc);

	if(file)
	{
        while (!m_input->isEmpty())
            file << m_input->pull() << std::endl;
        
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
