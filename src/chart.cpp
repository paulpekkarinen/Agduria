//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include <cmath>
#include "chart.h"
#include "coords.h"
#include "element.h"
#include "rect.h"
#include "rng.h"
#include "terrain.h"
#include "way.h"

Chart::Chart(int w, int h)
	: width(w), height(h), volume(w*h)
{
	data=new Element[volume];
	Clear();
}

Chart::~Chart()
{
	delete[] data;
}

void Chart::Clear()
{
	Clear(Terrain::Void);
}

//Check if this area is empty for room.
bool Chart::Check_Room_Area(const Rectangle &a)
{
	for (int sy=a.y; sy<a.y+a.height; sy++)
	{
		for (int sx=a.x; sx<a.x+a.width; sx++)
		{
			//create rooms only on walls for now
			if (Get_Mask_Type(sx, sy)!=Mask::Wall)
				return false;
		}
	}

	return true;
}

void Chart::Clear(int v)
{
	for (int t=0; t<volume; t++)
		data[t].Clear(v);
}

//Assumes valid location.
void Chart::Display_Terrain(int x, int y)
{
	data[y*width+x].Display();
}

bool Chart::Is_Next_To_Room(int x, int y)
{
	Coords c(x, y);
	Coords d;
	int a=0;

	for (int t=Way::North; t<Way::North_West; t++)
	{
		d=c;
		d.Move_Direction(t);
		if (Get_Mask_Type(d.x, d.y)==Mask::Wall) a++;
	}

	if (a>=2) return true;
	return false;
}

bool Chart::Is_Bedrock(int x, int y)
{
	if (Get_Terrain_Type(x, y)==Terrain::Bedrock)
		return true;

	return false;
}

bool Chart::Is_Outside(int x, int y)
{
	if (x>=width || y>=height || x<0 || y<0) return true;
	return false;
}

bool Chart::Is_Floor(int x, int y)
{
	Element e=Get_Terrain(x, y);
	if (e.Get_Mask()==Mask::Floor)
		return true;

	return false;
}

bool Chart::Is_Wall(int x, int y)
{
	Element e=Get_Terrain(x, y);
	if (e.Get_Mask()==Mask::Wall)
		return true;

	return false;
}

int Chart::Get_Mask_Type(int x, int y)
{
	Element e=Get_Terrain(x, y);
	return e.Get_Mask();
}

Element Chart::Get_Terrain(int x, int y)
{
	Element e; //if outside returns 'void' terrain

	if (Is_Outside(x, y)==false)
		e=data[y*width+x];

	return e;
}

int Chart::Get_Terrain_Type(int x, int y)
{
	Element e=Get_Terrain(x, y);
	return e.type;
}

int Chart::Get_Room_Id(int x, int y)
{
	if (Is_Outside(x, y)==false)
		return data[y*width+x].room_id;

	return -1;
}

void Chart::Put_Room_Mask(int x, int y, int id)
{
	if (Is_Outside(x, y))
		return;

	data[y*width+x].room_id=id;
}

bool Chart::Put_Terrain(int type, int x, int y)
{
	if (Is_Outside(x, y))
		return false;
	data[y*width+x].type=type;
	return true;
}

bool Chart::Put_Terrain_Over(int type, int over, int x, int y)
{
	if (Get_Terrain(x, y)==over)
		return Put_Terrain(type, x, y);
	return false;
}

int Chart::Get_Random_X(int width_clip)
{
	return rng->Get(width-width_clip-1)+1;
}

int Chart::Get_Random_Y(int height_clip)
{
	return rng->Get(height-height_clip-1)+1;
}

void Chart::Draw_Rectangle(int type, const Rectangle &a)
{
	int sy=a.y;

	for (int sx=a.x; sx<a.x+a.width; sx++)
		Put_Terrain(type, sx, sy);

	for (int sh=0; sh<=(a.height-2); sh++)
	{
		Put_Terrain(type, a.x, sy);
		Put_Terrain(type, a.x+a.width-1, sy);
		sy++;
	}

	for (int sx=a.x; sx<a.x+a.width; sx++)
		Put_Terrain(type, sx, sy);
}

void Chart::Draw_Box(int type, const Rectangle &a)
{
	for (int sy=a.y; sy<a.y+a.height; sy++)
	{
		for (int sx=a.x; sx<a.x+a.width; sx++)
			Put_Terrain(type, sx, sy);
	}
}

void Chart::Draw_Box_Over(int type, int over, const Rectangle &a)
{
	for (int sy=a.y; sy<a.y+a.height; sy++)
	{
		for (int sx=a.x; sx<a.x+a.width; sx++)
		{
			Put_Terrain_Over(type, over, sx, sy);
		}
	}
}

void Chart::Draw_Room_Mask(const Rectangle &r, int id)
{
	for (int sy=r.y; sy<r.y+r.height; sy++)
	{
		for (int sx=r.x; sx<r.x+r.width; sx++)
		{
			Put_Room_Mask(sx, sy, id);
		}
	}
}

void Chart::Put_Data(int pos, int type)
{
	if (pos>=0 && pos<volume)
		data[pos]=type;
}

Element Chart::Get_Data(int pos)
{
	if (pos>=0 && pos<volume)
		return data[pos];
	return -1;
}

void Chart::Ellipse_Quad_Line(int sx, int sy, int x, int y, int type)
{
	//draws part of a filled ellipse
	int dx=sx+x, dy=sy+y, dx2=sx-x, dy2=sy-y;

	for (int t=dy2; t<=dy; t++)
	{
		if (t<height && t>-1)
		{
			//fill right side of the ellipse
			if (dx<width && dx>-1) Put_Terrain(type, dx, t);
			//fill left side
			if (dx2<width && dx2>-1) Put_Terrain(type, dx2, t);
		}
	}
}

void Chart::Draw_Ellipse(int xc, int yc, int radius_x, int radius_y, int type)
{
	radius_x=std::abs(radius_x);
	radius_y=std::abs(radius_y);

	float aa=(float)(radius_x*radius_x);
	float bb=(float)(radius_y*radius_y);
	float aa2=(aa*2);
	float bb2=(bb*2);

	int x=0, y=radius_y;
	float fx=0.0f, fy=(aa2*(float)radius_y);

	float p=(bb-(aa*(float)radius_y)+(0.25f*aa)+0.5f);

	Ellipse_Quad_Line(xc, yc, x, y, type);

	while (fx<fy)
	{
		x++; fx+=bb2;

		if (p<0) p+=(fx+bb);
		else { y--; fy-=aa2; p+=(fx+bb-fy); }

		Ellipse_Quad_Line(xc, yc, x, y, type);
	}

	float nfx=(float)x;
	float nfy=(float)y;

	//note: this may now buggy with wrong set of parentheses
	p=(bb*(nfx+0.5f)*(nfx+0.5f))+(aa*((nfy-1)*(nfy-1))-(aa*bb)+0.5f);

	while(y>0)
	{
		y--; fy-=aa2;

		if (p>=0) p+=(aa-fy);
		else { x++; fx+=bb2; p+=(fx+aa-fy); }

		Ellipse_Quad_Line(xc, yc, x, y, type);
	}
}
