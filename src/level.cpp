//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "gameview.h"
#include "level.h"
#include "tile.h"

Level::Level(int w, int h, int th, int id)
	: Site(w, h, th), level_id(id)
{

}

void Level::Display_Tile(const Coords &c, Gameview *g)
{
	Tile &t=g->Get_Tile(c);

	if (t.vision==Tile::Outside)
		return;

	//show possible game object here
	if (t.Display())
		return;

	//last display terrain if no objects were shown
	Display_Terrain(c.x, c.y);
}
