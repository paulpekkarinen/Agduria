//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include <random>
#include "rng.h"

std::random_device rand_dev;
std::mt19937 mersenne(rand_dev());

int Random_Generator::Get(int ra)
{
	//if 1 or smaller values used, return 0
	if (ra<2)
		return 0;

	return Get_Min_Max(0, ra-1);
}

int Random_Generator::Get_Min_Max(int rmin, int rmax)
{
	if (rmin==rmax) return rmin;

	std::uniform_int_distribution<int> dist(rmin, rmax);
	return dist(mersenne);
}

bool Random_Generator::Random_Chance(int percent)
{
	if (percent>=100) return true;
	if (percent<=0) return false;
	if (Get(100)+1<=percent) return true;
	return false;
}

bool Random_Generator::Flip_Coin()
{
	if (Get(2)==1) return true;
	return false;
}

float Random_Generator::Get_Float(float min_value, float max_value)
{
	return ((max_value-min_value)*((float)rand()/RAND_MAX))+min_value;
}

unsigned char Random_Generator::Get_From_String(const unsigned char *str)
{
	int a=0;
	while (str[a]!=0) a++; //count amount of items in the string

	const int i=Get_Min_Max(0, a-1);

	return str[i]; //return one of the chars in the string
}

bool Random_Generator::Usually()
{
	return Random_Chance(75);
}

bool Random_Generator::Sometimes()
{
	return Random_Chance(35);
}

bool Random_Generator::Rarely()
{
	return Random_Chance(20);
}

bool Random_Generator::Very_Rarely()
{
	return Random_Chance(2);
}
