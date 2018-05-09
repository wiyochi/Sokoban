#ifndef _LEVEL_H_
#define _LEVEL_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../Board/Board.h"

class Level
{
private:
	Board* m_board;
	char** m_layout;
	int m_nLevel;
	int m_wBoard;
	int m_hBoard;
	int m_nBox;
	unsigned int m_nMove;

public:
	enum Dir
	{
		top,
		right,
		bottom,
		left
	};

	Level();
	~Level();
	void load(const char*);
	void update();
	void draw();
	void move(Dir d);
	bool win();
};

#endif /*_LEVEL_H_*/