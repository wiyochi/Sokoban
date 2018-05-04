#ifndef _CASE_H_
#define _CASE_H_

#include <iostream>
#include "../Point.h"

class Case
{
public:
	Case(const Point& p);
	~Case();
	virtual void draw();
	bool hasBox();
	bool hasPlayer();
	void hasBox(bool b);
	void hasPlayer(bool b);

protected:
	Point m_position;
	bool m_hasBox;
	bool m_hasPlayer;
};

#endif /*_CASE_H_*/