//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include <cmath>
#include "coords.h"
#include "corridor.h"
#include "drunkard.h"
#include "feature.h"
#include "places.h"
#include "region.h"
#include "rng.h"
#include "site.h"
#include "terrain.h"
#include "way.h"

Site::Site(int w, int h, int th)
	: Scene(w, h), theme(th), current_room_id(0)
{

}

Coords Site::Get_Random_Mask_Place(int mt)
{
	places.Find_Masks(this, mt);
	return places.Get_Random();
}

void Site::Create()
{
	Clear(Terrain::Bedrock);

	switch (theme)
	{
		case Region::Dungeon: Create_Dungeon(); break;
		case Region::Mines: Create_Mine(); break;
		case Region::Natural: break;
		default: break;
	}
}

bool Site::Create_Random_Room(int min_size, int max_size)
{
	Rectangle r;

	for (int t=0; t<3000; t++)
	{
		r.Set_Size(
			rng->Get_Min_Max(min_size, max_size),
			rng->Get_Min_Max(min_size, max_size));

		r.Set_Location(
			rng->Get_Min_Max(0, Get_Width()-r.width),
			rng->Get_Min_Max(0, Get_Height()-r.height));

		if (Check_Room_Area(r))
		{
			Create_Room(r, Room::Empty);
			return true;
		}
	}
	return false;
}

void Site::Create_Room(const Rectangle &r, int room_type)
{
	Room room(r, this, room_type);
	room_list.push_back(room);
	room.Create(current_room_id);
	current_room_id++;
}

void Site::Create_Dungeon()
{
	int a=rng->Get_Min_Max(8, 15);
	int t=0;

	//make possible for big rooms to appear, but reduce that by decreasing
	//the size
	int max_room_size=15;
	//same for min room size to avoid having only small rooms
	int min_room_size=8;

	while (t<a)
	{
		if (Create_Random_Room(min_room_size, max_room_size))
		{
			t++;
			if (max_room_size>10) max_room_size--;
			if (min_room_size>4) min_room_size--;
		}
		else break;
	}
}

void Site::Create_Corridor(int x, int y, int a, int b)
{
	Corridor cr(Terrain::Corridor, x, y, a, b);
	cr.Create(this);
}

Room& Site::Find_Closest_Room(Room &src_room)
{
	int r=0;
	int index=0;
	const Point mp=src_room.Get_Midpoint();

	//preset current closest room distance with large value
	int closest=1000;

	for (riter i=room_list.begin(); i!=room_list.end(); i++)
	{
		Room &dest_room=(*i);
		Point dest_mp=dest_room.Get_Midpoint();

		//exclude same room and rooms with more than one connection
		if (&dest_room==&src_room || dest_room.Get_Connections()>1)
		{
			index++;
			continue;
		}

		//get the sum of x and y distances to find out which room is the
		//closest one (not sure if this is a good routine, but results are ok)
		const int v=abs(mp.x-dest_mp.x)+abs(mp.y-dest_mp.y);
		if (v<=closest)
		{
			//new closest room
			closest=v;
			r=index;
		}

		index++;
	}

	return room_list[r];
}

void Site::Create_Mine()
{
	const int a=rng->Get_Min_Max(1, 3);
	Feature f(this, Feature::Mineral_Vein);

	for (int t=0; t<a; t++)
		f.Create();
}

//Clean rogue pillars and walls created by dungeon generator.
void Site::Pillar_Fix(int floor_tile)
{
	for (int y=1; y<Get_Height()-2; y++)
	{
		for (int x=1; x<Get_Width()-2; x++)
		{
			if (Is_Wall(x, y) && Get_Room_Id(x, y)==0)
			{
				if (Is_Floor(x+1, y) && Is_Floor(x-1, y))
					Put_Terrain(floor_tile, x, y);

				if (Is_Floor(x, y+1) && Is_Floor(x, y-1))
					Put_Terrain(floor_tile, x, y);
			}
		}
	}
}

void Site::Test_Room_Connections()
{
	//shows connected rooms with water or ice floors
	for (riter i=room_list.begin(); i!=room_list.end(); ++i)
	{
		const int c=(*i).Get_Connections();
		if (c>0)
		{
			int tt;
			if (c==1) tt=Terrain::Water;
			else tt=Terrain::Ice;

			(*i).Change_Floor(tt);
		}
	}
}
