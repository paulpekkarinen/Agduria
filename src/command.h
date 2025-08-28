//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit command: Gameplay commands for characters.

#pragma once

class Command
{
public:
	enum Command_Type
	{
		Move_West,
		Move_East,
		Move_North,
		Move_South,
		Exit_Game,
		Remake_Level,
		Debug_Menu,
		Keyboard_Commands,
		Unknown,
		Max_Commands
	};

private:
	int cmd;

public:
	Command() : cmd(Unknown) { }
	Command(int c);

	int Get() const { return cmd; }
	const char *Get_Name();

	int Get_Default_Keycode();
	bool Redraw_After() const;
};

