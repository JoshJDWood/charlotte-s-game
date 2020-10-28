#pragma once

#include "Vec2.h"
#include "Board.h"

class Poo
{
public:
	Poo(Vec2& locin, float floorin);
	void Draw(Board& brd);
	Vec2 GetLocation();
	float GetFloor();
	bool GetRolledIn();
	void SetToRolledIn();
private:
	Vec2 loc;
	float floor;
	bool RolledIn = false;
	Color poocolor = Color(138, 77, 0);
};