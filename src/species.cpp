//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "family.h"
#include "species.h"
#include "gui.h"

struct Species_Data
{
	const char *name;
	char ascii;
	int family;
};

Species_Data species_type[Species::Max_Species_Types]=
{
	{"ant", 'a', Family::Insect},
	{"bee", 'b', Family::Insect},
	{"centipede", 'c', Family::Insect},
	{"duck", 'd', Family::Bird},
	{"floating eye", 'e', Family::Phantom},
	{"fox", 'f', Family::Canine},
	{"gremlin", 'g', Family::Humanoid},
	{"hyena", 'h', Family::Canine},
	{"imp", 'i', Family::Phantom},
	{"jellyfish", 'j', Family::Mariner},
	{"komodo dragon", 'k', Family::Reptile},
	{"llama", 'l', Family::Mammal},
	{"mermaid", 'm', Family::Mariner},
	{"nymph", 'n', Family::Phantom},
	{"orc", 'o', Family::Humanoid},
	{"puma", 'p', Family::Feline},
	{"quagga", 'q', Family::Mammal},
	{"rat", 'r', Family::Mammal},
	{"spider", 's', Family::Insect},
	{"turtle", 't', Family::Testudinidae},
	{"unicorn", 'u', Family::Mammal},
	{"vulture", 'v', Family::Bird},
	{"wolf", 'w', Family::Canine},
	{"bug", 'x', Family::Insect},
	{"zokor", 'z', Family::Mammal},
	{"ape", 'A', Family::Humanoid},
	{"bat", 'B', Family::Mammal},
	{"centaur", 'C', Family::Phantom},
	{"dragon", 'D', Family::Reptile},
	{"elf", 'E', Family::Humanoid},
	{"fungus", 'F', Family::Fungi},
	{"giant", 'G', Family::Humanoid},
	{"horse", 'H', Family::Mammal},
	{"ikuturso", 'I', Family::Mariner},
	{"jackalope", 'J', Family::Mammal},
	{"kraken", 'K', Family::Mariner},
	{"lion", 'L', Family::Feline},
	{"mummy", 'M', Family::Undead},
	{"nephilim", 'N', Family::Humanoid},
	{"ogre", 'O', Family::Humanoid},
	{"pegasus", 'P', Family::Phantom},
	{"quinotaur", 'Q', Family::Phantom},
	{"reptilian", 'R', Family::Reptile},
	{"snake", 'S', Family::Reptile},
	{"troll", 'T', Family::Humanoid},
	{"vampire", 'V', Family::Phantom},
	{"worm", 'W', Family::Vermes},
	{"yeti", 'Y', Family::Humanoid},
	{"zombie", 'Z', Family::Undead},
	{"golem", '\'', Family::Phantom},
	{"human", '@', Family::Humanoid},
	{"spirit", '&', Family::Phantom},
	{"fish", ';', Family::Mariner},
	{"lizard", ':', Family::Reptile}
};

Species::Species()
	: Family(species_type[Troll].family), spec(Troll)
{
	
}
	
Species::Species(int s)
	: Family(species_type[s].family), spec(s)
{

}

const char *Species::Get_Name()
{
	return species_type[spec].name;
}

//displays only the ascii letter of the creature, color has to be set
//previously to match the possible subtype.
void Species::Display()
{
	gui->Put_Char(species_type[spec].ascii);
}
