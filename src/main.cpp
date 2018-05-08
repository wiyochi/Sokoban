#include <iostream>
#include "Board/Board.h"
#include "Level/Level.h"

int main(int argc, char const *argv[])
{
	Level* l = new Level();

	l->load("niveau2.txt");

	while(!l->win())
		l->update();

	l->draw();
	std::cout << "############### END ###############" << std::endl;

	delete l;

	return 0;
}