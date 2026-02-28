//Agduria - Copyright (C) Paul Pekkarinen

//Unit game: Gameplay instance.

#pragma once

class Game
{
public:
	enum State_Type {Running, Exit};

private:
	int state;

public:
	Game();
	~Game();

	void Menu();
	void Run();
	void Set_State(int s);
};

extern Game *gameplay;
