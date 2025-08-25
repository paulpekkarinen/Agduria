//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit lvlnode: Level (node) in world structure data.

#pragma once

#include <vector>
#include "stairs.h"

class Level;

class Node
{
private:
	int id; //id of the level
	int section; //which section this level is located
	int theme; //level's theme
	Level *lvl; //if not yet visited then this is zero
	std::vector<Stairs> stairs_list; //list of connections to other level(s)

	typedef std::vector<Stairs>::iterator siter;

public:
	Node(int i, int sec, int th);
	~Node();

	int Get_Id() const { return id; }
	int Get_Section() const { return section; }
	int Get_Theme() const { return theme; }

	Level *Enter();
	void Add_Stairs(Stairs &st);
	void Show_Info();
};
