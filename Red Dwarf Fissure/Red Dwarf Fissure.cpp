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
	Character player(SDL_Point{10, 250}, &sprites, &tileMap, window._renderer, &cam);


	Uint32 startingTick, fpsTick = SDL_GetTicks();
	int actFPS = 0;
	bool running = true;
	while (running) {
		startingTick = SDL_GetTicks();
		actFPS++;

		if (!window.pEvents())
			break;

		int mouseX = 0, mouseY = 0;
		const Uint8 *CKS = SDL_GetKeyboardState(nullptr);
		const Uint16 CMS = SDL_GetMouseState(&mouseX, &mouseY);
		SDL_Point mousePos{mouseX, mouseY};


		SDL_SetRenderDrawColor(window._renderer, 0, 255, 255, 0xFF);
		SDL_RenderClear(window._renderer);

		tileMap.render(&cam);
		player.update(CKS, CMS, mousePos);
		cam.update(SDL_Point{player.getX(), player.getY()});
		player.render();

		SDL_RenderPresent(window._renderer);

		if (SDL_GetTicks() > fpsTick + 1000) {
			fpsTick = SDL_GetTicks();
			cout << actFPS << endl;
			actFPS = 0;
		}
		if ((1000 / FPS) > SDL_GetTicks() - startingTick)
			SDL_Delay(1000 / FPS - (SDL_GetTicks() - startingTick));
	}
	return 0;
}