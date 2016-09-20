#pragma once
#include "SDL.h"
#include "SpriteMngr.h"
#include "TileMap.h"
#include "Camera.h"

class Character {
private:
	int _charFrame = 0, _walking = 0, _walkingTimer = 0, _blinkTimer = 1, _idleTimer = 1;
	int _vel = SCALE * 1.5, _dir = 0, _jump = 0, _fallingVel = 0, _jumpHeight = 0, _fVTicks = 0;
	bool _pressed = false, _jumped = false;
	SpriteMngr *mSprMngr;
	TileMap * tileMap;

	SDL_Rect _pos;
	SDL_Rect* currentClip;

	bool tileCollision(SDL_Rect a, SDL_Rect b);
	bool checkCollision(SDL_Rect);
public:

	void update();
	void pEvent(const Uint8 *);
	void render(Camera *cam = nullptr);
	int getX() { return _pos.x; }
	int getY() { return _pos.y; }
	int getHeight() { return _pos.h; }
	int getWidth() { return _pos.w; }

	Character(SpriteMngr *, TileMap *);
};

