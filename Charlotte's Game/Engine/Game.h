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
#include "Sound.h"
#include <random>
#include <chrono>

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
	void formatscore();
	void DrawScore(int x, int y);
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
	static constexpr int ntreats = 15;
	Treat treats[ntreats];
	static constexpr int nPoos = 4;
	Poo poos[nPoos];
	static constexpr int nFamily = 4;
	Family familymem[nFamily];
	static constexpr int nMW = nFamily + 2;
	float MWx[nMW];
	float MWy[nMW];
	float MWf[nMW];
	bool GameIsOver = false;
	bool GameIsWon = false;
	bool GameIsStarted = false;

	//counters
	float LMoveCounter = 0;
	float LMovePeriodbase = 0.5;
	float LMovePeriod = LMovePeriodbase;
	float smellyboost = 0.7;
	float SmellyCounter = 0;
	float SmellyPeriod = 8;

	float CMoveCounter = 0;
	float CMovePeriod = 0.65;
	float CMovePeriodMax = 0.65;
	float CMovePeriodMin = 0.4;
	float CMovePeriodCR = 0.02;
	float CStunnedCounter = 0;

	float FMoveCounter[nFamily] = { 0,0,0,0 };
	float FMovePeriod[nFamily] = { 0.65,0.7,0.75,0.8 };	
	float RestingCounter[nFamily] = { 0,0,0,0 };
	float FStunnedCounter[nFamily] = { 0,0,0,0 };
	float RestingPeriod = 8;
	float StunnedPeriod = 5;
	int TreatsEatenCounter = 0;

	//scoring
	int scoreRF[4] = { 0,0,0,0 };
	int score = 0;
	int TS = 0;
	static constexpr int sockS = 200;
	static constexpr int pooS = 50;
	static constexpr int FstunS = 300;
	static constexpr int CstunS = 500;
	std::chrono::steady_clock::time_point start;
	std::chrono::steady_clock::time_point end;
	static constexpr float maxtime = 135;
	static constexpr float buffertime = 45;
	static constexpr int PpS = 20;
	int timepoints = 0;

	//surfaces
	Surface groundsurf = Surface("ground_final.bmp");
	Surface alleysurf = Surface("alley_Ftextured.bmp");
	Surface frontsurf = Surface("front_Ftextured.bmp");
	Surface backsurf = Surface("back_final.bmp");
	Surface titlesurf = Surface("title_screen.bmp");
	Surface winsurf = Surface("win_screen.bmp");
	Surface caughtsurf = Surface("lose_screen.bmp");
	Surface S0 = Surface("score0.bmp");
	Surface S1 = Surface("score1.bmp");
	Surface S2 = Surface("score2.bmp");
	Surface S3 = Surface("score3.bmp");
	Surface S4 = Surface("score4.bmp");
	Surface S5 = Surface("score5.bmp");
	Surface S6 = Surface("score6.bmp");
	Surface S7 = Surface("score7.bmp");
	Surface S8 = Surface("score8.bmp");
	Surface S9 = Surface("score9.bmp");

	//sound effects	
	static constexpr int FBn = 4;
	int b = 0;
	Sound fart0sound;
	Sound fart1sound;
	Sound fart2sound;
	Sound fart3sound;
	Sound bark0sound;
	Sound bark1sound;
	Sound bark2sound;
	Sound bark3sound;
	/********************************/
};