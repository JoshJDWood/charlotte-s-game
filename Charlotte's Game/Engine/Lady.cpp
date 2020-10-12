#include "Lady.h"

void Lady::Draw(Board& brd)
{
	brd.DrawLady(loc);
}

void Lady::Update(Vec2& delta_L)
{
	loc += delta_L;
}

Vec2 Lady::GetLocation()
{
	return loc;
}
