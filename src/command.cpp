//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include <curses.h>
#include "command.h"

struct Command_Data
{
	const char *name; //name of the command
	int def_key; //default key code
	bool redraw_after; //redrawn whole gameview after command use
};

const Command_Data cmd_data[Command::Max_Commands]=
{
	{"Move west", KEY_LEFT, false},
	{"Move east", KEY_RIGHT, false},
	{"Move north", KEY_UP, false},
	{"Move south", KEY_DOWN, false},
	{"Exit game", 'Q', false},
	{"Remake level", 'R', true},
	{"Debug menu", 'D', true},
	{"Keyboard commands", 'K', true},
	{"Unknown", '?', false}
};

Command::Command(int c)
	: cmd(c)
{

}

int Command::Get_Default_Keycode()
{
	return cmd_data[cmd].def_key;
}

const char *Command::Get_Name()
{
	return cmd_data[cmd].name;
}

bool Command::Redraw_After() const
{
	return cmd_data[cmd].redraw_after;
}

