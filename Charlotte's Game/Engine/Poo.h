#pragma once

#include "Vec2.h"
#include "Board.h"
#include <random>

class Poo
{
public:
	Poo() = default;
	Poo(std::mt19937& rng, Board& brd, int floorin);
	void Draw(Board& brd);
	Vec2 GetLocation();
	float GetFloor();
	bool IsRolledIn();
	void SetToRolledIn();
private:
	Vec2 loc = { 0,0 };
	float floor = 0;
	bool RolledIn = false;
};