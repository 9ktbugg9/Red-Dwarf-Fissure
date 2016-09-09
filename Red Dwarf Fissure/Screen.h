#pragma once
#include "SDL.h"
#include "SDL_mixer.h"
#include "SDL_image.h"
#include <iostream>
#include "CTexture.h"
#include "GlobalVars.h"

using namespace std;

#define WINDOW_NAME "Red Dwarf Fissure"

class Screen {
private://SCREEN_WIDTH / 16 * 9;
	void close();
	bool init();
	bool loadMedia();

public:

	SDL_Texture* loadTexture(string path);

	SDL_Window* gWindow = NULL;
	SDL_Renderer* gRenderer = NULL;
	SDL_Texture* gTexture = NULL;
	SDL_Texture* gCurrentTexture = NULL;

	int getWidth() { return SCREEN_WIDTH; }
	int getHeight() { return SCREEN_HEIGHT; }


	Screen() { init();}
	~Screen() { close(); }
};

