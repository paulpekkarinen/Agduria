//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include <cstdio>
#include "stairs.h"
#include "gui.h"
#include "terrain.h"

Stairs::Stairs(int i, int t, int did, int dsi)
	: id(i), terrain_type(t), dest_level_id(did), dest_stairs_id(dsi)
{

}

void Stairs::Show_Info()
{
	char ot[80];

	Terrain tt(terrain_type);

	sprintf(ot, "type: %s, sid: %d, dst lvl: %d, dst s: %d\r",
		tt.Get_Name(), id, dest_level_id, dest_stairs_id);

	gui->Write_Text(ot);
}
