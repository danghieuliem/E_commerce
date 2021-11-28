#include "E_commerce.hpp"

Date::Date()
{

	this->Ngay = 1;
	this->Thang = 1;
	this->Nam = 1000;

}



bool Date::Set_NgTgNm(const int& Ngay, const int& Thang, const int& Nam)
{

	this->Nam = Nam;

	if (Thang > 0 && Thang < 13)
		this->Thang = Thang;
	else
		return false;

	if (this->Nam % 4 == 0 && this->Nam % 100 != 0 || this->Nam % 400 == 0)
	{
		if (Ngay > 0 && Ngay < this->Ngay_Nhuan[this->Thang] + 1)
		{
			this->Ngay = Ngay;
		}
		else
			return false;
	}
	else
	{
		if (Ngay > 0 && Ngay < this->Ngay_KoNhuan[this->Thang] + 1)
		{
			this->Ngay = Ngay;
		}
		else
			return false;
	}
	return true;
}

void Date::Set_Ngay(const int& Ngay)
{
	if (this->Nam % 4 == 0 && this->Nam % 100 != 0 || this->Nam % 400 == 0)
	{
		if (Ngay > 0 && Ngay < this->Ngay_Nhuan[this->Thang] + 1)
		{
			this->Ngay = Ngay;
		}

	}
	else
	{
		if (Ngay > 0 && Ngay < this->Ngay_KoNhuan[this->Thang] + 1)
		{
			this->Ngay = Ngay;
		}
	}
}

void Date::Set_Thang(const int& Thang)
{
	if (this->Thang > 0 && this->Get_Thang() < 13)
		this->Thang = Thang;
}

void Date::Set_Nam(const int& Nam)
{
	this->Nam = Nam;
}

void Date::Show()
{
	cout << this->Ngay << "-" << this->Thang << "-" << this->Nam;
}

int Date::Get_Ngay()
{
	return this->Ngay;
}

int Date::Get_Thang()
{
	return this->Thang;
}

int Date::Get_Nam()
{
	return this->Nam;
}

Date Date::operator=(const Date& date)
{
	this->Ngay = date.Ngay;
	this->Thang = date.Thang;
	this->Nam = date.Nam;
	return *this;
}

bool Date::operator==(const Date& date)
{
	return (this->Ngay == date.Ngay
		&& this->Thang == date.Thang
		&& this->Nam == date.Nam);
}