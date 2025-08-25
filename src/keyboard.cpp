//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include <curses.h>
#include "keyboard.h"

Keycode Keyboard::Get_Key()
{
	return Keycode(getch());
}

char Keyboard::Get_Ascii()
{
	Keycode code=Get_Key();
	int k=code.key;

	//the default value is keycode mapped to char if it's an ascii value
	char rv;
	if (k<128)
		rv=(char)k;
	else
		rv=0; //zero if not an ascii value

	return rv;
}
