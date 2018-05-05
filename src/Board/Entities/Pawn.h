#include "../Point.h"

class Pawn
{
private:
	Point m_position;

public:
	Pawn(const Point& p);
	~Pawn();
	Point position();
};