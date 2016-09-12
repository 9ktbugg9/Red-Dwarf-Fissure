#include "stdafx.h"
#include "CTexture.h"

SDL_Window CTexture::*mWindow = NULL;

bool CTexture::loadFromFile(std::string path) {
	free();
	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
		std::cout << "-Unable to Load Image- Reason: " << IMG_GetError() << "  -Path: " << path.c_str();
	else {
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0xFF, 0x00, 0xFF));
		newTexture = SDL_CreateTextureFromSurface(mRenderer, loadedSurface);
		if (newTexture == NULL)
			std::cout << "-Unable to Create Texture- Reason: " << SDL_GetError() << "  -Path: " << path.c_str();
		else {
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}
		SDL_FreeSurface(loadedSurface);
	}
	mTexture = newTexture;
	return mTexture != NULL;
}

void CTexture::free() {
	if (mTexture != NULL) {
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = mHeight = 0;
	}
}

void CTexture::render(int x, int y, SDL_Rect* clip, double scaleW, double scaleH, int sW, int sH, double angle, SDL_Point* center, SDL_RendererFlip flip) {
	SDL_Rect renderQuad = {x, y, mWidth, mHeight};
	if (scaleW == 0)
		scaleW = 1;
	if (scaleH == 0)
		scaleH = 1;
	if (clip != NULL) {
		if (sW != 0 && sH != 0) {
			renderQuad.w = sW;
			renderQuad.h = sH;
		}
		else {
			renderQuad.w = clip->w;
			renderQuad.h = clip->h;
			renderQuad.w *= static_cast<int>(scaleW);
			renderQuad.h *= static_cast<int>(scaleH);
		}
	}
	SDL_RenderCopyEx(mRenderer, mTexture, clip, &renderQuad, angle, center, flip);
}

void CTexture::render(int x, int y, SDL_Rect *pos, SDL_Renderer *rend) {
	SDL_Rect renderQuad = {x, y, mWidth, mHeight};

	SDL_RenderCopy(rend, mTexture, &renderQuad, pos);
}