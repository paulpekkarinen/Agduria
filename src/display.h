//Agduria - Copyright (C) Paul Pekkarinen

//Unit display: Display something.

#pragma once

struct Element;
struct Tile;

class Display
{
public:
	//where text display begins usually on empty screen
	static const int Text_Content_X=0;
	static const int Text_Content_Y=2;
	 
private:
	static const int Title_Width=37;
	static const int Title_Height=7;
	//+1 for the trailing zero
	static const char title_data[(Title_Width*Title_Height)+1];
	
	void Centered_Text(const char *txt, int line, int color);
	
public:
	void Tile_Info(Tile &t, Element &e);
	void Footer(const char *txt);
	void Full_Gameview(); //redraw gameview
	void Header(const char *txt);
	void Keycode_Text(int key);
	void Keybinds();
	void Title_Screen();
	void Version();
};

extern Display display;

