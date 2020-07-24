#include "Target.h"

void Target::SpawnTarget(int spawn_x, int spawn_y)
{
	x = spawn_x;
	y = spawn_y;
}

void Target::ProcessContact(const Dude& dude)
{
	const int duderight = dude.GetX() + dude.GetWidth();
	const int dudebottom = dude.GetY() + dude.GetHeight();
	const int targetright = x + width;
	const int targetbottom = y + height;

	if (duderight > x &&
		targetright > dude.GetX() &&
		dudebottom > y &&
		targetbottom > dude.GetY())
	{
		counter += 1;
		IsHit = true;
	}
}

void Target::Draw(Graphics& gfx)
{
	Color c;
	c.SetR(blue);
	c.SetG(blue);
	c.SetB(255);
	gfx.DrawRectDim(x, y, width, height, c);
	if (blue == 0)
	{
		changeblue = 5;
	}
	else if (blue == 255)
	{
		changeblue = -5;
	}
	blue += changeblue;
}

void Target::DrawScore(Graphics& gfx) const
{	
	gfx.DrawRectDim(10, 10, counter*10, 10, Colors::Green);	
}
