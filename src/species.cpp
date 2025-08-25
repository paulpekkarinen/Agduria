//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include "species.h"
#include "gui.h"

struct Species_Data
{
	const char *name;
	char ascii;
};

Species_Data species_type[Species::Max_Species_Types]=
{
	{"ant", 'a'},
	{"bee", 'b'},
	{"centipede", 'c'},
	{"duck", 'd'},
	{"floating eye", 'e'},
	{"fox", 'f'},
	{"gremlin", 'g'},
	{"hyena", 'h'},
	{"imp", 'i'},
	{"jellyfish", 'j'},
	{"komodo dragon", 'k'},
	{"llama", 'l'},
	{"mermaid", 'm'},
	{"nymph", 'n'},
	{"orc", 'o'},
	{"puma", 'p'},
	{"quagga", 'q'},
	{"rat", 'r'},
	{"spider", 's'},
	{"turtle", 't'},
	{"unicorn", 'u'},
	{"vulture", 'v'},
	{"wolf", 'w'},
	{"bug", 'x'},
	{"zokor", 'z'},
	{"ape", 'A'},
	{"bat", 'B'},
	{"centaur", 'C'},
	{"dragon", 'D'},
	{"elemental", 'E'},
	{"fungus", 'F'},
	{"giant", 'G'},
	{"horse", 'H'},
	{"ikuturso", 'I'},
	{"jabberwock", 'J'},
	{"kraken", 'K'},
	{"lion", 'L'},
	{"mummy", 'M'},
	{"nephilim", 'N'},
	{"ogre", 'O'},
	{"pegasus", 'P'},
	{"quinotaur", 'Q'},
	{"reptilian", 'R'},
	{"snake", 'S'},
	{"troll", 'T'},
	{"vampire", 'V'},
	{"worm", 'W'},
	{"yeti", 'Y'},
	{"zombie", 'Z'},
	{"golem", '\''},
	{"humanoid", '@'},
	{"spirit", '&'},
	{"fish", ';'},
	{"lizard", ':'}
};

Species::Species(int s)
	: spec(s)
{

}

//displays only the ascii letter of the creature, color has to be set
//previously to match the possible subtype.
void Species::Display()
{
	gui->Put_Char(species_type[spec].ascii);
}
