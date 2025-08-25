//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit tilemap: 2D map of 'Tile' objects.

#pragma once

struct Coords;
struct Tile;

//Tile map is the visual map of things displayed on screen. It has
//pointers to game objects which update their own map location.
class Tile_Map
{
private:
	Tile *tiles;
	int width;
	int height;

	bool Is_Outside(const Coords &c);

public:
	Tile_Map(int w, int h);
	~Tile_Map();

	Tile &Get_Tile(const Coords &c);
};
