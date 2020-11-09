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
#include "Poo.h"
#include "Family.h"
#include "Surface.h"
#include <random>

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
	Vec2 delta_L = { 0,0 };
	Charlotte charlie;
	std::mt19937 rng;
	static constexpr int ntreats = 10;
	Treat treats[ntreats];
	static constexpr int nPoos = 3;
	Poo poos[nPoos];
	static constexpr int nFamily = 4;
	Family familymem[nFamily];
	static constexpr int nMW = nFamily + 2;
	float MWx[nMW];
	float MWy[nMW];
	float MWf[nMW];

	//counters
	float LMoveCounter = 0;
	float LMovePeriod = 0.5;
	float CMoveCounter = 0;
	float CMovePeriod = 0.65;
	float CMovePeriodMax = 0.65;
	float CMovePeriodMin = 0.4;
	float CMovePeriodCR = 0.02;
	float FMoveCounter[nFamily] = { 0,0,0,0 };
	float FMovePeriod[nFamily] = { 0.7,0.8,0.85,0.9 };
	float SmellyCounter = 0;
	float SmellyPeriod = 8;
	float RestingCounter[nFamily] = { 0, 0, 0, 0 };
	float RestingPeriod = 2;
	int TreatsEatenCounter = 0;
	bool GameIsOver = false;
	bool GameIsWon = false;

	//surfaces
	Surface groundsurf = Surface("ground_Ftextured.bmp");
	Surface alleysurf = Surface("alley_Ftextured.bmp");
	Surface frontsurf = Surface("front_Ftextured.bmp");
	Surface backsurf = Surface("back_Ftextured.bmp");
	/********************************/
};