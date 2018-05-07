#ifndef _POINT_H_
#define _POINT_H_

struct Point
{
	int x;
	int y;

	Point();
	Point(int a, int b);
	Point(const Point& p);
	~Point();
	void set(int a, int b);
	void move(int a, int b);
};

#endif /*_POINT_H_*/