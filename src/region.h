//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit region: Level theme, type of a level.

#pragma once

struct Rectangle;

class Region
{
public:
	enum Region_Types {Dungeon, Natural, Mines};

private:
	int type;

public:
	Region(int t);

	Rectangle Get_Random_Size();
};
