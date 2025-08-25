//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include <curses.h>
#include "gui.h"

Gui::Gui(int w, int h)
	: width(w), height(h)
{


}

void Gui::Set_Font_Color(int c)
{
	attron(COLOR_PAIR(c));
}

void Gui::GotoXY(int x, int y)
{
	move(y, x);
}

void Gui::Put_Char(char c)
{
	addch(c);
}

void Gui::Put_Char(char c, int color)
{
	Set_Font_Color(color);
	Put_Char(c);
}

int Gui::Write_Text(const char *txt)
{
	int x, y;
	getyx(stdscr, y, x); //save current pos
	int t=0;
	char c;

	while (txt[t]!=0)
	{
		c=txt[t++];

		if (c==13) //move to next line
		{
			y++;
			move(y, x);
			continue;
		}

		Put_Char(c);
	}

	return t;
}

void Gui::Clear_Screen()
{
	clear();
}

void Gui::Update_Screen()
{
	refresh();
}
