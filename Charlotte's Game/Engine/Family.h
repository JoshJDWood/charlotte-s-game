#pragma once

#include "Board.h"
#include <random>

class Family
{
public:
	Family() = default;
	Family(int index, std::mt19937& rng);
	void FindNewDestination(std::mt19937& rng, int des1, int des2);
	bool DestinationVacant(int newDI_in);
	void Draw(Board& brd);
	void Update(float* MWx, float* MWy, float* MWf, int nMW, Board& brd);
	Vec2 FindTarget(Vec2& targetloc, Vec2& targetfloor);
	Vec2 GetLoction();
	Vec2 GetFloor();
	bool IsResting();
	void SetToResting();
	void SetRestingEnd();
	int GetDI();
private:
	//family specific
	int selfindex = 10;
	static constexpr int nDestinations = 8;
	Vec2 Destinationloc[nDestinations] = { {21,15}, {4,14}, {6,1}, {15,1}, {2,2}, {2,9}, {8,14}, {21,7} };
	Vec2 Destinationfloor[nDestinations] = { {0,4}, {0,5}, {1,0}, {1,0}, {2,0}, {2,0}, {3,0}, {3,0} };
	Vec2 Destination[2] = { {0,0}, {0,0} };
	int Destinationindex = 0;
	bool resting = false;
	
	//shared with charlotte
	Vec2 loc = { 8,9 };
	Vec2 oldloc = { 0,0 };
	Vec2 floor = { 0, 3 };
	Vec2 delta_F = { 0,0 };
	static constexpr int CPn = 4;
	Vec2 F0CPH[CPn] = { {12,4}, {19,4}, {20,8}, {13,11} };
	Vec2 F0CPL[CPn] = { {11,4}, {18,4}, {20,7}, {13,10} };
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
	bool moved = false;
	float MovePrefAlt = 1;
	float FloorPrefAlt = 1;
};