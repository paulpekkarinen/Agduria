//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "gender.h"

struct Gender_Data
{
	const char *name;
};

const Gender_Data gender_data[Gender::Max_Genders]=
{
	{"none"},
	{"male"},
	{"female"},
	{"hermaphrodite"}
};

Gender::Gender(int g)
	: gender(g)
{

}

const char *Gender::Get_String()
{
	return gender_data[gender].name;
}
