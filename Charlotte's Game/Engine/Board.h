#pragma once

#include "Graphics.h"

class Board
{
public:
	Board(Graphics& gfx);
	void DrawBorder();
	void DrawWalls();
	void DrawCell( Vec2& loc, Color c);
private:
	static constexpr int nWalls = 41;
	Vec2 walls[nWalls] = { {3,0}, {4,0}, {5,0}, {6,0}, {7,0}, {1,1}, {9,1}, 
	{1,2}, {3,2}, {4,2}, {6,2}, {7,2}, {9,2}, {0,4}, {2,4}, {4,4}, {6,4}, 
		{8,4}, {10,4}, {2,5}, {4,5}, {6,5}, {8,5}, {0,6}, {2,6}, {4,6}, {5,6},
		{6,6}, {8,6}, {10,6}, {5,7}, {1,8}, {3,8}, {5,8}, {7,8}, {9,8},
		{1,9}, {5,9}, {9,9}, {3,10}, {7,10} };
	static constexpr float dim = 30;
	static constexpr float width = 11;
	static constexpr float height = 11;
	static constexpr Color bordercolor = Colors::Blue;
	static constexpr float borderthickness = 3;
	static constexpr float shiftx = (400 - width * dim / 2);
	static constexpr float shifty = (300 - height * dim / 2);
	Graphics& gfx;
};