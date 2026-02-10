//Agduria - Copyright (C) Paul K. Pekkarinen

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
