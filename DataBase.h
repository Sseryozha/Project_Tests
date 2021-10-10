#pragma once
#include <windows.h>
#include <iostream>
#include <string>
#include "User.h"
#include"Server.h"
#include <memory>
#include<vector>
#include <fstream>
#include <algorithm>
#include <map>
using namespace std;
class DataBase : public User
{
private:
	
	map<string, string> m;
public:
	DataBase() {}

	void  UserAdd() override {}
	void UserSave()override{}
	void Open()override
	{
		do
		{
		
		lin.open("Students_list.dbd");//открывает дл€ вывода на консоль список студентов
		if (lin.is_open())
		{
			cout << "ID\t\t\tƒанные студентов\n";
			while (!lin.eof())
			{
				getline(lin, str);//последовательно считывает строки(string)
				cout << str << endl;//и передает их в консоль
			}
			lin.ignore();
		}
		lin.close();
		in.open("Students_list.dbd");//открывает дл€ выбора конкретного студента
		if (in.is_open())
		{

			while (in >> ID >> Login >> F >> I >> O >> Phone >> e_mail)
			{
						m[ID] = Login;
			}
			in.close();

			cout << "¬ыберите номер ID студента, дл€ выхода введите exit :  ";									
			cin >> ID;
			if (m.find(ID) != m.end())
			{
				lin.open(server.getPath() + m[ID] + ".ttt");
				if (lin.is_open())
				{
					while (!lin.eof())
					{
						getline(lin, str);//последовательно считывает строки(string)
						cout << str << endl;//и передает их в консоль
					}
					cout << endl;
					lin.close();
				}
				else cout << "Ќе открылс€ файл\n";

			}
			else if(ID != "exit") cout << "ќшибка" << endl;
		}
		else
		{
			cout << "Ѕаза данных отсутствует или не найдена\n";
			ID = "exit";
		}
		system("pause");
		system("cls");
		} while (ID != "exit");
	}

	void UserDel()     /////////ѕока нет реализации
	{
		in.open("Students_list.dbd");//открывает дл€ выбора конкретного студента
		if (in.is_open())
		{

			while (in >> ID >> Login >> F >> I >> O >> Phone >> e_mail)
			{
				m[ID] = Login;
			}
			in.close();

			cout << "¬ыберите номер ID студента, дл€ удалени€  : ";									
			cin >> ID;
			if (m.find(ID) != m.end())
			{
				lin.open(server.getPath() + m[ID] + ".ttt");
				if (lin.is_open())
				{
					while (!lin.eof())
					{
						getline(lin, str);//последовательно считывает строки(string)
						cout << str << endl;//и передает их в консоль
					}
					cout << endl;
					lin.close();
				}
			}
		}
	
	}
};