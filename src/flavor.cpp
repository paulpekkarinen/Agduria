//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "flavor.h"

struct Flavor_Data
{
	const char *name;
};

Flavor_Data flavor_data[Flavor::Max_Flavors]=
{
	{"none"},
	{"killer"},
	{"carnivorous"},
	{"electric"},
	{"acid"},
	{"quivering"},
	{"floating"},
	{"freezing"},
	{"shocking"},
	{"flaming"},
	{"winged"},
	{"gas"},
	{"spotted"},
	{"shimmering"},
	{"fire"},
	{"frost"},
	{"winter"},
	{"storm"},
	{"wood"},
	{"mountain"},
	{"hill"},
	{"rock"},
	{"sewer"},
	{"cave"},
	{"plains"},
	{"forest"},
	{"blue"},
	{"ochre"},
	{"white"},
	{"gray"},
	{"black"},
	{"silver"},
	{"yellow"},
	{"red"},
	{"orange"},
	{"green"},
	{"brown"},
	{"violet"},
	{"golden"}
};

Flavor::Flavor(int f)
	: flavor(f)
{

}

const char *Flavor::Get_String()
{
	return flavor_data[flavor].name;
}
