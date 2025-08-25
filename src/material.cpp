//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "material.h"

struct Material_Data
{
	const char *name;
	int burn_rate;
};

const Material_Data mat_data[Material::Max_Materials]=
{
	{"none", 0},
	{"wood", Combust::Medium},
	{"stone", Combust::None},
	{"straw", Combust::Fast},
	{"paper", Combust::Fast},
	{"rope", Combust::Medium},
	{"gold", Combust::None},
	{"silver", Combust::None},
	{"copper", Combust::None},
	{"brass", Combust::None},
	{"iron", Combust::None},
	{"leather", Combust::Slow},
	{"flesh", Combust::Slow},
	{"clay", Combust::None},
	{"glass", Combust::None},
	{"gelatine", Combust::Slow},
	{"dirt", Combust::None},
	{"fog", Combust::None},
	{"dust", Combust::None},
	{"ice", Combust::None},
	{"energy", Combust::None},
	{"steam", Combust::None},
	{"lava", Combust::None},
	{"water", Combust::None}
};

Material::Material(int m)
	: material(m)
{

}

const char *Material::Get_String()
{
	return mat_data[material].name;
}

int Material::Get_Burn_Rate()
{
	return mat_data[material].burn_rate;
}
