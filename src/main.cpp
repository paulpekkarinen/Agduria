//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit main: Entry point of the program.

#include <cstdlib>
#include <curses.h>
#include <locale.h>
#include "game.h"
#include "gui.h"
#include "keybinds.h"
#include "keyboard.h"
#include "resource.h"
#include "rng.h"

//Some of the global instances, externs of these are found in each system's
//header file. World and Player instances are handled by 'Game' class.
Game *gameplay; //current game
Gui *gui; //graphics output routines
Random_Generator *rng; //randon number generator
Keybindings *keybinds; //keyboard bindings
Keyboard *keyboard; //keyboard input

int main(int argc, char *argv[])
{
	//start up curses, set some defaults
	setlocale(LC_ALL, "");
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);

	//check and initialize colors for curses
	if (has_colors()==FALSE || can_change_color()==FALSE)
	{
		printf("This terminal does not support colors that can be changed.");
		return EXIT_FAILURE;
	}

	start_color();
	Resource rc;
	rc.Initialize_Colors();

	//create random number generator
	rng=new Random_Generator;

	//get the size of the console window and store the size to gui class
	int w, h;
	getmaxyx(stdscr, h, w);
	gui=new Gui(w, h);

	//create keyboard handling classes
	keyboard=new Keyboard;
	keybinds=new Keybindings;

	//create and run game instance (at the moment there is no title screen)
	gameplay=new Game;
	gameplay->Run(); //run game until exit
	delete gameplay;

	//delete subsystems in reverse order, just to be cool
	delete keybinds;
	delete keyboard;
	delete gui;
	delete rng;

	//clear curses
	endwin();

	return EXIT_SUCCESS;
}
