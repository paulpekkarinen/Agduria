//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit flavor: Flavor of a creature.

#pragma once

class Flavor
{
public:
	enum Flavor_Type {None, Killer, Carnivorous, Electric, Acid, Quivering,
		Floating, Freezing, Shocking, Flaming, Winged, Gas, Spotted, Shimmering,
		Fire, Frost, Winter, Storm, Wood, Mountain, Hill, Rock, Sewer, Cave,
		Plains, Forest, Blue, Ochre, White, Gray, Black, Silver, Yellow, Red,
		Orange, Green, Brown, Violet, Golden, Max_Flavors};

private:
	int flavor;

public:
	Flavor() :  flavor(None) { }
	Flavor(int f);

	int Get() const { return flavor; }

	const char *Get_String();
};
