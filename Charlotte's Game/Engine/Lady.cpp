#include "Lady.h"

void Lady::Draw(Board& brd)
{
	brd.DrawLady(loc, floor.x, smelly);
}

void Lady::Update(Vec2& delta_L, float* MWx, float* MWy, float* MWf, int nMW, Board& brd)
{
	oldloc = loc;
	Vec2 next = loc + delta_L;
	if (smelly)
	{
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
	else
	{
		if (brd.IsInPlay(next, floor.x) && brd.IsInPlayMW(next, floor.x, MWx, MWy, MWf, nMW))
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
}

void Lady::Restart()
{
	loc = startloc;
	floor = startfloor;
	smelly = false;
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

bool Lady::IsSmelly()
{
	return smelly;
}

void Lady::SetToSmelly()
{
	smelly = true;
}

void Lady::SetSmellyOver()
{
	smelly = false;
}
