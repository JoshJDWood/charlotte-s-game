#include "Charlotte.h"

void Charlotte::Draw(Board& brd)
{
	brd.DrawCell(loc, c);
}

void Charlotte::Update(Lady& lady, Board& brd)
{
	Vec2 diff = lady.GetLocation() - loc;
	if (abs(diff.x) > abs(diff.y))
	{
		delta_C.x = diff.x / abs(diff.x);
		Vec2 next = loc + delta_C;
		if (brd.IsInPlay(next))
		{
			loc = next;
		}
		else if ( !diff.y == 0)
		{
			delta_C = { 0,diff.y / abs(diff.y) };
			next = loc + delta_C;
			if (brd.IsInPlay(next))
			{
				loc = next;
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
		}
		else if (!diff.x == 0)
		{
			delta_C = { diff.x / abs(diff.x),0 };
			next = loc + delta_C;
			if (brd.IsInPlay(next))
			{
				loc = next;
			}
		}
	}
	delta_C = { 0,0 };
}

Vec2 Charlotte::GetLoction()
{
	return loc;
}
