#pragma once
#include "SpriteMngr.h"
#include <fstream>

class Tile {
private:
	SDL_Rect mPos;
	int mType;

	SpriteMngr *sprMngr;
public:

	void render(SDL_Rect &cam);
	int getType() { return mType; }
	SDL_Rect getPos() { return mPos; }


	Tile(int, int, int, SpriteMngr *);
	~Tile();
};

