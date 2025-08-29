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
		display.Footer("Space");

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
			case ' ': loop=false; break;
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

	wait_footer_key("Space");
}

void Debug::View_Level()
{
	display.Header("View level");

	bool loop=true;
	Coords pc=player->Get_Location();

	while (loop)
	{
		gameview->Show(pc);
		gameview->Show_Debug_Location();
	
		const int ch=getch();

		switch (ch)
		{
			case ' ': loop=false; break;
			default: break;
		}		
	}	
}

