#include "stdafx.h"
#include "Window.h"

bool Window::init(string WINDOW_NAME) {
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		cout << "-Initialization Failed- Reason: " << SDL_GetError() << endl;
		success = false;
	}

	else {
		_window = SDL_CreateWindow(WINDOW_NAME.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (_window == NULL) {
			cout << "-Window Creation Failed- Reason: " << SDL_GetError() << endl;
			success = false;
		}

		else {

			_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_PRESENTVSYNC);

			SDL_SetRenderDrawBlendMode(_renderer, SDL_BLENDMODE_BLEND);

			if (_renderer == NULL) {
				cout << "-Renderer Creation Failed- Reason: " << SDL_GetError() << endl;
				success = false;
			}

			else {

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags)) {
					cout << "-SDL_Image Error- Reason: " << IMG_GetError() << endl;
					success = false;
				}
				else {
					SDL_Surface *icon = IMG_Load("res/textures/Icon.png");
					SDL_SetWindowIcon(_window, icon);
					SDL_FreeSurface(icon);
				}
			}
		}
	}
	return success;
}

bool Window::pEvents() {
	bool running = true;
	SDL_Event event;

	if (SDL_PollEvent(&event) != NULL) {
		switch (event.type) {
			case SDL_QUIT: running = false; break;

			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE) running = false;
				break;

			default: break;
		}
	}
	return running;
}

SDL_Texture* Window::loadTexture(string path) {
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
		cout << "-Unable to Load Image- Image: " << path.c_str() << "Reason: " << IMG_GetError() << endl;
	else {
		newTexture = SDL_CreateTextureFromSurface(_renderer, loadedSurface);
		if (newTexture == NULL)
			cout << "-Unable to Create Texture- Image: " << path.c_str() << "Reason: " << SDL_GetError() << endl;
		SDL_FreeSurface(loadedSurface);
	}
	return newTexture;
}

void Window::close() {
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	_window = NULL; _renderer = NULL;

	IMG_Quit();
	SDL_Quit();
}