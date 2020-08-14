
#include "AmoObject.h"
//tao constructor tham so cua vien dan
AmoObject::AmoObject()
{
    Rect_.x = 0;
    Rect_.y = 0;
    x_val_ = 0;
    y_val_ = 0;
    is_move_ = false;//chua xuat hien
    amo_type_ = NONE;//chua co dang j ca
}
//constructor ko tham so
AmoObject::~AmoObject()
{

}
//ham xuat hien vien dan
void AmoObject::HandleMove(const int& x_border, const int& y_border)
{
    if (is_move_ == true)
    {
        //ban thang theo truc x
        Rect_.x += 20;
        //huy vien dan neu dan vuot qua man hinh
        if (Rect_.x > x_border)
        {
            is_move_ = false;
        }
    }
}
//ham di chuyen dan tu phai sang trai
void AmoObject::HandleMoveRighttoLeft()
{
    //toc do ban
    Rect_.x -= 10;
    if (Rect_.x < 0)
    {
        is_move_ = false;
    }
}
void AmoObject::HandleInputAction(SDL_Event events)
{
    ;//Todo
}
