//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit family: Basic creature type.

#pragma once

//Basic creature type which has some generic data for that
//creature derived to species.
class Family
{
public:
	enum Family_Type {Insect, Bird, Canine, Mariner, Mammal,
		Feline, Humanoid, Testudinidae, Reptile, Fungi,
		Phantom, Undead, Vermes, Max_Families};

private:
	int family;

public:
	Family() : family(Bird) { }
	Family(int f);

	const char *Get_Family_Name();
	int Get_Preferred_Gender();
};

