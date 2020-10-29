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
	sx = shiftx(width[int(floorindex)]);
	sy = shifty(height[int(floorindex)]);
	
	gfx.DrawRectDim(int(sx + loc.x * dim), int(sy + loc.y * dim),
		int(dim), int(dim), c);
}

void Board::DrawTreat(Vec2& loc, float floorindex)
{		
	x = int(shiftx(width[int(floorindex)]) + loc.x * dim) + 14;
	y = int(shifty(height[int(floorindex)]) + loc.y * dim) + 14;
}

void Board::DrawPoo(Vec2& loc, float floorindex)
{	
	x = int(shiftx(width[int(floorindex)]) + loc.x * dim) + 16;
	y = int(shifty(height[int(floorindex)]) + loc.y * dim) + 16;
}

void Board::DrawLady(Vec2& loc, float floorindex, bool smelly)
{	
	sx = shiftx(width[int(floorindex)]);
	sy = shifty(height[int(floorindex)]);
	
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
		if (next.x == -1 || next.y == 0 || next.y == 17)
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

bool Board::IsInPlayCon(Vec2& next, float floorindex)
{
	if (floorindex == 0)
	{
		if (next.y == 17 || next.y == 0 || next.x == 0 || next.x == 23)
		{
			return false;
		}
		else if (next.x > 0 && next.x < 3 && next.y > 0 && next.y < 7)
		{
			return false;
		}
		else if (next == Vec2(6, 6) || next == Vec2(4, 7) || next == Vec2(1, 11) ||
			next == Vec2(22, 7) || next == Vec2(6, 6) || next == Vec2(22, 16) ||
			next == Vec2(19, 14) || next == Vec2(17, 14))
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
		if (next.y == 0 || next.y == 5 || next.x == 0 || next.x == 23)
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
		if ((next.x == 0 && next.y > 7) || next.y == 0 || next.y == 17 || next.x == 17)
		{
			return false;
		}
		else if (
			(next.y == 3 && next.x > 10 && next.x < 14) || next == Vec2(12, 15) || next == Vec2(16, 16) ||
			(next.y == 6 && next.x > 2 && next.x < 7) || (next.y == 7 && next.x > 11 && next.x < 15) ||
			(next.x == 4 && next.y > 10 && next.y < 15) || (next.x == 9 && next.y > 11 && next.y < 15) ||
			(next.x == 13 && next.y > 10 && next.y < 14) || next == Vec2(3, 11) || next == Vec2(5, 13))
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
		if (next.y == 0 || next.y == 17 || next.x == 0 || next.x == 23)
		{
			return false;
		}
		else if ((next.x > 7 && next.x < 11 && next.y > 3 && next.y < 7) || next == Vec2(6, 1) ||
			(next.x > 9 && next.x < 16 && next.y > 11 && next.y < 15) || next == Vec2(13, 1) ||
			(next.x > 18 && next.x < 23 && next.y > 13 && next.y < 16) ||
			next == Vec2(1, 5) || next == Vec2(1, 16))
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
	else
	{
		return false;
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

float Board::GetWidth(int floorindex)
{
	return width[floorindex];
}

float Board::GetHeight(int floorindex)
{
	return height[floorindex];
}
