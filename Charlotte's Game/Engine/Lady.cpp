#include "Lady.h"

void Lady::Draw(Board& brd)
{
	brd.DrawLady(loc, floor.x);
}

void Lady::Update(Vec2& delta_L, Board& brd)
{
	oldloc = loc;
	loc += delta_L;
	brd.UpdateFloor( floor, loc, oldloc);
}

Vec2 Lady::GetLocation()
{
	return loc;
}

Vec2 Lady::GetFloor()
{
	return floor;
}
