#include "stdafx.h"
#include "Character.h"


void Character::update() {

	int bFr = _blinkTimer / 20;
	int iFr = _idleTimer / 75;

	if (bFr >= 2) {
		_blinkTimer = 0;
		bFr = 0;
	}
	if (iFr >= 2) {
		_idleTimer = 0;
		iFr = 1;
	}

	if (!_pressed)
		currentClip = &mSprMngr->charClips[_walking][0][iFr][bFr];
	else
		currentClip = &mSprMngr->charClips[_walking][_dir][0][bFr];


	_idleTimer++;
	_blinkTimer++;
}

void Character::pEvent(const Uint8* CKS, TileMap *tileMap) {
	_pressed = false;

	if (CKS[SDL_SCANCODE_A]) {
		_pos.x -= _vel;
		_dir = 1;
		_pressed = true;
	}
	if (CKS[SDL_SCANCODE_D]) {
		_pos.x += _vel;
		_dir = 0;
		_pressed = true;
	}

	if (CKS[SDL_SCANCODE_W]) {
		_pos.y -= _vel;
		_pressed = true;
	}
	if (CKS[SDL_SCANCODE_S]) {
		_pos.y += _vel;
		_pressed = true;
	}

	if (CKS[SDL_SCANCODE_A] && CKS[SDL_SCANCODE_D])
		_pressed = false;


	if (!_pressed) {
		_walking = 0;
		_walkingTimer = 0;
	}
	else {
		++_walkingTimer;
		int timing = 6;
		int _wTimer = _walkingTimer / timing;
		if (_wTimer >= 9) { _walkingTimer = timing * 3; _wTimer = 3; }

		if (_wTimer == 0) { _walking = 1; }
		if (_wTimer == 1) { _walking = 2; }
		if (_wTimer == 2) { _walking = 3; }

		if (_wTimer == 3) { _walking = 4; }
		if (_wTimer == 4) { _walking = 5; }
		if (_wTimer == 5) { _walking = 6; }
		if (_wTimer == 6) { _walking = 7; }
		if (_wTimer == 7) { _walking = 8; }
		if (_wTimer == 8) { _walking = 9; }
		if (_wTimer == 9) { _walking = 10; }

	}
}



void Character::render(Camera *cam) {
	if (cam)
		mSprMngr->charSheet.render(_pos.x - cam->camera.x - _pos.w * static_cast<int>((SCALE / 4)), _pos.y - cam->camera.y - _pos.h * static_cast<int>((SCALE / 4)), currentClip, SCALE, SCALE, NULL, NULL, SDL_FLIP_NONE);
	else
		mSprMngr->charSheet.render(_pos.x - 0 - _pos.w * static_cast<int>((SCALE / 2)), _pos.y - 0 - _pos.h * static_cast<int>((SCALE / 2)), currentClip, SCALE, SCALE, NULL, NULL, SDL_FLIP_NONE);

}

Character::Character(SpriteMngr * src) {
	mSprMngr = src;
	currentClip = &mSprMngr->charClips[0][0][0][0];
	_pos.w = mSprMngr->charClips[0][0][0][0].w;
	_pos.h = mSprMngr->charClips[0][0][0][0].h;
	_pos.x = 100;
	_pos.y = 100;

}

