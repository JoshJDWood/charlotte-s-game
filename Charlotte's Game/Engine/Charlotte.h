#pragma once

#include "Board.h"
#include "Lady.h"

class Charlotte
{
public:
	void Draw(Board& brd);
	void Update(Vec2& target, Board& brd);
	Vec2 FindTarget(Vec2& lfloor, Vec2& lloc);
	Vec2 UpdateFloor();
	Vec2 GetLoction();
	Vec2 GetFloor();
private:
	Vec2 loc = { 2,2 };
	Vec2 oldloc;
	Vec2 floor = { 1, 0 };
	Vec2 delta_C = { 0,0 };
	static constexpr int CPn = 4;
	Vec2 F0CPH[CPn] = { {12,4}, {19,4}, {20,8}, {13,12} };
	Vec2 F0CPL[CPn] = { {11,4}, {18,4}, {20,7}, {13,11} };
	Vec2 F0CP5H = { 8,11 };
	Vec2 F0CP5L = { 8,10 };
	Color c = Colors::Red;
	bool moved = false;
	float MovePrefAlt = 1;
};