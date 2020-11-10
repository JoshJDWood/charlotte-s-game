#include "Family.h"

Family::Family(int index, std::mt19937& rng, int des1, int des2, int des3)
{
	selfindex = index;
	loc.x += index;
	FindNewDestination(rng, des1, des2, des3);
}

void Family::FindNewDestination(std::mt19937& rng, int des1, int des2, int des3)
{
	std::uniform_int_distribution<int> DDist(0, nDestinations-1);
	int newDI = DDist(rng);
	do
	{
		newDI = DDist(rng);
	} while (newDI == des1 || newDI == des2 || newDI == des3);

	Destinationindex = newDI;
	Destination[0] = Destinationloc[Destinationindex];
	Destination[1] = Destinationfloor[Destinationindex];
}

void Family::Draw(Board& brd)
{
	brd.DrawFamily(loc, floor.x, selfindex);
}

void Family::Update(float* MWx, float* MWy, float* MWf, int nMW, Board& brd)
{
	Vec2 target = brd.FindTarget(loc, floor, Destination[0], Destination[1]);
	oldloc = loc;
	Vec2 diff = target - loc;	

	if (diff == Vec2(0, 0))
	{
		//fake move so it can change floor
		moved = true;
	}
	else if (abs(diff.x) >= abs(diff.y))
	{
		delta_F = { diff.x / abs(diff.x), 0 };
		Vec2 next = loc + delta_F;
		if (brd.IsInPlay(next, floor.x) && brd.IsInPlayMW(next, floor.x, MWx, MWy, MWf, nMW))
		{
			loc = next;
			moved = true;
		}
		else if (!moved)
		{
			if (diff.y != 0)
			{
				delta_F = { 0,diff.y / abs(diff.y) };
				next = loc + delta_F;
				if (brd.IsInPlay(next, floor.x) && brd.IsInPlayMW(next, floor.x, MWx, MWy, MWf, nMW))
				{
					loc = next;
					moved = true;
				}
			}
			if (!moved)
			{
				MovePrefAlt *= -1;
				delta_F = { 0, 1 * MovePrefAlt };
				next = loc + delta_F;
				Vec2 altnext = loc - delta_F;
				if (brd.IsInPlay(next, floor.x) && brd.IsInPlayMW(next, floor.x, MWx, MWy, MWf, nMW))
				{
					loc = next;
					moved = true;
				}
				else if (brd.IsInPlay(altnext, floor.x) && brd.IsInPlayMW(next, floor.x, MWx, MWy, MWf, nMW))
				{
					loc = altnext;
					moved = true;
				}
				if (!moved)
				{
					delta_F = { -diff.x / abs(diff.x), 0 };
					next = loc + delta_F;
					if (brd.IsInPlay(next, floor.x) && brd.IsInPlayMW(next, floor.x, MWx, MWy, MWf, nMW))
					{
						loc = next;
						moved = true;
					}
				}
			}
		}
	}
	else
	{
		delta_F = { 0, diff.y / abs(diff.y) };
		Vec2 next = loc + delta_F;
		if (brd.IsInPlay(next, floor.x) && brd.IsInPlayMW(next, floor.x, MWx, MWy, MWf, nMW))
		{
			loc = next;
			moved = true;
		}
		else if (!moved)
		{
			if (diff.x != 0)
			{
				delta_F = { diff.x / abs(diff.x),0 };
				next = loc + delta_F;
				if (brd.IsInPlay(next, floor.x) && brd.IsInPlayMW(next, floor.x, MWx, MWy, MWf, nMW))
				{
					loc = next;
					moved = true;
				}
			}
			if (!moved)
			{
				MovePrefAlt *= -1;
				delta_F = { 1 * MovePrefAlt, 0 };
				next = loc + delta_F;
				Vec2 altnext = loc - delta_F;
				if (brd.IsInPlay(next, floor.x) && brd.IsInPlayMW(next, floor.x, MWx, MWy, MWf, nMW))
				{
					loc = next;
					moved = true;
				}
				else if (brd.IsInPlay(altnext, floor.x) && brd.IsInPlayMW(next, floor.x, MWx, MWy, MWf, nMW))
				{
					loc = altnext;
					moved = true;
				}
				if (!moved)
				{
					delta_F = { 0, -diff.y / abs(diff.y) };
					next = loc + delta_F;
					if (brd.IsInPlay(next, floor.x) && brd.IsInPlayMW(next, floor.x, MWx, MWy, MWf, nMW))
					{
						loc = next;
						moved = true;
					}
				}
			}
		}
	}
	brd.UpdateFloor(floor, loc, oldloc);
	if (loc == Destination[0] && floor == Destination[1])
	{
		resting = true;
	}
	delta_F = { 0,0 };
	moved = false;
}

Vec2 Family::GetLoction()
{
	return loc;
}

Vec2 Family::GetFloor()
{
	return floor;
}

bool Family::IsResting()
{
	return resting;
}

void Family::SetToResting()
{
	resting = true;
}

void Family::SetRestingEnd()
{
	resting = false;
}

int Family::GetDI()
{
	return Destinationindex;
}
