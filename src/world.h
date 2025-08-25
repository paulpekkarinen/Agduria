//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit world: List of levels nodes, the game world.

#pragma once

#include <vector>
#include "node.h"

class Gameview;
class Level;
class Player;

//World contains levels and generic information of the game world state.
class World
{
public:
	Level *current_level;

private:
	size_t location; //current level index
	std::vector<Node> levels;

	typedef std::vector<Node>::iterator niter;

public:
	World();
	~World();

	void Arrival();
	void Enter();
	void Remake_Current_Level();

	void Show();
};

extern World *world;
