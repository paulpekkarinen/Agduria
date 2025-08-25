//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include <cstdio>
#include <cstdlib>
#include "codex.h"

void panic_exit(const char *txt)
{
	printf("Error: %s.", txt);
	exit(EXIT_FAILURE);
}

int round_float(float f)
{
	return (int)(f+0.5);
}
