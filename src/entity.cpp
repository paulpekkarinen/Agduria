//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "contact.h"
#include "entity.h"
#include "world.h"
#include "level.h"

Entity::Entity(const Coords &c)
	: location(c)
{

}

Coords Entity::Get_Location()
{
	return location;
}

void Entity::Reset_Location(const Coords &c)
{
	location=c;
	Set_Map();
}

int Entity::Set_Location(const Coords &c)
{
	if (world->current_level->Is_Outside(c.x, c.y))
		return Contact::Level_Border;

	Clear_Map(); //clear previous position

	location=c;

	Set_Map();

	return Contact::Nothing;
}

int Entity::Move(int dir)
{
	Coords c=location;
	c.Move_Direction(dir);
	return Set_Location(c);
}
