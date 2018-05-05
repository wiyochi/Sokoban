#include "Pawn.h"

Pawn::Pawn(const Point& p) :
	m_position(p)
{
}

Pawn::~Pawn()
{
}

Point Pawn::position()
{
	return Point(m_position);
}