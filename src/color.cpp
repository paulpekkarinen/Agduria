//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include <curses.h>
#include "color.h"

struct Color_Data
{
	const char *name;
	short fore_color;
	short back_color;
};

const Color_Data color_data[Color::Max_Colors]=
{
	{"reserved", 0, 0},
	{"black", COLOR_BLACK, COLOR_GREY},
	{"brown", COLOR_BROWN, COLOR_BLACK},
	{"dark green", COLOR_DARKGREEN, COLOR_BLACK},
	{"ochre", COLOR_OCHRE, COLOR_BLACK},
	{"dark blue", COLOR_BLUE, COLOR_BLACK},
	{"violet", COLOR_VIOLET, COLOR_BLACK},
	{"orange", COLOR_ORANGE, COLOR_BLACK},
	{"silver", COLOR_SILVER, COLOR_BLACK},
	{"grey", COLOR_GREY, COLOR_BLACK},
	{"red", COLOR_RED, COLOR_BLACK},
	{"green", COLOR_GREEN, COLOR_BLACK},
	{"yellow", COLOR_YELLOW, COLOR_BLACK},
	{"blue", COLOR_OCEAN, COLOR_BLACK},
	{"magenta", COLOR_MAGENTA, COLOR_BLACK},
	{"cyan", COLOR_CYAN, COLOR_BLACK},
	{"white", COLOR_WHITE, COLOR_BLACK}
};

const char *Color::Get_Name()
{
	return color_data[color].name;
}

void Color::Init_Curses_Color_Pair()
{
	init_pair((short)color, color_data[color].fore_color,
		color_data[color].back_color);
}
