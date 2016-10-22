#pragma once
#include "SDL.h"
#include <vector>
#include "CTexture.h"

class SpriteMngr {
private:
	SDL_Renderer *_renderer;
	SDL_Window *_window;

	void setSolids();
public:

	CTexture tiles;
	SDL_Rect tileClips[4 * 5 + 3 + 3];
	enum tileTypes {
		FLOOR1, FLOOR2, FLOOR3, FLOOR4,
		CRACK1, CRACK2, CRACK3, CRACK4,
		SPACE1, SPACE2, SPACE3, SPACE4,
		GOOPY1, GOOPY2, GOOPY3, GOOPY4,
		BLOOD1, BLOOD2, BLOOD3, BLOOD4,
		SOLID, LINES, RINGS, GRASS, DIRTY, EMPTY
	};
	std::vector<int> solidTiles;

	CTexture charSheet;
	SDL_Rect charClips[11][2][2][2];

	CTexture startingMap;

	SpriteMngr(SDL_Renderer *, SDL_Window *);
	~SpriteMngr();
};

