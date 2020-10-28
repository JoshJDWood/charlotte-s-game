#pragma once

#include "Vec2.h"
#include "Board.h"
#include <random>

class Treat
{
public:
	Treat() = default;
	Treat(std::mt19937 & rng, Board & brd, int floorin);
	void Draw(Board& brd);	
	Vec2 GetLocation();
	float GetFloor();
	bool GetEaten();
	void SetToEaten();
private:
	Vec2 loc = { 0,0 };
	float floor = 0;
	bool eaten = false;
	Color c = Colors::Cyan;
};