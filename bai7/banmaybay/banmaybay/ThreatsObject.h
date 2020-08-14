#ifndef THREATS_OBJECT_H_
#define THREATS_OBJECT_H_
#include"Common_Function.h"
#include"BaseObject.h"
#include"AmoObject.h"
#include<vector>
#define WIDTH_THREAT 90
#define HEIGHT_THREAT 40
//tao doi tuong may bay dich
class ThreatObject : public BaseObject
{
public:
	//ham construtor
	ThreatObject();
	//ham destructor
	~ThreatObject();
	//ham xu li di chuyen
	void HandleMove(const int& x_bordr, const int& y_bordr);
	void HandleInputAction(SDL_Event events);
	//ham get set cho vi tri ban dau
	void set_x_val(const int& val) { x_val_ = val; }
	void set_y_val(const int& val) { y_val_ = val; }
	int get_x_val()const { return x_val_; }
	int get_y_val()const { return y_val_; }
	//ham get set dan
	void SetAmoList(std::vector<AmoObject*> amo_list) { p_amo_list_ = amo_list; }
	std::vector<AmoObject*> GetAmoList() const { return p_amo_list_; }
	//khai bao vien dan cho dich
	void InitAmo(AmoObject* p_amo);
	//ham ban dan ra
	void MakeAmo(SDL_Surface* des, const int& x_limit, const int& y_limit);

private:
	int x_val_;
	int y_val_;
	//khoi tao list vien dan
	std::vector<AmoObject*> p_amo_list_;

};

#endif