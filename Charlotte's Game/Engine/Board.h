#pragma once

#include "Graphics.h"
#include "Surface.h"
#include "SpriteCodex.h"

class Board
{
public:
	Board(Graphics& gfx);
	void DrawWalls(float floorindex);
	void DrawCell( Vec2& loc, float floorindex, Color c);
	void DrawTreat(Vec2& loc, float floorindex);
	void DrawPoo(Vec2& loc, float floorindex);
	void DrawLady(Vec2& loc, float floorindex, bool smelly);
	void DrawCharlotte(Vec2& loc, float floorindex, bool stunned);
	void DrawFamily(Vec2& loc, float floorindex, int famindex, bool stunned);
	bool IsInPlay(Vec2& next, float floorindex);
	bool IsInPlayMW(Vec2& next, float floorindex, float* MWx, float* MWy, float* MWf, int nMW);
	bool IsInPlayCon(Vec2& next, float floorindex);
	void UpdateFloor(Vec2& floor, Vec2& loc, Vec2& oldloc);
	Vec2 FindTarget(Vec2& loc, Vec2& floor, Vec2& targetloc, Vec2& targetfloor);
	int FindBestExit(Vec2* exits, int nexits, Vec2& targetloc);
	float GetWidth(int floorindex);
	float GetHeight(int floorindex);
private:
	
	static constexpr int nFloors = 4;
	static constexpr float width[nFloors] = { 24,24,18,24 };
	static constexpr float height[nFloors] = { 18,5,18,18 };
	//floor0 - ground floor
	static const int nWalls0 = 171;
	Vec2 walls0[nWalls0] = {{13,-1}, //floorchange in row
		{5,0},{6,0},{7,0},{12,0},{14,0},{16,0},{19,0},{20,0},{21,0},
		{4,1},{8,1},{9,1},{10,1},{11,1},{12,1},{14,1},{15,1},{17,1},{18,1},{22,1},
		{3,2},{6,2},{8,2},{14,2},{15,2},{18,2},{20,2},{22,2},
		{2,3},{5,3},{6,3},{10,3},{12,3},{13,3},{14,3},{15,3},{16,3},{18,3},{20,3},{22,3},
		{2,4},{4,4},{7,4},{9,4},{10,4},{22,4},
		{2,5},{6,5},{7,5},{12,5},{13,5},{14,5},{15,5},{16,5},{18,5},{19,5},{22,5},
		{1,6},{3,6},{4,6},{5,6},{7,6},{8,6},{9,6},{10,6},{11,6},{12,6},{13,6},{14,6},{15,6},{18,6},{19,6},{22,6},
		{0,7},{2,7},{3,7},{4,7},{5,7},{6,7},{15,7},{16,7},{17,7},{18,7},{19,7},{21,7},
		{0,8},{4,8},{8,8},{9,8},{10,8},{11,8},{12,8},{13,8},{14,8},{15,8},{17,8},{22,8},
		{22,9}, {-1,9}, //floorchange in row
		{0,10}, {1,10},{4,10},{5,10},{15,10},{16,10},{17,10},{18,10},{19,10},{20,10},{21,10},{22,10},
		{2,11},{3,11},{4,11},{5,11},{8,11},{8,11},{9,11},{10,11},{11,11},{12,11},
		{14,11},{15,11},{16,11},{17,11},{18,11},{19,11},{20,11},{21,11},{22,11},
		{1,12},{6,12},{11,12},{23,12},
		{0,13},{3,13},{4,13},{9,13},{11,13},{12,13},{17,13},{19,13},{24,13}, //floorchange in row
		{0,14},{2,14},{3,14},{9,14},{11,14},{12,14},{14,14},{16,14},{18,14},{20,14},{23,14},
		{0,15},{5,15},{8,15},{9,15},{11,15},{12,15},{17,15},{18,15}, {19,15},{22,15},
		{1,16},{3,16},{11,16},{14,16},{15,16},{21,16} };	
	static constexpr float width0 = 24;
	static constexpr float height0 = 18;
	//floor1 - alleyway
	static const int nWalls1 = 42;
	Vec2 walls1[nWalls1] = {
		{0,1},{1,1},{2,1},{3,1},{4,1},{5,1},{16,1},{17,1},{18,1},{19,1},{21,1},{22,1},{23,1},
		{-1,2},{9,2},{10,2},{11,2},{24,2},
		{0,3},{4,3},{5,3},{6,3},{15,3},{16,3},{17,3},{23,3},
		{1,4},{2,4},{3,4},{7,4},{8,4},{9,4},{10,4},{11,4},{12,4},{14,4},{18,4},{19,4},{20,4},{21,4},{22,4},
		{13,5} };
	static constexpr float width1 = 24;
	static constexpr float height1 = 5;
	//floor2 - front garden
	static const int nWalls2 = 106;
	Vec2 walls2[nWalls2] = {
		{7,1},{8,1},{17,1},
		{1,2},{3,2},{5,2},{10,2},{11,2},{12,2},{13,2},{14,2},{18,2},
		{10,3},{14,3},{17,3},
		{10,4},{11,4},{12,4},{13,4},{14,4},{17,4},
		{2,5},{3,5},{4,5},{5,5},{6,5},{7,5},{17,5},
		{2,6},{7,6},{11,6},{12,6},{13,6},{14,6},{15,6},{17,6},
		{2,7},{3,7},{4,7},{5,7},{6,7},{7,7},{11,7},{15,7},{17,7},
		{0,8},{11,8},{12,8},{13,8},{14,8},{15,8},{17,8},
		{0,9},{17,9},
		{0,10},{3,10},{4,10},{5,10},{12,10},{13,10},{14,10},{17,10},
		{0,11},{2,11},{5,11},{8,11},{9,11},{10,11},{12,11},{14,11},{18,11},
		{0,12},{3,12},{5,12},{8,12},{10,12},{12,12},{15,12},{17,12},
		{0,13},{3,13},{6,13},{8,13},{10,13},{12,13},{14,13},{17,13},
		{1,14},{3,14},{5,14},{8,14},{10,14},{12,14},{13,14},{14,14},{17,14},
		{1,15},{3,15},{4,15},{5,15},{8,15},{9,15},{10,15},{16,15},
		{1,16},{15,16} };
	static constexpr float width2 = 18;
	static constexpr float height2 = 18;
	//floor3 - back garden
	static const int nWalls3 = 115;
	Vec2 walls3[nWalls3] = { 
		{0,1},{5,1},{7,1},{8,1},{12,1},{14,1},{19,1},{20,1},
		{-1,2},{5,2},{6,2},{13,2},{16,2},{17,2},{19,2},{20,2},{22,2},
		{0,3},{1,3},{8,3},{9,3},{10,3},{16,3},{17,3},{22,3},
		{1,4},{2,4},{7,4},{11,4},{19,4},{20,4},
		{2,5},{7,5},{11,5},{15,5},{16,5},{17,5},{19,5},{20,5},{22,5},
		{1,6},{2,6},{7,6},{11,6},{15,6},{16,6},{17,6},{19,6},{22,6},
		{1,7},{8,7},{9,7},{10,7},
		{1,8},{16,8},{17,8},{19,8},{21,8},
		{0,9},{16,9},{17,9},{19,9},
		{0,10},{2,10},{17,10},{19,10},
		{0,11},{2,11},{4,11},{6,11},{7,11},{10,11},{11,11},{12,11},{13,11},{14,11},{15,11},{19,11},
		{0,12},{9,12},{15,12},{18,12},{19,12},{22,12},
		{-1,13},{4,13},{6,13},{7,13},{9,13},{16,13},{22,13},
		{0,14},{9,14},{16,14},{18,14},{19,14},{20,14},{21,14},
		{1,15},{5,15},{6,15},{7,15},{8,15},{9,15},{10,15},
		{11,15},{12,15},{13,15},{14,15},{15,15},{16,15},{18,15},
		{2,16},{3,16},{18,16} };
	static constexpr float width3 = 24;
	static constexpr float height3 = 18;
	//update floor values
	//floor 0
	static constexpr int CPn = 5;
	Vec2 F0CPH[CPn] = { {12,4}, {19,4}, {20,8}, {16,9}, {13,11} };
	Vec2 F0CPL[CPn] = { {11,4}, {18,4}, {20,7}, {17,9}, {13,10} };
	Vec2 F0CP6H = { 7,12 };
	Vec2 F0CP6L = { 7,11 };
	Vec2 F0CP7H = { 7,7 };
	Vec2 F0CP7L = { 7,8 };
	//floor 2
	Vec2 F2CP1Ha = { 15,15 };
	Vec2 F2CP1La = { 15,14 };
	Vec2 F2CP1Hb = { 11,11 };
	Vec2 F2CP1Lb = { 11,10 };
	Vec2 F2CP2H = { 7,14 };
	Vec2 F2CP2L = { 7,13 };
	Vec2 F2CP3H = { 1,11 };
	Vec2 F2CP3L = { 1,10 };
	Vec2 F2CP122H = { 10,16 };
	Vec2 F2CP122L = { 11,16 };
	Vec2 F2CP223H = { 2,16 };
	Vec2 F2CP223L = { 3,16 };
	static constexpr int F2R0En = 4;
	static constexpr int F2R1En = 3;
	static constexpr int F2R2En = 3;
	static constexpr int F2R3En = 2;
	Vec2 F2R0E[F2R0En] = { F2CP1Ha, F2CP1Hb, F2CP2H, F2CP3H };
	Vec2 F2R1E[F2R1En] = { F2CP1La, F2CP1Lb, F2CP122H };
	Vec2 F2R2E[F2R2En] = { F2CP2L, F2CP122L, F2CP223H };
	Vec2 F2R3E[F2R3En] = { F2CP3L, F2CP223L };
	//floor 3
	Vec2 F3CPHa = { 4,16 };
	Vec2 F3CPLa = { 4,15 };
	Vec2 F3CPHb = { 16,11 };
	Vec2 F3CPLb = { 16,10 };
	Vec2 F3CPHc = { 18,10 };
	Vec2 F3CPLc = { 18,9 };
	Vec2 F3CPHd = { 17,13 };
	Vec2 F3CPLd = { 18,13 };
	static constexpr int F3R0En = 4;
	static constexpr int F3R1En = 4;
	Vec2 F3R0E[F3R0En] = { F3CPHa, F3CPHb, F3CPHc, F3CPHd };
	Vec2 F3R1E[F3R1En] = { F3CPLa, F3CPLb, F3CPLc, F3CPLd };
	//between floors
	Vec2 F0T2 = { 0, 9 };
	Vec2 F2T0 = { 17, 11 };
	Vec2 F2T1 = { 17, 2 };
	Vec2 F1T2 = { 0, 2 };
	Vec2 F0T1 = { 13,0 };
	Vec2 F1T0 = { 13, 4 };
	Vec2 F1T3 = { 23, 2 };
	Vec2 F3T1 = { 0, 2 };
	Vec2 F0T3 = { 23, 13 };
	Vec2 F3T0 = { 0, 13 };

	static constexpr float dim = 32;
	static constexpr Color bordercolor = Colors::Blue;
	float shiftx(float width)
	{
		return 400 - width * dim / 2;
	}
	float shifty(float height)
	{
		return 300 - height * dim / 2;
	}
	float sx = 0;
	float sy = 0;
	int x = 0;
	int y = 0;
	Graphics& gfx;
	//textures for characters
	Surface ladysurf = Surface("lady_profile.bmp");
	Surface ladysmellysurf = Surface("lady_smelly.bmp");
	Surface poosurf = Surface("poo.bmp");
	Surface sockssurf = Surface("socks.bmp");
	Surface charlottesurf = Surface("Charlotte_Profile.bmp");
	Surface charlottesmellysurf = Surface("Charlotte_smelly.bmp");
	Surface mumsurf = Surface("mum_profile.bmp");
	Surface mumsmellysurf = Surface("mum_smelly.bmp");
	Surface dadsurf = Surface("dad_profile.bmp");
	Surface dadsmellysurf = Surface("dad_smelly.bmp");
	Surface joshsurf = Surface("josh_profile.bmp");
	Surface joshsmellysurf = Surface("josh_smelly.bmp");
	Surface izzysurf = Surface("izzy_profile.bmp");
	Surface izzysmellysurf = Surface("izzy_smelly.bmp");
};