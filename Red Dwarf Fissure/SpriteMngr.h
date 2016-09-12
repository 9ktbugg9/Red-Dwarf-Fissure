#pragma once
#include "SDL.h"
#include "CTexture.h"

class SpriteMngr {
private:
	SDL_Renderer *mRenderer;
	SDL_Window *mWindow;

public:
	CTexture tiles;
	SDL_Rect tileClips[8];
	enum tileTypes {
		FLOOR, CRACK, BLOOD, GOOPY,
		SOLID, SPACE, LINES, RINGS
	};

	CTexture startingMap;


	SpriteMngr(SDL_Renderer *, SDL_Window *);
	~SpriteMngr();
};

