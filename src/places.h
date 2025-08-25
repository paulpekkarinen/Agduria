//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit places: List of some kind of terrain tiles on the map.

#pragma once

#include <vector>
#include "coords.h"

class Chart;

class Places
{
private:
	std::vector<Coords> spots;

	int Get_Size();

public:
	Coords Get_Random();

	int Find_Masks(Chart *chart, int masktype);
	int Find_Terrains(Chart *chart, int terrain);
	bool Set_Random(Coords &dest);
};
