#include "Target.h"

Target::Target(const Point& p) :
	Case(p)
{
}

Target::~Target()
{
}

void Target::draw()
{
	if(m_hasBox)
		std::cout << "$";
	else if(m_hasPlayer)
		std::cout << "@";
	else
		std::cout << ".";
}