#ifndef COMMON_FUNC_H
#define COMMON_FUNC_H

#include <Windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include <string>

//khoi tao chieu rong man hinh
const int SCREEN_WIDTH = 1200;
//khoi tao chieu cao man hinh
const int SCREEN_HEIGHT = 600;
//khoi tao BPP
const int SCREEN_BPP = 32;
//quan li man hinh
static SDL_Surface* g_screen = NULL;
//quan li background anh
static SDL_Surface* g_bkground = NULL;
static SDL_Event g_even;


namespace SDLCommonFunc {
	SDL_Surface* LoadImage(std::string flie_path);
	void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
	void CleanUp();
}

#endif  
