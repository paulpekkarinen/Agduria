//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include <curses.h>
#include "command.h"

struct Command_Data
{
	const char *name; //name of the command
	int def_key; //default key code
};

const Command_Data cmd_data[Command::Max_Commands]=
{
	{"Move west", KEY_LEFT},
	{"Move east", KEY_RIGHT},
	{"Move north", KEY_UP},
	{"Move south", KEY_DOWN},
	{"Exit game", 'Q'},
	{"Remake level", 'R'},
	{"Debug menu", 'D'},
	{"Unknown", '?'}
};

Command::Command(int c)
	: cmd(c)
{

}

int Command::Get_Default_Keycode()
{
	return cmd_data[cmd].def_key;
}
