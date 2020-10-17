#include "Board.h"

Board::Board(Graphics& gfx)
	:
	gfx(gfx)
{
}

void Board::DrawWalls(float floorindex)
{;
	if (floorindex == 0)
	{
		sx = shiftx(width0);
		sy = shifty(height0);
		for (int i = 0; i < nWalls0; i++)
		{
			gfx.DrawRectDim(int(sx + walls0[i].x * dim), int(sy + walls0[i].y * dim),
				int(dim), int(dim), bordercolor);
		}
	}
	else if (floorindex == 1)
	{
		sx = shiftx(width1);
		sy = shifty(height1);
		for (int i = 0; i < nWalls1; i++)
		{
			gfx.DrawRectDim(int(sx + walls1[i].x * dim), int(sy + walls1[i].y * dim),
				int(dim), int(dim), bordercolor);
		}
	}
	
}

void Board::DrawCell(Vec2& loc, float floorindex, Color c)
{
	if (floorindex == 0)
	{
		sx = shiftx(width0);
		sy = shifty(height0);
	}
	else if (floorindex == 1)
	{
		sx = shiftx(width1);
		sy = shifty(height1);
	}
	gfx.DrawRectDim(int(sx + loc.x * dim), int(sy + loc.y * dim),
		int(dim), int(dim), c);
}

void Board::DrawTreat(Vec2& loc, float floorindex)
{
	if (floorindex == 0)
	{
		x = int(shiftx(width0) + loc.x * dim) + 14;
		y = int(shifty(height0) + loc.y * dim) + 14;
	}
	else if (floorindex == 1)
	{
		x = int(shiftx(width1) + loc.x * dim) + 14;
		y = int(shifty(height1) + loc.y * dim) + 14;
	}
	gfx.PutPixel(x, y, treatout);
	gfx.PutPixel(x + 1, y, treatout);
	gfx.PutPixel(x + 2, y, treatout);
	gfx.PutPixel(x + 3, y, treatout);
	gfx.PutPixel(x, y + 1, treatout);
	gfx.PutPixel(x + 1, y + 1, treatin);
	gfx.PutPixel(x + 2, y + 1, treatin);
	gfx.PutPixel(x + 3, y + 1, treatout);
	gfx.PutPixel(x, y + 2, treatout);
	gfx.PutPixel(x + 1, y + 2, treatin);
	gfx.PutPixel(x + 2, y + 2, treatin);
	gfx.PutPixel(x + 3, y + 2, treatout);
	gfx.PutPixel(x, y + 3, treatout);
	gfx.PutPixel(x + 1, y + 3, treatout);
	gfx.PutPixel(x + 2, y + 3, treatout);
	gfx.PutPixel(x + 3, y + 3, treatout);
}

void Board::DrawLady(Vec2& loc, float floorindex)
{
	
	if (floorindex == 0)
	{
		sx = shiftx(width0);
		sy = shifty(height0);
	}
	else if (floorindex == 1)
	{
		sx = shiftx(width1);
		sy = shifty(height1);
	}
	gfx.DrawSprite(int(sx +loc.x * dim), int(sy + loc.y * dim), ladysurf, Color(220,220,220));
}

bool Board::IsInPlay(Vec2& next, float floorindex)
{
	if (floorindex == 0)
	{
		for (int i = 0; i < nWalls0; ++i)
		{
			if (next == walls0[i])
			{
				return false;
			}
		}
		return true;
	}
	else if (floorindex == 1)
	{
		for (int i = 0; i < nWalls1; ++i)
		{
			if (next == walls1[i])
			{
				return false;
			}
		}
		return true;
	}
}
