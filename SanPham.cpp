#include"E_commerce.hpp"

void SanPham::Set_Ten(const string& Ten)
{
	this->Ten = Ten;
}
void SanPham::Set_Loai(const string& Loai)
{
	this->Loai = Loai;
}
void SanPham::Set_MaSP(const string& MaSp)
{
	this->MaSanPham = MaSp;
}
void SanPham::Set_Gia(const int& Gia)
{
	this->Gia = Gia;
}
void SanPham::Set_KM(const int& KM)
{
	this->KhuyenMai = KM;
}
void SanPham::Set_Info(const Info& Info)
{
	this->info = Info;
}
string SanPham::Get_Ten()
{
	return this->Ten;
}
string SanPham::Get_Loai()
{
	return this->Loai;
}
string SanPham::Get_MaSP()
{
	return this->MaSanPham;
}
int SanPham::Get_Gia()
{
	return this->Gia;
}
int SanPham::Get_KM()
{
	return this->KhuyenMai;
}
Info SanPham::Get_Info()
{
	return this->info;
}
void SanPham::Show_SanPham()
{
	cout << "  Ten       : " << this->Ten <<"\n";
	cout << "  Loai      : " << this->Loai << "\n";
	cout << "  KhuyenMai : " << this->KhuyenMai << "%\n";
	cout << "  Gia       : " << this->Gia << " VND\n";
}
void SanPham::Show_SanPham_Info()
{
	Date Dtemp = this->info.Get_NgayXuatBan();
	cout << "  Ten           : " << this->Ten << "\n";
	cout << "  Loai          : " << this->Loai << "\n";
	cout << "  Tac gia       : " << this->info.Get_TacGia() << "\n";
	cout << "  Nha xuat ban  : " << this->info.Get_NhaXuatBan() << "\n";
	cout << "  Ngay xuat ban : " << Dtemp.Get_Ngay() << "-" << Dtemp.Get_Thang() << "-" << Dtemp.Get_Nam()<<"\n";
	cout << "  Gia           : " << this->Gia << " VND\n";
	cout << "  KhuyenMai     : " << this->KhuyenMai << "%\n";
}
SanPham SanPham::operator = (const SanPham& San_Pham)
{
	this->Gia = San_Pham.Gia;
	this->info = San_Pham.info;
	this->KhuyenMai = San_Pham.KhuyenMai;
	this->Loai = San_Pham.Loai;
	this->MaSanPham = San_Pham.MaSanPham;
	return San_Pham;
}