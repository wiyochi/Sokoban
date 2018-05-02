#include <iostream>
#include "Board/Board.h"

int main(int argc, char const *argv[])
{
	Board* b = new Board(8, 8);

	b->draw();

	return 0;
}