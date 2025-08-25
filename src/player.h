//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit player: Player game object.

#pragma once

#include "creature.h"

class Command;
struct Coords;

class Player : public Creature
{
private:
	void Proceed(int d);

public:
	Player(const Coords &c);

	void Run_Command(Command &c);

	void Draw() override;
};

extern Player *player;
