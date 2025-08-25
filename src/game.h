//Agduria - Copyright 2009-2025 Paul Pekkarinen

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

	void Run();
	void Set_State(int s);
};

extern Game *gameplay;
