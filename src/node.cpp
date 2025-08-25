//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include <cstdio>
#include "gui.h"
#include "level.h"
#include "node.h"
#include "region.h"

Node::Node(int i, int sec, int th)
	: id(i), section(sec), theme(th), lvl(0)
{

}

Node::~Node()
{
	if (lvl!=0)
		delete lvl;
}

void Node::Add_Stairs(Stairs &st)
{
	stairs_list.push_back(st);
}

Level *Node::Enter()
{
	if (lvl==0)
	{
		Region rg(theme);
		Rectangle r=rg.Get_Random_Size();

		//create new level if not yet visited
		lvl=new Level(r.width, r.height, theme, id);
		lvl->Create();
	}

	return lvl;
}

void Node::Show_Info()
{
	char ot[80];

	char v;
	if (lvl!=0)
		v='Y';
	else
		v='N';

	sprintf(ot, "ID %d, Section: %d, Theme %d, Visited: %c, Stairs:\r",
		id, section, theme, v);
	gui->Write_Text(ot);

	for (siter i=stairs_list.begin(); i!=stairs_list.end(); i++)
	{
		(*i).Show_Info();
	}
}
