#pragma once

#include "Vec2.h"
#include "Board.h"

class Treat
{
public:
	Treat(Vec2& locin, float floorin);
	void Draw(Board& brd);
	bool eaten = false;
	Vec2 GetLocation();
	float GetFloor();
private:
	Vec2 loc;
	float floor;
};