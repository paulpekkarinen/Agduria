//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "age.h"
#include "decide.h"
#include "gender.h"
#include "rng.h"
#include "species.h"
#include "way.h"

const int card_dirs[4]={Way::North, Way::South, Way::East, Way::West};

int get_nearest_random_direction(int source_dir)
{
	//assumes that directions are in order
	int rv=source_dir;
	if (rng->Flip_Coin()==true) rv--;
	else rv++;

	//check limits
	if (rv>Way::North_West) rv=Way::North;
	else if (rv<Way::North) rv=Way::North_West;

	return rv;
}

int get_opposite_direction(int d)
{
	int rv;
	switch (d)
	{
		case Way::North: rv=Way::South; break;
		case Way::South: rv=Way::North; break;
		case Way::East: rv=Way::West; break;
		case Way::West: rv=Way::East; break;
		default: rv=Way::None; break;
	}
	return rv;
}

int get_random_age(int family)
{
	int rv=Age::Average; //default age

	switch (family)
	{
		case Family::Canine:
			if (rng->Rarely()) rv=Age::Pup;
			else if (rng->Very_Rarely()) rv=Age::Old;
		break;
		case Family::Feline:
			if (rng->Rarely()) rv=Age::Cub;
			else if (rng->Very_Rarely()) rv=Age::Old;
		break;
		case Family::Bird:
			if (rng->Rarely()) rv=Age::Hatchling;
		break;
		case Family::Reptile:
			if (rng->Very_Rarely()) rv=Age::Baby;
		break;
		case Family::Humanoid:
			if (rng->Very_Rarely()) rv=Age::Old;
		break;
		default: break;
	}

	return rv;
}

int get_random_cardinal_direction()
{
	const int i=rng->Get_Min_Max(0, 3);
	return card_dirs[i];
}

int get_random_direction()
{
	return rng->Get_Min_Max(Way::North, Way::North_West);
}

int get_random_gender(int preferred)
{
	int rv=preferred;

	if (rv==Gender::Both)
	{
		if (rng->Rarely())
			rv=Gender::Female;
		else
			rv=Gender::Male;	
	}

	return rv;
}

