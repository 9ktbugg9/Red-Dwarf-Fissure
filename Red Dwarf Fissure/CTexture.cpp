#include "stdafx.h"
#include "CTexture.h"

bool CTexture::loadFromFile(string path) {
	free();

	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());

	if (loadedSurface == NULL)
		cout << "-Unable to Load Image- Reason: " << IMG_GetError() << endl;

	else {
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 255, 0, 255));
		newTexture = SDL_CreateTextureFromSurface(mRenderer, loadedSurface);

		if (newTexture == NULL)
			cout << "-Unable to Create Texture- Image: " << path.c_str() << " -Reason: " << SDL_GetError() << endl;

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
			renderQuad.w *= scaleW;
			renderQuad.h *= scaleH;
		}
	}

	SDL_RenderCopyEx(mRenderer, mTexture, clip, &renderQuad, angle, center, flip);
}