//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit stairs: Stairs connection between levels.

#pragma once

//Stairs create connections to other levels, when stairs are entered
//the game knows what level and stairs is the destination.
class Stairs
{
private:
	int id;
	int terrain_type;
	int dest_level_id;
	int dest_stairs_id;

public:
	Stairs(int i, int t, int did, int dsi);

	int Get_Destination_Level() const { return dest_level_id; }
	int Get_Destination_Stairs() const { return dest_stairs_id; }
	int Get_Terrain_Type() const { return terrain_type; }

	void Show_Info();
};
