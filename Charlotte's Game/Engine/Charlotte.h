#pragma once

#include "Board.h"
#include "Lady.h"

class Charlotte
{
public:
	void Draw(Board& brd);
	void Update(Lady& lady, Board& brd);
	Vec2 GetLoction();
private:
	Vec2 loc = { 4,7 };
	Vec2 delta_C = { 0,0 };
	Color c = Colors::Red;
};