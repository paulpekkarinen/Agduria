//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include <curses.h>
#include "debug.h"
#include "display.h"
#include "gameview.h"
#include "gui.h"
#include "input.h"
#include "player.h"

Debug debug; //global instance

void Debug::Menu()
{
	bool loop=true;

	while (loop)
	{
		display.Header("Debug commands");
		display.Footer("Backspace");

		gui->Default_Color();
		gui->Write_Text_To(0, Display::Text_Content_Y,
			"t) terminal info\n"
			"v) view level\n"
		);

		const int ch=getch();

		switch (ch)
		{
			case 't': Show_Terminal_Info(); break;
			case 'v': View_Level(); break;
			case KEY_BACKSPACE: loop=false; break;
			default: break;
		}
	}
}

void Debug::Show_Terminal_Info()
{
	display.Header("Terminal info");

	gui->Default_Color();
	gui->Write_Text_To(0, 2, "Colors:\n");
	
	for (int t=1; t<Color::Max_Colors; t++)
	{
		Color c(t);
		gui->Set_Font_Color(t);
		gui->GotoXY(0, t+3);
		gui->Write_Text(c.Get_Name());
	}

	wait_footer_key("Backspace");
}

void Debug::View_Level()
{
	display.Header("View level");

	bool loop=true;
	Coords pc=player->Get_Location();
	curs_set(1); //show cursor while viewing level

	Rectangle r=gameview->Get_Level_Size();

	while (loop)
	{
		gameview->Show(pc);
		gameview->Show_Debug_Location(pc);

		Point p=gameview->Get_Screen_Location(pc);
		gui->GotoXY(p.x, p.y);

		const int ch=getch();

		switch (ch)
		{
			case KEY_DOWN: pc.y++; break;
			case KEY_UP: pc.y--; break;
			case KEY_LEFT: pc.x--; break;
			case KEY_RIGHT: pc.x++; break;
			case KEY_BACKSPACE: loop=false; break;
			default: break;
		}

		//limit locations inside level
		if (pc.x<0) pc.x=0;
		else
		{
			if (pc.x>=r.width)
				pc.x=r.width-1;
		}

		if (pc.y<0) pc.y=0;
		else
		{
			if (pc.y>=r.height)
				pc.y=r.height-1;
		}		
	}

	curs_set(0);
}

