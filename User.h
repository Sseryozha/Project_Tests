#pragma once
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include"Server.h"
#include"Setting.h"




using namespace std;
class User
{
public:
	virtual void  UserAdd() = 0;
	virtual void UserSave() = 0;
	virtual void Open() = 0;
	virtual void PassAdd()
	{
		
		cout << "Придумайте пароль: \t";
		set.SetColor(8,8);
		cin >> pass;
		num = hash(pass);													//создает хеш сумму пароля 
		set.SetColor(15, 0);
		cout << "Введите пароль ещё раз: ";									//Защита "От дурня"
		set.SetColor(8,8);
		cin >> pass;
		set.SetColor(15, 0);
		snum = hash(pass);													//создает хеш сумму для проверки пароля(в исходнике 64 битная версия!)
		if (snum == num)													//Проверка паролей по хеш-суммам
		{
			cout << "Пароль сохранен!" << endl;

		}
		else
		{
			cout << "Пароли не совпадают" << endl;
			Sleep(3000);
			system("cls");
			PassAdd();														//Рекурсия, если не совпали
		}
		server.Shifr();
	}
	string E_mail(string e_maill) 
	{
		e_mail = e_maill;

		count = 0;
		for (int i = 0; i < e_mail.length(); i++)
		{
			if (e_mail.at(i) == '@')
				count++;
		}
		if (count != 1)
		{
			cout << "Это не похоже на e-mail\n";							//в email должна содержаться только одна собачка
			e_mail = "null@null";
			
		}
		return e_mail;
	}

	
protected:
	int n_n = -1;
	int IData = 0;
	int count = 0;
	Setting set;
	ifstream in, lin;
	ofstream out;
	fstream inout;
	string pass, F, I, O, str, Login, ID;
	string voidSTR = "NULL";
	hash<string>hash;
	Server server;
	size_t snum = 0;
	size_t num = 0;
	string Oblast = "NULL";
	string Gorod = "NULL";
	string Ulica = "NULL";
	string Dom = "NULL";
	string Kvartira = "NULL";
	string Phone = "NULL", e_mail = "null@null";
	ofstream log;
	
};