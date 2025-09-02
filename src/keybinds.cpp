//Agduria - Copyright 2009-2025 Paul Pekkarinen

#include <list>
#include <utility>
#include "codex.h"
#include "command.h"
#include "display.h"
#include "gui.h"
#include "keybinds.h"

using std::list;
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
	mapiter it = keys.find(kc);

	if (it != keys.end()) return it->second;

	return -1;
}

void Keybindings::Show_List()
{
	int x=Display::Text_Content_X;
	int y=Display::Text_Content_Y;
	const int x_offset=6;

	gui->Default_Color();

	//create list to list commands, because std::map contains
	//items in 'random' order, this list can be also sorted
	list<Key_And_Command> keylist;

	for (mapiter it=keys.begin(); it!=keys.end(); ++it)
	{
		if (it->second<Command::Unknown)
		{
			keylist.push_back(Key_And_Command(it->first, it->second));
		}
	}

	for (list<Key_And_Command>::iterator it=keylist.begin();
		it!=keylist.end(); ++it)
	{
		gui->GotoXY(x, y);
		display.Keycode_Text((*it).keycode.key);
			
		gui->GotoXY(x+x_offset, y);
		Command c((*it).cmd);
		gui->Write_Text(c.Get_Name());
		y++;
	}
}

