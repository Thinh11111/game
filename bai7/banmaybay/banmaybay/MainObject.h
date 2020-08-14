#pragma once

#ifndef  MAIN_OBJECT_H
#define MAIN_OBJECT_H

#include "Common_Function.h"
#include "BaseObject.h"
#include"AmoObject.h"
#include<vector>
#define WIDTH_MAIN_OBJECT 64
#define HEIGHT_MAIN_OBJECT 90

// tro file MainSang file BseObject

class MainObject : public BaseObject
{
public:
	MainObject();
	~MainObject();

	// Su Ly Hanh Dong Cua Nhan Vat

	void HandleInputAction(SDL_Event events);
	void HandleMove();
	//get set list vien dan
	void SetAmoList(std::vector<AmoObject*> amo_list) { p_amo_list_ = amo_list; }
	std::vector<AmoObject*> GetAmoList() const { return p_amo_list_; }
private:
	int x_val_;
	int y_val_;
	//khoi tao list vien dan
	std::vector<AmoObject*> p_amo_list_;
};




#endif // ! MAIN_OBJECT_H#pragma once
