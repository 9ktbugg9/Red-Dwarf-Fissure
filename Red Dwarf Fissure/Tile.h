#pragma once
#include "SpriteMngr.h"
#include <fstream>

class Tile {
private:
	SDL_Rect _pos;
	int _type;

	SpriteMngr *sprMngr;
public:

	void render(SDL_Rect &cam);
	int getType() { return _type; }
	SDL_Rect getPos() { return _pos; }


	Tile(int, int, int, SpriteMngr *);
	~Tile();
};

