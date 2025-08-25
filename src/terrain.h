//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit terrain: Terrain type.

#pragma once

//mask is a generic type of terrain to help in dungeon generation etc.
namespace Mask
{
	enum Terrain_Mask_Type {None, Corridor, Floor, Wall, Object};
}

struct Terrain
{
	enum Terrain_Type {Void, Dirt_Floor, Cave_Floor, Wall, Staircase_Down,
		Staircase_Up, Ladder_Down, Ladder_Up, Water, Ice, Molten_Lava,
		Corridor, Sand, Swamp, Mineral_Vein, Bedrock, Max_Terrains};

	int type;

	Terrain() : type(Void) { }
	Terrain(int t);

	Terrain& operator=(const Terrain& r)
	{
		if(this == &r) return *this;
		type=r.type;
		return *this;
	}

	Terrain& operator=(const int r)
	{
		type=r;
		return *this;
	}

	bool operator==(const Terrain& r)
	{
		if(this == &r) return true;
		if (type==r.type) return true;
		return false;
	}

	int Get_Mask();
	const char *Get_Name();
	int Get_Reverse_Type();

	void Display();
};
