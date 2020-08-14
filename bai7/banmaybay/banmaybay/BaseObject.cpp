#include"BaseObject.h"
//tao ham constructor
BaseObject::BaseObject() {
	Rect_.x = 0;
	Rect_.y = 0;
	p_object_ = NULL;
}
BaseObject::~BaseObject() {
	if (p_object_ != NULL)
	{
		SDL_FreeSurface(p_object_);
	}
}

bool BaseObject::LoadImg(const char* file_name) {
	p_object_ = SDLCommonFunc::LoadImage(file_name);//doc anh tu ham loadimage
	if (p_object_ == NULL) {
		return false;
	}
	return true;
}

void BaseObject::Show(SDL_Surface* des) {
	if (p_object_ != NULL) {
		SDLCommonFunc::ApplySurface(p_object_, des, Rect_.x, Rect_.y);
	}
}