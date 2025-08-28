//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include <curses.h>
#include <string>
#include "display.h"
#include "input.h"
#include "keybinds.h"
#include "gui.h"
#include "world.h"

using std::string;

Display display; //global instance

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

	Footer("Space");
	wait_key();
}

void Display::Version()
{
	gui->Write_Text("Version 0.0.1");
}

