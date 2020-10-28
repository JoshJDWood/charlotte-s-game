#pragma once

#include "Vec2.h"
#include "Board.h"

class Treat
{
public:
	Treat(Vec2& locin, float floorin);
	void Draw(Board& brd);	
	Vec2 GetLocation();
	float GetFloor();
	bool GetEaten();
	void SetToEaten();
private:
	Vec2 loc;
	float floor;
	bool eaten = false;
};