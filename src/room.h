//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit room: Room feature of a dungeon.

#pragma once

#include "point.h"
#include "rect.h"

class Site;

class Room : public Rectangle
{
public:
	enum Room_Types {Empty, Bee_Hive, Shop, Max_Room_Types};

private:
	Site *lvl; //points to the level of the room
	int type;
	int connections; //how many places this room is connected

public:
	Room(const Rectangle &r, Site *l, int roomtype);

	int Get_Connections() const { return connections; }
	Point Get_Midpoint();
	Point Get_Random_Location();

	void Create(int room_id);

	void Increase_Connections() { connections++; }

	int Count_Doors(); //amount of existing connections
	int Count_Doors(int facing);

	//debug
	void Change_Floor(int tt);
};
