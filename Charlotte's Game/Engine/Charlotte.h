#pragma once

#include "Board.h"

class Charlotte
{
public:
	void Draw(Board& brd);
	void Update(Vec2& target, float Lfloor, bool smelly, float* MWx, float* MWy, float* MWf, int nMW, Board& brd);
	Vec2 FindTarget(Vec2& lfloor, Vec2& lloc);
	Vec2 GetLoction();
	Vec2 GetFloor();
private:
	Vec2 loc = { 22,1 };
	Vec2 oldloc = { 0,0 };
	Vec2 floor = { 3, 0 };
	Vec2 delta_C = { 0,0 };
	static constexpr int CPn = 4;
	Vec2 F0CPH[CPn] = { {12,4}, {19,4}, {20,8}, {13,12} };
	Vec2 F0CPL[CPn] = { {11,4}, {18,4}, {20,7}, {13,11} };
	Vec2 F0CP5H = { 7,12 };
	Vec2 F0CP5L = { 7,11 };
	Vec2 F0T2 = { 0, 9 };
	Vec2 F2T0 = { 17, 11 };
	Vec2 F2T1 = { 17, 2 };
	Vec2 F1T2 = { 0, 2 };
	Vec2 F0T1 = { 13,0 };
	Vec2 F1T0 = { 13, 4 };
	Vec2 F1T3 = { 23, 2 };
	Vec2 F3T1 = { 0, 2 };
	Vec2 F0T3 = { 23, 13 };
	Vec2 F3T0 = { 0, 13 };
	Color c = Colors::Red;
	bool moved = false;
	float MovePrefAlt = 1;
	float FloorPrefAlt = 1;
};