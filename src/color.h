//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit color: Colors for fonts.

#pragma once

//curses extra colors
#define COLOR_BROWN 8
#define COLOR_OCHRE 9
#define COLOR_VIOLET 10
#define COLOR_ORANGE 11
#define COLOR_SILVER 12
#define COLOR_GREY 13
#define COLOR_DARKGREEN 14
#define COLOR_OCEAN 15

class Color
{
public:
	enum Color_Id {Reserved, Black, Brown, Dark_Green, Ochre, Dark_Blue,
		Violet, Orange, Silver, Grey, Red, Green, Yellow, Blue, Magenta,
		Cyan, White, Max_Colors};

private:
	int color;

public:
	Color(int c) : color(c) { }

	const char *Get_Name();

	void Init_Curses_Color_Pair();
};
