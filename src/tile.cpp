//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "creature.h"
#include "item.h"
#include "object.h"
#include "tile.h"

//Show things on a tile in certain order.
bool Tile::Display()
{
	if (being!=0)
	{
		being->Draw();
		return true;
	}

	if (obj!=0)
	{
		obj->Draw();
		return true;
	}

	if (item!=0)
	{
		item->Draw();
		return true;
	}

	return false;
}

