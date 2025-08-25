//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit rank: Rank of a creature.

#pragma once

class Rank
{
public:
	enum Rank_Type {None, Soldier, Captain, Sergeant, Lieutenant,
		Queen, Lord, King, Master, Demi, Arch, High, Vampire, Mummy, Zombie,
		Were, Rabid, Max_Ranks};

	enum Rank_Place {Before, After, Attached_Before, Line_Attached};

private:
	int rank;

public:
	Rank() : rank(None) { }
	Rank(int r);

	int Get() const { return rank; }

	int Get_Place();
	const char *Get_String();
};
