#include "Charlotte.h"

void Charlotte::Draw(Board& brd)
{
	brd.DrawCharlotte(loc, floor.x, stunned);
}

void Charlotte::Update(Vec2& target, Vec2& Lloc, float Lfloor, bool smelly, 
	float* MWx, float* MWy, float* MWf, int nMW, Board& brd)
{
	oldloc = loc;	
	Vec2 diff;
	if (smelly && floor.x == Lfloor && (abs(Lloc.x - loc.x) + abs(Lloc.y - loc.y)) < 5)
	{
		diff = loc - Lloc;		
	}
	else
	{
		diff = target - loc;
	}
	
	if (diff == Vec2(0, 0))
	{
		//fake move so it can change floor
		moved = true;
	}
	else if (abs(diff.x) > abs(diff.y))
	{
		delta_C = { diff.x / abs(diff.x), 0 };
		Vec2 next = loc + delta_C;
		if (brd.IsInPlay(next, floor.x) && brd.IsInPlayMW(next, floor.x, MWx, MWy, MWf, nMW))
		{
			loc = next;
			moved = true;
		}
		else if (!moved)
		{
			if (diff.y != 0)
			{
				delta_C = { 0,diff.y / abs(diff.y) };
				next = loc + delta_C;
				if (brd.IsInPlay(next, floor.x) && brd.IsInPlayMW(next, floor.x, MWx, MWy, MWf, nMW))
				{
					loc = next;
					moved = true;
				}
			}
			if (!moved)
			{
				MovePrefAlt *= -1;
				delta_C = { 0, 1 * MovePrefAlt };
				next = loc + delta_C;
				Vec2 altnext = loc - delta_C;
				if (brd.IsInPlay(next, floor.x) && brd.IsInPlayMW(next, floor.x, MWx, MWy, MWf, nMW))
				{
					loc = next;
					moved = true;
				}
				else if (brd.IsInPlay(altnext, floor.x) && brd.IsInPlayMW(next, floor.x, MWx, MWy, MWf, nMW))
				{
					loc = altnext;
					moved = true;
				}
				if (!moved)
				{
					delta_C = { -diff.x / abs(diff.x), 0 };
					next = loc + delta_C;
					if (brd.IsInPlay(next, floor.x) && brd.IsInPlayMW(next, floor.x, MWx, MWy, MWf, nMW))
					{
						loc = next;
						moved = true;
					}
				}
			}
		}		
	}
	else
	{
		delta_C = { 0, diff.y / abs(diff.y) };
		Vec2 next = loc + delta_C;
		if (brd.IsInPlay(next, floor.x) && brd.IsInPlayMW(next, floor.x, MWx, MWy, MWf, nMW))
		{
			loc = next;
			moved = true;
		}
		else if (!moved)
		{
			if (diff.x != 0)
			{
				delta_C = { diff.x / abs(diff.x),0 };
				next = loc + delta_C;
				if (brd.IsInPlay(next, floor.x) && brd.IsInPlayMW(next, floor.x, MWx, MWy, MWf, nMW))
				{
					loc = next;
					moved = true;
				}
			}
			if (!moved)
			{
				MovePrefAlt *= -1;
				delta_C = { 1 * MovePrefAlt, 0 };
				next = loc + delta_C;
				Vec2 altnext = loc - delta_C;
				if (brd.IsInPlay(next, floor.x) && brd.IsInPlayMW(next, floor.x, MWx, MWy, MWf, nMW))
				{
					loc = next;
					moved = true;
				}
				else if (brd.IsInPlay(altnext, floor.x) && brd.IsInPlayMW(next, floor.x, MWx, MWy, MWf, nMW))
				{
					loc = altnext;
					moved = true;
				}
				if (!moved)
				{
					delta_C = { 0, -diff.y / abs(diff.y) };
					next = loc + delta_C;
					if (brd.IsInPlay(next, floor.x) && brd.IsInPlayMW(next, floor.x, MWx, MWy, MWf, nMW))
					{
						loc = next;
						moved = true;
					}
				}
			}
		}
	}
	brd.UpdateFloor(floor, loc, oldloc);
	delta_C = { 0,0 };
	moved = false;	
}

Vec2 Charlotte::GetLoction()
{
	return loc;
}

Vec2 Charlotte::GetFloor()
{
	return floor;
}

bool Charlotte::IsStunned()
{
	return stunned;
}

void Charlotte::Stun()
{
	stunned = true;
}

void Charlotte::UnStun()
{
	stunned = false;
}


