//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include <curses.h>
#include "display.h"
#include "input.h"

void wait_key()
{
	getch();
}

void wait_footer_key(const char *txt)
{
	display.Footer(txt);
	wait_key();
}

