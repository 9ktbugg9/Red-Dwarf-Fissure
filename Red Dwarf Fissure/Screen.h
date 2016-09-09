#pragma once
#include "SDL.h"
#include "SDL_mixer.h"
#include "SDL_image.h"
#include <iostream>
#include "CTexture.h"
#include "GlobalVars.h"

using namespace std;

class Screen {
private://SCREEN_WIDTH / 16 * 9;
	void close();
	bool init(string);
	bool loadMedia();

public:

	SDL_Texture* loadTexture(string path);

	SDL_Window* gWindow = NULL;
	SDL_Renderer* gRenderer = NULL;
	SDL_Texture* gTexture = NULL;
	SDL_Texture* gCurrentTexture = NULL;

	int getWidth() { return SCREEN_WIDTH; }
	int getHeight() { return SCREEN_HEIGHT; }


	Screen(string winName) { init(winName);}
	~Screen() { close(); }
};

