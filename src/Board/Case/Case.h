#ifndef _CASE_H_
#define _CASE_H_

#include <iostream>
#include <string>
#include "../Point.h"

class Case
{
public:
	Case(const Point& p);
	~Case();
	virtual void draw();
	virtual std::string type();
	void drawDebug();
	bool hasBox();
	bool hasPawn();
	void hasBox(bool b);
	void hasPawn(bool b);

protected:
	Point m_position;
	bool m_hasBox;
	bool m_hasPawn;
};

#endif /*_CASE_H_*/