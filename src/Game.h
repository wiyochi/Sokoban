#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>
#include <string>
#include <sstream>
#include "Level/Level.h"

class Game
{
private:
	int m_nbLevel;
	int m_nLevel;
	Level* m_level;
	bool m_end;

public:
	Game(int nbLevel);
	~Game();
	void loadLevel(int nbLevel);
	void startLevel();
	void nextLevel();
	void restartLevel();
	void menu();
};


#endif /* _GAME_H_ */