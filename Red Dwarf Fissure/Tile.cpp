#include "stdafx.h"
#include "Tile.h"


void Tile::render(SDL_Rect &cam) {
	sprMngr->tiles.render(_pos.x - cam.x, _pos.y - cam.y, &sprMngr->tileClips[_back], TILE_SCALE, TILE_SCALE);
	if(_type != sprMngr->EMPTY)
		sprMngr->tiles.render(_pos.x - cam.x, _pos.y - cam.y, &sprMngr->tileClips[_type], TILE_SCALE, TILE_SCALE);
}

Tile::Tile(int x, int y, int type, int back, SpriteMngr *sprSrc) : sprMngr(sprSrc), _type(type), _back(back) {
	_pos.x = x;
	_pos.y = y;
	_pos.h = _pos.w = 16;
}


Tile::~Tile() {
}

