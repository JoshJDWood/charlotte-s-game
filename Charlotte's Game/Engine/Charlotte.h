#pragma once

#include "Board.h"
#include "Lady.h"

class Charlotte
{
public:
	void Draw(Board& brd);
	void Update(Lady& lady, Board& brd);
private:
	Vec2 loc = { 5,5 };
	Vec2 delta_C = { 0,0 };
	Color c = Colors::Red;
};