//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "size.h"

struct Size_Data
{
	const char *name;
};

const Size_Data size_data[Size::Max_Sizes]=
{
	{"none"},
	{"tiny"},
	{"small"},
	{"medium"},
	{"average"},
	{"large"},
	{"huge"},
	{"giant"},
	{"gargantuan"}
};

Size::Size(int s)
	: size(s)
{

}

const char *Size::Get_String()
{
	return size_data[size].name;
}
