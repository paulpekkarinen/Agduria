//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include <curses.h>
#include "color.h"
#include "resource.h"

struct RedGreenBlue
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

constexpr short Amt_Extra_Colors=8;

RedGreenBlue extra_colors[Amt_Extra_Colors]=
{
	{143, 63, 0}, //brown
	{165, 144, 8}, //ochre
	{122, 0, 237}, //violet
	{237, 96, 0}, //orange
	{244, 248, 244}, //silver
	{112, 112, 112}, //grey
	{0, 139, 0}, //dark green
	{0, 146, 196} //ocean blue
};

//change color values from 0..255 to 0..1000 required by curses
short Resource::Get_Color_Component(unsigned char c)
{
	double fc=(double)c;
	double rv=(1000.0/255.0)*fc;
	return (short)rv;
}

void Resource::Initialize_Colors()
{
	//define extra colors
	for (short i=0; i<Amt_Extra_Colors; i++)
	{
		short r=Get_Color_Component(extra_colors[i].r);
		short g=Get_Color_Component(extra_colors[i].g);
		short b=Get_Color_Component(extra_colors[i].b);

		//new colors start from index 8
		init_color(i+8, r, g, b);
	}

	//create color pairs or actual colors for curses
	for (short i=0; i<Color::Max_Colors; i++)
	{
		Color c(i);
		c.Init_Curses_Color_Pair();
	}
}
