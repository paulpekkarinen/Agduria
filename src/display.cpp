//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include <string>
#include "display.h"
#include "gui.h"

using std::string;

Display display; //global instance

void Display::Header(const char *txt)
{
	gui->Clear_Screen();

	string s("-=[ ");
	s.append(txt);
	s.append(" ]=-");

	gui->Clear_Line(0, Color::Black);

	const int w=s.size();

	int x=(gui->Get_Width()-w)/2;

	gui->Write_Text_To(x, 0, s.c_str());	
}

void Display::Version()
{
	gui->Write_Text("Version 0.0.1");
}
