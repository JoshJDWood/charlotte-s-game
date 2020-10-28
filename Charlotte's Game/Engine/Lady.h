#pragma once

#include "Board.h"

class Lady
{
public:
	void Draw(Board& brd);
	void Update(Vec2& delta_L, Board& brd);
	Vec2 GetLocation();
	Vec2 GetFloor();
	bool DidMove();
	bool IsSmelly();
	void SetToSmelly();
	void SetSmellyOver();
private:
	Vec2 loc = { 1,1 };
	Vec2 oldloc = { 0,0 };
	Vec2 floor = { 3,0 };
	bool moved = false;
	bool smelly = false;
};