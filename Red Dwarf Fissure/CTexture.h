#pragma once
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "GlobalVars.h"

class CTexture {
private:
	int mWidth = 0, mHeight = 0;
	SDL_Texture *mTexture = NULL;
	SDL_Renderer *mRenderer = NULL;
	SDL_Window *mWindow = NULL;

	void* mPixels;
	int mPitch;

public:
	bool loadFromFile(std::string);
	void render(int x, int y, SDL_Rect *clip = NULL, double scaleW = 1, double scaleH = 1, int sW = 0, int sH = 0, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void render(int, int, SDL_Rect *, SDL_Renderer *);
	int getWidth() { return mWidth; }
	int getHeight() { return mHeight; }
	void setWH(int w, int h) { mWidth = w; mHeight = h; }
	void setSpecs(SDL_Renderer *src, SDL_Window *win) { mRenderer = src; mWindow = win; }
	void free();
	void setAlpha(Uint8 alpha) { SDL_SetTextureAlphaMod(mTexture, alpha); }
	void setBlendMode(SDL_BlendMode blnd = SDL_BLENDMODE_BLEND) { SDL_SetTextureBlendMode(mTexture, blnd); }

	CTexture() {};
	~CTexture() { free(); }
};
