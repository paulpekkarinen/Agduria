//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit point: Point (x, y).

#pragma once

struct Point
{
	int x;
	int y;

	Point() : x(0), y(0) { }
	Point(int sx, int sy);

	void Set_Location(int sx, int sy);

	Point& operator=(const Point &r)
	{
		if(this == &r) return *this;
		x=r.x;
		y=r.y;
		return *this;
	}

	bool operator==(const Point& r)
	{
		if(this == &r) return true;
		if (x==r.x && x==r.y) return true;
		return false;
	}
};
