#include "stdafx.h"
#include "SpriteMngr.h"


SpriteMngr::SpriteMngr(SDL_Renderer *src) {
	mRenderer = src;

	//clips.setRenderer(mRenderer);

}


SpriteMngr::~SpriteMngr() {
	//clips.free();
}
