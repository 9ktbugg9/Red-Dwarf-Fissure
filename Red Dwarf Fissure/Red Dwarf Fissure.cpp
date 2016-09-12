#include "stdafx.h"
#include "Window.h"
#include "Camera.h"
#include "SpriteMngr.h"
#include "AudioMngr.h"
#include "TileMap.h"

#define WINDOW_NAME "Red Dwarf Fissure"
#define FPS 60

int main(int args, char* argc[]) {

	Window window(WINDOW_NAME);
	Camera camera(window.getWidth(), window.getHeight());
	AudioMngr *sounds;
	SpriteMngr sprites(window._renderer, window._window);
	TileMap tileMap("res/levels/spawn_level.png", &sprites, window._renderer, window._window);

	Camera cam(tileMap.levelWidth() * static_cast<int>(SCALE), tileMap.levelHeight() * static_cast<int>(SCALE), static_cast<int>(SCALE));

	Uint32 startingTick, fpsTick = SDL_GetTicks();

	bool running = true;
	while (running) {
		startingTick = SDL_GetTicks();

		if (!window.pEvents())
			running = false;

		SDL_RenderClear(window._renderer);
		SDL_SetRenderDrawColor(window._renderer, 30, 30, 30, 0xFF);

		tileMap.render(&cam);

		SDL_RenderPresent(window._renderer);

		if ((1000 / FPS) > SDL_GetTicks() - startingTick) {
			SDL_Delay(1000 / FPS - (SDL_GetTicks() - startingTick));
		}
	}
	return 0;
}