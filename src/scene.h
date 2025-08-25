//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit scene: Contains the object data of a level.

#pragma once

#include <list>
#include "chart.h"

class Creature;

//Scene is the first class derived from base Chart (terrain) map of the level.
//It contains only theme-agnostic data like game objects.
class Scene : public Chart
{
private:
	std::list<Creature*> beings; //creatures in this level

	typedef std::list<Creature*>::iterator citer;

public:
	Scene(int w, int h);
	virtual ~Scene();

	void Clear_Objects();
	void Store_Creature(Creature *bob);
};
