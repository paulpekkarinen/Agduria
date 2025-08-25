//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "corridor.h"
#include "rng.h"
#include "site.h"
#include "terrain.h"

Corridor::Corridor(int tt, int x, int y, int a, int b)
	: terrain_type(tt), src(x, y), dest(a, b)
{

}

void Corridor::Create(Site *lvl)
{
	for (int t=0; t<5000; t++)
	{
		const int piece_length=rng->Get_Min_Max(2, 5);

		//alternate randomly between vertical and horizontal runs
		const bool vertical=rng->Flip_Coin();

		for (int j=0; j<piece_length; j++)
		{
			if (vertical)
			{
				if (src.y<dest.y) src.y++;
				else if (src.y>dest.y) src.y--;
			}
			else
			{
				if (src.x<dest.x) src.x++;
				else if (src.x>dest.x) src.x--;
			}

			//create corridor only on base tile to avoid breaking room walls
			//or other constructions
			if (lvl->Is_Bedrock(src.x, src.y))
				lvl->Put_Terrain(Terrain::Corridor, src.x, src.y);

			if (src==dest) break;
		}
	}
}
