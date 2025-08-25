//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit object: Simple game objects like fountains, traps etc.

#pragma once

#include "entity.h"

class Object : public Entity
{
public:
	enum Object_Types {Door, Iron_Bars, Tree, Grave, Throne, Sink, Fountain};

private:
	int type;

public:
	Object(const Coords &c, int ot);

	void Clear_Map() override;
	void Set_Map() override;
};
