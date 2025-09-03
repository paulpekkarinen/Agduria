//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include <format>
#include <string>
#include "display.h"
#include "element.h"
#include "gameview.h"
#include "gui.h"
#include "level.h"
#include "terrain.h"
#include "tile.h"

using std::format;
using std::string;

Gameview::Gameview(Level *l, const Rectangle &r)
	: Tile_Map(l->Get_Width(), l->Get_Height()), lvl(l), view(r)
{
	camera.Set_Location(5, 5); //note: test location
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

void Gameview::Show(const Coords &actor)
{
	const int mapwidth=lvl->Get_Width();
	const int mapheight=lvl->Get_Height();

	//check horizontal size
	const int a=view.width-mapwidth;
	if (a>=0) //smaller than view: center
	{
		camera.x=view.x+(a/2);
	}
	else //bigger than view
	{
		//scroll view if near edges
		const int dx=actor.x-camera.x;
		
		if (dx<Horizontal_Limit)
		{
			camera.x-=Horizontal_Limit;
			Clamp_Camera_X();
		}
		else
		{
			if (dx>=view.width-Horizontal_Limit)
			{
				camera.x+=Horizontal_Limit;
				Clamp_Camera_X();
			}
		}
	}

	//check vertical size
	const int b=view.height-mapheight;
	if (b>=0)
	{
		camera.y=view.y+(b/2);
	}
	else
	{
		//scroll view if near edges
		const int dy=actor.y-camera.y;

		if (dy<Vertical_Limit)
		{
			camera.y-=Vertical_Limit;
			Clamp_Camera_Y();
		}
		else
		{
			if (dy>=view.height-Vertical_Limit)
			{
				camera.y+=Vertical_Limit;
				Clamp_Camera_Y();
			}
		}
	}

	Coords c(camera.x, camera.y);
	
	for (int y=view.y; y<view.y+view.height; y++)
	{
		//set display cursor location start per line
		gui->GotoXY(view.x, y);

		for (int x=view.x; x<view.x+view.width; x++)
		{
			Display_Tile(c);
			c.x++; //increase level location also
		}

		//next row
		c.x=camera.x;
		c.y++;
	}
}

void Gameview::Show_Debug_Location(const Coords &c)
{
	gui->Default_Color();

	gui->Goto_Last_Line();
	string s=format("Pos: {},{} Camera: {}, {}   ",
		c.x, c.y, camera.x, camera.y);
	gui->Write_Text(s.c_str());

	Tile &t=Get_Tile(c);
	Element e=lvl->Get_Terrain(c.x, c.y);

	display.Tile_Info(t, e);	
}

void Gameview::Clamp_Camera_X()
{
	if (camera.x<0) camera.x=0;
	else
	{
		const int w=lvl->Get_Width();
		const int gw=view.width;
		
		if (camera.x+gw>w) camera.x=w-gw;
	}
}

void Gameview::Clamp_Camera_Y()
{
	if (camera.y<0) camera.y=0;
	else
	{
		const int h=lvl->Get_Height();
		const int gh=view.height;
		if (camera.y+gh>h) camera.y=h-gh;
	}
}

void Gameview::Clamp_Camera()
{
	Clamp_Camera_X();
	Clamp_Camera_Y();
}

void Gameview::Center(const Coords &c)
{
	camera.Set_Location(c.x-(view.width/2), c.y-(view.height/2));
	Clamp_Camera();
}

Rectangle Gameview::Get_Level_Size()
{
	return Rectangle(0, 0, lvl->Get_Width(), lvl->Get_Height());
}

Point Gameview::Get_Screen_Location(const Coords &c)
{
	return Point((c.x-camera.x)+view.x, (c.y-camera.y)+view.y);
}

void Gameview::Display_Tile(const Coords &c)
{
	Tile &t=Get_Tile(c);

	if (t.vision==Tile::Outside)
	{
		gui->Put_Char('?');
		return;
	}

	//show possible game object here
	if (t.Display())
		return;

	//last display terrain if no objects were shown
	lvl->Display_Terrain(c.x, c.y);
}

