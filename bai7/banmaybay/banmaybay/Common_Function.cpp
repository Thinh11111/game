#include"Common_Function.h"
//ham load anh
SDL_Surface* SDLCommonFunc:: LoadImage(std::string file_path)
{
	//Lay KQ viec doc anh
	SDL_Surface* load_image = NULL;
	//toi uu dinh dang
	SDL_Surface* optimize_image = NULL;
	load_image = IMG_Load(file_path.c_str());
	//kiem tra Null
	if (load_image != NULL)
	{
		optimize_image = SDL_DisplayFormat(load_image);
		//giai phong anh
		SDL_FreeSurface(load_image);

		if (optimize_image != NULL)
		{
			//lay ma mau cua background
			UINT32 color_key = SDL_MapRGB(optimize_image->format, 0, 0xFF, 0xFF);
			//lam trung mau nv voi nen
			SDL_SetColorKey(optimize_image, SDL_SRCCOLORKEY, color_key);
		}
	}

	return optimize_image;
}

//ham load anh vao man hinh screen
void SDLCommonFunc:: ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y)
{
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(src, NULL, des, &offset);
}

//ham giai phong vung nho
void SDLCommonFunc::CleanUp()
{
	//giai phong man hinh
	SDL_FreeSurface(g_screen);
	//giai phong anh nen
	SDL_FreeSurface(g_bkground);
}



