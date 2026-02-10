//Agduria - Copyright (C) Paul K. Pekkarinen

//Unit coords: x, y, z coordinates.

#pragma once

#include "point.h"

struct Coords : public Point
{
	int z;

	Coords() : Point(0, 0), z(0) { }
	Coords(int sx, int sy);
	Coords(int sx, int sy, int sz);
	Coords(const Point &p);

	void Move_Direction(int d);
	void Move_Opposite_Direction(int d);
	void Set_Location(int sx, int sy, int sz);

	Coords& operator=(const Coords& r)
	{
		if(this == &r) return *this;
		x=r.x;
		y=r.y;
		z=r.z;
		return *this;
	}

	bool operator==(const Coords& r)
	{
		if(this == &r) return true;
		if (x==r.x && x==r.y && z==r.z) return true;
		return false;
	}
};
