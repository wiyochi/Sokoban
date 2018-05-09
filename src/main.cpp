#include <iostream>
#include "Game.h"

int main(int argc, char const *argv[])
{
	Game* g = new Game(5);

	g->menu();

	return 0;
}