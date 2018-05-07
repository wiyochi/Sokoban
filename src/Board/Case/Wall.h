#ifndef _WALL_H_
#define _WALL_H_

#include <iostream>
#include "Case.h"

class Wall : public Case
{
public:
	Wall(const Point& p);
	~Wall();
	virtual void draw();
	virtual std::string type();
};

#endif /*_WALL_H_*/