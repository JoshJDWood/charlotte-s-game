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
	else if (floorindex == 2)
	{
		sx = shiftx(width2);
		sy = shifty(height2);
		for (int i = 0; i < nWalls2; i++)
		{
			gfx.DrawRectDim(int(sx + walls2[i].x * dim), int(sy + walls2[i].y * dim),
				int(dim), int(dim), bordercolor);
		}
	}
	else if (floorindex == 3)
	{
		sx = shiftx(width3);
		sy = shifty(height3);
		for (int i = 0; i < nWalls3; i++)
		{
			gfx.DrawRectDim(int(sx + walls3[i].x * dim), int(sy + walls3[i].y * dim),
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
	else if (floorindex == 2)
	{
		sx = shiftx(width2);
		sy = shifty(height2);
	}
	else if (floorindex == 3)
	{
		sx = shiftx(width3);
		sy = shifty(height3);
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
	else if (floorindex == 2)
	{
		x = int(shiftx(width2) + loc.x * dim) + 14;
		y = int(shifty(height2) + loc.y * dim) + 14;
	}
	else if (floorindex == 3)
	{
		x = int(shiftx(width3) + loc.x * dim) + 14;
		y = int(shifty(height3) + loc.y * dim) + 14;
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
	else if (floorindex == 2)
	{
		sx = shiftx(width2);
		sy = shifty(height2);
	}
	else if (floorindex == 3)
	{
		sx = shiftx(width3);
		sy = shifty(height3);
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
	else if (floorindex == 2)
	{
		if (next.x == 0 || next.y == 0 || next.y == 17)
		{
			return false;
		}
		for (int i = 0; i < nWalls2; ++i)
		{
			if (next == walls2[i])
			{
				return false;
			}
		}
		return true;
	}
	else if (floorindex == 3)
	{
		if (next.y == 0 || next.y == 17 || next.x == 23)
		{
			return false;
		}
		for (int i = 0; i < nWalls3; ++i)
		{
			if (next == walls3[i])
			{
				return false;
			}
		}
		return true;
	}
}

void Board::UpdateFloor(Vec2& floor, Vec2& loc, Vec2& oldloc)
{
	if (floor.x == 0)
	{
		for (int i = 0; i < CPn; i++)
		{
			if (oldloc == F0CPL[i] && loc == F0CPH[i])
			{
				floor.y = float(i) + 1;				
			}
			else if (oldloc == F0CPH[i] && loc == F0CPL[i])
			{
				floor.y = float(i);
			}
		}
		if (oldloc == F0CP5L && loc == F0CP5H)
		{
			floor.y = 5;
		}
		else if (oldloc == F0CP5H && loc == F0CP5L)
		{
			floor.y = 3;
		}
		if (oldloc == loc && loc == Vec2(13, 0))
		{
			floor.x = 1;
			loc = { 13,4 };
		}
		if (oldloc == loc && loc == Vec2(0, 9))
		{
			floor = { 2,0 };
			loc = { 17,11 };
		}
	}
	else if (floor.x == 1)
	{
		if (oldloc == loc && loc == Vec2(13, 4))
		{
			floor = { 0,0 };
			loc = { 13,0 };
		}
		else if (oldloc == loc && loc == Vec2(0, 2))
		{
			floor.x = 2;
			loc = { 17,2 };
		}
	}
	else if (floor.x == 2)
	{
		if (oldloc == loc && loc == Vec2(17, 2))
		{
			floor.x = 1;
			loc = { 0, 2 };
		}
		else if (oldloc == loc && loc == Vec2(17, 11))
		{
			floor = { 0,3 };
			loc = { 0, 9 };
		}
	}
}
