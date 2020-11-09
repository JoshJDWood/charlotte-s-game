#pragma once

#include "Board.h"

class Lady
{
public:
	void Draw(Board& brd);
	void Update(Vec2& delta_L, float* MWx, float* MWy, float* MWf, int nMW, Board& brd);
	Vec2 GetLocation();
	Vec2 GetFloor();
	bool DidMove();
	bool IsSmelly();
	void SetToSmelly();
	void SetSmellyOver();
private:
	Vec2 loc = { 2,9 };
	Vec2 oldloc = { 0,0 };
	Vec2 floor = { 0,4 };
	bool moved = false;
	bool smelly = false;
	bool caught = false;
};