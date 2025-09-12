//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "family.h"
#include "gender.h"

struct Family_Data
{
	const char *name;
};

Family_Data family_data[Family::Max_Families]=
{
	{"Insect"},
	{"Bird"},
	{"Canine"},
	{"Mariner"},
	{"Mammal"},
	{"Feline"},
	{"Humanoid"},
	{"Testudinidae"},
	{"Reptile"},
	{"Fungi"},
	{"Phantom"},
	{"Undead"},
	{"Vermes"}
};

Family::Family(int f)
	: family(f)
{
	
}

const char *Family::Get_Family_Name()
{
	return family_data[family].name;
}

int Family::Get_Preferred_Gender()
{
	int rv;

	switch (family)
	{
		case Phantom:
		case Undead:
			rv=Gender::None;
		break;
		
		case Fungi:
		case Vermes:
			rv=Gender::Hermaphrodite;
		break;
		
		default: rv=Gender::Both; break;
	}

	return rv;
}
