//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "area.h"
#include "chart.h"
#include "terrain.h"

Area::Area(int t, Chart *dest_chart)
	: type(t), chart(dest_chart)
{

}

//Check area of the area to determine if it can be created on its
//current location.
bool Area::Check()
{
	for (int dy=y; dy<y+height; dy++)
	{
		for (int dx=x; dx<x+width; dx++)
		{
			if (Is_Forbidden(dx, dy)) return false;
		}
	}

	return true;
}

bool Area::Is_Forbidden(int dx, int dy)
{
	const int masktype=chart->Get_Mask_Type(dx, dy);

	//don't create over object type terrains (these are stairs mainly)
	if (masktype==Mask::Object)
		return true;

	const int room_id=chart->Get_Room_Id(dx, dy);

	switch (type)
	{
		case Opening:
			//openings can be created only on wall areas
			if (room_id!=-1) return true;
			if (masktype==Mask::Floor) return true;
		break;
		case Room:
			//another room's area found (includes only the floor area of room,
			//walls can overlap)
			if (room_id!=-1 && masktype==Mask::Floor)
				return true;
		break;
		default: break;
	}

	return false;
}
