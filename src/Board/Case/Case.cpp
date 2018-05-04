#include "Case.h"

Case::Case(const Point& p) :
	m_position(p),
	m_hasBox(false),
	m_hasPlayer(false)
{
}

Case::~Case()
{
}

void Case::draw()
{
	if(m_hasBox)
		std::cout << "$";
	else if(m_hasPlayer)
		std::cout << "@";
	else
		std::cout << " ";
}

bool Case::hasBox()
{
	return m_hasBox;
}

bool Case::hasPlayer()
{
	return m_hasPlayer;
}

void Case::hasBox(bool b)
{
	m_hasBox = b;
}

void Case::hasPlayer(bool b)
{
	m_hasPlayer = b;
}

