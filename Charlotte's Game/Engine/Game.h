/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "FrameTimer.h"
#include "Sound.h"
#include "board.h"
#include "Lady.h"
#include "Charlotte.h"
#include "Treat.h"
#include "Surface.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */

	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	Board brd;
	FrameTimer ft;
	Lady lady;
	Charlotte charlie;
	static constexpr int ntreats = 4;
	Treat treats[ntreats] = { {Vec2(0,0), 0}, {Vec2(10,0), 0}, {Vec2(0,10), 0}, {Vec2(10,10), 0} };
	Vec2 delta_L = { 0,0 };
	float MoveCounter = 0;
	float MovePeriod = 0.5;
	int TreatsEatenCounter = 0;
	bool GameIsOver = false;
	bool GameIsWon = false;
	Surface groundsurf = Surface("ground_textured.bmp");
	Surface alleysurf = Surface("alley_textured.bmp");
	Surface frontsurf = Surface("front_placeholder.bmp");
	Surface backsurf = Surface("back_layout.bmp");
	/********************************/
};