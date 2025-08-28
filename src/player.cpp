//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "command.h"
#include "debug.h"
#include "display.h"
#include "game.h"
#include "gui.h"
#include "player.h"
#include "species.h"
#include "way.h"
#include "world.h"

Player::Player(const Coords &c)
	: Creature(c, Species::Humanoid)
{

}

void Player::Proceed(int d)
{
	dir=d;
	Move(dir);
}

void Player::Run_Command(Command &c)
{
	switch (c.Get())
	{
		case Command::Move_East: Proceed(Way::East); break;
		case Command::Move_West: Proceed(Way::West); break;
		case Command::Move_South: Proceed(Way::South); break;
 		case Command::Move_North: Proceed(Way::North); break;

		case Command::Exit_Game: gameplay->Set_State(Game::Exit); break;
		case Command::Remake_Level: world->Remake_Current_Level(); break;
		case Command::Debug_Menu: debug.Menu(); break;
		case Command::Keyboard_Commands: display.Keybinds(); break;
		default: break;
	}
}

void Player::Draw()
{
	gui->Put_Char('@', Color::White);
}
