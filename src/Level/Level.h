#ifndef _LEVEL_H_
#define _LEVEL_H_

#include <iostream>
#include <fstream>
#include <sstream>
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

public:
	enum dir
	{
		top,
		right,
		bottom,
		left
	};

	Level();
	~Level();
	void load(const char*);
	void draw();
	void move(dir d);
};

#endif /*_LEVEL_H_*/