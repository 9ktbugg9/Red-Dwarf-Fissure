#pragma once
#include <vector>
#include <random>
#include "Tile.h"
#include "Camera.h"

class TileMap {
private:
	int tileAmount, _width, _height;

	std::string _path;
	void setTiles(SpriteMngr *);
	SDL_Renderer *_rend;
	SDL_Window *_wind;
public:
	std::vector<Tile> tileSet;

	int levelWidth() { return _width; }
	int levelHeight() { return _height; }
	int getTileAmount() { return tileAmount; }

	void render(Camera *);

	TileMap(std::string, SpriteMngr *, SDL_Renderer *, SDL_Window *);
	~TileMap();
};

