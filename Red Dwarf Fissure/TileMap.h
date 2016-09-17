#pragma once
#include <vector>
#include <random>
#include "Tile.h"
#include "Camera.h"

class TileMap {
private:
	int tileAmount, mWidth, mHeight;
	std::vector<Tile> tileSet;

	std::string _path;
	bool setTiles(SpriteMngr *);
	SDL_Renderer *rend;
	SDL_Window *wind;
public:

	int levelWidth() { return mWidth; }
	int levelHeight() { return mHeight; }

	void render(Camera *);

	TileMap(std::string, SpriteMngr *, SDL_Renderer *, SDL_Window *);
	~TileMap();
};

