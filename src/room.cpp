//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "coords.h"
#include "room.h"
#include "rng.h"
#include "site.h"
#include "terrain.h"
#include "way.h"

struct Room_Data
{
	int wall_tile;
	int floor_tile;
};

Room_Data room_data[Room::Max_Room_Types]=
{
	{Terrain::Wall, Terrain::Cave_Floor},
	{Terrain::Wall, Terrain::Dirt_Floor},
	{Terrain::Wall, Terrain::Cave_Floor}
};

Room::Room(const Rectangle &r, Site *l, int roomtype)
	: Rectangle(r), lvl(l), type(roomtype), connections(0)
{

}

Point Room::Get_Midpoint()
{
	return Point(x+(width/2), y+(height/2));
}

Point Room::Get_Random_Location()
{
	Point p;
	p.x=rng->Get_Min_Max(x+1, x+width-3);
	p.y=rng->Get_Min_Max(y+1, y+height-3);
	return p;
}

void Room::Change_Floor(int tt)
{
	Rectangle r=Get_Clone();
	r.Shrink();
	lvl->Draw_Box(tt, r);
}

void Room::Create(int room_id)
{
	Rectangle r=Get_Clone();

	//create walls
	lvl->Draw_Rectangle(room_data[type].wall_tile, r);

	//create floor tiles
	r.Shrink();

	lvl->Draw_Box(room_data[type].floor_tile, r);

	//set room id for mask on the floor area
	lvl->Draw_Room_Mask(r, room_id);
}

int Room::Count_Doors()
{
	int rv=Count_Doors(Way::North);
	rv+=Count_Doors(Way::South);
	rv+=Count_Doors(Way::East);
	rv+=Count_Doors(Way::West);
	return rv;
}

int Room::Count_Doors(int facing)
{
	int rv=0, dx, dy, w;
	int d;

	switch (facing)
	{
		case Way::North: dx=x+1; dy=y; w=width-2; d=Way::East; break;
		case Way::South: dx=x+1; dy=y+height-1; w=width-2; d=Way::East; break;
		case Way::West: dx=x; dy=y+1; w=height-2; d=Way::South; break;
		case Way::East: dx=x+width-1; dy=y+1; w=height-2; d=Way::South; break;
		default: dx=0; dy=0; w=0; break;
	}

	Coords c(dx, dy);

	for (int t=0; t<w; t++)
	{
		if (lvl->Get_Mask_Type(c.x, c.y)!=Mask::Wall) rv++;
		c.Move_Direction(d);
	}

	return rv;
}
