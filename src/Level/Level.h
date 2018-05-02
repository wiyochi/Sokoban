#include <iostream>
#include <fstream>
#include "../Board/Board.h"

class Level
{
private:
	Board* m_board;
	char** m_layout;
	int m_nLevel;
	int m_wBoard;
	int m_hBoard;
	int m_idk;

public:
	Level();
	~Level();
	void load(const char*);
	void draw();
};