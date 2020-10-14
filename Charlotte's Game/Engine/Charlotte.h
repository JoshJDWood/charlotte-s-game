#pragma once

#include "Board.h"
#include "Lady.h"

class Charlotte
{
public:
	void Draw(Board& brd);
	void Update(Vec2& target, Board& brd);
	Vec2 GetLoction();
private:
	Vec2 loc = { 10,14 };
	Vec2 delta_C = { 0,0 };
	Color c = Colors::Red;
	bool moved = false;
	float MovePrefAlt = 1;
};