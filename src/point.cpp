//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "point.h"

Point::Point(int sx, int sy)
	: x(sx), y(sy)
{

}

void Point::Set_Location(int sx, int sy)
{
	x=sx;
	y=sy;
}
