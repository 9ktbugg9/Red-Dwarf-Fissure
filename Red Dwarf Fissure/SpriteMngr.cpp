#include "stdafx.h"
#include "SpriteMngr.h"


SpriteMngr::SpriteMngr(SDL_Renderer *src, SDL_Window *win) :_renderer(src), _window(win) {

	tiles.setSpecs(_renderer, _window);
	charSheet.setSpecs(_renderer, _window);
	startingMap.setSpecs(_renderer, _window);
	effectSheet.setSpecs(_renderer, _window);

	startingMap.loadFromFile("res/levels/test_level_2.png");

	if (charSheet.loadFromFile("res/textures/sheets/char_64x64.png")) {

		for (int i = 0; i < 2; i++)
			for (int k = 0; k < 2; k++) {
				charClips[0][0][k][i].x = i * 64;
				charClips[0][0][k][i].y = k * 64;
				charClips[0][0][k][i].w = charClips[0][0][k][i].h = 64;
			}

		for (int k = 0; k < 2; k++)
			for (int i = 0; i < 2; i++) {
				for (int z = 1; z < 4; z++) {
					charClips[z][k][0][i].x = (z - 1 + (k * 4)) * 64;
					charClips[z][k][0][i].y = (2 + (i * 3)) * 64;
					charClips[z][k][0][i].w = charClips[z][k][0][i].h = 64;
				}
				for (int z = 4; z < 8; z++) {
					charClips[z][k][0][i].x = (z - 4 + (k * 4)) * 64;
					charClips[z][k][0][i].y = (3 + (i * 3)) * 64;
					charClips[z][k][0][i].w = charClips[z][k][0][i].h = 64;
				}
				for (int z = 8; z < 11; z++) {
					charClips[z][k][0][i].x = (z - 8 + (k * 4)) * 64;
					charClips[z][k][0][i].y = (4 + (i * 3)) * 64;
					charClips[z][k][0][i].w = charClips[z][k][0][i].h = 64;
				}
			}
	}

	if (tiles.loadFromFile("res/textures/sheets/tiles_16x16.png")) {
		for (int i = 0; i < 4; i++) { // FLOOR 1 - 4
			tileClips[i].x = 0 * 16;
			tileClips[i].y = i * 16;
			tileClips[i].w = tileClips[i].h = 16;
		}

		for (int i = 0; i < 4; i++) { // CRACK 1 - 4
			tileClips[i + 4].x = 1 * 16;
			tileClips[i + 4].y = i * 16;
			tileClips[i + 4].w = tileClips[i + 4].h = 16;
		}

		for (int i = 0; i < 4; i++) { // SPACE 1 - 4
			tileClips[i + 8].x = 4 * 16;
			tileClips[i + 8].y = i * 16;
			tileClips[i + 8].w = tileClips[i + 8].h = 16;
		}

		for (int i = 0; i < 4; i++) { // GOOPY 1 - 4
			tileClips[i + 12].x = 3 * 16;
			tileClips[i + 12].y = i * 16;
			tileClips[i + 12].w = tileClips[i + 12].h = 16;
		}

		for (int i = 0; i < 4; i++) { // BLOOD 1 - 4
			tileClips[i + 16].x = 2 * 16;
			tileClips[i + 16].y = i * 16;
			tileClips[i + 16].w = tileClips[i + 16].h = 16;
		}

		tileClips[SOLID].x = 5 * 16;
		tileClips[SOLID].y = 0 * 16;
		tileClips[SOLID].w = tileClips[SOLID].h = 16;

		tileClips[LINES].x = 5 * 16;
		tileClips[LINES].y = 1 * 16;
		tileClips[LINES].w = tileClips[LINES].h = 16;

		tileClips[RINGS].x = 5 * 16;
		tileClips[RINGS].y = 2 * 16;
		tileClips[RINGS].w = tileClips[RINGS].h = 16;

		tileClips[GRASS].x = 0 * 16;
		tileClips[GRASS].y = 4 * 16;
		tileClips[GRASS].w = tileClips[GRASS].h = 16;

		tileClips[DIRTY].x = 0 * 16;
		tileClips[DIRTY].y = 5 * 16;
		tileClips[DIRTY].w = tileClips[DIRTY].h = 16;
	}

	if (effectSheet.loadFromFile("res/textures/sheets/effects.png")) {

		effectClips[LAZER1].x = 0 * 8;
		effectClips[LAZER1].y = 0 * 8;
		effectClips[LAZER1].w = 16 * 3;
		effectClips[LAZER1].h = 8;

		effectClips[LAZER2].x = 0 * 8;
		effectClips[LAZER2].y = 1 * 8 + 2;
		effectClips[LAZER2].w = 16 * 3;
		effectClips[LAZER2].h = 8;

		effectClips[LAZER3].x = 0 * 8;
		effectClips[LAZER3].y = 2 * 8 + 4;
		effectClips[LAZER3].w = 16 * 3;
		effectClips[LAZER3].h = 8;
	}

	setSolids();
}

void SpriteMngr::setSolids() {
	solidTiles.push_back(SOLID);
	solidTiles.push_back(RINGS);
	solidTiles.push_back(GRASS);
	solidTiles.push_back(DIRTY);
}

SpriteMngr::~SpriteMngr() {
	startingMap.free();
	tiles.free();
}
