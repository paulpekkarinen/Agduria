//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit creature: A living game object.

#pragma once

#include "entity.h"

class Creature : public Entity
{
private:
	//note: replace later with dataset for creatures
	int type;

protected:
	int dir; //moving direction

public:
	Creature(const Coords &c, int ct);

	void Clear_Map() override;
	void Set_Map() override;
};
