//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit gender: Gender of a creature.

#pragma once

class Gender
{
public:
	enum Gender_Type {None, Male, Female, Both, Max_Genders};

private:
	int gender;

public:
	Gender() : gender(None) { }
	Gender(int g);

	int Get() const { return gender; }

	const char *Get_String();
};
