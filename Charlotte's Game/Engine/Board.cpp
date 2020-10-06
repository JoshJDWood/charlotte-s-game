#include "Board.h"

Board::Board(Graphics& gfx)
	:
	gfx(gfx)
{
}

void Board::DrawBorder()
{
	int left = int(shiftx - borderthickness);
	int right = int(shiftx + borderthickness + width * dim);
	int top = int(shifty - borderthickness);
	int bottom = int(shifty + borderthickness + height * dim);
	gfx.DrawRect(left, top, right, top + int(borderthickness), bordercolor);
	gfx.DrawRect(left, top, left + int(borderthickness), bottom, bordercolor);
	gfx.DrawRect(right - int(borderthickness), top, right, bottom, bordercolor);
	gfx.DrawRect(left, bottom - int(borderthickness), right, bottom, bordercolor);
}

void Board::DrawWalls()
{
	for (int i = 0; i < nWalls; i++)
	{
		gfx.DrawRectDim(int(shiftx + walls[i].x * dim), int(shifty + walls[i].y * dim),
			int(dim), int(dim), bordercolor);
	}
}
