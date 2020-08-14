#include"Common_Function.h"
#include"MainObject.h"
#undef main


//khoi tao ban dau
bool Init()
{
	//kiem tra che do thu vien SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		return false;
	}
	//thiet lap che do man hinh
	g_screen = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP,SDL_SWSURFACE);
	//kiem tra dinh dang man hinh 
	if (g_screen == NULL)
		return false;
	return true;
}


int main(int arc, char* argv[])
{	
	//tao bien kt loop
	bool is_quit = false;
	if (Init() == false)
		return 0;
	//load anh nen
	g_bkground = SDLCommonFunc::LoadImage("bkground.png");
	//kt load anh co thanh cong ko
	if (g_bkground == NULL)
	{
		return 0;
	}

	
	//tao doi tuong nv
	MainObject human_object;
	//xac dinh vi tri nv
	human_object.SetRect(300, 420);
	//lay hinh anh nv
	bool ret = human_object.LoadImg("z.png");
	//kt ret sai thi tra ve 0
	if (!ret) {
		return 0;
	}
	
	
	while (!is_quit)
	{ 
		//kt su kien event
		while (SDL_PollEvent(&g_even))
		{
			//kt even 
			if (g_even.type == SDL_QUIT)
			{
				is_quit = true;
				break;
			}
			human_object.HandleInputAction(g_even);
		}
		//reset bkground
		SDLCommonFunc::ApplySurface(g_bkground, g_screen, 0, 0);

		//cap nhat lai vi tri nv
		human_object.Show(g_screen);
		human_object.HandleMove();
		//kt xem co dan dc ban ra hay ko
		for (int i = 0; i < human_object.GetAmoList().size(); i++)
		{
			//lay list vien dan ra
			std::vector<AmoObject*> amo_list = human_object.GetAmoList();
			//lay dc vien dan 
			AmoObject* p_amo = amo_list.at(i);
			//kt neu dan dc ban ra
			if (p_amo != NULL)
			{
				if (p_amo->get_is_move())
				{
					//show vien dan ra
					p_amo->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
					p_amo->Show(g_screen);
				}
				else
				{

					if (p_amo != NULL)
					{
						//xoa vien dan neu bay qua man hinh
						amo_list.erase(amo_list.begin() + i);
						human_object.SetAmoList(amo_list);

						delete p_amo;
						p_amo = NULL;
					}

				}
			}
		}
		//kt man hinh 
		if (SDL_Flip(g_screen) == -1)
			return 0;
	}
	SDLCommonFunc::CleanUp();
	SDL_Quit();
	return 0;
}