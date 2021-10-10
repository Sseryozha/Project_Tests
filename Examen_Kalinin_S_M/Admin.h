#pragma once
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include "User.h"
#include"Server.h"
#include <memory>

using namespace std;
class Admin : public User
{
	
public:
bool check = false;

	Admin() {}
	
	void  UserAdd() override
	{
		cout << "Введите Фамилию Имя Отчество\n";
		cin >> F >> I >> O;
		cout << "Телефон: ";
		cin >> Phone;
		do {
			cout << "e-mail: ";
			cin >> e_mail;
			e_mail=E_mail(e_mail);
		} while (e_mail== "null@null");
		PassAdd();
	}
	void PassAdd()
	{
		
		cout << "Придумайте пароль: \t";
		set.SetColor(8,8);
		cin >> pass;
		num = hash(pass);												//создает хеш сумму пароля 
		set.SetColor(15, 0);
		cout << "Введите пароль ещё раз: ";
		set.SetColor(8,8);
		cin >> pass;
		set.SetColor(15, 0);
		snum = hash(pass);												//создает хеш сумму для проверки пароля(в исходнике 64 битная версия!)
		if (snum == num)												//Проверка паролей по хеш-суммам
		{
			cout << "Пароль сохранен!" << endl;
			server.Console(true);										//создаст папки C:\AcademySPU011_Test
		}
		else
		{
			cout << "Пароли не совпадают" << endl;
			Sleep(3000);
			system("cls");
			PassAdd();
		}
		server.Shifr();
	}
	void UserSave()override
	{
		in.open(server.getPath() + server.getSTR() + ".adm");			//Открывает для чтения данных
		if (in.is_open())
		{
			cout << "Логин занят\n";
			in.close();
		}
		else
		{
			out.open(server.getPath() + server.getSTR() + ".adm", ios::app);//Сохраняет файл с зашифрованным именем(от логина), открывает файл для записи в конец текста
			if (out.is_open())											//Если файл существует и открыт
			{
				out << num << endl;
				out << F + " " << I + " " << O << endl;
				out << "Телефон:  " << Phone << endl;
				out << "e-mail:   " << e_mail << endl;
				log.open(server.getPath() + "admi1.adm");//Создает проверочный файл для доступа только одного админа
				log << "qwerty";
				log.close();
			}
			else cout << "Файл не создан\n";
			out.close();
		}
	}
	void Open()override
	{
		server.Shifr();//Шифрует логин(название файла)
		in.open(server.getPath() + server.getSTR() + ".adm");//Открывает для чтения данных
		if (in.is_open())
		{
			in >> snum;
			if (snum == server.getNUM())//если хэш сумма от пароля введенного в консоле и число записаное в файле совпадают 
			{
				system("cls");
				cout << "Доступ разрешен!\n\n";
				while (!in.eof())
				{
					
					getline(in, str);//последовательно считывает строки(string)
					cout << str << endl;//и передает их в консоль
					check = true;
				}
				cout << endl;
				
			}
			else cout << "Доступа нет.\n";
		}
		else cout << "Проверьте логин и пароль!\n";//если файла нет или пароль и логин не сошлись
		in.close();
	}
	void UserDel()//Удаление данных администратора
	{
		server.Shifr();
		in.open(server.getPath() + server.getSTR() + ".adm");
		if (in.is_open())//Если файл существует и открыт
		{
			in >> snum;//читает первую строку, там хэшсумма пароля
			if (snum == server.getNUM())//если хэш сумма от пароля введенного в консоле и число записаное в файле совпадают 
			{
				cout << "Данные удалены!\n\n";
				in.close();
				server.Console(false);//Удаляет данные админа

			}
		}
		else cout << "Такого пользователя не существует\n";
	}

};