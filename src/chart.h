//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit chart: Terrain map.

#pragma once

struct Element;
struct Rectangle;
struct Terrain;

class Chart
{
private:
	Element *data; //2D array of terrain
	int width;
	int height;
	int volume; //size: width x height

	void Ellipse_Quad_Line(int sx, int sy, int x, int y, int type);
	Element Get_Data(int pos);
	void Put_Data(int pos, int type);
	void Put_Room_Mask(int x, int y, int id);

protected:
	void Display_Terrain(int x, int y);

public:
	Chart(int w, int h);
	~Chart();

	bool Check_Room_Area(const Rectangle &a);
	int Get_Height() const { return height; }
	int Get_Mask_Type(int x, int y);
	Element Get_Terrain(int x, int y);
	int Get_Terrain_Type(int x, int y);
	int Get_Random_X(int width_clip);
	int Get_Random_Y(int height_clip);
	int Get_Room_Id(int x, int y);
	int Get_Width() const { return width; }
	bool Is_Bedrock(int x, int y);
	bool Is_Floor(int x, int y);
	bool Is_Next_To_Room(int x, int y);
	bool Is_Outside(int x, int y);
	bool Is_Wall(int x, int y);

	void Clear();
	void Clear(int v);

	void Draw_Box(int type, const Rectangle &a);
	void Draw_Box_Over(int type, int over, const Rectangle &a);
	void Draw_Ellipse(int xc, int yc, int radius_x, int radius_y, int type);
	void Draw_Rectangle(int type, const Rectangle &a);
	void Draw_Room_Mask(const Rectangle &r, int id);

	bool Put_Terrain(int type, int x, int y);
	bool Put_Terrain_Over(int type, int over, int x, int y);
};
