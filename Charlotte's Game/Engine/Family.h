#pragma once

#include "Board.h"
#include <random>

class Family
{
public:
	Family() = default;
	Family(int index, std::mt19937& rng, int des1, int des2, int des3);
	void FindNewDestination(std::mt19937& rng, int des1, int des2, int des3);
	void Draw(Board& brd);
	void Update(float* MWx, float* MWy, float* MWf, int nMW, Board& brd);
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
	Vec2 Destinationfloor[nDestinations] = { {0,5}, {0,6}, {1,0}, {1,0}, {2,0}, {2,0}, {3,0}, {3,0} };
	Vec2 Destination[2] = { {0,0}, {0,0} };
	int Destinationindex = 0;
	bool resting = false;
	
	//shared with charlotte
	Vec2 loc = { 9,7 };
	Vec2 oldloc = { 0,0 };
	Vec2 floor = { 0, 6 };
	Vec2 delta_F = { 0,0 };
	bool moved = false;
	float MovePrefAlt = 1;
	float FloorPrefAlt = 1;
};