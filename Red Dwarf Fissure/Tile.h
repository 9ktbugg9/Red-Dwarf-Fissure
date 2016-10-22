#pragma once
#include "SpriteMngr.h"
#include <fstream>

class Tile {
private:
	SDL_Rect _pos;
	int _type, _back;

	SpriteMngr *sprMngr;
public:

	void render(SDL_Rect &cam);
	int getType() { return _type; }
	SDL_Rect getPos() { return _pos; }
	void replace(int type) { _type = type; }

	Tile(int, int, int, int, SpriteMngr *);
	~Tile();
};

