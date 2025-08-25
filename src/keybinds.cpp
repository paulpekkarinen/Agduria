//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include <utility>
#include "codex.h"
#include "command.h"
#include "gui.h"
#include "keybinds.h"

using std::map;
using std::pair;

Keybindings::Keybindings()
{
	//map default keyboard codes to commands
	for (int t=0; t<Command::Max_Commands; t++)
	{
		Command c(t);
		Key_And_Command kac(c.Get_Default_Keycode(), t);
		Insert_Command(kac);
	}
}

void Keybindings::Insert_Command(const Key_And_Command &kac)
{
	pair<map<Keycode, int>::iterator, bool> rv;

	rv=keys.insert(std::make_pair(kac.keycode, kac.cmd));

	//check for duplicates (key can only have one command pair)
	if (rv.second==false)
		panic_exit("Matching id found in keycode data.");
}

int Keybindings::Get_Command(const Keycode &kc)
{
	map<Keycode, int>::iterator it = keys.find(kc);

	if (it != keys.end()) return it->second;

	return -1;
}
