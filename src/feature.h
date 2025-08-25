//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit feature: Terrain feature.

#pragma once

class Site;

class Feature
{
public:
	enum Feature_Types {Sand_Pit, Swamp, Mineral_Vein, River, Lava_River,
		Cavern, Max_Features};

private:
	Site *lvl; //points to the level of feature
	int type;

	void Draw_Line(int x1, int y1, int x2, int y2, int r, int tile);
	void Plot(int x, int y, int r, int tile);

public:
	Feature(Site *l, int ft);

	void Create();
};
