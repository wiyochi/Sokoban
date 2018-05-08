#ifndef _BOARD_H_
#define _BOARD_H_

#include <iostream>
#include "Case/Case.h"
#include "Case/Target.h"
#include "Case/Wall.h"
#include "Point.h"

class Board
{
private:
	Case*** m_cases;
	int m_width;
	int m_height;
	Point m_pawn;

public:
	Board(int w, int h, char** layout);
	~Board();
	void draw();
	void move(int dx, int dy);
	Case& operator[](const Point& p);
};

#endif /*_BOARD_H_*/