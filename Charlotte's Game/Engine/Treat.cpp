#include "Treat.h"

Treat::Treat(Vec2& locin)
	:
	loc(locin)
{
}

void Treat::Draw(Board& brd)
{
	brd.DrawTreat(loc);
}

Vec2 Treat::GetLocation()
{
	return loc;
}
