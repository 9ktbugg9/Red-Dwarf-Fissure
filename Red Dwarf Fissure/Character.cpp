#include "stdafx.h"
#include "Character.h"

bool Character::checkCollision(SDL_Rect box) {
	for (int i = 0; i < tileMap->getTileAmount(); ++i) {
		bool solid = false;
		for (unsigned int k = 0; k < _sprMngr->solidTiles.size(); k++)
			if (tileMap->tileSet[i].getType() == _sprMngr->solidTiles[k]) { solid = true; break; };

		if (solid)
			if (!tileCollision(box, tileMap->tileSet[i].getPos())) return true;
	}
	return false;
}

bool Character::tileCollision(SDL_Rect a, SDL_Rect b) {
	if (a.y + (a.h - 6) * SCALE + 1 <= b.y) return true;
	if (a.y + 8 * SCALE + 11 >= b.y + b.h * TILE_SCALE) return true;
	if (a.x + (a.w - 8) * SCALE - 1 <= b.x) return true;
	if (a.x + 8 * SCALE + 1 >= b.x + b.w * TILE_SCALE) return true;
	return false;
}

void Character::update(const Uint8 *CKS, const Uint8 CMS, SDL_Point mousePos) {
	if (CKS) pEvent(CKS);
	if (CMS) { pEvent(CMS, mousePos); if (_lazerTimer < 100) _lazerTimer++; }
	else _lazerTimer = 0;

	int bFr = _blinkTimer / 20;
	int iFr = _idleTimer / 75;

	if (bFr >= 2) { _blinkTimer = 0; bFr = 0; }
	if (iFr >= 2) { _idleTimer = 0; iFr = 1; }

	if (!_pressed) currentClip = &_sprMngr->charClips[_walking][0][iFr][bFr];
	else currentClip = &_sprMngr->charClips[_walking][_dir][0][bFr];

	if (_jump != 0) {
		_pos.y -= --_jump;

		//TODO: Make this so it doesn't have to check multiple times
		if (checkCollision(_pos)) {
			if (_jump < _jumpHeight - 1) {
				while (checkCollision(_pos)) _pos.y++;
				_jump = 0;
				if (CKS[SDL_SCANCODE_D]) {
					_pos.x += 5;
					if (checkCollision(_pos))
						_pos.x -= 5;
				}
				if (CKS[SDL_SCANCODE_A]) {
					_pos.x -= 5;
					if (checkCollision(_pos))
						_pos.x += 5;
				}
			}
			else {
				_pos.y += _jump;
				_jump = 0;
			}
		}

		_pos.y += _vel;
		if (checkCollision(_pos))
			_pos.y -= _vel;
	}

	else {
		_pos.y += _vel * 2 + (_fallingVel / 2);

		if (checkCollision(_pos)) {
			_pos.y -= _vel;

			//TODO: Make this more effective
			while (checkCollision(_pos)) _pos.y--;

			_fallingVel = _fVTicks = 0;
			_jumped = false;
		}
		else
			_fallingVel++;
	}
	_idleTimer++; _blinkTimer++;
}

void Character::pEvent(const Uint8 CMS, SDL_Point mousePos) {
	_mouseAngle = (atan2((_pos.y - _cam->camera.y + (_pos.h * SCALE / 2)) - mousePos.y - (7 * SCALE), (_pos.x - _cam->camera.x + (_pos.w * SCALE / 2)) - mousePos.x) * 180.0000) / 3.14159253589;
	if (_mouseAngle == 0) _mouseAngle = 1;

	int distX = (mousePos.x ) - (_pos.x +  _pos.w / 2) + _cam->camera.x;
	int distY = (mousePos.y ) - (_pos.y +  _pos.h / 2) + _cam->camera.y;
	_mouseDist = -sqrt((distX *= distX) + (distY *= distY)); // FIXME: Doesn't always work perfectly
	mousePos.x += _cam->camera.x; mousePos.y += _cam->camera.y;

	SDL_Point mouseTile{mousePos.x / (_sprMngr->tileClips[0].h * TILE_SCALE), mousePos.y / (_sprMngr->tileClips[0].h * TILE_SCALE)};
	int point = ((mouseTile.y * (tileMap->levelWidth() / 16) + mouseTile.x));
	tileMap->tileSet[point].replace(_sprMngr->EMPTY);
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
		int timing = 4;
		int _wTimer = _walkingTimer / timing;
		if (_wTimer > 9) { _walkingTimer = timing * 3; _wTimer = 3; }

		switch (_wTimer) {
			case 0:  _walking = 1; break;
			case 1:  _walking = 2; break;
			case 2:  _walking = 3; break;
			case 3:  _walking = 4; break;
			case 4:  _walking = 5; break;
			case 5:  _walking = 6; break;
			case 6:  _walking = 7; break;
			case 7:  _walking = 8; break;
			case 8:  _walking = 9; break;
			case 9:  _walking = 10; break;
		}
	}

	if (_lazerTimer > 0) {
		++_lTimer;
		int timing = 4;
		int lFrame = _lTimer / timing;
		if (lFrame > 3) { _lTimer = 0; lFrame = 0; }
		switch (lFrame) {
			case 1: _lFrame = 0; break;
			case 2: _lFrame = 1; break;
			case 3: _lFrame = 2; break;
		}
	}

}



void Character::render() {
	if (_cam)
		_sprMngr->charSheet.render(_pos.x - _cam->camera.x, _pos.y - _cam->camera.y, currentClip, SCALE, SCALE, NULL, NULL, SDL_FLIP_NONE);
	else
		_sprMngr->charSheet.render(_pos.x - 0 - _pos.w * static_cast<int>((SCALE / 2)), _pos.y - 0 - _pos.h * static_cast<int>((SCALE / 2)), currentClip, SCALE, SCALE, NULL, NULL, SDL_FLIP_NONE);

	if (_lazerTimer > 0) {

		SDL_SetRenderDrawColor(_rend, 0x00, 0x00, 0x00, 0xFF);
		SDL_Rect opening;
		SDL_Point center{4, 4};

		if (_idleTimer / 75 && !_walkingTimer) {
			opening = {_pos.x - _cam->camera.x + (_pos.w * SCALE / 2) - 14 / 2, _pos.y - _cam->camera.y + _pos.h / 2 + 7 * SCALE, 14, 14};
			SDL_RenderFillRect(_rend, &opening);
			_sprMngr->effectSheet.render(_pos.x - _cam->camera.x + (_pos.w * SCALE / 2) - 8 / 2, _pos.y - _cam->camera.y + _pos.h - 15, &_sprMngr->effectClips[_lFrame], SCALE, SCALE, _mouseDist, 8 * SCALE, _mouseAngle, center);
		}
		else {
			opening = {_pos.x - _cam->camera.x + (_pos.w * SCALE / 2) - 14 / 2, _pos.y - _cam->camera.y + _pos.h / 2 + 5 * SCALE, 14, 14};
			SDL_RenderFillRect(_rend, &opening);
			_sprMngr->effectSheet.render(_pos.x - _cam->camera.x + (_pos.w * SCALE / 2) - 8 / 2, _pos.y - _cam->camera.y + _pos.h - 18, &_sprMngr->effectClips[_lFrame], SCALE, SCALE, _mouseDist, 8 * SCALE, _mouseAngle, center);
		}

	}
}

Character::Character(SDL_Point spawnPos, SpriteMngr *src, TileMap *tSrc, SDL_Renderer *rend, Camera *cam) : tileMap(tSrc), _cam(cam), _rend(rend) {
	_sprMngr = src;
	currentClip = &_sprMngr->charClips[0][0][0][0];
	_pos = *currentClip;
	_pos.x = spawnPos.x;
	_pos.y = spawnPos.y;

	//TODO: Make this scale with the scale
	if (TILE_SCALE == 2) _jumpHeight = 15;
	else if (TILE_SCALE == 3) _jumpHeight = _sprMngr->tileClips[0].h;
	else if (TILE_SCALE > 3) _jumpHeight = static_cast<int>(_sprMngr->tileClips[0].h * (TILE_SCALE / 3) * 0.75);

}

