#ifndef AMO_OBJECT_H_
#define AMO_OBJECT_H_
#include "BaseObject.h"

#define WIDTH_AKM 35
#define HEIGHT_AKM 5

#define WIDTH_SPHERE 10
#define HEIGHT_SPHERE 10
//tao doi tuong vien dan
class AmoObject : public BaseObject
{
public:
    //cac dang cua vien dan
    enum AmoType
    {
        NONE = 0,//dan chua xuat hien
        AKM = 1,//dan sung AK
        SPHERE = 2// dan hinh cau
    };
    //tao constructor
    AmoObject();
    ~AmoObject();
    void HandleInputAction(SDL_Event events);
    void HandleMove(const int& x_border, const int& y_border);
    //ham get set de lay cac gia tri
    int get_type() const { return amo_type_; }
    void set_type(const int& type) { amo_type_ = type; }

    bool get_is_move() const { return is_move_; }
    void set_is_move(bool is_move) { is_move_ = is_move; }
    //ham dinh dang vien dan theo tung loai
    void SetWidthHeight(const int& widht, const int& height) { Rect_.w = widht; Rect_.h = height; };
private:
    //vi tri vien dan 
    int x_val_;
    int y_val_;
    bool is_move_;
    int amo_type_;
};


#endif
