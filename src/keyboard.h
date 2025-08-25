//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit keyboard: Raw keyboard input.

#pragma once

#include "keycode.h"

class Keyboard
{
public:
	Keycode Get_Key();
	char Get_Ascii();
};

extern Keyboard *keyboard;
