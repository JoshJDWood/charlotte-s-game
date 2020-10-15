#include "Charlotte.h"

void Charlotte::Draw(Board& brd)
{
	brd.DrawCell(loc, floor.x, c);
}

void Charlotte::Update(Vec2& target, Board& brd)
{
	oldloc = loc;
	Vec2 diff = target - loc;
	if (abs(diff.x) > abs(diff.y))
	{
		delta_C.x = diff.x / abs(diff.x);
		Vec2 next = loc + delta_C;
		if (brd.IsInPlay(next, floor.x))
		{
			loc = next;
			moved = true;
		}
		else if (!moved)
		{
			if (diff.y != 0)
			{
				delta_C = { 0,diff.y / abs(diff.y) };
				next = loc + delta_C;
				if (brd.IsInPlay(next, floor.x))
				{
					loc = next;
					moved = true;
				}
			}
			if (!moved)
			{
				MovePrefAlt *= -1;
				delta_C = { 0, 1 * MovePrefAlt };
				next = loc + delta_C;
				Vec2 altnext = loc - delta_C;
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
					delta_C.x = -diff.x / abs(diff.x);
					next = loc + delta_C;
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
		delta_C.y = diff.y / abs(diff.y);
		Vec2 next = loc + delta_C;
		if (brd.IsInPlay(next, floor.x))
		{
			loc = next;
			moved = true;
		}
		else if (!moved)
		{
			if (diff.x != 0)
			{
				delta_C = { diff.x / abs(diff.x),0 };
				next = loc + delta_C;
				if (brd.IsInPlay(next, floor.x))
				{
					loc = next;
					moved = true;
				}
			}
			if (!moved)
			{
				MovePrefAlt *= -1;
				delta_C = { 1 * MovePrefAlt, 0 };
				next = loc + delta_C;
				Vec2 altnext = loc - delta_C;
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
					delta_C.y = -diff.y / abs(diff.y);
					next = loc + delta_C;
					if (brd.IsInPlay(next, floor.x))
					{
						loc = next;
						moved = true;
					}
				}
			}
		}
	}
	UpdateFloor();
	delta_C = { 0,0 };
	moved = false;	
}

Vec2 Charlotte::FindTarget(Lady& lady, Board& brd)
{
	Vec2 Lfloor = lady.GetFloor();
	if (floor == Lfloor)
	{
		return lady.GetLocation();
	}
	if (floor.x == 0)
	{
		if (Lfloor.y > floor.y)
		{
			return F0CPH[int(floor.y)];
		}
		else
		{
			return F0CPL[int(floor.y - 1)];
		}
	}
}

void Charlotte::UpdateFloor()
{
	for (int i = 0; i < CPn; i++)
	{
		if (oldloc == F0CPL[i] && loc == F0CPH[i])
		{
			floor.y = float(i) + 1;
		}
		else if (oldloc == F0CPH[i] && loc == F0CPL[i])
		{
			floor.y = float(i);
		}
	}
}

Vec2 Charlotte::GetLoction()
{
	return loc;
}

Vec2 Charlotte::GetFloor()
{
	return floor;
}


