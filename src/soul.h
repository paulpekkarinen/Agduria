//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit soul: Build of a creature.

#pragma once

#include "age.h"
#include "gender.h"
#include "species.h"

struct Soul
{
	Species type;
	Gender gender;
	Age age;

	Soul(int st);
};

