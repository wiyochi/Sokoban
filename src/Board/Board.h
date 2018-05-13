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
	bool move(int dx, int dy);
	bool moveBox(const Point& origin, const Point& target);
	bool movePawn(const Point& target);
	void placeBoxes(const Point* boxes, int nBoxes);
	bool win();
	Case& operator[](const Point& p);
	Point getPawn();
	Point* getBoxes();
	int getNbBoxes();
};

#endif /*_BOARD_H_*/