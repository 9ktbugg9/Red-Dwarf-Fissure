#include "stdafx.h"
#include "Character.h"


void Character::update() {

	int bFr = _blinkTimer / 20;
	int iFr = _idleTimer / 60;
	
	if (bFr >= 2) {
		_blinkTimer = 0;
		bFr = 1;
	}
	if (iFr >= 2) {
		_idleTimer = 0;
		iFr = 1;
	}

	currentClip = &mSprMngr->charClips[iFr][bFr];

	_idleTimer++;
	_blinkTimer++;
}

void Character::pEvent(const Uint8* CKS, TileMap *tileMap) {
	bool pressed = false;

	if (CKS[SDL_SCANCODE_A]) {
		_pos.x -= _vel;
		_dir = 1;
		pressed = true;
	}
	if (CKS[SDL_SCANCODE_D]) {
		_pos.x += _vel;
		_dir = 2;
		pressed = true;
	}

	if (CKS[SDL_SCANCODE_W]) {
		_pos.y -= _vel;
		pressed = true;
	}
	if (CKS[SDL_SCANCODE_S]) {
		_pos.y += _vel;
		pressed = true;
	}


	if (!pressed) {
		_walking = 0;
		_walkingTimer = 0;
	}
	else
		_walkingTimer++;
}



void Character::render(Camera *cam) {
	if (cam)
		mSprMngr->charSheet.render(_pos.x - cam->camera.x - _pos.w * static_cast<int>((SCALE / 2)), _pos.y - cam->camera.y - _pos.h * static_cast<int>((SCALE / 2)), currentClip, SCALE, SCALE, NULL, NULL, SDL_FLIP_NONE);
	else
		mSprMngr->charSheet.render(_pos.x - 0 - _pos.w * static_cast<int>((SCALE / 2)), _pos.y - 0 - _pos.h * static_cast<int>((SCALE / 2)), currentClip, SCALE, SCALE, NULL, NULL, SDL_FLIP_NONE);

}

Character::Character(SpriteMngr * src) {
	mSprMngr = src;
	currentClip = &mSprMngr->charClips[0][0];
	_pos.x = 100;
	_pos.y = 100;

}

