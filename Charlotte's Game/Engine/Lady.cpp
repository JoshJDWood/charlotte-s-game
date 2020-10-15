#include "Lady.h"

void Lady::Draw(Board& brd)
{
	brd.DrawLady(loc);
}

void Lady::Update(Vec2& delta_L)
{
	oldloc = loc;
	loc += delta_L;
	UpdateFloor();
}

void Lady::UpdateFloor()
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

Vec2 Lady::GetLocation()
{
	return loc;
}

Vec2 Lady::GetFloor()
{
	return floor;
}
