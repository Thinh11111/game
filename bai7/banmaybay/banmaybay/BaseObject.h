#ifndef BASE_OBJECT_H_
#define BASE_OBJECTH_
#pragma once

#include "Common_Function.h"
class BaseObject {

public:
	BaseObject();
	~BaseObject();
	// Dich Den Cua Hinh
	void Show(SDL_Surface* des);
	// File HinhAnh Duoc Lay
	bool LoadImg(const char* file_name);
	// Lay Toa Do Hinh Anh Nam O Dau
	void SetRect(int x, int y) {
		Rect_.x = x;
		Rect_.y = y;
	}
	SDL_Rect GetRect() const { return Rect_; };
	SDL_Surface* GetObject() { return p_object_; }
protected:
	SDL_Rect Rect_;
	SDL_Surface* p_object_;
};


#endif // BASEOBJECT_H