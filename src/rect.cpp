//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "rect.h"

Rectangle::Rectangle(int sx, int sy, int sw, int sh)
	: Point(sx, sy), width(sw), height(sh)
{

}

Rectangle Rectangle::Get_Clone()
{
	return Rectangle(x, y, width, height);
}

int Rectangle::Get_Volume()
{
	return width*height;
}

void Rectangle::Set_Size(int sw, int sh)
{
	width=sw;
	height=sh;
}

void Rectangle::Shrink()
{
	x++;
	y++;
	width-=2;
	height-=2;
}
