#include "stdafx.h"
#include "SpriteMngr.h"


SpriteMngr::SpriteMngr(SDL_Renderer *src, SDL_Window *win) :mRenderer(src), mWindow(win) {

	tiles.setSpecs(mRenderer, mWindow);
	charSheet.setSpecs(mRenderer, mWindow);
	startingMap.setSpecs(mRenderer, mWindow);

	startingMap.loadFromFile("res/levels/spawn_level.png");

	if (charSheet.loadFromFile("res/textures/sheets/char_32x32.png")) {
		charClips[0][0].x = 0 * 32;
		charClips[0][0].y = 0 * 32;
		charClips[0][0].w = charClips[0][0].h = 32;

		charClips[1][0].x = 0 * 32;
		charClips[1][0].y = 1 * 32;
		charClips[1][0].w = charClips[1][0].h = 32;

		charClips[0][1].x = 1 * 32;
		charClips[0][1].y = 0 * 32;
		charClips[0][1].w = charClips[0][1].h = 32;

		charClips[1][1].x = 1 * 32;
		charClips[1][1].y = 1 * 32;
		charClips[1][1].w = charClips[1][1].h = 32;
	}

	if (tiles.loadFromFile("res/textures/sheets/tiles_16x16.png")) {
		tileClips[FLOOR1].x = 0 * 16;
		tileClips[FLOOR1].y = 0 * 16;
		tileClips[FLOOR1].w = tileClips[FLOOR1].h = 16;
		tileClips[FLOOR2].x = 0 * 16;
		tileClips[FLOOR2].y = 1 * 16;
		tileClips[FLOOR2].w = tileClips[FLOOR2].h = 16;
		tileClips[FLOOR3].x = 0 * 16;
		tileClips[FLOOR3].y = 2 * 16;
		tileClips[FLOOR3].w = tileClips[FLOOR3].h = 16;
		tileClips[FLOOR4].x = 0 * 16;
		tileClips[FLOOR4].y = 3 * 16;
		tileClips[FLOOR4].w = tileClips[FLOOR4].h = 16;

		tileClips[CRACK1].x = 1 * 16;
		tileClips[CRACK1].y = 0 * 16;
		tileClips[CRACK1].w = tileClips[CRACK1].h = 16;
		tileClips[CRACK2].x = 1 * 16;
		tileClips[CRACK2].y = 1 * 16;
		tileClips[CRACK2].w = tileClips[CRACK2].h = 16;
		tileClips[CRACK3].x = 1 * 16;
		tileClips[CRACK3].y = 2 * 16;
		tileClips[CRACK3].w = tileClips[CRACK3].h = 16;
		tileClips[CRACK4].x = 1 * 16;
		tileClips[CRACK4].y = 3 * 16;
		tileClips[CRACK4].w = tileClips[CRACK4].h = 16;

		tileClips[BLOOD1].x = 2 * 16;
		tileClips[BLOOD1].y = 0 * 16;
		tileClips[BLOOD1].w = tileClips[BLOOD1].h = 16;
		tileClips[BLOOD2].x = 2 * 16;
		tileClips[BLOOD2].y = 1 * 16;
		tileClips[BLOOD2].w = tileClips[BLOOD2].h = 16;
		tileClips[BLOOD3].x = 2 * 16;
		tileClips[BLOOD3].y = 2 * 16;
		tileClips[BLOOD3].w = tileClips[BLOOD3].h = 16;
		tileClips[BLOOD4].x = 2 * 16;
		tileClips[BLOOD4].y = 3 * 16;
		tileClips[BLOOD4].w = tileClips[BLOOD4].h = 16;

		tileClips[GOOPY1].x = 3 * 16;
		tileClips[GOOPY1].y = 0 * 16;
		tileClips[GOOPY1].w = tileClips[GOOPY1].h = 16;
		tileClips[GOOPY2].x = 3 * 16;
		tileClips[GOOPY2].y = 1 * 16;
		tileClips[GOOPY2].w = tileClips[GOOPY2].h = 16;
		tileClips[GOOPY3].x = 3 * 16;
		tileClips[GOOPY3].y = 2 * 16;
		tileClips[GOOPY3].w = tileClips[GOOPY3].h = 16;
		tileClips[GOOPY4].x = 3 * 16;
		tileClips[GOOPY4].y = 3 * 16;
		tileClips[GOOPY4].w = tileClips[GOOPY4].h = 16;

		tileClips[SOLID].x = 5 * 16;
		tileClips[SOLID].y = 0 * 16;
		tileClips[SOLID].w = tileClips[SOLID].h = 16;

		tileClips[SPACE1].x = 4 * 16;
		tileClips[SPACE1].y = 0 * 16;
		tileClips[SPACE1].w = tileClips[SPACE1].h = 16;
		tileClips[SPACE2].x = 4 * 16;
		tileClips[SPACE2].y = 1 * 16;
		tileClips[SPACE2].w = tileClips[SPACE2].h = 16;
		tileClips[SPACE3].x = 4 * 16;
		tileClips[SPACE3].y = 2 * 16;
		tileClips[SPACE3].w = tileClips[SPACE3].h = 16;
		tileClips[SPACE4].x = 4 * 16;
		tileClips[SPACE4].y = 3 * 16;
		tileClips[SPACE4].w = tileClips[SPACE4].h = 16;

		tileClips[LINES].x = 6 * 16;
		tileClips[LINES].y = 0 * 16;
		tileClips[LINES].w = tileClips[LINES].h = 16;

		tileClips[RINGS].x = 7 * 16;
		tileClips[RINGS].y = 0 * 16;
		tileClips[RINGS].w = tileClips[RINGS].h = 16;
	}

}


SpriteMngr::~SpriteMngr() {
	startingMap.free();
	tiles.free();
}
