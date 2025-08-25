//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "rect.h"
#include "region.h"

Region::Region(int t)
	: type(t)
{

}

Rectangle Region::Get_Random_Size()
{
	return Rectangle(0, 0, 80, 25);
}
