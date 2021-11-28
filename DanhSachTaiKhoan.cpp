#include"E_commerce.hpp"

TaiKhoan* DanhSachTaiKhoan::KiemTra(const string& User, const string& PassWorld)
{
	for (int i = this->list.size() - 1; i > -1; i--)
	{
		if (this->list[i]->Get_User() == User && this->list[i]->Get_PassWord() == PassWorld)
		{
			return this->list[i];
		}
	}
	return nullptr;
}

void DanhSachTaiKhoan::Them_File(const char* fileName)
{
	ifstream InPut;

	InPut.open(fileName);

	if (InPut.fail())
		cout << "Khong doc dc file tai khoan";
	else
	{
		//doc tai khoan tu file
		this->fileName = fileName;
		int Itemp , Itemp1;
		char* Ctemp = new char[LengthUser_PassWord];
		Admin Atemp;
		KhachHang KHtemp;
		Date Dtemp;

		InPut >> Itemp;
		InPut.ignore();

		for (int i = Itemp; i > 0; i--)
		{

			InPut >> Itemp;
			InPut.ignore();

			if (Itemp == 1)
			{

				InPut.getline(Ctemp, LengthUser_PassWord);
				Atemp.Set_User(Ctemp);

				InPut.getline(Ctemp, LengthUser_PassWord);
				Atemp.Set_PassWord(Ctemp);

				this->list.push_back(new Admin(Atemp));
			}
			else
			{
				InPut.getline(Ctemp, LengthUser_PassWord);
				KHtemp.Set_User(Ctemp);

				InPut.getline(Ctemp, LengthUser_PassWord);
				KHtemp.Set_PassWord(Ctemp);

				InPut.getline(Ctemp, LengthUser_PassWord);
				KHtemp.Set_Gmail(Ctemp);

				InPut.getline(Ctemp, LengthUser_PassWord);
				KHtemp.Set_Sdt(Ctemp);
				
				InPut >> Itemp;
				InPut.ignore();
				Dtemp.Set_Ngay(Itemp);

				InPut >> Itemp;
				InPut.ignore();
				Dtemp.Set_Thang(Itemp);

				InPut >> Itemp;
				InPut.ignore();
				Dtemp.Set_Nam(Itemp);

				KHtemp.Set_Ng_Sinh(Dtemp);

				

				//doc lich su mua hang

				
				SanPham SPtemp;
				Info IFtemp;
				Date Dtemp;
				HoaDon HDtemp;
				vector<HoaDon> List_HD;

				ifstream History;

				string Stemp = KHtemp.Get_User() + ".txt";
				History.open(Stemp);

				int Itemp_F1;
				History >> Itemp_F1;
				History.ignore();
				if (Itemp_F1 != 0)
				{
					for (int i = 0; i < Itemp_F1; i++)
					{
						vector<pair<SanPham, int>> LSan_Pham;
						int Itemp_F2;
						History >> Itemp_F2;
						History.ignore();
						for (int j = 0; j < Itemp_F2; j++)
						{

							History.getline(Ctemp, 100);
							SPtemp.Set_MaSP(Ctemp);

							History.getline(Ctemp, 100);
							SPtemp.Set_Ten(Ctemp);

							History.getline(Ctemp, 100);
							SPtemp.Set_Loai(Ctemp);

							//***********doc file Info*************
							History.getline(Ctemp, 100);
							IFtemp.Set_TacGia(Ctemp);

							History.getline(Ctemp, 100);
							IFtemp.Set_NhaXuatBan(Ctemp);

							History >> Itemp;
							History.ignore();
							Dtemp.Set_Ngay(Itemp);

							History >> Itemp;
							History.ignore();
							Dtemp.Set_Thang(Itemp);

							History >> Itemp;
							History.ignore();
							Dtemp.Set_Nam(Itemp);

							IFtemp.Set_NgayXuatBan(Dtemp);

							//***************************************

							SPtemp.Set_Info(IFtemp);

							History >> Itemp;
							SPtemp.Set_Gia(Itemp);
							History.ignore();

							History >> Itemp;
							SPtemp.Set_KM(Itemp);
							History.ignore();

							History >> Itemp;
							History.ignore();

							pair<SanPham, int> TMP(SPtemp, Itemp);

							LSan_Pham.push_back(TMP);
						}

						HDtemp.Set_SP(LSan_Pham);

						History.getline(Ctemp, 100);
						HDtemp.Set_date(Ctemp);

						History >> Itemp;
						HDtemp.Set_Tong_Gia(Itemp);
						History.ignore();

						History >> Itemp;
						HDtemp.Set_ThangTien(Itemp);
						History.ignore();

						List_HD.push_back(HDtemp);
					}
					
				}
				KHtemp.Set_Lich_Su_Mua_Hang(List_HD);
				this->list.push_back(new KhachHang(KHtemp));
			}			
		}
	}
	InPut.close();
}

TaiKhoan* DanhSachTaiKhoan::Them() 
{
	system("cls");
	
	

	KhachHang KH;
	int Itemp;
	char* Ctemp = new char[LengthUser_PassWord];
	char* Ctemp2 = new char[LengthUser_PassWord];
	Date Dtemp;

	cout << "**********TAO TAI KHOAN**************\n";

	while (true)
	{
		
		cout << "Nhap Tai Khoan           : ";
		cin.getline(Ctemp, LengthUser_PassWord);
		KH.Set_User(Ctemp);
		int i = this->list.size() - 1;
		for (; i > -1; i--)
		{
			if (this->list[i]->Get_User() == Ctemp)
			{
				cout << "Tai khoan da ton tai !\n";
				break;
			}
		}
		if (i == -1)
			break;
	}

	cout << "Nhap PassWord            : ";
	cin.getline(Ctemp, LengthUser_PassWord);

	cout << "Nhap Lai PassWord        : ";
	cin.getline(Ctemp2, LengthUser_PassWord);

	string Stemp1 = Ctemp;
	string Stemp2 = Ctemp2;

	while (Stemp1 != Stemp2)
	{
		cout << "Mat khau khong trung khop .\n";
		cout << "Nhap Lai PassWord        : ";
		cin.getline(Ctemp2, LengthUser_PassWord);
		Stemp2 = Ctemp2;

	} 
	KH.Set_PassWord(Ctemp);

	cout << "Nhap Gmail               : ";
	regex pattern("[a-zA-Z0-9_\.]+@[a-zA-Z]+\.[a-zA-Z]+(\.[a-zA-Z]+)*");
	cin.getline(Ctemp, LengthUser_PassWord);
	while (!regex_match(Ctemp, pattern))
	{
		cout << "Gmail khong hop le!.\n";
		cout << "Nhap Gmail               : ";
		cin.getline(Ctemp, LengthUser_PassWord);
	}
	KH.Set_Gmail(Ctemp);

	cout << "Sdt                      : ";
	string SDT;
	cin.getline(Ctemp, LengthUser_PassWord);
	SDT = Ctemp;
	while (SDT.size() != 10 || SDT[0] != '0')
	{
		cout << "So dien thoai vua nhap khong hop le!.\n";
		cout << "Sdt                      : ";
		cin.getline(Ctemp, LengthUser_PassWord);
		SDT = Ctemp;
	}
	KH.Set_Sdt(Ctemp);


	
	int INgay, IThang, INam;

	while (true)
	{
		cout << "Nhap Ngay thang Nam sinh  \n";

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



	KH.Set_Ng_Sinh(Dtemp);


	string NewFile = this->list[this->list.size()-1]->Get_User() + ".txt";
	ofstream Ftemp;
	Ftemp.open(NewFile);
	Ftemp << 0;
	Ftemp.close();

	this->list.push_back(new KhachHang(KH));
	this->UpDate();

	return this->list[this->list.size()-1];
}

void DanhSachTaiKhoan::UpDate()
{
	ofstream OutFile(this->fileName);

	int size = list.size();

	OutFile << size  << endl;

	for (int i = 0; i < size; i++)
	{
		if (this->list[i]->Get_Type() == "Khach Hang")
		{
			OutFile << 0 << endl;
			OutFile <<  this->list[i]->Get_User() << endl;
			OutFile << this->list[i]->Get_PassWord() << endl;
			OutFile << this->list[i]->Get_Gmail() << endl;
			OutFile << this->list[i]->Get_Sdt() << endl;
			OutFile << this->list[i]->Get_Ng_Sinh().Get_Ngay() << " "
				<< this->list[i]->Get_Ng_Sinh().Get_Thang() << " "
				<< this->list[i]->Get_Ng_Sinh().Get_Nam() << "\n";
		}
		else if(this->list[i]->Get_Type() == "Admin")
		{
			OutFile << 1 << endl;
			OutFile << this->list[i]->Get_User() << endl;
			OutFile << this->list[i]->Get_PassWord() << endl;
		}
	}
	OutFile.close();
}

void DanhSachTaiKhoan::Xoa()
{
	
	int Itemp;
	while (true)
	{
		system("cls");
		this->Show();
		cout << "Nhap STT san pham can xoa (0 de thoat): ";
		cin >> Itemp;
		cin.ignore();


		if (Itemp == 0)
		{
			break;
		}
		else
		{
			if (Itemp > this->list.size() || Itemp < 1)
			{
				cout << "Khong co san pham nay.\n An phim bat ki de tiep tuc.\n";
				_getch();
			}
			else
			{
				if (this->list[Itemp - 1]->Get_Type() == "Admin")
				{
					cout << "Khong the xoa Admin.\n";
					cout << "An phim bat ki de tiep tuc.\n";
					_getch();
				}
				else
				{
					string Del_file_name = this->list[Itemp - 1]->Get_User() + ".txt";
					const char* str_pattern = Del_file_name.c_str();
					remove(str_pattern);
					this->list.erase(this->list.begin() + Itemp - 1);
					cout << "Da xoa thang cong.\n";
					cout << "An phim bat ki de tiep tuc.\n";
					_getch();
				}
			}
		}
	}
}

void DanhSachTaiKhoan::Show()
{
	int size = this->list.size();
	for (int i = 0; i < size; i++)
	{

		cout << "STT : " << i + 1 << "\n";
		cout << "\n-Loai Tai Khoan : " << this->list[i]->Get_Type() << "\n";
		this->list[i]->Show();
		cout << "**********************************\n";
	}
}

int DanhSachTaiKhoan::Get_size()
{
	return this->list.size();
}

DanhSachTaiKhoan::~DanhSachTaiKhoan()
{
	int size = this->list.size();
	for (int i = size - 1; i > -1 ; i--)
	{
		delete(this->list[i]);
		this->list.pop_back();
	}
}
