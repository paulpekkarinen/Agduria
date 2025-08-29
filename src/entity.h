//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit entity: Game object's abstract base class.

#pragma once

#include "coords.h"

//Base class for all game objects like doors, creatures etc. that are other
//than terrain tiles and can possibly also move.
class Entity
{
protected:
	Coords location;

public:
	Entity(const Coords &c);
	virtual ~Entity() { }

	Coords Get_Location();

	virtual void Clear_Map() = 0;
	virtual void Draw() = 0;
	int Move(int dir);
	int Set_Location(const Coords &c);
	virtual void Set_Map() = 0;
	void Reset_Location(const Coords &c);
};
