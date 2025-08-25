//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "decide.h"
#include "drunkard.h"
#include "level.h"
#include "rng.h"
#include "terrain.h"
#include "way.h"

Drunkard::Drunkard(Level *c, int ft)
	: cave(c), direction(-1), floor_tile(ft), sober(false), steps(0)
{

}

void Drunkard::Create(int percentage, const Coords &origin)
{
	location=origin;
	int cleared_tiles=0;
	const int width=cave->Get_Width();
	const int height=cave->Get_Height();

	//count amount of tiles needed to clear
	const int sz=width*height;
	const double p=(double)percentage/100.0;
	const int required_tiles=(int)(sz*p);

	//set a safety limit after which the generation stops
	const int max_steps=required_tiles*10;

	direction=-1;
	Turn(); //get first random direction

	steps=-1;
	Think(); //select initial walking mode

	//walk until required number of tiles are cleared
	int panic_steps=0;
	while (cleared_tiles<required_tiles)
	{
		if (cave->Is_Bedrock(location.x, location.y))
		{
			cave->Put_Terrain(floor_tile, location.x, location.y);
			cleared_tiles++;
		}

		Think();

		if (sober)
		{
			if (Get_Edge_Direction()!=-1) sober=false;
		}

		if (sober==false) Turn();

		location.Move_Direction(direction);

		//use hard limit check to preserve edges of level
		if (location.x<1) location.x++;
		else if (location.x>=width-1) location.x--;

		if (location.y<1) location.y++;
		else if (location.y>=height-1) location.y--;

		//count all steps and panic exit if max reached
		panic_steps++;
		if (panic_steps>max_steps) break;
	}

	cave->Pillar_Fix(floor_tile);
}

int Drunkard::Get_Edge_Direction()
{
	//turn around when reaching edge area of level
	static const int Edge_Size=5;
	int sd=-1;

	if (location.y<Edge_Size) sd=Way::South;
	else if (location.y>cave->Get_Height()-Edge_Size) sd=Way::North;

	if (location.x<Edge_Size) sd=Way::East;
	else if (location.x>cave->Get_Width()-Edge_Size) sd=Way::West;

	return sd;
}

bool Drunkard::Sober_Up()
{
	//don't sober up at edges of the level
	if (Get_Edge_Direction()!=-1) return false;

	//start by centering a rectangle on the location
	Rectangle r(location.x-4, location.y-4, 9, 9);

	//move the rectange from the origin and extend to current direction
	switch (direction)
	{
		case Way::North: r.y-=4; break;
		case Way::South: r.y+=4; break;
		case Way::West: r.x-=4; break;
		case Way::East: r.x+=4; break;
		default: break;
	}

	//max 25% of tiles can be floor tiles
	const int min_amount=r.Get_Volume()/4;
	int a=0;

	//check the area ahead if it's empty enough to create a corridor
	Coords c;
	for (c.y=r.y; c.y<=r.y+r.height; c.y++)
	{
		for (c.x=r.x; c.x<=r.x+r.width; c.x++)
		{
			const int tt=cave->Get_Terrain_Type(c.x, c.y);
			//outside level, don't sober up
			if (tt==Terrain::Void) return false;
			if (tt==floor_tile) a++;
			//too many floor tiles, don't sober up
			if (a>min_amount) return false;
		}
	}

	return true;
}

void Drunkard::Think()
{
	if (steps<=0)
	{
		if (Sober_Up() && rng->Sometimes())
		{
			sober=true;

			//corridor steps
			steps=rng->Get_Min_Max(5, 10);
		}
		else
		{
			sober=false;

			//cavern steps
			steps=rng->Get_Min_Max(20, 30);
		}
	}
	else steps--;
}

void Drunkard::Turn()
{
	int d=direction;

	//select another direction until it's different than original
	while (d==direction)
	{
		d=get_random_cardinal_direction();
	}

	//try to limit the creation to edges of the level
	int sd=Get_Edge_Direction();

	//make it slightly random to avoid too blunt limit
	if (sd!=-1 && rng->Flip_Coin()) d=sd;

	direction=d;
}
