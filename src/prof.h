//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit prof: Character class of a creature.

#pragma once

class Profession
{
public:
	enum Profession_Type {None, Mage, Shaman, Priest, Priestess, Watchman,
		Doctor, Nurse, Shopkeeper, Guard, Prisoner, Kop, Prophet, Oracle,
		Archaeologist, Barbarian, Amazonian, Caveman, Cavewoman, Healer, Knight,
		Monk, Nun, Ranger, Rogue, Samurai, Tourist, Warlock, Valkyrie, Wizard,
		Witch, Max_Professions};

private:
	int prof;

public:
	Profession() : prof(None) { }
	Profession(int p);

	int Get() const { return prof; }

	int Get_Gender();
	const char *Get_String(int g);
};
