#include"E_commerce.hpp"

void Info::Set_TacGia(const string& Tac_Gia)
{
	this->TacGia = Tac_Gia;
}
void Info::Set_NhaXuatBan(const string& Nha_Xuat_Ban)
{
	this->NhaXuatBan = Nha_Xuat_Ban;
}
void Info::Set_NgayXuatBan(const Date& date)
{
	this->NgayXuatBan = date;
}
string Info::Get_TacGia()
{
	return this->TacGia;
}
string Info::Get_NhaXuatBan()
{
	return this->NhaXuatBan;
}
Date Info::Get_NgayXuatBan()
{
	return this->NgayXuatBan;
}
Info Info::operator = (const Info& info)
{
	this->TacGia = info.TacGia;
	this->NhaXuatBan = info.NhaXuatBan;
	this->NgayXuatBan = info.NgayXuatBan;
	return info;
}