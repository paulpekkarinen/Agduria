//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit species: Creature type.

#pragma once

//Species are the main division of creatures which can have subtypes.
//Some species name can't be used as it is, a creature derived from that
//subtype has the proper name, like all humanoids.
class Species
{
public:
	enum Species_Type {Ant, Bee, Centipede, Duck, Eye, Fox, Gremlin,
		Hyena, Imp, Jellyfish, Komodo, Llama, Mermaid, Nymph, Orc, Puma,
		Quagga, Rat, Spider, Turtle, Unicorn, Vulture, Wolf, Bug, Zokor,
		Ape, Bat, Centaur, Dragon, Elf, Fungus, Giant, Horse, Ikuturso,
		Jackalope, Kraken, Lion, Mummy, Nephilim, Ogre, Pegasus, Quinotaur,
		Reptilian, Snake, Troll, Vampire, Worm, Yeti,
		Zombie, Golem, Human, Spirit, Fish, Lizard, Max_Species_Types};

private:
	int spec;

public:
	Species() : spec(Troll) { }
	Species(int s);

	void Display();
};
