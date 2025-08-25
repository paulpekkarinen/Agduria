//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit level: One level in the game world.

#pragma once

#include "site.h"

class Gameview;

//Last of the level hierarchy, this part is the complete level class in the
//game world's list of levels.
class Level : public Site
{
private:
	int level_id;

public:
	Level(int w, int h, int th, int id);

	void Display_Tile(const Coords &c, Gameview *g);
};
