//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit rng: Random number generator.

#pragma once

class Random_Generator
{
public:
	bool Flip_Coin(); //returns 50% chance
	int Get(int ra);
	float Get_Float(float min_value, float max_value);
	unsigned char Get_From_String(const unsigned char *str);
	int Get_Min_Max(int rmin, int rmax);
	bool Random_Chance(int percent); //percentage value success or failure
	bool Rarely();
	bool Sometimes();
	bool Usually();
	bool Very_Rarely();
};

extern Random_Generator *rng;
