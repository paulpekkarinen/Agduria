//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit gui: Graphical user interface.

#pragma once

#include "color.h"

class Gui
{
private:
	//size of the terminal screen
	int width;
	int height;

public:
	Gui(int w, int h);

	int Get_Width() const { return width; }
	int Get_Height() const { return height; }

	void Clear_Screen();
	void GotoXY(int x, int y);
	void Put_Char(char c);
	void Put_Char(char c, int color);
	void Set_Font_Color(int c);
	void Update_Screen();
	int Write_Text(const char *txt);
};

extern Gui *gui;
