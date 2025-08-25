//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit age: Age specifier for a creature, how old or developed it is.

#pragma once

class Age
{
public:
	enum Age_Id {None, Cub, Pup, Hatchling, Baby, Senior, Ancient, Max_Ages};

private:
	int age;

public:
	Age(int a) : age(a) { }

	int Get() const { return age; }
	const char *Get_String();
	int Get_Name_Location();
};
