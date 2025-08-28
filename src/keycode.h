//Agduria - Copyright 2009-2025 Paul Pekkarinen

//Unit keycode: Keycode type.

#pragma once

struct Keycode
{
	int key;

	Keycode() : key('?') { }
	Keycode(int k);

	bool operator==(const Keycode& r)
	{
		if(this == &r) return true;
		if (key==r.key) return true;
		return false;
	}

	//operator < is needed for std::map
	friend bool operator<(const Keycode& l, const Keycode& r)
	{
    	return (l.key < r.key);
	}
};

