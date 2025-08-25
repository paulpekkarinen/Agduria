//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "rank.h"

struct Rank_Data
{
	const char *name;
	int place;
};

Rank_Data rank_data[Rank::Max_Ranks]=
{
	{"none", Rank::Before},
	{"soldier", Rank::After},
	{"captain", Rank::After},
	{"sergeant", Rank::After},
	{"lieutenant", Rank::After},
	{"queen", Rank::After},
	{"lord", Rank::After},
	{"king", Rank::After},
	{"master", Rank::After},
	{"demi", Rank::Attached_Before},
	{"arch", Rank::Line_Attached},
	{"high", Rank::Before},
	{"vampire", Rank::After},
	{"mummy", Rank::After},
	{"zombie", Rank::After},
	{"were", Rank::Attached_Before},
	{"rabid", Rank::Before}
};

Rank::Rank(int r)
	: rank(r)
{

}

const char *Rank::Get_String()
{
	return rank_data[rank].name;
}

int Rank::Get_Place()
{
	return rank_data[rank].place;
}
