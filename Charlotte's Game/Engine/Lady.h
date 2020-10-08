#pragma once

#include "Board.h"

class Lady
{
public:
	void Draw(Board& brd);
	void Update(Vec2& delta_L);
	Vec2 GetLocation();
private:
	Vec2 loc = { 2,0 };
	Color c = Colors::Gray;
};