//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "coords.h"
#include "tile.h"
#include "tilemap.h"

//in case the map index is invalid, return this tile with empty values
Tile dummy(Tile::Outside);

Tile_Map::Tile_Map(int w, int h)
	: width(w), height(h)
{
	unsigned long sz=(unsigned long)(w*h);
	tiles=new Tile[sz];
}

Tile_Map::~Tile_Map()
{
	delete[] tiles;
}

bool Tile_Map::Is_Outside(const Coords &c)
{
	if (c.x>=width || c.y>=height || c.x<0 || c.y<0) return true;
	return false;
}

Tile &Tile_Map::Get_Tile(const Coords &c)
{
	if (Is_Outside(c)) return dummy;
	return tiles[c.y*width+c.x];
}

