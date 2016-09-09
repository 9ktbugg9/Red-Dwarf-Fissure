#pragma once
#include "SDL.h"
#include "CTexture.h"

class SpriteMngr {
private:
	SDL_Renderer *mRenderer;

public:
	//CTecture clips;


	SpriteMngr(SDL_Renderer *);
	~SpriteMngr();
};

