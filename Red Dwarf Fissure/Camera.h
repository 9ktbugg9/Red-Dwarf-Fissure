#pragma once
#include "SDL.h"
#include "GlobalVars.h"


class Camera {
private:
	int LEVEL_WIDTH, LEVEL_HEIGHT;
	int playerScale;

public:
	SDL_Rect camera = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

	void update(int, int);

	Camera(int w, int h, int s) : LEVEL_WIDTH(w), LEVEL_HEIGHT(h), playerScale(32 * (s / 2)) {}
	~Camera();
};

