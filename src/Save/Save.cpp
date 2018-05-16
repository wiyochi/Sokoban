#include "Save.h"

Save::Save(int level) :
	m_savePawn(),
	m_nLevel(level)
{
}

Save::~Save()
{
	if(m_saveBoxes != NULL)
		delete[] m_saveBoxes;
}

void Save::addPawn(Point p)
{
	m_savePawn = p;
}

void Save::addBox(Point p)
{
	Point* tmp = new Point[m_nbBoxes];
	for (int i = 0; i < m_nbBoxes; ++i)
		tmp[i] = m_saveBoxes[i];
	delete[] m_saveBoxes;

	m_nbBoxes++;
	m_saveBoxes = new Point[m_nbBoxes];
	for (int i = 0; i < m_nbBoxes - 1; ++i)
		m_saveBoxes[i] = tmp[i];
	delete[] tmp;

	m_saveBoxes[m_nbBoxes - 1] = p;
}

void Save::addBoxes(Point* p, int n)
{
	m_nbBoxes = n;
	m_saveBoxes = new Point[n];
	for (int i = 0; i < n; ++i)
	{
		m_saveBoxes[i] = p[i];
	}
}

const Point& Save::getPawn()
{
	return m_savePawn;
}

const Point* Save::getBoxes()
{
	return m_saveBoxes;
}

int Save::getNbBoxes()
{
	return m_nbBoxes;
}


void Save::writeSave()
{
	std::string path = getPath();

	std::ofstream file(path.c_str(), std::ios::out | std::ios::trunc);

	if(file)
	{
		file << m_nbBoxes << std::endl;
		for (int i = 0; i < m_nbBoxes; ++i)
		{
			file << m_saveBoxes[i].x << std::endl;
			file << m_saveBoxes[i].y << std::endl;
		}
		file << m_savePawn.x << std::endl;
		file << m_savePawn.y << std::endl;

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
		std::istringstream(line) >> m_nbBoxes;

		m_saveBoxes = new Point[m_nbBoxes];

		for (int i = 0; i < m_nbBoxes; ++i)
		{
			getline(file, line);
			std::istringstream(line) >> m_saveBoxes[i].x;
			getline(file, line);
			std::istringstream(line) >> m_saveBoxes[i].y;
		}
		getline(file, line);
		std::istringstream(line) >> m_savePawn.x;
		getline(file, line);
		std::istringstream(line) >> m_savePawn.y;

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
