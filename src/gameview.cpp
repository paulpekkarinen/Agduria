//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "gameview.h"
#include "gui.h"
#include "level.h"
#include "terrain.h"
#include "tile.h"

Gameview::Gameview(Level *l, const Rectangle &r)
	: Tile_Map(l->Get_Width(), l->Get_Height()), lvl(l), view(r)
{

}

//If 'c' is outside the level this has no effect since the object
//is placed in the 'dummy' tile.
void Gameview::Put_Creature(Creature *b, const Coords &c)
{
	Tile &t=Get_Tile(c);
	t.being=b;
}

void Gameview::Put_Item(Item *i, const Coords &c)
{
	Tile &t=Get_Tile(c);
	t.item=i;
}

void Gameview::Put_Object(Object *o, const Coords &c)
{
	Tile &t=Get_Tile(c);
	t.obj=o;
}

void Gameview::Show()
{
	Coords c(camera.x, camera.y);

	for (int y=view.y; y<view.y+view.height; y++)
	{
		//set display cursor location start per line
		gui->GotoXY(view.x, y);

		for (int x=view.x; x<view.x+view.width; x++)
		{
			lvl->Display_Tile(c, this);

			c.x++; //map location has to be increased as well
		}

		c.y++;
		c.x=camera.x;
	}
}
