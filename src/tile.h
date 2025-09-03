//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit tile: One tile of a display map.

#pragma once

class Creature;
class Item;
class Object;

//Tile contains game object pointers which objects set as they are created
//or when they are moving. There are several layers for different types of
//game objects.
struct Tile
{
	enum Visions {Visible, Blocked, Outside};

	int vision; //if tile is visible or blocked by fov, or outside level
	Creature *being; //living creatures are the top layer
	Object *obj; //any object type like movables, fountains etc.

	//items are the bottom layer, they can be under anything else. The item is
	//the topmost if more than one item in this tile.
	Item *item;

	Tile() : vision(Visible), being(0), obj(0), item(0) { }
	Tile(int v) : vision(v), being(0), obj(0), item(0) { }

	bool Display();
};
