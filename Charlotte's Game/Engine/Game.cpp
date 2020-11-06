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
	brd( gfx ),
	rng( std::random_device()())
{
	std::uniform_int_distribution<int> FDist(0, 3);
	for (int i = 0; i < nPoos; ++i)
	{
		poos[i] = Poo(rng, brd, FDist(rng));
	}
	for (int i = 0; i < ntreats; ++i)
	{
		treats[i] = Treat(rng, brd, FDist(rng));
	}
	for (int i = 0; i < nFamily; ++i)
	{
		familymem[i] = Family(i, rng, familymem[(i + 1) % nFamily].GetDI(),
			familymem[(i + 2) % nFamily].GetDI(), familymem[(i + 3) % nFamily].GetDI());
	}
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

		if (lady.IsSmelly())
		{
			SmellyCounter += dt;
		}

		for (int i = 0; i < nFamily; ++i)
		{
			if (familymem[i].IsResting())
			{
				RestingCounter[i] += dt;
			}
		}
		for (int i = 0; i < nFamily; ++i)
		{		
			FMoveCounter[i] += dt;
		}
		for (int i = 0; i < nFamily; ++i)
		{
			if (FMoveCounter[i] > FMovePeriod[i])
			{				
				if (familymem[i].IsResting())
				{
					if (RestingCounter[i] > RestingPeriod)
					{
						familymem[i].FindNewDestination(rng, familymem[(i+1)% nFamily].GetDI(), 
							familymem[(i + 2) % nFamily].GetDI(), familymem[(i + 3) % nFamily].GetDI());
						familymem[i].SetRestingEnd();
						RestingCounter[i] = 0;
					}
				}
				else
				{
					for (int a = 0; a < nFamily; ++a)
					{						
						MWx[a] = familymem[(a + (4 - i)) % nFamily].GetLoction().x;
						MWy[a] = familymem[(a + (4 - i)) % nFamily].GetLoction().y;
						MWf[a] = familymem[(a + (4 - i)) % nFamily].GetFloor().x;
					}
					MWx[4] = lady.GetLocation().x;
					MWy[4] = lady.GetLocation().y;
					MWf[4] = lady.GetFloor().x;
					MWx[5] = charlie.GetLoction().x;
					MWy[5] = charlie.GetLoction().y;
					MWf[5] = charlie.GetFloor().x;
					familymem[i].Update(&MWx[1], &MWy[1], &MWf[1], nMW - 1, brd);
				}
				
				FMoveCounter[i] = 0;
			}
		}
		 
		CMoveCounter += dt;
		if (CMoveCounter > CMovePeriod)
		{
			for (int i = 0; i < nFamily; ++i)
			{
				MWx[i] = familymem[i].GetLoction().x;
				MWy[i] = familymem[i].GetLoction().y;
				MWf[i] = familymem[i].GetFloor().x;
			}
			charlie.Update(brd.FindTarget(charlie.GetFloor(), lady.GetLocation(), lady.GetFloor()),
				lady.GetFloor().x, lady.IsSmelly(), MWx, MWy, MWf, nFamily, brd);

			CMoveCounter = 0;
		}
		
		LMoveCounter += dt;
		if (LMoveCounter > LMovePeriod)
		{
			for (int i = 0; i < nFamily; ++i)
			{
				MWx[i] = familymem[i].GetLoction().x;
				MWy[i] = familymem[i].GetLoction().y;
				MWf[i] = familymem[i].GetFloor().x;
			}

			lady.Update(delta_L, MWx, MWy, MWf, nFamily, brd);
			if (lady.DidMove())
			{				
				for (int i = 0; i < ntreats; i++)
				{
					if (lady.GetLocation() == treats[i].GetLocation() 
						&& lady.GetFloor().x == treats[i].GetFloor())
					{
						if (treats[i].GetEaten() == false)
						{
							treats[i].SetToEaten();
							TreatsEatenCounter += 1;
							if (TreatsEatenCounter == ntreats)
							{
								GameIsWon = true;
							}
						}						
						break;
					}
				}
				for (int i = 0; i < nPoos; ++i)
				{
					if (lady.GetLocation() == poos[i].GetLocation()
						&& lady.GetFloor().x == poos[i].GetFloor()
						&& !poos[i].IsRolledIn())
					{				
						poos[i].SetToRolledIn();
						lady.SetToSmelly();
						break;
					}
				}
			}			
			if (SmellyCounter > SmellyPeriod)
			{
				//lady.SetSmellyOver();
				SmellyCounter = 0;
			}
			LMoveCounter = 0;
		}
		if (lady.GetLocation() == charlie.GetLoction() && lady.GetFloor() == charlie.GetFloor())
		{
			if (!lady.IsSmelly())
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

	for (int i = 0; i < ntreats; ++i)
	{
		if (!treats[i].GetEaten() && treats[i].GetFloor() == lady.GetFloor().x)
		{
			treats[i].Draw(brd);
		}
	}

	for (int i = 0; i < nPoos; ++i)
	{
		if (!poos[i].IsRolledIn() && lady.GetFloor().x == poos[i].GetFloor())
		{
			poos[i].Draw(brd);
		}
	}

	for (int i = 0; i < nFamily; ++i)
	{
		if (familymem[i].GetFloor().x == lady.GetFloor().x)
		{
			familymem[i].Draw(brd);
		}
	}

	if (charlie.GetFloor().x == lady.GetFloor().x)
	{
		charlie.Draw(brd);
	}

	lady.Draw(brd);

	
	//test to see wall locations
	//brd.DrawWalls(lady.GetFloor().x);

	if (GameIsOver)
	{
		gfx.DrawRectDim(50, 50, 50, 50, Colors::Red);
	}
	if (GameIsWon)
	{
		gfx.DrawRectDim(50, 50, 50, 50, Colors::Green);
	}
}
