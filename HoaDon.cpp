#include"E_commerce.hpp"


HoaDon::HoaDon()
{
	this->date = "NULL";
	this->Tong_Gia = -1;
	this->ThangTien = -1;
}

void HoaDon::Set_HoaDonTK(GioHang Gio_Hang)
{
	// tra ve date/time hien tai dua tren system hien tai
	time_t hientai = time(0);

	// chuyen doi hientai thanh dang chuoi
	this->date = ctime(&hientai);
	this->date.erase(this->date.begin()+24,this->date.end());
	this->San_Pham = Gio_Hang.Get_info();

	this->Tong_Gia = 0;

	int size = this->San_Pham.size();

	for (int i = 0; i < size; i++)
	{
		this->Tong_Gia += this->San_Pham[i].first.Get_Gia();
		this->Tong_Gia *= this->San_Pham[i].second;
		this->ThangTien += this->San_Pham[i].first.Get_Gia() * (100 - this->San_Pham[i].first.Get_KM()) / 100;
		this->ThangTien *= this->San_Pham[i].second;
	}
	this->ThangTien = this->ThangTien * 95 / 100;
} 

void HoaDon::Set_HoaDon(GioHang Gio_Hang)
{
	// tra ve date/time hien tai dua tren system hien tai
	time_t hientai = time(0);

	// chuyen doi hientai thanh dang chuoi
	this->date = ctime(&hientai);
	this->San_Pham = Gio_Hang.Get_info();

	this->Tong_Gia = 0;

	int size = this->San_Pham.size();

	for (int i = 0; i < size; i++)
	{
		this->Tong_Gia += this->San_Pham[i].first.Get_Gia();
		this->Tong_Gia *= this->San_Pham[i].second;
		this->ThangTien += this->San_Pham[i].first.Get_Gia() * (100 - this->San_Pham[i].first.Get_KM()) / 100;
		this->ThangTien *= this->San_Pham[i].second;
	}
}

void HoaDon::Show()
{
	int size = this->San_Pham.size();
	cout << "-------------------------------------------------------------------\n";
	for (int i = 0; i < size; i++)
	{
		
		this->San_Pham[i].first.Show_SanPham_Info();
		cout << "So luong        : "<<this->San_Pham[i].second<<"\n";
		cout << "*********************************************************\n";
	}
	cout << "Ngay giao dich  : " << this->date << endl;
	cout << "Tong gia        : " << this->Tong_Gia << "VND\n";
	cout << "Thanh Tien      : " << this->ThangTien << "VND\n";
	cout << "-------------------------------------------------------------------\n";
}
void HoaDon::Set_date(const string& date)
{
	this->date = date;
}
void HoaDon::Set_SP(vector<pair<SanPham, int>> list_SP)
{
	this->San_Pham = list_SP;
}
void HoaDon::Set_Tong_Gia(const int& Gia)
{
	this->Tong_Gia = Gia;
}
void HoaDon::Set_ThangTien(const int& TT)
{
	this->ThangTien = TT;
}
string HoaDon::Get_date()
{
	return this->date;
}
vector<pair<SanPham, int>> HoaDon::Get_SP()
{
	return this->San_Pham;
}
int HoaDon::Get_Tong_Gia()
{
	return this->Tong_Gia;
}
int HoaDon::Get_ThangTien()
{
	return this->ThangTien;
}
int HoaDon::Get_size()
{
	return this->San_Pham.size();
}