#include <iostream>
#include "Board/Board.h"
#include "Level/Level.h"

int main(int argc, char const *argv[])
{
	Level* l = new Level();

	l->load("niveau2.txt");

	l->draw();

	return 0;
}