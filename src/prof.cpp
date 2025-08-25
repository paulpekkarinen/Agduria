//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "prof.h"
#include "gender.h"

struct Profession_Data
{
	const char *name;
	//preferred gender of the profession, 'both' can be either male or female
	int gender;
};

const Profession_Data prof_data[Profession::Max_Professions]=
{
	{"none", Gender::Both},
	{"mage", Gender::Male},
	{"shaman", Gender::Male},
	{"priest", Gender::Male},
	{"priestess", Gender::Male},
	{"watchman", Gender::Male},
	{"doctor", Gender::Male},
	{"nurse", Gender::Female},
	{"shopkeeper", Gender::Male},
	{"guard", Gender::Male},
	{"prisoner", Gender::Both},
	{"kop", Gender::Male},
	{"prophet", Gender::Male},
	{"oracle", Gender::Female},
	{"barbarian", Gender::Male},
	{"amazonian", Gender::Female},
	{"caveman", Gender::Male},
	{"cavewoman", Gender::Female},
	{"healer", Gender::Male},
	{"knight", Gender::Male},
	{"monk", Gender::Male},
	{"nun", Gender::Female},
	{"ranger", Gender::Both},
	{"rogue", Gender::Both},
	{"samurai", Gender::Male},
	{"tourist", Gender::Both},
	{"warlock", Gender::Male},
	{"valkyrie", Gender::Female},
	{"wizard", Gender::Male},
	{"witch", Gender::Female}
};

Profession::Profession(int p)
	: prof(p)
{

}

int Profession::Get_Gender()
{
	return prof_data[prof].gender;
}

const char *Profession::Get_String(int g)
{
	return prof_data[prof].name;
}
