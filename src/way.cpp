//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "coords.h"
#include "way.h"

struct Direction_Data
{
	const char *name;
	int delta_x;
	int delta_y;
	int delta_z;
};

const Direction_Data dir_data[Way::Max_Directions]=
{
	{"None", 0, 0, 0},
	{"North", 0, -1, 0},
	{"North-East", 1, -1, 0},
	{"East", 1, 0, 0},
	{"South-East", 1, 1, 0},
	{"South", 0, 1, 0},
	{"South-West", -1, 1, 0},
	{"West", -1, 0, 0},
	{"North-West", -1, -1, 0},
	{"Ascend", 0, 0, 1},
	{"Descend", 0, 0, -1},
	{"Yourself", 0, 0, 0}
};

Way::Way(int d)
	: dir(d)
{

}

void Way::Change_Coords(Coords &c, int d)
{
	c.x+=dir_data[d].delta_x;
	c.y+=dir_data[d].delta_y;
	c.z+=dir_data[d].delta_z;
}

void Way::Change_Coords_Reverse(Coords &c, int d)
{
	c.x+=-dir_data[d].delta_x;
	c.y+=-dir_data[d].delta_y;
	c.z+=-dir_data[d].delta_z;
}

void Way::Set(int d)
{
	if (d>=0 && d<Max_Directions)
		dir=d;
}
