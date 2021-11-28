#include"E_commerce.hpp"


KhachHang::KhachHang()
{
	this->User = "NULL";
	this-> PassWord = "NULL";
	this-> Gmail = "NULL";
	this-> SDT = "NULL";
}
void KhachHang::Set_Gmail(const string& gmail)
{
	this->Gmail = gmail;
}
void KhachHang::Set_Sdt(const string& Sdt)
{
	this->SDT = Sdt;
}
void KhachHang::Set_Ng_Sinh(const Date& NgSinh)
{
	this->NgaySinh = NgSinh;
}
void KhachHang::Set_Lich_Su_Mua_Hang(const HoaDon& Hoa_Don)
{
	this->Lich_Su_Mua_Hang.push_back(Hoa_Don);
}
void KhachHang::Show_Lich_Su_Mua_Hang()
{
	int size = this->Lich_Su_Mua_Hang.size();
	for (int i = 0; i < size; i++)
	{
		cout << "STT : " << i;
		this->Lich_Su_Mua_Hang[i].Show();
	}
}
void KhachHang::Show()
{
	cout << "User      : " << this->User << "\n";
	cout << "PassWord  : " << this->PassWord << "\n";
	cout << "Gmail     : " << this->Gmail << "\n";
	cout << "Sdt       : " << this->SDT << "\n";
	cout << "Ngay Sinh : "; this->NgaySinh.Show(); cout << "\n";
}
string KhachHang::Get_Gmail()
{
	return this->Gmail;
}
string KhachHang::Get_Sdt()
{
	return this->SDT;
}
Date KhachHang::Get_Ng_Sinh()
{
	return this->NgaySinh;
}
vector<HoaDon> KhachHang::Get_Lich_Su_Mua_Hang()
{
	return this->Lich_Su_Mua_Hang;
}
void KhachHang::Set_User(const string& User)
{
	this->User = User;
}
void KhachHang::Set_PassWord(const string& PassWord)
{

	this->PassWord = PassWord;
}
string KhachHang::Get_User()
{
	return this->User;
}
string KhachHang::Get_PassWord()
{
	return this->PassWord;
}
string KhachHang::Get_Type()
{
	return "Khach Hang";
}
KhachHang KhachHang::operator=(const KhachHang& Khach_Hang)
{
	this->User = Khach_Hang.User;
	this->PassWord = Khach_Hang.PassWord;
	this->Gmail = Khach_Hang.Gmail;
	this->SDT = Khach_Hang.SDT;
	this->NgaySinh = Khach_Hang.NgaySinh;
	this->Lich_Su_Mua_Hang = Khach_Hang.Lich_Su_Mua_Hang;
	return Khach_Hang;
}

//KhachHang KhachHang::operator=(TaiKhoan Khach_Hang)
//{
//	(KhachHang)Khach_Hang.;
//}
//bool KhachHang::operator==(const KhachHang& Khach_Hang)
//{
//	return (this->User == Khach_Hang.User
//		&& this->PassWord == Khach_Hang.PassWord
//		&& this->Gmail == Khach_Hang.Gmail
//		&& this->SDT == Khach_Hang.SDT
//		&& this->NgaySinh == Khach_Hang.NgaySinh
//		&& this->Lich_Su_Mua_Hang == Khach_Hang.Lich_Su_Mua_Hang);
//}

void KhachHang::Set_Lich_Su_Mua_Hang(vector<HoaDon> List_HD)
{
	this->Lich_Su_Mua_Hang = List_HD;
}

void  KhachHang::UpData() {

	ofstream Out;
	string Stemp = this->User + ".txt";
	Out.open(Stemp);
	
	int size_history = this->Lich_Su_Mua_Hang.size();
	Out << size_history << endl;
	vector<pair<SanPham, int>> List_SP;

	for (int i = 0; i < size_history; i++)
	{
		List_SP = this->Lich_Su_Mua_Hang[i].Get_SP();
		int size_GH = this->Lich_Su_Mua_Hang[i].Get_size();
		Out << size_GH << endl;

		for (int j = 0; j < size_GH; j++)
		{
			Out << List_SP[j].first.Get_MaSP() << endl;
			Out << List_SP[j].first.Get_Ten() << endl;
			Out << List_SP[j].first.Get_Loai() << endl;
			Out << List_SP[j].first.Get_Info().Get_TacGia() << endl;
			Out << List_SP[j].first.Get_Info().Get_NhaXuatBan() << endl;
			Out << List_SP[j].first.Get_Info().Get_NgayXuatBan().Get_Ngay() << " ";
			Out << List_SP[j].first.Get_Info().Get_NgayXuatBan().Get_Thang() << " ";
			Out << List_SP[j].first.Get_Info().Get_NgayXuatBan().Get_Nam() << endl;
			Out << List_SP[j].first.Get_Gia() << endl;
			Out << List_SP[j].first.Get_KM() << endl;
			Out << List_SP[j].second << endl;
		}
		Out << this->Lich_Su_Mua_Hang[i].Get_date() << endl;
		Out << this->Lich_Su_Mua_Hang[i].Get_Tong_Gia() << endl;
		Out << this->Lich_Su_Mua_Hang[i].Get_ThangTien() << endl;
	}

	Out.close();
}