#include "stdafx.h"
#include "TileMap.h"

Uint32 get_pixel_at(Uint32 * pixels, int x) {
	return pixels[x];
}

void TileMap::render(Camera *cam) {
	for (int i = 0; i < tileAmount; ++i)
		tileSet[i].render(cam->camera);
}

bool TileMap::setTiles(SpriteMngr *sprMngr) {
	mWidth = sprMngr->startingMap.getWidth() * 16;
	mHeight = sprMngr->startingMap.getHeight() * 16;
	tileAmount = sprMngr->startingMap.getHeight() * sprMngr->startingMap.getWidth();
	//std::cout << tileAmount;
	bool tilesLoaded = true;
	int x = 0, y = 0;

	void* mPixels = nullptr;
	int mPitch = 0;

	SDL_Texture* newTexture = nullptr;
	SDL_Surface* loadedSurface = IMG_Load(_path.c_str());

	SDL_Surface* formattedSurface = SDL_ConvertSurface(loadedSurface, SDL_GetWindowSurface(wind)->format, NULL);

	newTexture = SDL_CreateTexture(rend, SDL_GetWindowPixelFormat(wind), SDL_TEXTUREACCESS_STREAMING, formattedSurface->w, formattedSurface->h);

	SDL_LockTexture(newTexture, NULL, &mPixels, &mPitch);

	memcpy(mPixels, formattedSurface->pixels, formattedSurface->pitch * formattedSurface->h);

	std::vector<Uint32 *> pixelColors;

	for (int i = 0; i < tileAmount; i++) {
		Uint32 pixel = get_pixel_at((Uint32 *)mPixels, i);

		Uint32 * colors = nullptr;
		colors = (Uint32 *)pixel;
		//std::cout << i / sprMngr->startingMap.getHeight() << " - " << i % sprMngr->startingMap.getWidth() << " - " << Uint32(colors) << std::endl;
		pixelColors.push_back(colors);
	}

	SDL_UnlockTexture(newTexture);
	mPixels = NULL;


	SDL_FreeSurface(formattedSurface);

	SDL_FreeSurface(loadedSurface);


	for (int i = 0; i < tileAmount; ++i) {
		int tileType = 0;
		//std::cout << int(pixelColors[i]) << std::endl;
		switch (Uint32(pixelColors[i])) {
			case 0x00000000:
				switch (rand() % 4) {
					case 0:
						tileType = sprMngr->FLOOR1;
						break;
					case 1:
						tileType = sprMngr->FLOOR2;
						break;
					case 2:
						tileType = sprMngr->FLOOR3;
						break;
					case 3:
						tileType = sprMngr->FLOOR4;
						break;
				}
				break;

			case 0x0000FF00:
				switch (rand() % 4) {
					case 0:
						tileType = sprMngr->GOOPY1;
						break;
					case 1:
						tileType = sprMngr->GOOPY2;
						break;
					case 2:
						tileType = sprMngr->GOOPY3;
						break;
					case 3:
						tileType = sprMngr->GOOPY4;
						break;
				}
				break;

			case 0x00FF0000:
				switch (rand() % 4) {
					case 0:
						tileType = sprMngr->BLOOD1;
						break;
					case 1:
						tileType = sprMngr->BLOOD2;
						break;
					case 2:
						tileType = sprMngr->BLOOD3;
						break;
					case 3:
						tileType = sprMngr->BLOOD4;
						break;
				}
				break;

			case 0x00333333:
				tileType = sprMngr->SOLID;
				break;

			case 0x00777777:
				switch (rand() % 4) {
					case 0:
						tileType = sprMngr->CRACK1;
						break;
					case 1:
						tileType = sprMngr->CRACK2;
						break;
					case 2:
						tileType = sprMngr->CRACK3;
						break;
					case 3:
						tileType = sprMngr->CRACK4;
						break;
				}
				break;

			case 0x00112233:
				tileType = sprMngr->RINGS;
				break;

			case 0x00332211:
				tileType = sprMngr->LINES;
				break;

			default:
				switch (rand() % 4) {
					case 0:
						tileType = sprMngr->SPACE1;
						break;
					case 1:
						tileType = sprMngr->SPACE2;
						break;
					case 2:
						tileType = sprMngr->SPACE3;
						break;
					case 3:
						tileType = sprMngr->SPACE4;
						break;
				}
				break;
		}

		Tile tile(x, y, tileType, sprMngr);
		tileSet.push_back(tile);

		x += 16 * static_cast<int>(TILE_SCALE);

		if (x >= mWidth * TILE_SCALE) {
			x = 0;
			y += 16 * static_cast<int>(TILE_SCALE);
		}
	}

	return tilesLoaded;
}

TileMap::TileMap(std::string mapPath, SpriteMngr *sprMngr, SDL_Renderer *renderer, SDL_Window *window) : _path(mapPath), rend(renderer), wind(window) {
	setTiles(sprMngr);
}


TileMap::~TileMap() {
}
