#include "stdafx.h"
#include "Tile.h"


void Tile::render(SDL_Rect &cam) {
	sprMngr->tiles.render(mPos.x - cam.x, mPos.y - cam.y, &sprMngr->tileClips[mType], TILE_SCALE, TILE_SCALE);
}

Tile::Tile(int x, int y, int type, SpriteMngr *sprSrc) : sprMngr(sprSrc) {
	mPos.x = x;
	mPos.y = y;
	mPos.h = mPos.w = 16;

	mType = type;
}


Tile::~Tile() {
}

