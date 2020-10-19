/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	brd( gfx )
{
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (!GameIsOver && !GameIsWon)
	{
		float dt = ft.Mark();

		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			delta_L = { 0,-1 };
		}
		if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			delta_L = { 0,1 };
		}
		if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			delta_L = { -1,0 };
		}
		if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			delta_L = { 1,0 };
		}

		MoveCounter += dt;
		if (MoveCounter > MovePeriod)
		{
			Vec2 next = lady.GetLocation() + delta_L;
			charlie.Update(charlie.FindTarget(lady.GetFloor(), lady.GetLocation()), brd);
			if (brd.IsInPlay(next, lady.GetFloor().x))
			{
				lady.Update(delta_L);
				for (int i = 0; i < ntreats; i++)
				{
					if (lady.GetLocation() == treats[i].GetLocation() 
						&& lady.GetFloor().x == treats[i].GetFloor())
					{
						if (treats[i].eaten == false)
						{
							treats[i].eaten = true;
							TreatsEatenCounter += 1;
							if (TreatsEatenCounter == ntreats)
							{
								GameIsWon = true;
							}
						}						
						break;
					}
				}
				MoveCounter = 0;
			}
			else
			{
				delta_L = { 0,0 };
				MoveCounter = 0;
			}
			if (lady.GetLocation() == charlie.GetLoction() && lady.GetFloor() == charlie.GetFloor())
			{
				GameIsOver = true;
			}
		}
	}
}

void Game::ComposeFrame()
{
	if (lady.GetFloor().x == 0)
	{
		gfx.DrawSpriteNonChroma(16, 12, groundsurf);
	}
	else if (lady.GetFloor().x == 1)
	{
		gfx.DrawSpriteNonChroma(16, 220, alleysurf);
	}
	else if (lady.GetFloor().x == 2)
	{
		gfx.DrawSpriteNonChroma(112, 12, frontsurf);
	}
	else if (lady.GetFloor().x == 3)
	{
		gfx.DrawSpriteNonChroma(16, 12, backsurf);
	}

	lady.Draw(brd);

	if (charlie.GetFloor().x == lady.GetFloor().x)
	{
		charlie.Draw(brd);
	}

	for (int i = 0; i < ntreats; i++)
	{
		if (!treats[i].eaten)
		{
			if (treats[i].GetFloor() == lady.GetFloor().x)
			{
				treats[i].Draw(brd);
			}
		}
	}
	//test to see wall locations
	brd.DrawWalls(lady.GetFloor().x);
	if (GameIsOver)
	{
		gfx.DrawRectDim(50, 50, 50, 50, Colors::Red);
	}
	if (GameIsWon)
	{
		gfx.DrawRectDim(50, 50, 50, 50, Colors::Green);
	}
}
