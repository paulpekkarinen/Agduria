//Agduria - Copyright (C) Paul Pekkarinen

#include <curses.h>
#include <cstring>
#include "gui.h"

Gui::Gui(int w, int h)
	: width(w), height(h)
{

}

void Gui::Clear_Line(int y, int color)
{
	Set_Font_Color(color);
	GotoXY(0, y);
	for (int x=0; x<width; x++)
		Put_Char(' ');
}

void Gui::Default_Color()
{
	Set_Font_Color(Color::White);
}

void Gui::Set_Font_Color(int c)
{
	attron(COLOR_PAIR(c));
}

void Gui::Goto_Last_Line()
{
	move(height-1, 0);
}

void Gui::GotoXY(int x, int y)
{
	move(y, x);
}

void Gui::GotoXYC(int x, int y, int color)
{
	GotoXY(x, y);
	Set_Font_Color(color);
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

int Gui::Write_Centered_Text(int y, const char *txt)
{
	const int len=strlen(txt);
	if (len>=width)
		return 0;

	const int x=(width-len)/2;

	return Write_Text_To(x, y, txt);
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

int Gui::Write_Text_To(int x, int y, const char *txt)
{
	GotoXY(x, y);
	return Write_Text(txt);
}

void Gui::Clear_Screen()
{
	clear();
}

void Gui::Update_Screen()
{
	refresh();
}

void Gui::Goto_First_Line()
{
	move(0, 0);
}

