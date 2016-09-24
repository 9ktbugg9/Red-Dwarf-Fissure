#include "stdafx.h"
#include <ctime>
#include "Window.h"
#include "Camera.h"
#include "SpriteMngr.h"
#include "AudioMngr.h"
#include "TileMap.h"
#include "Character.h"

#define WINDOW_NAME "Red Dwarf Fissure"
#define FPS 60

int main(int args, char* argc[]) {
	srand(unsigned(time(nullptr)));

	Window window(WINDOW_NAME);
	//AudioMngr sounds;
	SpriteMngr sprites(window._renderer, window._window);
	TileMap tileMap(sprites.startingMap.getPath(), &sprites, window._renderer, window._window);
	Camera cam(tileMap.levelWidth() * static_cast<int>(TILE_SCALE), tileMap.levelHeight() * static_cast<int>(TILE_SCALE), static_cast<int>(SCALE));
	Character player(SDL_Point{10, 250}, &sprites, &tileMap);

	Uint32 startingTick, fpsTick = SDL_GetTicks();
	bool running = true;
	while (running) {
		startingTick = SDL_GetTicks();

		if (!window.pEvents())
			running = false;

		const Uint8 *CKS = SDL_GetKeyboardState(nullptr);

		SDL_RenderClear(window._renderer);
		SDL_SetRenderDrawColor(window._renderer, 255, 255, 255, 0xFF);

		tileMap.render(&cam);
		player.update(CKS);
		cam.update(SDL_Point{player.getX(), player.getY()});
		player.render(&cam);

		SDL_RenderPresent(window._renderer);

		if ((1000 / FPS) > SDL_GetTicks() - startingTick)
			SDL_Delay(1000 / FPS - (SDL_GetTicks() - startingTick));
	}
	return 0;
}