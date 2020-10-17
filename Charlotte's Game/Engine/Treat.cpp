#include "Treat.h"

Treat::Treat(Vec2& locin, float floorin)
	:
	loc(locin),
	floor(floorin)
{
}

void Treat::Draw(Board& brd)
{
	brd.DrawTreat(loc, floor);
}

Vec2 Treat::GetLocation()
{
	return loc;
}

float Treat::GetFloor()
{
	return floor;
}
