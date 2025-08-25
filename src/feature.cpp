//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include <cmath>
#include "codex.h"
#include "coords.h"
#include "decide.h"
#include "feature.h"
#include "rect.h"
#include "rng.h"
#include "site.h"
#include "terrain.h"
#include "way.h"

enum class Shape {Across, Long, Short, Round};

enum class Sizevar {None, Random, Increasing, Decreasing};

enum class Start {Edges, Center, Random};

struct Feature_Data
{
	const char *name;

	Shape shape;
	Sizevar size_variation;
	Start start_point;
	int dir_change_rate;
	int jitter_amount;
	int speed;

	int terrain;
	int min_size;
	int max_size;
};

const Feature_Data cave_feature[Feature::Max_Features]=
{
	{"sand pit", Shape::Round, Sizevar::None, Start::Random, 50, 3, 1,
		Terrain::Sand, 2, 6},

	{"swamp", Shape::Round, Sizevar::None, Start::Random, 50, 3, 1,
		Terrain::Swamp, 2, 6},

	{"mineral vein", Shape::Long, Sizevar::Decreasing, Start::Random, 10, 3, 2,
		Terrain::Mineral_Vein, 3, 5},

	{"river", Shape::Across, Sizevar::None, Start::Edges, 5, 2, 1,
		Terrain::Water, 1, 2},

	{"lava river", Shape::Short, Sizevar::Decreasing, Start::Center, 30, 3, 3,
		Terrain::Molten_Lava, 1, 4},

	{"cavern", Shape::Short, Sizevar::Random, Start::Random, 30, 5, 2,
		Terrain::Dirt_Floor, 2, 5}
};

Feature::Feature(Site *l, int ft)
	: lvl(l), type(ft)
{

}

void Feature::Draw_Line(int x1, int y1, int x2, int y2, int r, int tile)
{
	if (x1==x2 && y1==y2)
	{
		Plot(x1, y1, r, tile);
		return;
	}

	int dx=x2-x1;
	int dy=y2-y1;

	int loop;
	if (abs(dy)<=abs(dx)) loop=abs(dx);
	else loop=abs(dy);

	float x_inc=(float)(dx/loop);
	float y_inc=(float)(dy/loop);

	float x=(float)x1;
	float y=(float)y1;

	for(int i=0; i<=loop; i++)
	{
		Plot(round_float(x), round_float(y), r, tile);
		x+=x_inc;
		y+=y_inc;
	}
}

void Feature::Plot(int x, int y, int r, int tile)
{
	bool is_round;
	if (r<3) is_round=false;
	else is_round=true;

	if (is_round)
	{
		//use r-2, because size 3 as radius is actually 6 or 7 tiles width, so
		//we get minimum size ellipses with radius 3=1
		lvl->Draw_Ellipse(x, y, r-2, r-2, tile);
	}
	else
	{
		Rectangle rr(x, y, r, r);
		lvl->Draw_Box(tile, rr);
	}
}

void Feature::Create()
{
	int x;
	int y;
	int dir;
	const int max_radius=cave_feature[type].max_size;
	const int width=lvl->Get_Width();
	const int height=lvl->Get_Height();

	//determine starting point and direction of the feature
	switch (cave_feature[type].start_point)
	{
		case Start::Edges:
		{
			if (rng->Flip_Coin()==true) //horizontal edge
			{
				x=rng->Get_Min_Max(3, width-3);
				if (rng->Flip_Coin()) { y=0; dir=Way::South; }
				else { y=height-1; dir=Way::North; }

				//randomly shift the direction to nearest direction
				if (rng->Flip_Coin())
					dir=get_nearest_random_direction(dir);
			}
			else //vertical edge
			{
				y=rng->Get_Min_Max(3, height-3);
				if (rng->Flip_Coin()) { x=0; dir=Way::East; }
				else { x=width-1; dir=Way::West; }

				if (rng->Flip_Coin())
					dir=get_nearest_random_direction(dir);
			}
		}
		break;

		case Start::Center:
		{
			int dw=width/3;
			int dh=height/3;
			x=rng->Get_Min_Max(dw, dw*2);
			y=rng->Get_Min_Max(dh, dh*2);
			dir=get_random_direction();
		}
		break;

		case Start::Random:
			x=rng->Get_Min_Max(max_radius*2, width-(max_radius*2));
			y=rng->Get_Min_Max(max_radius*2, height-(max_radius*2));
			dir=get_random_direction();
		break;

		default:
			x=0; y=0; dir=Way::None;
		break;
	}

	//determine length
	int len;
	switch (cave_feature[type].shape)
	{
		case Shape::Across: len=width+height; break;
		case Shape::Long: len=rng->Get_Min_Max(width/3, width/2); break;
		case Shape::Round:
		case Shape::Short: len=rng->Get_Min_Max(8, 15); break;
		default: len=0; break;
	}

	//determine starting radius
	int r;
	switch (cave_feature[type].size_variation)
	{
		case Sizevar::None:
		case Sizevar::Random:
			r=rng->Get_Min_Max(cave_feature[type].min_size, max_radius);
		break;
		case Sizevar::Increasing: r=1; break;
		case Sizevar::Decreasing: r=max_radius; break;
		default: r=0; break;
	}

	Coords c(x, y);
	Coords sc;
	float fs=(float)r;

	//use a fractional value to decrease or increase the size of feature
	const float dec_fs=(fs/(float)len);

	int s;
	for (int t=0; t<len; t++)
	{
		sc=c;

		//move to main direction
		for (s=0; s<cave_feature[type].speed; s++)
			c.Move_Direction(dir);

		int ja=cave_feature[type].jitter_amount;
		if (r<ja) ja=r+1;

		//add jitter
		int jdist=rng->Get(ja);
		if (rng->Flip_Coin()==true) c.x+=jdist;
		else c.x-=jdist;

		jdist=rng->Get(ja);
		if (rng->Flip_Coin()==true) c.y+=jdist;
		else c.y-=jdist;

		Draw_Line(sc.x, sc.y, c.x, c.y, r, cave_feature[type].terrain);

		if (lvl->Is_Outside(c.x, c.y))
			break;

		//change size
		switch (cave_feature[type].size_variation)
		{
			case Sizevar::None: break;
			case Sizevar::Random:
				r=rng->Get_Min_Max(cave_feature[type].min_size, max_radius);
			break;
			case Sizevar::Increasing:
				fs+=dec_fs;
				r=(int)fs;
				if (r>max_radius) r=max_radius;
			break;
			case Sizevar::Decreasing:
				fs-=dec_fs;
				r=(int)fs;
				if (r<1) r=1;
			break;
			default: break;
		}

		//change main direction randomly
		if (rng->Random_Chance(cave_feature[type].dir_change_rate))
		  dir=get_nearest_random_direction(dir);
	}
}
