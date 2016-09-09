#pragma once
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
using namespace std;

class CTexture {
private:
	int mWidth = 0, mHeight = 0;
	SDL_Texture* mTexture = NULL;
	SDL_Renderer* mRenderer = NULL;

public:
	bool loadFromFile(string);
	void render(int x, int y, SDL_Rect* clip = NULL, double scaleW = 1, double scaleH = 1, int sW = 0, int sH = 0, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	int getWidth() { return mWidth; }
	int getHeight() { return mHeight; }
	void setWH(int w, int h) { mWidth = w; mHeight = h; }
	void setRenderer(SDL_Renderer *src) { mRenderer = src; }
	void free();

	CTexture() {};
	~CTexture() { free(); }
};
