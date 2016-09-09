#include "stdafx.h"
#include "Screen.h"
#include "Camera.h"
#include "SpriteMngr.h"
#include "AudioMngr.h"

#define WINDOW_NAME "Red Dwarf Fissure"

#define FPS 60

int main(int args, char* argc[]) {
	Screen screen(WINDOW_NAME);
	Camera camera(screen.getWidth(), screen.getHeight());
	AudioMngr *sounds;
	SpriteMngr *sprites;

	SDL_SetRenderDrawBlendMode(screen.gRenderer, SDL_BLENDMODE_BLEND);

	Uint32 startingTick, fpsTick = SDL_GetTicks();

	SDL_Event event;
	bool running = true;
	while (running) {
		startingTick = SDL_GetTicks();
		if (SDL_PollEvent(&event) != NULL) {
			if (event.type == SDL_QUIT)
				running = false;

			if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_ESCAPE)
					running = false;
			}
		}

		SDL_RenderClear(screen.gRenderer);
		SDL_SetRenderDrawColor(screen.gRenderer, 255, 255, 255, 255);


		SDL_RenderPresent(screen.gRenderer);

		if ((1000 / FPS) > SDL_GetTicks() - startingTick) {
			SDL_Delay(1000 / FPS - (SDL_GetTicks() - startingTick));
		}
	}
	return 0;
}