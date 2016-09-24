#pragma once
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "GlobalVars.h"

class CTexture {
private:
	int _width = 0, _height = 0;
	SDL_Texture *_texture = nullptr;
	SDL_Renderer *_renderer = nullptr;
	SDL_Window *_window = nullptr;
	std::string  _path;

	void* mPixels;
	int mPitch;

public:
	bool loadFromFile(std::string);
	void render(int x, int y, SDL_Rect *clip = nullptr, double scaleW = 1, double scaleH = 1, int sW = 0, int sH = 0, double angle = 0.0, SDL_Point* center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void render(int, int, SDL_Rect *, SDL_Renderer *);
	int getWidth() { return _width; }
	int getHeight() { return _height; }
	std::string getPath() { return _path; }
	void setWH(int w, int h) { _width = w; _height = h; }
	void setSpecs(SDL_Renderer *src, SDL_Window *win) { _renderer = src; _window = win; }
	void free();
	void setAlpha(Uint8 alpha) { SDL_SetTextureAlphaMod(_texture, alpha); }
	void setBlendMode(SDL_BlendMode blnd = SDL_BLENDMODE_BLEND) { SDL_SetTextureBlendMode(_texture, blnd); }

	CTexture() {};
	~CTexture() { free(); }
};
