#include "Poo.h"

Poo::Poo(std::mt19937& rng,Board& brd, int floorin)	
{
	std::uniform_int_distribution<int> xDist(0, int(brd.GetWidth(floorin)-1));
	std::uniform_int_distribution<int> yDist(0, int(brd.GetHeight(floorin)-1));

	Vec2 newloc;
	do
	{
		newloc.x = float(xDist(rng));
		newloc.y = float(yDist(rng));
	} while (!brd.IsInPlayCon(newloc, float(floorin)));
	loc = newloc;
	floor = float(floorin);
}

void Poo::Draw(Board& brd)
{
	brd.DrawPoo(loc, floor);
}

Vec2 Poo::GetLocation()
{
	return loc;
}

float Poo::GetFloor()
{
	return floor;
}

bool Poo::IsRolledIn()
{
	return RolledIn;
}

void Poo::SetToRolledIn()
{
	RolledIn = true;
}