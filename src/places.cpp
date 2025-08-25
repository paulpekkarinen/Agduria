//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "chart.h"
#include "element.h"
#include "places.h"
#include "rng.h"

int Places::Find_Masks(Chart *chart, int masktype)
{
	spots.clear();

	for (int y=0; y<chart->Get_Height(); y++)
	{
		for (int x=0; x<chart->Get_Width(); x++)
		{
			if (chart->Get_Mask_Type(x, y)==masktype)
			{
				spots.push_back(Coords(x, y));
			}
		}
	}

	return Get_Size();
}

int Places::Find_Terrains(Chart *chart, int terrain)
{
	spots.clear();

	for (int y=0; y<chart->Get_Height(); y++)
	{
		for (int x=0; x<chart->Get_Width(); x++)
		{
			Element e=chart->Get_Terrain(x, y);
			if (e.type==terrain)
			{
				Coords c(x, y);
				spots.push_back(c);
			}
		}
	}

	return Get_Size();
}

Coords Places::Get_Random()
{
	Coords rv(-1, -1); //fail location

	const int amt=Get_Size();

	if (amt<1)
		return rv;

	const unsigned long r=(unsigned long)rng->Get(amt);
	rv=spots.at(r);

	//erase the place so it's not selected again
	std::vector<Coords>::iterator vi=spots.begin();
	spots.erase(vi+(long)r);

	return rv;
}

int Places::Get_Size()
{
	return (int)spots.size();
}

bool Places::Set_Random(Coords &dest)
{
	const int amt=Get_Size();

	if (amt<1) return false;

	const unsigned long r=(unsigned long)rng->Get(amt);
	dest=spots.at(r);

	return true;
}
