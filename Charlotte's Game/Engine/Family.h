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
	bool IsStunned();
	void Stun();
	void UnStun();
	int GetDI();
private:
	//family specific
	int selfindex = 10;
	static constexpr int nDestinations = 22;
	Vec2 Destinationloc[nDestinations] = { 
		{21,2}, {18,8}, {21,15}, {8,14}, {4,14}, {6,8}, {13,14}, {21,8},  //F0
		{6,1}, {15,1}, //F1
		{2,2}, {6,2}, {2,10}, {11,5}, {5,16}, //F2
		{8,14}, {21,7}, {15,3}, {2,8}, {3,15}, {11,7}, {17,14} }; //F3
	Vec2 Destinationfloor[nDestinations] = { 
		{0,2}, {0,3}, {0,5}, {0,6}, {0,6}, {0,4}, {0,5}, {0,3}, //F0
		{1,0}, {1,0}, //F1
		{2,0}, {2,0}, {2,0}, {2,0}, {2,2}, //F2
		{3,0}, {3,0}, {3,0}, {3,0}, {3,0}, {3,0}, {3,1} }; //F3
	Vec2 Destination[2] = { {0,0}, {0,0} };
	int Destinationindex = 0;
	bool resting = false;
	bool stunned = false;
	
	//shared with charlotte
	Vec2 startloc = { 9,7 };
	Vec2 startfloor = { 0, 7 };
	Vec2 loc = { 9,7 };
	Vec2 oldloc = { 0,0 };
	Vec2 floor = { 0, 7 };
	Vec2 delta_F = { 0,0 };
	bool moved = false;
	float MovePrefAlt = 1;
	float FloorPrefAlt = 1;
};