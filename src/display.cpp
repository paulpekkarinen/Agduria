//Agduria - Copyright (C) Paul Pekkarinen

#include <curses.h>
#include <format>
#include <string>
#include "display.h"
#include "element.h"
#include "input.h"
#include "keybinds.h"
#include "tile.h"
#include "gui.h"
#include "world.h"

using std::format;
using std::string;

Display display; //global instance

const char Display::title_data[(Display::Title_Width*Display::Title_Height)+1]=
"-------------------------------------"
" ###   ###  ####  #   # ####  #  ### "
"#   # #     #   # #   # #   # # #   #"
"##### # ### #   # #   # ####  # #####"
"#   # #   # #   # #   # #   # # #   #"
"#   #  ###  ####   ###  #   # # #   #"
"-------------------------------------";

void Display::Centered_Text(const char *txt, int line, int color)
{
	string s("-=[ ");
	s.append(txt);
	s.append(" ]=-");

	gui->Clear_Line(line, color);

	const int w=s.size();

	int x=(gui->Get_Width()-w)/2;

	gui->Write_Text_To(x, line, s.c_str());
}

void Display::Footer(const char *txt)
{
	Centered_Text(txt, gui->Get_Height()-1, Color::Black);
}

void Display::Full_Gameview()
{
	//note: clear for now, show top and bottom strips later
	gui->Clear_Screen();

	//show level
	world->Show();
}

void Display::Header(const char *txt)
{
	gui->Clear_Screen();
	Centered_Text(txt, 0, Color::Black);
}

void Display::Keycode_Text(int key)
{
	const char *ch=0;

	//make some keyboard commands prettier than in curses
	switch (key)
	{
		case KEY_LEFT: ch="Left"; break;
		case KEY_RIGHT: ch="Right"; break;
		case KEY_DOWN: ch="Down"; break;
		case KEY_UP: ch="Up"; break;
		case ' ': ch="Space"; break;
		default: ch=keyname(key); break;
	}
	
	if (ch!=0)
		gui->Write_Text(ch);
	else
		gui->Write_Text("Null");	
}

void Display::Keybinds()
{
	Header("Keyboard commands");

	keybinds->Show_List();

	Footer("Backspace");
	wait_key();
}

void Display::Version()
{
	gui->Write_Text("Version 0.0.1");
}

void Display::Tile_Info(Tile &t, Element &e)
{
	const char *p=0;

	if (t.being!=0)
	{
		p="Creature";
	}

	if (t.obj!=0)
	{
		p="Object";
	}

	if (t.item!=0)
	{
		p="Item";
	}

	if (p==0)
		p=e.Get_Name();

	string s=format("'{}' Room: {}     ", p, e.room_id);

	gui->Write_Text(s.c_str());
}

void Display::Title_Screen()
{
	gui->Clear_Screen();
	gui->Set_Font_Color(Color::Cyan);

	//draw the logo
	int dx=(gui->Get_Width()-Title_Width)/2;
	int index=0;
	for (int y=0; y<Title_Height; y++)
	{
		gui->GotoXY(dx, y);
		
		for (int x=0; x<Title_Width; x++)
		{
			const char ch=title_data[index++];
			gui->Put_Char(ch);
		}
	}

	//show version
	gui->GotoXYC(dx, Title_Height, Color::Blue);
	Version();

	//show menu and copyright note
	const int screen_height=gui->Get_Height();

	dx+=10;
	int dy=screen_height-3;

	gui->Set_Font_Color(Color::White);
	gui->Write_Text_To(dx, dy-2, "p) Play");
	gui->Write_Text_To(dx, dy-1, "k) Keyboard commands");
	gui->Write_Text_To(dx, dy, "q) Quit");

	gui->Set_Font_Color(Color::Blue);
	gui->Write_Centered_Text(screen_height-1,
		"Copyright 2009-2026 Paul K. Pekkarinen");
}

