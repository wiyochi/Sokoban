#ifndef _LEVEL_H_
#define _LEVEL_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include "../Board/Board.h"
#include "../Save/Save.h"

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
	std::time_t m_start;
	Save* m_save;

public:
	enum Dir
	{
		top,
		right,
		bottom,
		left,
        back
	};

	Level(const char* path);
	~Level();
	void draw();
	void move(Dir d);
	bool win();
	void save();
	void load();
	void replay();
};

#endif /*_LEVEL_H_*/
