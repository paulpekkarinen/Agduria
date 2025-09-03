//Agduria - Copyright 2009-2025 Paul Pekkarinen

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
	void Centered_Text(const char *txt, int line, int color);
	
public:
	void Tile_Info(Tile &t, Element &e);
	void Footer(const char *txt);
	void Full_Gameview(); //redraw gameview
	void Header(const char *txt);
	void Keycode_Text(int key);
	void Keybinds();
	void Version();
};

extern Display display;

