//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include <curses.h>
#include "debug.h"
#include "display.h"
#include "gui.h"

Debug debug; //global instance

void Debug::Menu()
{
	bool loop=true;

	while (loop)
	{
		display.Header("Debug commands");

		gui->Default_Color();
		gui->Write_Text_To(0, 2,
			"t) terminal info");

		const int ch=getch();

		switch (ch)
		{
			case 't': Show_Terminal_Info(); break;
			case KEY_ESC: loop=false; break;
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

	getch();
}
