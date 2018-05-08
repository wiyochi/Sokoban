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
	int m_nBoxes;
	Point m_pawn;
	Point** m_boxes;

public:
	Board(int w, int h, int nBoxes, char** layout);
	~Board();
	void draw();
	void move(int dx, int dy);
	void moveBox(const Point& origin, const Point& target);
	void movePawn(const Point& target);
	bool win();
	Case& operator[](const Point& p);
};

#endif /*_BOARD_H_*/