#include "Treat.h"

Treat::Treat(std::mt19937& rng, Board& brd, int floorin)
{
	std::uniform_int_distribution<int> xDist(0, int(brd.GetWidth(floorin) - 1));
	std::uniform_int_distribution<int> yDist(0, int(brd.GetHeight(floorin) - 1));

	Vec2 newloc;
	do
	{
		newloc.x = float(xDist(rng));
		newloc.y = float(yDist(rng));
	} while (!brd.IsInPlayCon(newloc, float(floorin)));
	loc = newloc;
	floor = float(floorin);
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

bool Treat::GetEaten()
{
	return eaten;
}

void Treat::SetToEaten()
{
	eaten = true;
}
