#include "Case.h"

Case::Case() :
	m_type(Case::wall)
{
}

Case::~Case()
{
}

void Case::draw()
{
	switch(m_type)
	{
		case empty:
			std::cout << "  ";
			break;
		case wall:
			std::cout << "# ";
			break;
		case target:
			std::cout << ". ";
			break;
	}
}