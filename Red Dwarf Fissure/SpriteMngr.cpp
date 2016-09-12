#include "stdafx.h"
#include "SpriteMngr.h"


SpriteMngr::SpriteMngr(SDL_Renderer *src, SDL_Window *win) :mRenderer(src), mWindow(win) {

	tiles.setSpecs(mRenderer, mWindow);
	startingMap.setSpecs(mRenderer, mWindow);

	startingMap.loadFromFile("res/levels/spawn_level.png");

	if (tiles.loadFromFile("res/textures/sheets/tiles_16x16.png")) {
		tileClips[FLOOR].x = 0 * 16;
		tileClips[FLOOR].y = 0 * 16;
		tileClips[FLOOR].w = 16;
		tileClips[FLOOR].h = 16;

		tileClips[CRACK].x = 1 * 16;
		tileClips[CRACK].y = 0 * 16;
		tileClips[CRACK].w = 16;
		tileClips[CRACK].h = 16;

		tileClips[BLOOD].x = 2 * 16;
		tileClips[BLOOD].y = 0 * 16;
		tileClips[BLOOD].w = 16;
		tileClips[BLOOD].h = 16;

		tileClips[GOOPY].x = 3 * 16;
		tileClips[GOOPY].y = 0 * 16;
		tileClips[GOOPY].w = 16;
		tileClips[GOOPY].h = 16;

		tileClips[SOLID].x = 4 * 16;
		tileClips[SOLID].y = 0 * 16;
		tileClips[SOLID].w = 16;
		tileClips[SOLID].h = 16;

		tileClips[SPACE].x = 5 * 16;
		tileClips[SPACE].y = 0 * 16;
		tileClips[SPACE].w = 16;
		tileClips[SPACE].h = 16;

		tileClips[LINES].x = 6 * 16;
		tileClips[LINES].y = 0 * 16;
		tileClips[LINES].w = 16;
		tileClips[LINES].h = 16;

		tileClips[RINGS].x = 7 * 16;
		tileClips[RINGS].y = 0 * 16;
		tileClips[RINGS].w = 16;
		tileClips[RINGS].h = 16;
	}

}


SpriteMngr::~SpriteMngr() {
	startingMap.free();
	tiles.free();
}
