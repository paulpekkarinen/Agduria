//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "creature.h"
#include "scene.h"

Scene::Scene(int w, int h)
	: Chart(w, h)
{

}

Scene::~Scene()
{
	Clear_Objects();
}

void Scene::Clear_Objects()
{
	for (citer i=beings.begin(); i!=beings.end(); ++i)
	{
		delete (*i);
	}

	beings.clear();
}

void Scene::Store_Creature(Creature *bob)
{
	//whether objects overlap something else is not checked here
	beings.push_back(bob);
}
