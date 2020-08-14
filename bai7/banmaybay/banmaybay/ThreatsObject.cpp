#include"ThreatsObject.h"

//dinh nghia vi tri dich
ThreatObject::ThreatObject()
{

	//xuat hien ben phai
	Rect_.x = SCREEN_WIDTH;
	Rect_.y = SCREEN_HEIGHT*0.5;
	Rect_.w = WIDTH_THREAT;
	Rect_.h = HEIGHT_THREAT;
	//khoi tao vi tri ban dau
	x_val_=0;
	y_val_=0;
}
ThreatObject::~ThreatObject()
{
	//delete dan de giai phogn vung nho
	if (p_amo_list_.size() > 0)
	{
		for (int i = 0; i < p_amo_list_.size(); i++)
		{
			AmoObject* p_amo = p_amo_list_.at(i);
			//dan khac NULL thi delete
			if (p_amo != NULL)
			{
				delete p_amo;
				p_amo = NULL;
			}
		}
		p_amo_list_.clear();
	}
}
//khoi tao doi tuong vien dan cho dich
void ThreatObject::InitAmo(AmoObject* p_amo)
{
	if (p_amo)
	{
		//load dan
		bool ret = p_amo->LoadImg("dan1.png");
		//neu thanh cong cho phep dan di chuyen
		if (ret)
		{
			//di chuyen dan
			p_amo->set_is_move(true);
			p_amo->SetWidthHeight(WIDTH_AKM, HEIGHT_AKM);
			p_amo->set_type(AmoObject::AKM);
			//vi tri xuat hien vien dan o may bay dich
			p_amo->SetRect(Rect_.x, Rect_.y*(-0,2)) ;
			//luu dan vao list
			p_amo_list_.push_back(p_amo);
		}
	}
}
//ham ban dan ra
void ThreatObject::MakeAmo(SDL_Surface* des, const int& x_limit, const int& y_limit) {
	//kt dan
	for (int i = 0; i < p_amo_list_.size(); i++)
	{
		//lay dan ra
		AmoObject* p_amo = p_amo_list_.at(i);
		if (p_amo)
		{
			if (p_amo->get_is_move())
			{
				p_amo->Show(des);
				//goi ham ban tu phai sang trai
				p_amo->HandleMoveRighttoLeft();
			}
			else
			{
				//tai su dung vien dan da ban
				p_amo->set_is_move(true);
				p_amo->SetRect(Rect_.x, Rect_.y + Rect_.h );
			}
		}
	}
}
//ham di chuyen
void ThreatObject::HandleMove(const int& x_bordr, const int& y_bordr)
{
	//di chuyen tu phai qua trai
	Rect_.x -= x_val_;
	//neu di chuyen vuot man hinh thi tro lai vi tri ngau nhien
	if (Rect_.x < 0)
	{
		Rect_.x = SCREEN_WIDTH;
		//tao so luong may bay dich ngau nhien
		int rand_y = rand() % 400;
		//kt so luong vuot qua man hinh 
		if (rand_y > SCREEN_HEIGHT)
		{
			//tao lai
			rand_y = SCREEN_HEIGHT * 0.3;
		}
		Rect_.y = rand_y;
	}
}



void ThreatObject::HandleInputAction(SDL_Event events)
{

}