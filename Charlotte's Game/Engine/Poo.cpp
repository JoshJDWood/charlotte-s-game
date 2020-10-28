#include "Poo.h"

Poo::Poo(Vec2& locin, float floorin)
	:
	loc(locin),
	floor(floorin)
{
}

void Poo::Draw(Board& brd)
{
	brd.DrawCell(loc, floor, poocolor);
}

Vec2 Poo::GetLocation()
{
	return loc;
}

float Poo::GetFloor()
{
	return floor;
}

bool Poo::GetRolledIn()
{
	return RolledIn;
}

void Poo::SetToRolledIn()
{
	RolledIn = true;
}