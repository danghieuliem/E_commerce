#include"E_commerce.hpp"



void App::Start()
{
	DanhSachSanPhamBan List_SP;
	DanhSachTaiKhoan List_TK;
	TaiKhoan* Tai_Khoan = nullptr;
	GioHang Gio_Hang;


	//nhap du lieu tu file
	List_SP.ThemSanPhamFile("San_Pham.txt");
	List_TK.Them_File("tai_Khoan.txt");

	

	char BanChon = '0';

	while (true)
	{
		switch (BanChon)
		{
		case '0':
		{
			//TRANH CHU

			system("cls");
			
			if (Tai_Khoan == nullptr)
			{
				cout << "CHAO MUNG BAN DEN VOI CUA HANG SACH !!\n";
				cout << "1.Dang Nhap.\n";
				cout << "2.Dang Ky.\n";
				cout << "3.Xem San Pham.\n";
				cout << "4.Xem Chi Tiet Cac San Pham.\n";
				cout << "5.Xem gio hang.\n";
				cout << "Nhap chuc nang : ";
				cin >> BanChon;
				cin.ignore();
				
				if (BanChon > '5')
					BanChon = -1;
			}
			else
			{
				if (Tai_Khoan->Get_Type() == "Admin")
				{
					cout << "Chao quan tri vien " << Tai_Khoan->Get_User() << "\n";
					cout << "******BAN CHON******\n";
					cout << "1.Quan ly danh sach san pham.\n";
					cout << "2.Quan ly danh sach khac hang.\n";
					cout << "3.Dang xuat\n";
					cout << "Nhap chuc nang : ";
					cin >> BanChon;
					cin.ignore();

					switch (BanChon)
					{
					case '1':
					{
						BanChon = 'a';
					}break;
					case '2':
					{
						BanChon = 'b';
					}break;
					case '3':
					{
						BanChon = '7';
					}break;
					default:
						BanChon = -1;
						break;
					}
				}
				else if (Tai_Khoan->Get_Type() == "Khach Hang")
				{
					cout << "Chao mung ban >>" << Tai_Khoan->Get_User() << "<< den voi cua hang !! \n";
					cout << "1.Xem San Pham.\n";
					cout << "2.Xem Chi Tiet Cac San Pham.\n";
					cout << "3.Xem gio hang.\n";
					cout << "4.Xem lich su mua hang.\n";
					cout << "5.Dang xuat\n";
					cout << "Nhap chuc nang : ";
					cin >> BanChon;
					cin.ignore();
					
					if (BanChon > '5')
						BanChon = -1;
					BanChon += 2;
				}
			}

		}break;

		case '1'://trang dang nhap
		{
			while (true)
			{


				Tai_Khoan = this->DangNhap(List_TK);

				if (Tai_Khoan != nullptr)
				{
					cout << "Dang Nhap Thang Cong !!" << "\n";
					cout << "An phim bat ki de tiep tuc !\n";
					BanChon = '0';
					_getch();
					break;
				}
				else
				{
					cout << "Tai khoan hoac mat khau khong dung !\n";
					cout << "An phim bat ki de dang nhap lai hoac an phim (ECS) de huy dang nhap.";
				}

				//bat su kien tu ban phim
				int  a = _getch();
				cin.ignore();
				if (a == 27)
				{
					BanChon = '0';
					break;
				}
			}
		}break;

		case '2'://trang dang ky
		{
			Tai_Khoan = List_TK.Them();
			cout << "Da dang ky thanh cong !\n";
			BanChon = '0';
			_getch();
		}break;

		case '3'://trang xem san pham
		{
			int Itemp1 = -1;
			int Itemp2;

			while (Itemp1 != 0)
			{
				system("cls");

				List_SP.Show_DanhSach();

				cout << "Chon san pham ban muon them vao gio hang (0 de quay ve trang chu): ";

				cin >> Itemp1;
				cin.ignore();

				if (Itemp1 == 0)
				{
					BanChon = '0';
					break;
				}

				Itemp1 -= 1;

				cout << "Nhap so luong : ";
				cin >> Itemp2;
				cin.ignore();

				Gio_Hang.Them(List_SP.Get_Info()[Itemp1], Itemp2);

				cout << "Da theo sang pham vao gio hang !\nAn phim bat ki de tiep tuc\n";
				_getch();
			}

		}break;

		case '4'://trang xen chi tiet sang pham
		{
			
			int Itemp1 = -1;
			int Itemp2;

			while (Itemp1 != 0)
			{
				system("cls");

				List_SP.Show_DanhSach_Info();

				cout << "Chon san pham ban muon them vao gio hang (0 de quay ve trang chu): ";

				cin >> Itemp1;
				cin.ignore();

				if (Itemp1 == 0)
				{
					BanChon = '0';
					break;
				}

				Itemp1 -= 1;

				cout << "Nhap so luong : ";
				cin >> Itemp2;
				cin.ignore();

				Gio_Hang.Them(List_SP.Get_Info()[Itemp1], Itemp2);

				cout << "Da theo sang pham vao gio hang !\nAn phim bat ki de tiep tuc\n";
				_getch();
			}
		}break;

		case '5'://trang xem gio hang
		{
			
			system("cls");

			if (Gio_Hang.Get_size() == 0)
			{
				Gio_Hang.Show();
				cout << "Gio hang rong.\n";
				cout << "An phim bat ki de ve trang chu.\n";
				cout << "An \"1\" Xem danh sach sang pham.\n";

				BanChon = _getch();

				switch (BanChon)
				{
				case '1':
				{
					BanChon = '3';
				}break;
				default:
					BanChon = '0';
					break;
				}
			}
			else
			{
				if (Tai_Khoan == nullptr)
				{
					Gio_Hang.Show();
					cout << "***Neu ban dang nhap se dc giam them 5% tong don hang.\n";
					cout << "An phim bat ki de ve trang chu.\n";
					cout << "An \"1\" den giao dien dang nhap.\n";
					cout << "An \"2\" den giao dien dang ky.\n";
					cout << "An \"3\" tiep tuc mua hang.\n";
					cout << "An \"4\" de thanh toan.\n";
					cout << "An phim \"ESC\" de lam moi gio hang.\n";
					BanChon = _getch();

					switch (BanChon)
					{
					case '1':
					{
						BanChon = '1';
					}break;
					case '2':
					{
						BanChon = '2';
					}break;
					case '3':
					{
						BanChon = '3';
					}break;
					case '4':
					{
						BanChon = '8';
					}break;
					case 27:
					{
						BanChon = '5';
						Gio_Hang.clear();
					}break;
					default:
						BanChon = '0';
						break;
					}
				}
				else
				{
					if (Tai_Khoan->Get_Type() == "Khach Hang")
					{
						Gio_Hang.Show();
						cout << "***Ban dc giam them 5% tong don hang.\n";
						cout << "An phim bat ki de ve trang chu.\n";
						cout << "An \"1\" tiep tuc mua hang.\n";
						cout << "An \"2\" de thanh toan.\n";
						cout << "An phim \"ESC\" de lam moi gio hang.\n";
						BanChon = _getch();

						switch (BanChon)
						{
						case '1':
						{
							BanChon = '3';
						}break;
						case '2':
						{
							BanChon = '8';
						}break;
						case 27:
						{
							BanChon = '5';
							Gio_Hang.clear();
						}break;
						default:
							BanChon = '0';
							break;
						}
					}
				}
			}
		}break;

		case '6'://xem lich su mua hang
		{
			
			BanChon = '0';
			if (Tai_Khoan == nullptr)
			{
				cout << "Ban chua dang nhap.\n";
				_getch();
			}
			else
			{
				BanChon = '0';
				int size = Tai_Khoan->Get_Lich_Su_Mua_Hang().size();
				if (size == 0)
				{
					cout << "Khong co lich su mua hang.\n";
					_getch();
				}
				else
				{
					system("cls");
					vector<HoaDon> list_temp = Tai_Khoan->Get_Lich_Su_Mua_Hang();
					for (int i = 0; i < size; i++)
					{
						list_temp[i].Show();
					}
					cout << "An phim bat ki de tiep tuc.\n";
					_getch();
				}
			}
			
		}break;

		case '7'://dang xuat
		{
			
			Tai_Khoan = nullptr;
			Gio_Hang.clear();
			BanChon = '0';
			cout << "Dang xuat thanh cong.\n";
			_getch();
		}break;

		case '8'://thanh toan
		{
			system("cls");
			if (Tai_Khoan == nullptr)
			{
				HoaDon Hoa_Don;
				Hoa_Don.Set_HoaDon(Gio_Hang);
				Hoa_Don.Show();
				cout << "Thanh toan thanh cong !\n An phim bat ki de tiep tuc.\n";
				BanChon = '0';
				Gio_Hang.clear();
				_getch();
			}
			else
			{
				if (Tai_Khoan->Get_Type() == "Khach Hang")
				{
					HoaDon Hoa_Don;
					Hoa_Don.Set_HoaDonTK(Gio_Hang);
					Hoa_Don.Show();
					Tai_Khoan->Set_Lich_Su_Mua_Hang(Hoa_Don);
					Tai_Khoan->UpData();
					cout << "Thanh toan thanh cong ban dc giam them 5% tong gia tri don hang !\n"
						<<" An phim bat ki de tiep tuc.\n";
					BanChon = '0';
					Gio_Hang.clear();
					_getch();
				}
			}
		}break;

		case 'a'://Quan ly danh sach san pham
		{
			char BanChon_a = '0';
			while (BanChon_a != -1)
			{
				switch (BanChon_a)
				{
				case '0':
				{
					system("cls");
					List_SP.Show_DanhSach_Info();
					cout << "----- QUAN LY SAN PHAM -----\n";
					cout << "0.Ve trang chu.\n";
					cout << "1.Them San Pham.\n";
					cout << "2.Xoa San Pham.\n";
					cout << "Nhap chuc nang : ";
					cin >> BanChon_a;
					cin.ignore();

					if (BanChon_a == '0')
					{
						BanChon_a = -1;
						BanChon = '0';
						break;
					}
				}break;

				case '1': 
				{
					while (true)
					{
						List_SP.ThemSanPham();
						cout << "Da them san pham moi.\n"
							<< "An phim bat ky de tiep tuc them.\n"
							<< "\"Esc\" de hoat.\n";
						BanChon_a = _getch();

						if (BanChon_a == 27)
						{
							List_SP.Update();
							BanChon_a = '0';
							break;
						}
					}
				}break;

				case '2':
				{
					List_SP.XoaSanPham();
					List_SP.Update();
					BanChon_a = '0';
				}break;

				default:
					cout << "Khong co chuc nang nay !\nAn phim bat ki de tiep tuc.\n";
					_getch();
					BanChon_a = '0';
					break;
				}

			}

		}break;

		case 'b'://Quan ly danh sach khac hang
		{
			char BanChon_b = '0';
			while (BanChon_b != -1)
			{
				switch (BanChon_b)
				{
				case '0':
				{
					system("cls");
					List_TK.Show();
					cout << "----- QUAN LY SAN PHAM -----\n";
					cout << "0.Ve trang chu.\n";
					cout << "1.Them Tai Khoan.\n";
					cout << "2.Xoa Tai Khoan.\n";
					cout << "Nhap chuc nang : ";
					cin >> BanChon_b;
					cin.ignore();
					if (BanChon_b == '0')
					{
						BanChon_b = -1;
						BanChon = '0';
						break;
					}
				}break;

				case '1':
				{

					BanChon_b = '0';
					List_TK.Them();
					cout << "Da tao thanh cong !\n";
					List_TK.UpDate();
					_getch();

				}break;

				case '2':
				{
					List_TK.Xoa();
					List_TK.UpDate();
					BanChon_b = '0';
				}break;

				default:
					cout << "Khong co chuc nang nay !\nAn phim bat ki de tiep tuc.\n";
					_getch();
					BanChon_b = '0';
					break;
				}
			}
		}break;

		default:
			cout << "Khong co chuc nang nay !\nAn phim bat ki de tiep tuc.\n";
			_getch();
			BanChon = '0';
			break;
		}
	}
}
TaiKhoan* App::DangNhap(DanhSachTaiKhoan& List_TK)
{

	TaiKhoan* Tai_Khoan;
	string  User;
	string PassWorld;


	system("cls");

	cout << "*******DANG NHAP*******\n";

	cout << "Ten Tai Khoan : ";
	cin >> User;

	cout << "PassWorld     : ";
	cin >> PassWorld;

	Tai_Khoan = List_TK.KiemTra(User, PassWorld);

	return Tai_Khoan;
}
void App::End()
{
	cout << "Tam biet va hen gap lai.\n";
	_sleep(3000);
}


