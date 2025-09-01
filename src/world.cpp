//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "coords.h"
#include "gameview.h"
#include "gui.h"
#include "level.h"
#include "node.h"
#include "player.h"
#include "region.h"
#include "rng.h"
#include "terrain.h"
#include "world.h"

Gameview *gameview;

//Links a section of level to another one with some kind of portal
//(usually stairs).
struct Link
{
	enum Connection_Types {Start, End, Middle};

	int section; //destination section (-1 = end of list)
	int where; //where in levels the connection is made
};

//Contains number of levels and theme in a section of the dungeon, and
//possible connections to other sections.
struct Section
{
	//index of section in 'sections' array
	enum Section_Types {Entrance, Crystal_Caves, Gnomish_Mines,
		Max_World_Sections};

	static const int Max_Links=10;

	int level_theme;

	//the connection stairs style and direction inside the theme levels
	int stairs_type;

	//number of levels created for this section
	int min_levels;
	int max_levels;

	//where this section is connected, if the connection type is middle
	//then find random level from one of the levels of destination section
	Link links[Max_Links];
};

Section sections[Section::Max_World_Sections]=
{
	{
		Region::Dungeon, Terrain::Staircase_Down, 3, 4,
		{Section::Crystal_Caves, Link::End, -1, -1}
	},
	{
		Region::Natural, Terrain::Staircase_Down, 3, 4,
		{Section::Gnomish_Mines, Link::End, -1, -1}
	},
	{
		Region::Mines, Terrain::Staircase_Down, 2, 2,
		{-1, -1}
	}
};

World::World()
	: current_level(0), location(0)
{
	gameview=0;

	//Create the stucture of the game world with level nodes. Each world
	//section is a part of the dungeon, either one level or set of levels
	//with a level theme.
	int id=0;

	for (int t=0; t<Section::Max_World_Sections; t++)
	{
		const int a=rng->Get_Min_Max(
			sections[t].min_levels, sections[t].max_levels);

		for (int r=0; r<a; r++)
		{
			//'t' is the current section of the level stored in node class
			Node n(id, t, sections[t].level_theme);
			levels.push_back(n);
			id++;
		}
	}

	//Create stairs that connect each level of a section. This routine
	//assumes that levels of section are continuous.
	int stairs_id=0; //running id of stairs

	for (size_t t=0; t<levels.size()-1; t++)
	{
		const int src=levels[t].Get_Section();
		const int dest=levels[t+1].Get_Section();

		if (src==dest) //connect levels of same section
		{
			const int stype=sections[src].stairs_type;
			Terrain tt(stype);

			//create stairs of source
			Stairs s(stairs_id, stype, levels[t+1].Get_Id(), stairs_id+1);
			//destination stairs, get reverse stairs type from terrain data
			Stairs d(stairs_id+1, tt.Get_Reverse_Type(),
				levels[t].Get_Id(), stairs_id);

			levels[t].Add_Stairs(s);
			levels[t+1].Add_Stairs(d);
			stairs_id+=2;
		}
	}
}

World::~World()
{
	levels.clear();
	delete gameview;
}

void World::Arrival()
{
	Enter();

	//put player to a random place in some floor
	Coords c=current_level->Get_Random_Mask_Place(Mask::Floor);
	player->Reset_Location(c);
	gameview->Center(c);
}

void World::Enter()
{
	current_level=levels[location].Enter();
	delete gameview;
	Rectangle r(0, 1, gui->Get_Width(), gui->Get_Height()-2);
	gameview=new Gameview(current_level, r);
}

void World::Remake_Current_Level()
{

}

void World::Show()
{
	const Coords &pc=player->Get_Location();
	gameview->Show(pc);
}
