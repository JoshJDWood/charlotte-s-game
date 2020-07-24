#pragma once

#include "dude.h"
#include "Graphics.h"

class Target
{
public:
	void SpawnTarget(int spawn_x, int spawn_y);
	void ProcessContact(const Dude& dude);
	void Draw(Graphics& gfx);
	void DrawScore(Graphics& gfx) const;
	bool IsHit = false;
private:
	int x;
	int y;
	const int width = 18;
	const int height = 18;
	int counter = 0;
	int blue = 0;
	int changeblue = 0;
};