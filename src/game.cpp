//Agduria - Copyright (C) Paul Pekkarinen

#include "command.h"
#include "display.h"
#include "game.h"
#include "gui.h"
#include "keybinds.h"
#include "keyboard.h"
#include "player.h"
#include "world.h"

//world and player instances are global
World *world;
Player *player;

Game::Game()
	: state(Running)
{
	world=new World;

	//use outside map coordinates for player before he is placed into
	//the generated level, this is fine
	Coords c(-1, -1, -1);
	player=new Player(c);
}

Game::~Game()
{
	delete world;
	delete player;
}

void Game::Menu()
{
	bool loop=true;

	while (loop)
	{
		display.Title_Screen();

		switch (keyboard->Get_Ascii())
		{
			case 'p':
				Run();
				loop=false; //exit directly in test version
			break;
			case 'k': display.Keybinds(); break;
			case 'q': loop=false; break;
			default: break;
		}
	}
}

void Game::Run()
{
	bool loop=true;
	bool redraw=true;
	Command cmd;

	gui->Clear_Screen();

	world->Arrival();

	while (loop)
	{
		if (redraw)
			display.Full_Gameview();
		else
			world->Show();

		//get command from keyboard code
		cmd=keybinds->Get_Command(keyboard->Get_Key());

		//process the command
		player->Run_Command(cmd);

		redraw=cmd.Redraw_After();

		if (state==Exit)
			loop=false;
	}
}

void Game::Set_State(int s)
{
	state=s;
}
