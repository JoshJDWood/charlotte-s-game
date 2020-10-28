#include "Family.h"

Family::Family(int index, Color c_in, std::mt19937& rng)
{
	selfindex = index;
	c = c_in;
	loc.x += index;
	FindNewDestination(rng);
}

void Family::FindNewDestination(std::mt19937& rng)
{
	std::uniform_int_distribution<int> DDist(0, nDestinations-1);
	//int newDI;	
	Destinationindex = DDist(rng);
	Destination[0] = Destinationloc[Destinationindex];
	Destination[1] = Destinationfloor[Destinationindex];
}

bool Family::DestinationVacant(int newDI_in)
{
	for (int i = 0; i < 3; ++i)
	{
		//use when not allowing same destination
	}
	return true;
}

void Family::Draw(Board& brd)
{
	brd.DrawCell(loc, floor.x, c);
}

void Family::Update(Board& brd)
{
	Vec2 target = FindTarget(Destination[0], Destination[1]);
	oldloc = loc;
	Vec2 diff = target - loc;	

	if (diff == Vec2(0, 0))
	{
		//fake move so it can change floor
		moved = true;
	}
	else if (abs(diff.x) > abs(diff.y))
	{
		delta_F.x = diff.x / abs(diff.x);
		Vec2 next = loc + delta_F;
		if (brd.IsInPlay(next, floor.x))
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
				if (brd.IsInPlay(next, floor.x))
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
				if (brd.IsInPlay(next, floor.x))
				{
					loc = next;
					moved = true;
				}
				else if (brd.IsInPlay(altnext, floor.x))
				{
					loc = altnext;
					moved = true;
				}
				if (!moved)
				{
					delta_F.x = -diff.x / abs(diff.x);
					next = loc + delta_F;
					if (brd.IsInPlay(next, floor.x))
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
		delta_F.y = diff.y / abs(diff.y);
		Vec2 next = loc + delta_F;
		if (brd.IsInPlay(next, floor.x))
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
				if (brd.IsInPlay(next, floor.x))
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
				if (brd.IsInPlay(next, floor.x))
				{
					loc = next;
					moved = true;
				}
				else if (brd.IsInPlay(altnext, floor.x))
				{
					loc = altnext;
					moved = true;
				}
				if (!moved)
				{
					delta_F.y = -diff.y / abs(diff.y);
					next = loc + delta_F;
					if (brd.IsInPlay(next, floor.x))
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

Vec2 Family::FindTarget(Vec2& targetloc, Vec2& targetfloor)
{
	if (floor == targetfloor)
	{
		return targetloc;
	}
	if (floor.x == 0)
	{
		if (targetfloor.x == 0)
		{
			if (floor.y == 3 && targetfloor.y == 5)
			{
				return F0CP5H;
			}
			else if (floor.y == 5)
			{
				return F0CP5L;
			}
			else if (targetfloor.y > floor.y)
			{
				return F0CPH[int(floor.y)];
			}
			else
			{
				return F0CPL[int(floor.y - 1)];
			}
		}
		else if (targetfloor.x == 1)
		{
			if (floor.y != 0)
			{
				Vec2 phantomfloor = { 0,0 };
				return FindTarget(targetloc, phantomfloor);
			}
			else
			{
				return F0T1;
			}
		}
		else if (targetfloor.x == 2)
		{
			if (floor.y != 3)
			{
				Vec2 phantomfloor = { 0,3 };
				return FindTarget(targetloc, phantomfloor);
			}
			else
			{
				return F0T2;
			}
		}
		else if (targetfloor.x == 3)
		{
			if (floor.y != 4)
			{
				Vec2 phantomfloor = { 0,4 };
				return FindTarget(targetloc, phantomfloor);
			}
			else
			{
				return F0T3;
			}
		}
	}
	else if (floor.x == 1)
	{
		if (targetfloor.x == 0)
		{
			return F1T0;
		}
		else if (targetfloor.x == 2)
		{
			return F1T2;
		}
		else if (targetfloor.x == 3)
		{
			return F1T3;
		}
	}
	else if (floor.x == 2)
	{
		if (targetfloor.x == 0)
		{
			return F2T0;
		}
		else if (targetfloor.x == 1)
		{
			return F2T1;
		}
		else if (targetfloor.x == 3)
		{
			return F2T1;
		}
	}
	else if (floor.x == 3)
	{
		if (targetfloor.x == 0)
		{
			return F3T0;
		}
		else if (targetfloor.x == 1)
		{
			return F3T1;
		}
		else if (targetfloor.x == 2)
		{
			return F3T1;
		}
	}
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
