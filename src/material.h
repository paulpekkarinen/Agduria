//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit material: Material of something.

#pragma once

//How fast the material will burn if at all.
namespace Combust
{
	enum Burn_Rate {None, Slow, Medium, Fast};
}

class Material
{
public:
	enum Material_Type {None, Wood, Stone, Straw, Paper, Rope, Gold, Silver,
		Copper, Brass, Iron, Leather, Flesh, Clay, Glass, Gelatine, Dirt, Fog,
		Dust, Ice, Energy, Steam, Lava, Water, Max_Materials};

private:
	int material;

public:
	Material() : material(None) { }
	Material(int m);

	int Get() const { return material; }

	const char *Get_String();
	int Get_Burn_Rate();
};
