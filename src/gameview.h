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
	static const int Horizontal_Limit=10;
	static const int Vertical_Limit=6;

	Level *lvl; //current level
	Point camera;
	Rectangle view;

public:
	Gameview(Level *l, const Rectangle &r);

	void Put_Creature(Creature *b, const Coords &c);
	void Put_Item(Item *i, const Coords &c);
	void Put_Object(Object *o, const Coords &c);

	void Show(const Coords &actor);
	void Show_Debug_Location();
};

extern Gameview *gameview;

