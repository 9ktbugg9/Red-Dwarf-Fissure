#pragma once
#include "SDL.h"
#include "SDL_mixer.h"
#include "SDL_image.h"
#include <iostream>
#include "CTexture.h"
#include "GlobalVars.h"

using namespace std;

class Window {
private:
	void close();
	bool init(string);

public:

	SDL_Texture* loadTexture(string path);

	SDL_Window* _window = NULL;
	SDL_Renderer* _renderer = NULL;

	bool pEvents();

	int getWidth() { return SCREEN_WIDTH; }
	int getHeight() { return SCREEN_HEIGHT; }


	Window(string winName) { init(winName); }
	~Window() { close(); }
};

