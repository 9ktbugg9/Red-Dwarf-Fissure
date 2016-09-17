#include "stdafx.h"
#include <ctime>
#include "Window.h"
#include "Camera.h"
#include "SpriteMngr.h"
#include "AudioMngr.h"
#include "TileMap.h"

#define WINDOW_NAME "Red Dwarf Fissure"
#define FPS 60

int main(int args, char* argc[]) {
	srand(unsigned(time(nullptr)));

	Window window(WINDOW_NAME);
	//AudioMngr sounds;
	SpriteMngr sprites(window._renderer, window._window);
	TileMap tileMap("res/levels/spawn_level.png", &sprites, window._renderer, window._window);

	Camera cam(tileMap.levelWidth() * static_cast<int>(TILE_SCALE), tileMap.levelHeight() * static_cast<int>(TILE_SCALE), static_cast<int>(SCALE));

	Uint32 startingTick, fpsTick = SDL_GetTicks();
	bool running = true;
	while (running) {
		startingTick = SDL_GetTicks();

		if (!window.pEvents())
			running = false;

		const Uint8 *CKS = SDL_GetKeyboardState(nullptr);

		if (CKS[SDL_SCANCODE_W])
			cam.camera.y -= 4;
		if (CKS[SDL_SCANCODE_S])
			cam.camera.y += 4;
		if (CKS[SDL_SCANCODE_D])
			cam.camera.x += 4;
		if (CKS[SDL_SCANCODE_A])
			cam.camera.x -= 4;

		cam.constrain();

		SDL_RenderClear(window._renderer);
		SDL_SetRenderDrawColor(window._renderer, 30, 30, 30, 0xFF);

		tileMap.render(&cam);

		SDL_RenderPresent(window._renderer);

		if ((1000 / FPS) > SDL_GetTicks() - startingTick)
			SDL_Delay(1000 / FPS - (SDL_GetTicks() - startingTick));
	}
	return 0;
}