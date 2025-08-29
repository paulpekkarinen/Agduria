//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit coords: x, y, z coordinates.

#pragma once

struct Point;
class Way;

struct Coords
{
	int x;
	int y;
	int z;

	Coords() : x(0), y(0), z(0) { }
	Coords(int sx, int sy);
	Coords(int sx, int sy, int sz);
	Coords(const Point &p);

	void Move_Direction(int d);
	void Move_Opposite_Direction(int d);
	void Set(int sx, int sy, int sz);
	void Set(int sx, int sy);

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
