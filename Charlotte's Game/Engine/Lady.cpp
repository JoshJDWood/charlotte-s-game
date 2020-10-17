#include "Lady.h"

void Lady::Draw(Board& brd)
{
	brd.DrawLady(loc, floor.x);
}

void Lady::Update(Vec2& delta_L)
{
	oldloc = loc;
	loc += delta_L;
	UpdateFloor();
}

Vec2 Lady::UpdateFloor()
{	
	if (floor.x == 0)
	{
		for (int i = 0; i < CPn; i++)
		{
			if (oldloc == F0CPL[i] && loc == F0CPH[i])
			{
				floor.y = float(i) + 1;
				return floor;
			}
			else if (oldloc == F0CPH[i] && loc == F0CPL[i])
			{
				floor.y = float(i);
				return floor;
			}
		}
		if (oldloc == F0CP5L && loc == F0CP5H)
		{
			floor.y = 5;
			return floor;
		}
		else if (oldloc == F0CP5H && loc == F0CP5L)
		{
			floor.y = 3;
			return floor;
		}
		if (oldloc == loc && loc == Vec2(13, 0))
		{
			floor.x = 1;
			loc = { 13,4 };
			return floor;
		}
	}
	else if (floor.x == 1)
	{
		if (oldloc == loc && loc == Vec2(13, 4))
		{
			floor.x = 0;
			loc = { 13,0 };
			return floor;
		}
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
