//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "age.h"

struct Age_Data
{
	const char *name;
	int name_location; //-1=before, 0=none, 1=after
};

const Age_Data age_data[Age::Max_Ages]=
{
	{"average", 0}, //not displayed, normal age
	{"cub", 1},
	{"pup", 1},
	{"hatchling", 1}, //from an egg
	{"baby", -1},
	{"old", -1},
	{"senior", -1},
	{"ancient", -1}
};

const char *Age::Get_String()
{
	return age_data[age].name;
}

int Age::Get_Name_Location()
{
	return age_data[age].name_location;
}
