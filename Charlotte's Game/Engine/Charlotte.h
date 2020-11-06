#pragma once

#include "Board.h"

class Charlotte
{
public:
	void Draw(Board& brd);
	void Update(Vec2& target, float Lfloor, bool smelly, 
		float* MWx, float* MWy, float* MWf, int nMW, Board& brd);
	Vec2 GetLoction();
	Vec2 GetFloor();
private:
	Vec2 loc = { 14,7 };
	Vec2 oldloc = { 0,0 };
	Vec2 floor = { 0, 6 };
	Vec2 delta_C = { 0,0 };
	bool moved = false;
	float MovePrefAlt = 1;
	float FloorPrefAlt = 1;
};