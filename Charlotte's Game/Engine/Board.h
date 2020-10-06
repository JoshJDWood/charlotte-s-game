#pragma once

#include "Location.h"
#include "Graphics.h"

class Board
{
public:
	Board(Graphics& gfx);
	void DrawBorder();
private:
	static constexpr float dimension = 25;
	static constexpr float width = 10;
	static constexpr float height = 10;
	static constexpr Color bordercolor = Colors::Blue;
	static constexpr float borderthickness = 2;
	static constexpr float shiftx = (400 - width * dimension / 2);
	static constexpr float shifty = (300 - height * dimension / 2);
	Graphics& gfx;
};