#pragma once

#include "Graphics.h"
#include "Keyboard.h"

class Dude
{
public:
	void ClampToScreen();
	void Draw(Graphics& gfx)const;
	void Update(const Keyboard& kbd);
	void GameOver();
	int GetX() const;
	int GetY() const;
	int GetWidth() const;
	int GetHeight() const;
private:
	int x = 400;
	int y = 300;
	int width = 20;
	int height = 20;
	int speed = 2;
};
