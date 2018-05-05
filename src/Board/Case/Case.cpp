#include "Case.h"

Case::Case(const Point& p) :
	m_position(p),
	m_hasBox(false),
	m_hasPawn(false)
{
}

Case::~Case()
{
}

void Case::draw()
{
	if(m_hasBox)
		std::cout << "$";
	else if(m_hasPawn)
		std::cout << "@";
	else
		std::cout << " ";
}

bool Case::hasBox()
{
	return m_hasBox;
}

bool Case::hasPawn()
{
	return m_hasPawn;
}

void Case::hasBox(bool b)
{
	m_hasBox = b;
}

void Case::hasPawn(bool b)
{
	m_hasPawn = b;
}

