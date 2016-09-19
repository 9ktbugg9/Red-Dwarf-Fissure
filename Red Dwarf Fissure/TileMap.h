#pragma once
#include <vector>
#include <random>
#include "Tile.h"
#include "Camera.h"

class TileMap {
private:
	int tileAmount, mWidth, mHeight;

	std::string _path;
	void setTiles(SpriteMngr *);
	SDL_Renderer *rend;
	SDL_Window *wind;
public:
	std::vector<Tile> tileSet;

	int levelWidth() { return mWidth; }
	int levelHeight() { return mHeight; }
	int getTileAmount() { return tileAmount; }

	void render(Camera *);

	TileMap(std::string, SpriteMngr *, SDL_Renderer *, SDL_Window *);
	~TileMap();
};

