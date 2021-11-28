#include"E_commerce.hpp"


void Admin::Show()
{
	cout << "User      : " << this->User << "\n";
	cout << "PassWorld : " << this->PassWord << "\n";
}
void Admin::Set_User(const string& User)
{
	this->User = User;
}
void Admin::Set_PassWord(const string& PassWord)
{

	this->PassWord = PassWord;
}
string Admin::Get_User()
{
	return this->User;
}
string Admin::Get_PassWord()
{
	return this->PassWord;
}
string Admin::Get_Type()
{
	return "Admin";
}