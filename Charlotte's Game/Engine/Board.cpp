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

void Board::DrawPoo(Vec2& loc, float floorindex)
{
	if (floorindex == 0)
	{
		x = int(shiftx(width0) + loc.x * dim) + 16;
		y = int(shifty(height0) + loc.y * dim) + 16;
	}
	else if (floorindex == 1)
	{
		x = int(shiftx(width1) + loc.x * dim) + 16;
		y = int(shifty(height1) + loc.y * dim) + 16;
	}
	else if (floorindex == 2)
	{
		x = int(shiftx(width2) + loc.x * dim) + 16;
		y = int(shifty(height2) + loc.y * dim) + 16;
	}
	else if (floorindex == 3)
	{
		x = int(shiftx(width3) + loc.x * dim) + 16;
		y = int(shifty(height3) + loc.y * dim) + 16;
	}
}

void Board::DrawLady(Vec2& loc, float floorindex, bool smelly)
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
	if (!smelly)
	{
		gfx.DrawSprite(int(sx + loc.x * dim), int(sy + loc.y * dim), ladysurf, Color(220, 220, 220));
	}
	else
	{
		gfx.DrawSpriteNonChroma(int(sx + loc.x * dim), int(sy + loc.y * dim), ladysurf);
	}
}

bool Board::IsInPlay(Vec2& next, float floorindex)
{
	if (floorindex == 0)
	{
		if (next.y == 17)
		{
			return false;
		}
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
		if (next.y == 0)
		{
			return false;
		}
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
		else if (oldloc == loc && loc == F0T1)
		{
			floor.x = 1;
			loc = F1T0;
		}
		else if (oldloc == loc && loc == F0T2)
		{
			floor = { 2,0 };
			loc = F2T0;
		}
		else if (oldloc == loc && loc == F0T3)
		{
			floor = { 3,0 };
			loc = F3T0;
		}
	}
	else if (floor.x == 1)
	{
		if (oldloc == loc && loc == F1T0)
		{
			floor = { 0,0 };
			loc = F0T1;
		}
		else if (oldloc == loc && loc == F1T2)
		{
			floor.x = 2;
			loc = F2T1;
		}
		else if (oldloc == loc && loc == F1T3)
		{
			floor.x = 3;
			loc = F3T1;
		}
	}
	else if (floor.x == 2)
	{
		if (oldloc == loc && loc == F2T1)
		{
			floor.x = 1;
			loc = F1T2;
		}
		else if (oldloc == loc && loc == F2T0)
		{
			floor = { 0,3 };
			loc = F0T2;
		}
	}
	else if (floor.x == 3)
	{
		if (oldloc == loc && loc == F3T1)
		{
			floor.x = 1;
			loc = F1T3;
		}
		else if (oldloc == loc && loc == F3T0)
		{
			floor = { 0,4 };
			loc = F0T3;
		}
	}
}
