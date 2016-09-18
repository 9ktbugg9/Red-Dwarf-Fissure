#include "stdafx.h"
#include "Tile.h"


void Tile::render(SDL_Rect &cam) {
	sprMngr->tiles.render(_pos.x - cam.x, _pos.y - cam.y, &sprMngr->tileClips[mType], TILE_SCALE, TILE_SCALE);
}

Tile::Tile(int x, int y, int type, SpriteMngr *sprSrc) : sprMngr(sprSrc) {
	_pos.x = x;
	_pos.y = y;
	_pos.h = _pos.w = 16;

	mType = type;
}


Tile::~Tile() {
}

