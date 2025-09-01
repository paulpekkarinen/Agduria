//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit gameview: Final display map of the game world.

#pragma once

#include "tilemap.h"
#include "rect.h"

class Creature;
class Item;
class Object;
class Level;

class Gameview : public Tile_Map
{
private:
	//how close to the edge until gameview is scrolled
	static const int Horizontal_Limit=9;
	static const int Vertical_Limit=6;

	Level *lvl; //current level
	Point camera;
	Rectangle view;

	void Clamp_Camera_X();
	void Clamp_Camera_Y();
	void Clamp_Camera();

public:
	Gameview(Level *l, const Rectangle &r);

	Point Get_Screen_Location(const Coords &c);
	Rectangle Get_Level_Size();

	void Center(const Coords &c);

	void Put_Creature(Creature *b, const Coords &c);
	void Put_Item(Item *i, const Coords &c);
	void Put_Object(Object *o, const Coords &c);

	void Show(const Coords &actor);
	void Show_Debug_Location(const Coords &actor);
};

extern Gameview *gameview;

