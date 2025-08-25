//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit way: Directions.

#pragma once

struct Coords;

class Way
{
public:
	enum Directions {None, North, North_East, East, South_East, South,
		South_West, West, North_West, Ascend, Descend, Yourself,
		Max_Directions};

private:
	int dir;

public:
	Way() : dir(None) { }
	Way(int d);

	static void Change_Coords(Coords &c, int d);
	static void Change_Coords_Reverse(Coords &c, int d);

	void Set(int d);
};
