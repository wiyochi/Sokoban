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

void Save::addPawn(Point& p)
{
	m_savePawn.x = p.x;
	m_savePawn.y = p.y;
}

void Save::addBox(Point& p)
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

void Save::saveBoxes(Point* p, int n)
{
	m_nbBoxes = n;
	m_saveBoxes = new Point[n];
	for (int i = 0; i < n; ++i)
	{
		m_saveBoxes[i].x = p[i].x;
		m_saveBoxes[i].y = p[i].y;
	}
}

void Save::writeSave(const char* path)
{
	std::ofstream file(path, std::ios::out | std::ios::ate);

	if(file)
	{
		file << m_nLevel << ":" << std::endl;
		file << m_nbBoxes << "=";
		for (int i = 0; i < m_nbBoxes; ++i)
		{
			file << m_saveBoxes[i].x << "," << m_saveBoxes[i].y << "|";
		}
		file << std::endl << m_savePawn.x << "," << m_savePawn.y << std::endl;;

		file.close();
	}
	else
	{
		throw std::ifstream::failure("Can't write save file");
	}
}