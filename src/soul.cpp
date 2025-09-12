//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "decide.h"
#include "soul.h"

Soul::Soul(int st)
	: type(st)
{
	const int prefgend=type.Get_Preferred_Gender();
	gender=get_random_gender(prefgend);
}

