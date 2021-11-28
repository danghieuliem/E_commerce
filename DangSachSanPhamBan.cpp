#include"E_commerce.hpp"

void DanhSachSanPhamBan::ThemSanPham()
{
	SanPham* San_Pham = new SanPham;
	string Stemp;
	Info IFtemp;
	Date Dtemp;
	int Itemp;

	system("cls");
	cout << "------ THEM SAN PHAM -------\n";

	cout << "Nhap Ten : ";
	getline(cin,Stemp);
	while (Stemp.size() < 1)
	{
		cout << "Ten Khong duoc de trong !/n";
		cout << "Nhap Ten : ";
		getline(cin, Stemp);
	}

	if (TimTheoTenCX(Stemp).Get_Ten() == "NULL")
		San_Pham->Set_Ten(Stemp);

	cout << "Nhap Loai : ";
	getline(cin, Stemp);	
	San_Pham->Set_Loai(Stemp);
	
	cout << "Nhap Gia : ";
	cin >> Itemp;
	cin.ignore();
	San_Pham->Set_Gia(Itemp);

	cout << "Nhap Khuyen mai : ";
	cin >> Itemp;
	cin.ignore();
	San_Pham->Set_KM(Itemp);

	cout << "Nhap ten Tac Gia : ";
	getline(cin, Stemp);
	IFtemp.Set_TacGia(Stemp);

	cout << "Nhap ten Nha Xuat Ban : ";
	getline(cin, Stemp);
	IFtemp.Set_NhaXuatBan(Stemp);

	int INgay, IThang, INam;

	while (true)
	{
		cout << "Nhap Ngay-Thang-Nam Xuat Ban\n";

		cout << "Nhap Ngay                : ";
		cin >> INgay;
		cin.ignore();

		cout << "Nhap Thang               : ";
		cin >> IThang;
		cin.ignore();

		cout << "Nhap Nam                 : ";
		cin >> INam;
		cin.ignore();

		if (Dtemp.Set_NgTgNm(INgay, IThang, INam) == false)
		{
			cout << "Ngay Thang Nam khong hop le vui long nhap lai .\n";
		}
		else
		{
			break;
		}
	}

	IFtemp.Set_NgayXuatBan(Dtemp);

	San_Pham->Set_Info(IFtemp);


	this->DanhSach.push_back(*San_Pham);

}

void DanhSachSanPhamBan::ThemSanPhamFile(const char* fileName)
{
	ifstream InPut;

	InPut.open(fileName);

	if (InPut.fail())
		cout << "Khong doc dc file San_Pham";
	else
	{

		//doc sang pham tu file
		

		this->fileName = fileName;

		int Itemp;
		SanPham SPtemp;
		char Ctemp[100];
		Info IFtemp;
		Date Dtemp;

		InPut >> Itemp;
		InPut.ignore();

		for (int i = Itemp; i > 0; i--)
		{


			InPut.getline(Ctemp, 100);
			SPtemp.Set_MaSP(Ctemp);

			InPut.getline(Ctemp, 100);
			SPtemp.Set_Ten(Ctemp);

			InPut.getline(Ctemp, 100);
			SPtemp.Set_Loai(Ctemp);

			//***********doc file Info*************
			InPut.getline(Ctemp, 100);
			IFtemp.Set_TacGia(Ctemp);

			InPut.getline(Ctemp, 100);
			IFtemp.Set_NhaXuatBan(Ctemp);

			InPut >> Itemp;
			InPut.ignore();
			Dtemp.Set_Ngay(Itemp);

			InPut >> Itemp;
			InPut.ignore();
			Dtemp.Set_Thang(Itemp);

			InPut >> Itemp;
			InPut.ignore();
			Dtemp.Set_Nam(Itemp);

			IFtemp.Set_NgayXuatBan(Dtemp);

			//***************************************

			SPtemp.Set_Info(IFtemp);

			InPut >> Itemp;
			SPtemp.Set_Gia(Itemp);
			InPut.ignore();

			InPut >> Itemp;
			SPtemp.Set_KM(Itemp);
			InPut.ignore();

			this->DanhSach.push_back(SPtemp);
		}
		
	}

	InPut.close();
}

void DanhSachSanPhamBan::XoaSanPham()
{
	system("cls");
	int Itemp;
	while(true)
	{
		this->Show_DanhSach_Info();
		cout << "Nhap STT san pham can xoa (0 de thoat): ";
		cin >> Itemp;
		cin.ignore();
		

		if (Itemp == 0)
		{
			return;
		}
		else
		{
			if (Itemp > this->DanhSach.size()|| Itemp < 1)
			{
				cout << "Khong co san pham nay.\n An phim bat ki de tiep tuc.\n";
				_getch();
			}
			else 
			{
				this->DanhSach.erase(this->DanhSach.begin() + Itemp - 1);
				cout << "Da xoa thang cong.\n";
				cout << "An phim bat ki de tiep tuc.\n";
				_getch();
			}
		}
	}
}

SanPham DanhSachSanPhamBan::TimTheoTenCX(const string& Ten)
{
	SanPham KQ;

	//Chuyen bien Ten string sang char*

	char* Ctemp_Ten = new char[Ten.size() + 1];
	copy(Ten.begin(), Ten.end(), Ctemp_Ten);
	Ctemp_Ten[Ten.size()] = '\0';


	for (int i = this->DanhSach.size() - 1; i > -1; i--)
	{
		string Stemp = this->DanhSach[i].Get_Ten();

		//Chuyen Ten sang phan trong danh sach tu string sang char*

		char* Ctemp_TenSp = new char[Stemp.size() + 1];
		copy(Stemp.begin(), Stemp.end(), Ctemp_TenSp);
		Ctemp_TenSp[Stemp.size()] = '\0';

		if (strstr(Ctemp_TenSp, Ctemp_Ten) != NULL)
			return KQ;

	}

	return KQ;
}

vector<SanPham> DanhSachSanPhamBan::TimTheoTen(const string& Ten)
{
	vector<SanPham> KQ;

	//Chuyen bien Ten string sang char*

	char* Ctemp_Ten = new char[Ten.size() + 1];
	copy(Ten.begin(), Ten.end(), Ctemp_Ten);
	Ctemp_Ten[Ten.size()] = '\0';


	for (int i = this->DanhSach.size()-1 ; i > -1; i--)
	{
		string Stemp = this->DanhSach[i].Get_Ten();

		//Chuyen Ten sang phan trong danh sach tu string sang char*

		char* Ctemp_TenSp = new char[Stemp.size() + 1];
		copy(Stemp.begin(), Stemp.end(), Ctemp_TenSp);
		Ctemp_TenSp[Stemp.size()] = '\0';

		if (strstr(Ctemp_TenSp, Ctemp_Ten) != NULL)
			KQ.push_back(DanhSach[i]);

	}

	return KQ;
}

vector<SanPham> DanhSachSanPhamBan::TimTheoLoai(const string& Loai)
{
	vector<SanPham> KQ;

	//Chuyen bien Loai string sang char*

	char* Ctemp_Ten = new char[Loai.size() + 1];
	copy(Loai.begin(), Loai.end(), Ctemp_Ten);
	Ctemp_Ten[Loai.size()] = '\0';


	for (int i = this->DanhSach.size()-1 ; i > -1; i--)
	{
		string Stemp = this->DanhSach[i].Get_Loai();

		//Chuyen Ten sang phan trong danh sach tu string sang char*

		char* Ctemp_TenSp = new char[Stemp.size() + 1];
		copy(Stemp.begin(), Stemp.end(), Ctemp_TenSp);
		Ctemp_TenSp[Stemp.size()] = '\0';

		if (strstr(Ctemp_TenSp, Ctemp_Ten) != NULL)
			KQ.push_back(DanhSach[i]);

	}

	return KQ;
}

vector<SanPham> DanhSachSanPhamBan::DangGiamGia()
{
	vector<SanPham> KQ;

	for (int i = this->DanhSach.size()-1; i > -1; i--)
	{

		if (this->DanhSach[i].Get_KM() > 0)
			KQ.push_back(DanhSach[i]);

	}

	return KQ;
}

vector<SanPham> DanhSachSanPhamBan::Get_Info()
{
	return this->DanhSach;
}

void DanhSachSanPhamBan::Show_DanhSach()
{
	cout << "******* DANH SACH SAN PHAM ********\n\n";
	int size = this->DanhSach.size();
	for (int i = 0; i < size; i++)
	{
		cout << "STT: " << i+1 << "\n";
		this->DanhSach[i].Show_SanPham();
		cout << "*********************************************************\n";
	}
}

void DanhSachSanPhamBan::Show_DanhSach_Info()
{
	cout << "******* DANH SACH SAN PHAM ********\n\n";
	int size = this->DanhSach.size();
	for (int i = 0; i < size; i++)
	{
		cout << "STT: " << i + 1 << "\n";
		this->DanhSach[i].Show_SanPham_Info();
		cout << "*********************************************************\n";
	}
}

void DanhSachSanPhamBan::Update()
{
	ofstream Out;

	Out.open(this->fileName);

	if (Out.fail())
		cout << "Khong doc dc file San_Pham";
	else
	{
		int size = this->DanhSach.size();

		Out << size << endl;
		for (int i = 0; i < size; i++)
		{
			Out << this->DanhSach[i].Get_MaSP() << endl;
			Out << this->DanhSach[i].Get_Ten() << endl;
			Out << this->DanhSach[i].Get_Loai() << endl;
			Out << this->DanhSach[i].Get_Info().Get_TacGia() << endl;
			Out << this->DanhSach[i].Get_Info().Get_NhaXuatBan() << endl;
			Out << this->DanhSach[i].Get_Info().Get_NgayXuatBan().Get_Ngay() <<" ";
			Out << this->DanhSach[i].Get_Info().Get_NgayXuatBan().Get_Thang() << " ";
			Out << this->DanhSach[i].Get_Info().Get_NgayXuatBan().Get_Nam() << endl;
			Out << this->DanhSach[i].Get_Gia() << endl;
			Out << this->DanhSach[i].Get_KM() << endl;
		}
	}

	Out.close();
}