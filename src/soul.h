//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit soul: Build of a creature.

#pragma once

#include "gender.h"
#include "species.h"

struct Soul
{
	Species type;
	Gender gender;

	Soul(int st);
};

