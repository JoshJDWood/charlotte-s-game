#pragma once

#include "Board.h"

class Lady
{
public:
	void Draw(Board& brd);
	void Update(Vec2& delta_loc);
private:
	Vec2 loc = { 5,3 };
	Color c = Colors::Gray;
};