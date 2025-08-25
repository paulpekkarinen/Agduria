//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "debug.h"
#include "gui.h"

void Debug::Show_Terminal_Info()
{
	gui->Clear_Screen();

	for (int t=1; t<Color::Max_Colors; t++)
	{
		Color c(t);
		gui->Set_Font_Color(t);
		gui->GotoXY(0, t);
		gui->Write_Text(c.Get_Name());
	}
}
