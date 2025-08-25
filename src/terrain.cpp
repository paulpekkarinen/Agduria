//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "gui.h"
#include "terrain.h"
#include "material.h"

struct Terrain_Data
{
	const char *name;
	bool blocking_fov;
	bool blocking_movement;
	char ascii;
	int color;
	int material;
	int mask_type;
};

const Terrain_Data terrain_data[Terrain::Max_Terrains]=
{
	{"void", true, true, '?', Color::Black, Material::None, Mask::None},
	{"dirt floor", false, false, '.', Color::Brown, Material::Dirt,
		Mask::Floor},
	{"cave floor", false, false, '.', Color::Grey, Material::Dirt,
		Mask::Floor},
	{"wall", true, true, '#', Color::Silver, Material::Stone, Mask::Wall},
	{"staircase down", false, false, '>', Color::Silver, Material::Dirt,
		Mask::Object},
	{"staircase up", false, false, '<', Color::Silver, Material::Dirt,
		Mask::Object},
	{"ladder down", false, false, '>', Color::Brown, Material::Dirt,
		Mask::Object},
	{"ladder up", false, false, '<', Color::Brown, Material::Dirt,
		Mask::Object},
	{"water", false, false, '}', Color::Dark_Blue, Material::Water,
		Mask::Floor},
	{"ice", false, false, '.', Color::Cyan, Material::Ice, Mask::Floor},
	{"molten lava", false, false, '}', Color::Red, Material::Lava, Mask::Floor},
	{"corridor", false, false, '#', Color::Grey, Material::Dirt,
		Mask::Corridor},
	{"sand", false, false, '.', Color::Ochre, Material::Dirt, Mask::Floor},
	{"swamp", false, false, '.', Color::Green, Material::Dirt, Mask::Floor},
	{"mineral vein", true, true, '#', Color::Cyan, Material::Stone, Mask::Wall},
	//bedrock is used in dungeon generation as a placeholder or 'empty' tile
	//on which everything is created
	{"bedrock", false, false, '#', Color::Magenta, Material::Stone, Mask::Wall}
};

Terrain::Terrain(int t)
	: type(t)
{

}

int Terrain::Get_Mask()
{
	return terrain_data[type].mask_type;
}

const char *Terrain::Get_Name()
{
	return terrain_data[type].name;
}

int Terrain::Get_Reverse_Type()
{
	int rv;

	switch (type)
	{
		case Staircase_Down: rv=Staircase_Up; break;
		case Staircase_Up: rv=Staircase_Down; break;
		case Ladder_Down: rv=Ladder_Up; break;
		case Ladder_Up: rv=Ladder_Down; break;
		default: rv=Void; break;
	}

	return rv;
}

void Terrain::Display()
{
	gui->Put_Char(terrain_data[type].ascii, terrain_data[type].color);
}
