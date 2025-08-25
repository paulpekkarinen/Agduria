//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit keybinds: List of keys bound to game commands.

#pragma once

#include <map>
#include "keycode.h"

//Keycode and associated command type.
struct Key_And_Command
{
	Keycode keycode;
	int cmd;

	Key_And_Command() : cmd(0) { }
	Key_And_Command(const Keycode &k, int c) : keycode(k), cmd(c) { }
};

//Keyboard bindings, a key combination mapped to a command.
class Keybindings
{
private:
	std::map<Keycode, int> keys;

	void Insert_Command(const Key_And_Command &kac);

public:
	Keybindings();

	int Get_Command(const Keycode &kc);
};

extern Keybindings *keybinds;
