#pragma once
#include "SDL.h"
#include "SpriteMngr.h"
#include "TileMap.h"
#include "Camera.h"

class Character {
private:
	int _charFrame = 0, _walking = 0, _walkingTimer = 0, _blinkTimer = 1, _idleTimer = 1, _vel = SCALE, _dir = 0;
	bool _pressed;
	SDL_Rect _pos;
	SpriteMngr *mSprMngr;
	SDL_Rect* currentClip;
	TileMap * tileMap;

	bool checkCollision(int, int);
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

