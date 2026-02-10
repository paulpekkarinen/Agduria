//Agduria - Copyright (C) Paul K. Pekkarinen

#include "coords.h"
#include "way.h"

Coords::Coords(int sx, int sy)
	: Point(sx, sy), z(0)
{

}

Coords::Coords(int sx, int sy, int sz)
	: Point(sx, sy), z(sz)
{

}

Coords::Coords(const Point &p)
	: Point(p), z(0)
{

}

void Coords::Move_Direction(int d)
{
	Way::Change_Coords(*this, d);
}

void Coords::Move_Opposite_Direction(int d)
{
	Way::Change_Coords_Reverse(*this, d);
}

void Coords::Set_Location(int sx, int sy, int sz)
{
	x=sx; y=sy; z=sz;
}

