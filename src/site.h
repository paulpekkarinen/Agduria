//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit site: Dungeon generation part of level.

#pragma once

#include <vector>
#include "places.h"
#include "room.h"
#include "scene.h"

struct Coords;
class Way;

//This part of the level hierarchy takes care of generating the level.
class Site : public Scene
{
private:
	int theme;
	int current_room_id;
	Places places;
	std::vector<Room> room_list;
	typedef std::vector<Room>::iterator riter;

	void Create_Cave_Feature(int type);
	void Create_Corridor(int x, int y, int a, int b);
	void Create_Dungeon();
	void Create_Mine();
	bool Create_Random_Room(int min_size, int max_size);
	void Create_Room(const Rectangle &r, int room_type);
	Room& Find_Closest_Room(Room &src_room);

public:
	Site(int w, int h, int th);

	Coords Get_Random_Mask_Place(int mt);

	void Create();
	void Pillar_Fix(int floor_tile);

	void Test_Room_Connections();
};
