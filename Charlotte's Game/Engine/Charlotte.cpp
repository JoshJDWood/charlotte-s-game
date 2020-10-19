#include "Charlotte.h"

void Charlotte::Draw(Board& brd)
{
	brd.DrawCell(loc, floor.x, c);
}

void Charlotte::Update(Vec2& target, Board& brd)
{
	oldloc = loc;
	Vec2 diff = target - loc;
	if (diff == Vec2(0, 0))
	{
		//fake move so it can change floor
		moved = true;
	}
	else if (abs(diff.x) > abs(diff.y))
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
	brd.UpdateFloor(floor, loc, oldloc);
	delta_C = { 0,0 };
	moved = false;	
}

Vec2 Charlotte::FindTarget(Vec2& lfloor, Vec2& lloc)
{
	if (floor == lfloor)
	{
		return lloc;
	}
	if (floor.x == 0)
	{
		if (lfloor.x == 0)
		{
			if (floor.y == 3 && lfloor.y == 5)
			{
				return F0CP5H;
			}
			else if (floor.y == 5)
			{
				return F0CP5L;
			}
			else if (lfloor.y > floor.y)
			{
				return F0CPH[int(floor.y)];
			}
			else
			{
				return F0CPL[int(floor.y - 1)];
			}
		}
		else if (lfloor.x == 1)
		{
			if (floor.y != 0)
			{
				Vec2 phantomfloor = { 0,0 };
				return FindTarget( phantomfloor, lloc);
			}
			else
			{
				return { 13,0 };
			}
		}
		else if (lfloor.x == 2)
		{
			if (floor.y != 3)
			{
				Vec2 phantomfloor = { 0,3 };
				return FindTarget(phantomfloor, lloc);
			}
			else
			{
				return { 0,9 };
			}
		}
	}
	else if (floor.x == 1)
	{
		if (lfloor.x == 0)
		{
			return { 13, 4 };
		}
		else if (lfloor.x == 2)
		{
			return { 0,2 };
		}
	}
	else if (floor.x == 2)
	{
		if (lfloor.x == 0)
		{
			return { 17,11 };
		}
		else if (lfloor.x == 1)
		{
			return { 17,2 };
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


