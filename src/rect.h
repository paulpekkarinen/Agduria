//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit rectangle: Rectangle.

#pragma once

#include "point.h"

struct Rectangle : public Point
{
	int width;
	int height;

	Rectangle() : Point(0, 0), width(0), height(0) { }
	Rectangle(int sx, int sy, int sw, int sh);

	Rectangle Get_Clone();
	int Get_Volume();
	void Set_Size(int sw, int sh);
	void Shrink();

	Rectangle& operator=(const Rectangle &r)
	{
		if(this == &r) return *this;
		x=r.x;
		y=r.y;
		width=r.width;
		height=r.height;
		return *this;
	}
};
