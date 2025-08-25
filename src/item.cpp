//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "gameview.h"
#include "item.h"

Item::Item(const Coords &c, int ot)
	: Entity(c), type(ot)
{

}

void Item::Clear_Map()
{
	gameview->Put_Item(0, location);
}

void Item::Set_Map()
{
	gameview->Put_Item(this, location);
}
