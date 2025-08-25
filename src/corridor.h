//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit corridor: Corridor dungeon feature.

#pragma once

#include "point.h"

class Site;

class Corridor
{
private:
	int terrain_type;
	Point src;
	Point dest;

public:
	Corridor(int tt, int x, int y, int a, int b);

	void Create(Site *lvl);
};
