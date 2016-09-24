#pragma once
#include "SDL.h"
#include "GlobalVars.h"


class Camera {
private:
	int LEVEL_WIDTH, LEVEL_HEIGHT;
	int playerScale;

public:
	SDL_Rect camera = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

	void constrain();
	void update(SDL_Point);

	Camera(int w, int h, int s = 0) : LEVEL_WIDTH(w), LEVEL_HEIGHT(h), playerScale(32 * (s / 2)) {}
	~Camera();
};

