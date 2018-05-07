#include "Point.h"

Point::Point() :
	x(0),
	y(0)
{
}

Point::Point(int a, int b) :
	x(a),
	y(b)
{
}

Point::Point(const Point& p) :
	x(p.x),
	y(p.y)
{
}

Point::~Point()
{
}

void Point::set(int a, int b)
{
	x = a;
	y = b;
}

void Point::move(int a, int b)
{
	x += a;
	y += b;
}