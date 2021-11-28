#include"E_commerce.hpp"

void GioHang::Them(SanPham San_Pham, const int& SL)
{
	int size = this->info.size();
	string Stemp = San_Pham.Get_Ten();
	for (int i = 0; i < size; i++)
	{
		if ( Stemp == this->info[i].first.Get_Ten())
		{
			this->info[i].second += SL;
			return;
		}
	}
	pair<SanPham, int> tmp(San_Pham, SL);
	this->info.push_back(tmp);
}
void GioHang::Xoa(const SanPham& San_Pham)
{

}

void GioHang::Show()
{
	cout << "******* GOI HANG NE ********\n\n";
	int size = this->info.size();
	for (int i = 0; i < size; i++)
	{
		cout << "San Pham : " << i << endl;
		this->info[i].first.Show_SanPham_Info();
		cout << "  So Luong      : " << this->info[i].second << "\n";
		cout << "*********************************************************\n";
	}
}
void GioHang::clear()
{
		this->info.clear();
}
vector<pair<SanPham, int>> GioHang::Get_info()
{
	return this->info;
}
int GioHang::Get_size()
{
	return this->info.size();
}