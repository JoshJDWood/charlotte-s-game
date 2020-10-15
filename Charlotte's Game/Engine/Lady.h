#pragma once

#include "Board.h"

class Lady
{
public:
	void Draw(Board& brd);
	void Update(Vec2& delta_L);
	Vec2 GetLocation();
	Vec2 GetFloor();
private:
	Vec2 loc = { 18,16 };
	Vec2 oldloc;
	Vec2 floor = { 0, 4 };
};