//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit item: Item game object like swords, potions etc.

#pragma once

#include "entity.h"

class Item : public Entity
{
private:
	int type;

public:
	Item(const Coords &c, int it);

	void Clear_Map() override;
	void Set_Map() override;
};
