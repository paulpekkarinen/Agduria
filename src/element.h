//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit element: An extended terrain with room id data.

#pragma once

#include "terrain.h"

struct Element : public Terrain
{
	int room_id; //-1 for no room, or greater for room id

	Element();
	Element(int terrain);

	void Clear(int tv);
};
