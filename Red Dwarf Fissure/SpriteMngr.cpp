#include "stdafx.h"
#include "SpriteMngr.h"


SpriteMngr::SpriteMngr(SDL_Renderer *src) {
	mRenderer = src;
	charSheet.setRenderer(mRenderer);
	background.setRenderer(mRenderer);

	background.loadFromFile("images/bg.png");
	if (charSheet.loadFromFile("images/32x32 Bugg Sprite-Sheet.png")) {

		for (int k = 0; k < 3; k++)
			for (int i = 0; i < 3; i++) {
				buggClips[0][k][i].x = (i + 3) * 32;
				buggClips[0][k][i].y = k * 32;
				buggClips[0][k][i].w = 32;
				buggClips[0][k][i].h = 32;
			}

		for (int k = 0; k < 3; k++)
			for (int i = 0; i < 3; i++) {
				buggClips[1][k][i].x = i * 32;
				buggClips[1][k][i].y = (k + 3) * 32;
				buggClips[1][k][i].w = 32;
				buggClips[1][k][i].h = 32;
			}

		for (int k = 0; k < 3; k++)
			for (int i = 0; i < 3; i++) {
				buggClips[2][k][i].x = i * 32;
				buggClips[2][k][i].y = k * 32;
				buggClips[2][k][i].w = 32;
				buggClips[2][k][i].h = 32;
			}

		for (int k = 0; k < 3; k++)
			for (int i = 0; i < 3; i++) {
				buggClips[3][k][i].x = (i + 3) * 32;
				buggClips[3][k][i].y = (k + 3) * 32;
				buggClips[3][k][i].w = 32;
				buggClips[3][k][i].h = 32;
			}
	}
}


SpriteMngr::~SpriteMngr() {
	charSheet.free();
	background.free();
}
