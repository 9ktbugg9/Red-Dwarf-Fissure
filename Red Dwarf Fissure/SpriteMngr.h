#pragma once
#include "SDL.h"
#include "CTexture.h"

class SpriteMngr {
private:
	SDL_Renderer *mRenderer;

public:
	CTexture charSheet;
	SDL_Rect buggClips[4][3][3];
	CTexture background;


	SpriteMngr(SDL_Renderer *);
	~SpriteMngr();
};

