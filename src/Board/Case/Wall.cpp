#include "Wall.h"

Wall::Wall(const Point& p) :
	Case(p)
{

}

Wall::~Wall()
{
}

void Wall::draw()
{
	std::cout << "#";
}