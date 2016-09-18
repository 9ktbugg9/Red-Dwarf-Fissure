#pragma once
#include "SDL.h"
#include "CTexture.h"

class SpriteMngr {
private:
	SDL_Renderer *mRenderer;
	SDL_Window *mWindow;

public:
	CTexture tiles;
	SDL_Rect tileClips[4 * 5 + 3];
	enum tileTypes {
		FLOOR1, FLOOR2, FLOOR3, FLOOR4,
		CRACK1, CRACK2, CRACK3, CRACK4,
		SPACE1, SPACE2, SPACE3, SPACE4,
		GOOPY1, GOOPY2, GOOPY3, GOOPY4,
		BLOOD1, BLOOD2, BLOOD3, BLOOD4,
		SOLID, LINES, RINGS
	};

	CTexture charSheet;
	SDL_Rect charClips[2][2];

	CTexture startingMap;

	SpriteMngr(SDL_Renderer *, SDL_Window *);
	~SpriteMngr();
};

