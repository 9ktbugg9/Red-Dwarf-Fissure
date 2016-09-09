#include "stdafx.h"
#include "Screen.h"

bool Screen::init(string WINDOW_NAME) {
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		cout << "-Initialization Failed- Reason: " << SDL_GetError() << endl;
		success = false;
	}
	else {
		gWindow = SDL_CreateWindow(WINDOW_NAME.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL) {
			cout << "-Window Creation Failed- Reason: " << SDL_GetError() << endl;
			success = false;
		}
		else {
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL) {
				cout << "-Renderer Creation Failed- Reason: " << SDL_GetError() << endl;
				success = false;
			}
			else {
				SDL_SetRenderDrawColor(gRenderer, 0xff, 0xff, 0xff, 0xff);

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags)) {
					cout << "-SDL_Image Error- Reason: " << IMG_GetError() << endl;
					success = false;
				}
				else {
					if (!loadMedia())
						cout << "-Failed to Load Media- Reason: " << SDL_GetError() << endl;
				}
			}
		}
	}
	return success;
}

bool Screen::loadMedia() {
	bool success = true;

	return success;
}


void Screen::close() {
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL; gRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* Screen::loadTexture(string path) {
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
		cout << "-Unable to Load Image- Image: " << path.c_str() << "Reason: " << IMG_GetError() << endl;
	else {
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
			cout << "-Unable to Create Texture- Image: " << path.c_str() << "Reason: " << SDL_GetError() << endl;
		SDL_FreeSurface(loadedSurface);
	}
	return newTexture;
}