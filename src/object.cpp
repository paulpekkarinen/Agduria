//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "gameview.h"
#include "object.h"

Object::Object(const Coords &c, int ot)
	: Entity(c), type(ot)
{

}

void Object::Clear_Map()
{
	gameview->Put_Object(0, location);
}

void Object::Set_Map()
{
	gameview->Put_Object(this, location);
}
