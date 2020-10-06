#include "Board.h"

Board::Board(Graphics& gfx)
	:
	gfx(gfx)
{
}

void Board::DrawBorder()
{
	int left = int(shiftx - borderthickness);
	int right = int(shiftx + borderthickness + width * dimension);
	int top = int(shifty - borderthickness);
	int bottom = int(shifty + borderthickness + height * dimension);
	gfx.DrawRect(left, top, right, top + 2 * int(borderthickness), bordercolor);
	gfx.DrawRect(left, top, left + 2 * int(borderthickness), bottom, bordercolor);
	gfx.DrawRect(right - 2 * int(borderthickness), top, right, bottom, bordercolor);
	gfx.DrawRect(left, bottom - 2 * int(borderthickness), right, bottom, bordercolor);
}
