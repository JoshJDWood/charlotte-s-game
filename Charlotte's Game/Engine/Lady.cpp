#include "Lady.h"

void Lady::Draw(Board& brd)
{
	brd.DrawLady(loc, floor.x);
}

void Lady::Update(Vec2& delta_L, Board& brd)
{
	oldloc = loc;
	Vec2 next = loc + delta_L;
	if (brd.IsInPlay(next, floor.x))
	{
		loc = next;
		moved = true;
		brd.UpdateFloor(floor, loc, oldloc);
	}
	else
	{
		brd.UpdateFloor(floor, loc, oldloc);
		moved = false;
	}
	
}

Vec2 Lady::GetLocation()
{
	return loc;
}

Vec2 Lady::GetFloor()
{
	return floor;
}

bool Lady::DidMove()
{
	return moved;
}
