#include "stdafx.h"
#include "SDL.h"
#include "Screen.h"

int main(int args, char* argc[]) {
	Screen screen;

	SDL_Event event;
	bool running = true;
	while (running) {
		if (SDL_PollEvent(&event) != NULL) {
			if (event.type == SDL_QUIT)
				running = false;

			if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_ESCAPE)
					running = false;

			}
		}
	}
	return 0;
}