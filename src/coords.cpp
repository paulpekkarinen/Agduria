//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "coords.h"
#include "point.h"
#include "way.h"

Coords::Coords(int sx, int sy)
	: x(sx), y(sy), z(0)
{

}

Coords::Coords(int sx, int sy, int sz)
	: x(sx), y(sy), z(sz)
{

}

Coords::Coords(const Point &p)
	: x(p.x), y(p.y), z(0)
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

void Coords::Set(int sx, int sy, int sz)
{
	x=sx; y=sy; z=sz;
}

void Coords::Set(int sx, int sy)
{
	x=sx; y=sy;
}

