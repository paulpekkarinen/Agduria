//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "element.h"

Element::Element()
	: Terrain(Terrain::Void), room_id(-1)
{

}

Element::Element(int terrain)
	: Terrain(Terrain::Void), room_id(-1)
{

}

void Element::Clear(int tv)
{
	type=tv;
	room_id=-1;
}
