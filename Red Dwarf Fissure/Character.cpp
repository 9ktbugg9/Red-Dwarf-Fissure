#include "stdafx.h"
#include "Character.h"

bool Character::checkCollision(SDL_Rect box) {
	for (int i = 0; i < tileMap->getTileAmount(); ++i) {
		if (tileMap->tileSet[i].getType() == mSprMngr->SOLID) {
			if (tileCollision(box, tileMap->tileSet[i].getPos())) {
				return true;
			}
		}
	}
	return false;
}

bool Character::tileCollision(SDL_Rect a, SDL_Rect b) {
	if (a.y + (a.h - 6) * SCALE <= b.y) return false;
	if (a.y + 8 * SCALE >= b.y + b.h * TILE_SCALE) return false;
	if (a.x + (a.w - 8) * SCALE <= b.x) return false;
	if (a.x + 8 * SCALE >= b.x + b.w * TILE_SCALE) return false;
	return true;
}

void Character::update() {
	int bFr = _blinkTimer / 20;
	int iFr = _idleTimer / 75;

	if (bFr >= 2) { _blinkTimer = 0; bFr = 0; }
	if (iFr >= 2) { _idleTimer = 0; iFr = 1; }

	if (!_pressed) currentClip = &mSprMngr->charClips[_walking][0][iFr][bFr];
	else currentClip = &mSprMngr->charClips[_walking][_dir][0][bFr];

	if (_jump != 0) {
		_jump--;
		_pos.y -= _jump;

		//TODO: Make this so it doesn't have to check collision twice
		if (checkCollision(_pos)) {
			_pos.y += _jump;
			_jump = 0;
		}

		_pos.y += _vel;
		if (checkCollision(_pos))
			_pos.y -= _vel;
	}

	else {
		_pos.y += _vel * 2 + (_fallingVel / 2);

		std::cout << checkCollision(_pos) << "     ";

		if (checkCollision(_pos)) {
			_pos.y -= _vel * 2;
			
			//TODO: Make this more effective
			while (checkCollision(_pos))
				_pos.y--;
			
			_fallingVel = _fVTicks = 0;
			_jumped = false;

			while (checkCollision(_pos)) 
				_pos.y--;

		}
		else {
				_fallingVel++;
		}
	}
	std::cout << _pos.y << " - " << checkCollision(_pos) << std::endl;
	_idleTimer++;
	_blinkTimer++;
}

void Character::pEvent(const Uint8* CKS) {
	_pressed = false;

	int addX = 0, addY = 0;
	if (CKS[SDL_SCANCODE_A]) {
		addX -= _vel;
		_dir = 1;
		_pressed = true;
	}
	if (CKS[SDL_SCANCODE_D]) {
		addX += _vel;
		_dir = 0;
		_pressed = true;
	}

	if (CKS[SDL_SCANCODE_W]) {
		//TODO: Make jump height scale with the scales
		if (_jump == 0 && !_jumped) _jump = _jumpHeight;
		_pressed = _jumped = true;
	}
	if (CKS[SDL_SCANCODE_S]) {
		addY += _vel;
		_pressed = true;
	}

	if (CKS[SDL_SCANCODE_A] && CKS[SDL_SCANCODE_D]) _pressed = false;

	SDL_Rect nPos = _pos;
	nPos.x += addX;
	nPos.y += addY;

	if (checkCollision(nPos)) _pressed = false;

	else { _pos.x += addX; _pos.y += addY; }

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
		mSprMngr->charSheet.render(_pos.x - cam->camera.x, _pos.y - cam->camera.y, currentClip, SCALE, SCALE, NULL, NULL, SDL_FLIP_NONE);
	else
		mSprMngr->charSheet.render(_pos.x - 0 - _pos.w * static_cast<int>((SCALE / 2)), _pos.y - 0 - _pos.h * static_cast<int>((SCALE / 2)), currentClip, SCALE, SCALE, NULL, NULL, SDL_FLIP_NONE);
}

Character::Character(SpriteMngr *src, TileMap *tSrc) : tileMap(tSrc) {
	mSprMngr = src;
	currentClip = &mSprMngr->charClips[0][0][0][0];
	_pos.w = mSprMngr->charClips[0][0][0][0].w;
	_pos.h = mSprMngr->charClips[0][0][0][0].h;
	_pos.x = 10;
	_pos.y = 150;
	_jumpHeight = mSprMngr->tileClips[0].h;
}

