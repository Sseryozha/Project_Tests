#pragma once
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include "User.h"
#include"Server.h"
#include"DataBase.h"
#include <memory>

#include <stdio.h>

using namespace std;

class Student : public User
{

public:
	Student() {}
	void  UserAdd() override
	{
		cout << "Введите Фамилию Имя Отчество\n";
		cin >> F >> I >> O;
		cout << "Введите адрес проживания\n\nОбласть: ";
		cin >> Oblast;
		cout << "Населенный пункт: ";
		cin >> Gorod;
		cout << "Улица: ";
		cin >> Ulica;
		cout << "Дом: ";
		cin >> Dom;
		cout << "Квартира: ";
		cin >> Kvartira;
		cout << "Телефон: ";
		cin >> Phone;
		do {
			cout << "e-mail: ";
			cin >> e_mail;
			E_mail(e_mail);
		} while (e_mail == "null@null");
		PassAdd();
	}

	void CheckID()
	{
		in.open("Students_list.dbd");
		if (in.is_open())//Если файл существует и открыт
		{
			if (in.is_open())
			{
				while (!in.eof())
				{
					in >> IData >> voidSTR >> voidSTR >> voidSTR >> voidSTR >> voidSTR >> voidSTR;//для получения последнего номера студента
				}
				in.close();
			}
		}
		in.close();
	}
	void UserSave()override
	{
		in.open(server.getPath() + server.getSTR() + ".ttt");//Проверяет и открывает для чтения данных
		if (in.is_open())
		{
			cout << "Логин занят\n";											//если такой логин уже есть добавить нельзя
			in.close();
		}
		else
		{
			out.open(server.getPath() + server.getSTR() + ".ttt", ios::app);//Сохраняет файл с зашифрованным именем(от логина), открывает файл для записи в конец текста
			if (out.is_open())//Если файл существует и открыт
			{

				out << num << endl;
				out << F + " " << I + " " << O << endl;							//Внутри файла данные не шифруются в рамках этой работы, для наглядности.
				out << "\tAдрес проживания" << endl;
				out << "Область   : " << Oblast << endl;
				out << "Нас. пункт: " << Gorod << endl;
				out << "Улица     : " << Ulica << endl;
				out << "Дом       : " << Dom << endl;
				out << "Квартира  : " << Kvartira << endl;
				out << "Телефон   : " << Phone << endl;
				out << "e-mail    : " << e_mail << endl;
				out.close();
				log.open("Students_list.dbd", ios::app);//Сохраняет файл с данными студентов
				if (log.is_open())//Если файл существует и открыт
				{
					log << ++IData << " ";										//Инкрементирует полученный ранее ID для записи нового студента с новым ID
					log << server.getSTR() << " \t ";							//сохраняет зашифрованный логин для доступа к файлу администратором
					log << F + " " << I + " " << O << " ";						//По фио админ и понимает кто данный студент
					log << Phone << " ";
					log << e_mail << "\n";
					log.close();
				}
				else cout << "Запись в базу не произведена\n";					//если не получен доступ к файлу списка студентов


			}
			else cout << "Файл не создан\n";									//Ну вааще не получилось

		}
	}
	void Open()override
	{
		server.Shifr();
		in.open(server.getPath() + server.getSTR() + ".ttt");					//Открывает для чтения файл с данными пользователя 
		if (in.is_open())
		{
			in >> snum;															//считывает хэш пароля
			if (snum == server.getNUM())										//если хэш сумма от пароля введенного в консоле и число записаное в файле совпадают 
			{
				cout << "Доступ разрешен!\n\n";
				nameDoc = server.getPath() + server.getSTR() + ".ttt";
				while (!in.eof())
				{
					str = "";
					getline(in, str);											//последовательно считывает строки(string)
					cout << str << endl;										//и передает их в консоль
				}
				cout << endl;
			}
			else cout << "Доступа нет.\n";										//если хеш суммы не сошлись
		}
		else cout << "Проверьте логин и пароль!\n";								//если файла нет или пароль и логин не сошлись
		in.close();
	}
	void UserDel()//Удаление данных студеня
	{
		server.Shifr();
		out.open(server.getPath() + server.getSTR() + ".ttt");
		if (out.is_open())//Если файл существует и открыт
		{

			out << "Данные пользователя были удалены администратором";  //файл остается но данные в нем стираются и войти студент со старыми параметрами уже не может
			cout << "Данные удалены!\n\n";
			out.close();

		}
		else cout << "Такого пользователя не существует\n";
	}
	string nameDoc;
	string getPhone() { return Phone; }
	string getF() { return F; }
	string getI() { return I; }
	string getO() { return O; }
	string getEmail() { return e_mail; }

};