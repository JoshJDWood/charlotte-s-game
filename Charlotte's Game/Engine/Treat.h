#pragma once

#include "Vec2.h"
#include "Board.h"

class Treat
{
public:
	Treat(Vec2& locin);
	void Draw(Board& brd);
	bool eaten = false;
	Vec2 GetLocation();
private:
	Vec2 loc;
};