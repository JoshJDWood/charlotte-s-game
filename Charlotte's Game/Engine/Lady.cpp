#include "Lady.h"

void Lady::Draw(Board& brd)
{
	brd.DrawCell(loc, c);
}

void Lady::Update(Vec2& delta_loc)
{
	loc += delta_loc;
}
