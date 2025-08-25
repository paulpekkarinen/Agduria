//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit drunkard: Random cave and corridor generation routine.

#pragma once

#include "coords.h"

class Level;

//Corridor & cavern generator.
class Drunkard
{
private:
	Level *cave;
	Coords location;
	int direction;
	int floor_tile;
	bool sober;
	int steps;

	int Get_Edge_Direction();
	bool Sober_Up();
	void Think();
	void Turn();

public:
	Drunkard(Level *c, int ft);

	void Create(int percentage, const Coords &origin);
};
