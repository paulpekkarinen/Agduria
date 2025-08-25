//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit size: Size of something.

#pragma once

class Size
{
public:
	enum Size_Type {None, Tiny, Small, Medium, Average, Large, Huge, Giant,
		Gargantuan, Max_Sizes};

private:
	int size;

public:
	Size() : size(None) { }
	Size(int s);

	int Get() const { return size; }

	const char *Get_String();
};
