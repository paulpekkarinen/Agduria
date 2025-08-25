//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "creature.h"
#include "gameview.h"
#include "way.h"

Creature::Creature(const Coords &c, int ct)
	: Entity(c), type(ct), dir(Way::None)
{

}

void Creature::Clear_Map()
{
	gameview->Put_Creature(0, location);
}

void Creature::Set_Map()
{
	gameview->Put_Creature(this, location);
}
