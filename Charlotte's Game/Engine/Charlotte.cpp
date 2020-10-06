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

	}
	else
	{
		delta_C.y = diff.y / abs(diff.y);
	}
}
