#include "Common_Function.h"
#include "MainObject.h"

MainObject::MainObject() {
	// reset Gia TRI ban dau
	Rect_.x = 0;
	Rect_.y = 0;
	Rect_.w = WIDTH_MAIN_OBJECT;
	Rect_.h = HEIGHT_MAIN_OBJECT;
	x_val_ = 0;
	y_val_ = 0;
}
MainObject ::~MainObject() {

}

void MainObject::HandleInputAction(SDL_Event events) {

	// Bat Su Kien Chuot Va Ban Phim
	if (events.type == SDL_KEYDOWN) {
		// Khi Phim An xuong ...
		switch (events.key.keysym.sym)
		{
		case SDLK_UP: // Khi An Phiem Len Thi object se dich chuyen 
			//1 doan = y_vla -= kich thuoc cua object ;
			y_val_ -= HEIGHT_MAIN_OBJECT / 8;
			break;
		case SDLK_DOWN:
			// Khi An Phiem Len Thi object se dich chuyen 
			//1 doan = y_vla += kich thuoc rong cua object ;
			y_val_ += HEIGHT_MAIN_OBJECT / 8;
			break;
		case SDLK_LEFT:
			// Khi An Phiem Len Thi object se dich chuyen 
			//1 doan = y_vla -= kich thuoc rong cua object ;
			x_val_ -= WIDTH_MAIN_OBJECT / 8;
			break;
		case SDLK_RIGHT:
			// Khi An Phiem sang phai Thi object se dich chuyen 
			//1 doan = x_vla += kich thuoc cua object ;
			x_val_ += WIDTH_MAIN_OBJECT / 8;
			break;
		default:
			break;
		}
		// Sau Khi Chinh toa do khi event say ra . thi phai thay doi object tren display
		// thong qua ham HandleMove
		// voi vi tri ban dau la  : Rect_.x = .....
		//Sau Khi event say ra thi toa do thay doi so voi vi tri ban dau : Rect_.x += x_val_ ;
	}
	else if (events.type == SDL_KEYUP) {
		// Khi Phim Duoc Tha Ra
		// Khi tha phiem ra no phai tru di 1 phan mk no da cong tren.
		// khong la no se di het duong bien man hinh
		// Khi Tha ra reset lai gia tri dang o vi tri nao
		switch (events.key.keysym.sym)
		{
		case SDLK_UP:
			y_val_ += HEIGHT_MAIN_OBJECT / 8;
			break;
		case SDLK_DOWN:
			y_val_ -= HEIGHT_MAIN_OBJECT / 8;
			break;
		case SDLK_LEFT:
			x_val_ += WIDTH_MAIN_OBJECT / 8;
			break;
		case SDLK_RIGHT:
			x_val_ -= WIDTH_MAIN_OBJECT / 8;
			break;
		default:
			break;
		}
	}
	else if (events.type == SDL_MOUSEBUTTONDOWN) {
		//	 KHI CHUOT DUOC click
		//sinh ra 1 vien dan
		AmoObject* p_amo = new AmoObject();
		//kt neu an chuot trai
		if (events.button.button == SDL_BUTTON_LEFT)
		{
			//ban dan AK
			p_amo->SetWidthHeight(WIDTH_AKM, HEIGHT_AKM);
			//load anh vien dan
			p_amo->LoadImg("dan1.png");
			//lay du lieu loai dan
			p_amo->set_type(AmoObject::AKM);
		}
		//kt neu an chuot phai
		else if (events.button.button == SDL_BUTTON_RIGHT)
		{
			//ban dan hinh cau
			p_amo->SetWidthHeight(WIDTH_SPHERE, HEIGHT_SPHERE);
			//load anh dan hinh cau
			p_amo->LoadImg("dan2.png");
			//lau du lieu dan hinh cau
			p_amo->set_type(AmoObject::SPHERE);
		}
		//cap nhat vi tri vien dan trong vung may bay
		p_amo->SetRect(this->Rect_.x + this->Rect_.w - 20, this->Rect_.y + this->Rect_.h * 0.5);
		//xuat hien vien dan 
		p_amo->set_is_move(true);
		//ban ra nhieu vien dan
		p_amo_list_.push_back(p_amo);
	}
	else if (events.type == SDL_MOUSEBUTTONUP) {
		// Chuot Khong Duoc Click
	}
}
//kt gioi han di chueyn
void MainObject::HandleMove() {
	// Van De : 
	// cap nhat vi tri khi an trai hoac phai
	Rect_.x += x_val_;
	//kt neu di chuyen vuot qua chieu dai screen tu tru di toa do  rect_x
	if (Rect_.x < 0 || Rect_.x + WIDTH_MAIN_OBJECT > SCREEN_WIDTH) {
		Rect_.x -= x_val_;
	}
	// cap nhat vi tri khi an len hoac xuong
	Rect_.y += y_val_;
	//kt neu di chuyen vuot qua chieu cao screen tu tru di toa do  rect_y
	if (Rect_.y < 0 || Rect_.y + HEIGHT_MAIN_OBJECT > SCREEN_HEIGHT ) {
		Rect_.y -= y_val_;
	}
}