#include "Charlotte.h"

void Charlotte::Draw(Board& brd)
{
	brd.DrawCell(loc, c);
}

void Charlotte::Update(Vec2& target, Board& brd)
{
	Vec2 diff = target - loc;
	if (abs(diff.x) > abs(diff.y))
	{
		delta_C.x = diff.x / abs(diff.x);
		Vec2 next = loc + delta_C;
		if (brd.IsInPlay(next))
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
				if (brd.IsInPlay(next))
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
				if (brd.IsInPlay(next))
				{
					loc = next;
					moved = true;
				}
				else if (brd.IsInPlay(altnext))
				{
					loc = altnext;
					moved = true;
				}
				if (!moved)
				{
					delta_C.x = -diff.x / abs(diff.x);
					next = loc + delta_C;
					if (brd.IsInPlay(next))
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
		if (brd.IsInPlay(next))
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
				if (brd.IsInPlay(next))
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
				if (brd.IsInPlay(next))
				{
					loc = next;
					moved = true;
				}
				else if (brd.IsInPlay(altnext))
				{
					loc = altnext;
					moved = true;
				}
				if (!moved)
				{
					delta_C.y = -diff.y / abs(diff.y);
					next = loc + delta_C;
					if (brd.IsInPlay(next))
					{
						loc = next;
						moved = true;
					}
				}
			}
		}
	}
	delta_C = { 0,0 };
	moved = false;	
}

Vec2 Charlotte::GetLoction()
{
	return loc;
}


