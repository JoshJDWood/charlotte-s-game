#pragma once

#include "Board.h"

class Lady
{
public:
	void Draw(Board& brd);
	void Update(Vec2& delta_L);
	Vec2 UpdateFloor();
	Vec2 GetLocation();
	Vec2 GetFloor();
private:
	Vec2 loc = { 11,9 };
	Vec2 oldloc = { 0,0 };
	Vec2 floor = { 0,3 };
	static constexpr int CPn = 4;
	Vec2 F0CPH[CPn] = { {12,4}, {19,4}, {20,8}, {13,12} };
	Vec2 F0CPL[CPn] = { {11,4}, {18,4}, {20,7}, {13,11} };
	Vec2 F0CP5H = { 7,11 };
	Vec2 F0CP5L = { 7,10 };
};