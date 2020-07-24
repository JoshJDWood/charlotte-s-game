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

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
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
    if (wnd.kbd.KeyIsPressed(VK_UP))
    {
        y_mob = y_mob - 1;
    }
    
    if (wnd.kbd.KeyIsPressed(VK_DOWN))
    {
        y_mob = y_mob + 1;
    }
    
    if (wnd.kbd.KeyIsPressed(VK_LEFT))
    {
        x_mob = x_mob - 1;
    }
    
    if (wnd.kbd.KeyIsPressed(VK_RIGHT))
    {
        x_mob = x_mob + 1;
    }

    x_mob = ClampScreenX(x_mob);
    y_mob = ClampScreenY(y_mob);

    colliding = OverLapTest(x_mob, y_mob, x_fix, y_fix);    
}

void Game::ComposeFrame()
{
    DrawBox( x_fix, y_fix, 255, 255, 255 );

    if (colliding)
    {
        DrawBox( x_mob, y_mob, 255, 0, 0);
    }
    else
    {
        DrawBox( x_mob, y_mob, 0, 255, 0);
    }
}

void Game::DrawBox( int x, int y, int r, int g, int b )
{
    gfx.PutPixel(x - 5, y - 5, r, g, b);
    gfx.PutPixel(x - 4, y - 5, r, g, b);
    gfx.PutPixel(x - 5, y - 4, r, g, b);
    gfx.PutPixel(x + 5, y - 5, r, g, b);
    gfx.PutPixel(x + 4, y - 5, r, g, b);
    gfx.PutPixel(x + 5, y - 4, r, g, b);
    gfx.PutPixel(x - 5, y + 5, r, g, b);
    gfx.PutPixel(x - 4, y + 5, r, g, b);
    gfx.PutPixel(x - 5, y + 4, r, g, b);
    gfx.PutPixel(x + 5, y + 5, r, g, b);
    gfx.PutPixel(x + 4, y + 5, r, g, b);
    gfx.PutPixel(x + 5, y + 4, r, g, b);
}

bool Game::OverLapTest(int box0x, int box0y, int box1x, int box1y)
{
    const int left_box0 = box0x - 5;
    const int right_box0 = box0x + 5;
    const int top_box0 = box0y - 5;
    const int bottom_box0 = box0y + 5;
    const int left_box1 = box1x - 5;
    const int right_box1 = box1x + 5;
    const int top_box1 = box1y - 5;
    const int bottom_box1 = box1y + 5;

    return
        left_box0 <= right_box1 &&
        right_box0 >= left_box1 &&
        top_box0 <= bottom_box1 &&
        bottom_box0 >= top_box1;        
}

int Game::ClampScreenX(int x)
{
    const int left = x - 5;
    const int right = x + 5;
    if (left < 0)
    {
        return 5;
    }
    else if (right > gfx.ScreenWidth)
    {
        return gfx.ScreenWidth - 6;
    }
    else
    {
        return x;
    }
}

int Game::ClampScreenY(int y)
{
    const int top = y - 5;
    const int bottom = y + 5;
    if (top < 0)
    {
        return 5;
    }
    else if (bottom > gfx.ScreenHeight)
    {
        return gfx.ScreenHeight - 6;
    }
    else
    {
        return y;
    }
}
