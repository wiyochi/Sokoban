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

Point& Point::operator=(const Point& p)
{
	if(&p != this)
	{
		this->x = p.x;
		this->y = p.y;
	}
	return *this;
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

bool Point::equal(const Point& p) const
{
	return (this->x == p.x && this->y == p.y);
}

bool operator==(const Point& p1, const Point& p2)
{
	return p1.equal(p2);
}

bool operator!=(const Point& p1, const Point& p2)
{
	return !(p1.equal(p2));
}