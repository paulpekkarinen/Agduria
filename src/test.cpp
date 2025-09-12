//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include <format>
#include <string>
#include "gui.h"
#include "input.h"
#include "soul.h"
#include "test.h"

using std::format;
using std::string;

void test_souls();

void run_current_test()
{
	test_souls();
}

void test_souls()
{
	gui->Clear_Screen();

	for (int t=0; t<20; t++)
	{
		Soul soul(t);
		string s=format("{}: {}, g: {}\n",
			soul.type.Get_Family_Name(),
			soul.type.Get_Name(),
			soul.gender.Get_String());

		gui->Write_Text(s.c_str());	
	}

	wait_key();
}

