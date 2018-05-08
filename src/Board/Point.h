#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>

struct Point
{
	int x;
	int y;

	Point();
	Point(int a, int b);
	Point(const Point& p);
	Point& operator=(const Point& p);
	~Point();
	void set(int a, int b);
	void move(int a, int b);
	bool equal(const Point& p) const;
};

bool operator==(const Point& p1, const Point& p2);
bool operator!=(const Point& p1, const Point& p2);

#endif /*_POINT_H_*/