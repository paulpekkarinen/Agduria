//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit area: Rectangular area of dungeon.

#pragma once

#include "rect.h"

class Chart;

class Area : public Rectangle
{
public:
	enum Area_Types {Opening, Room};

private:
	int type; //type of the area (opening, room, etc.)
	Chart *chart; //points to destination map

	bool Is_Forbidden(int dx, int dy);

public:
	Area(int t, Chart *dest_chart);

	bool Check();
};
