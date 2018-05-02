#ifndef _BOARD_H_
#define _BOARD_H_

#include <iostream>
#include "Case/Case.h"

class Board
{
private:
	Case*** m_cases;
	int m_width;
	int m_height;

public:
	Board(int w, int h);
	~Board();
	void draw();
};

#endif