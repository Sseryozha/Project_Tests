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
		
		lin.open("Students_list.dbd");//��������� ��� ������ �� ������� ������ ���������
		if (lin.is_open())
		{
			cout << "ID\t\t\t������ ���������\n";
			while (!lin.eof())
			{
				getline(lin, str);//��������������� ��������� ������(string)
				cout << str << endl;//� �������� �� � �������
			}
			lin.ignore();
		}
		lin.close();
		in.open("Students_list.dbd");//��������� ��� ������ ����������� ��������
		if (in.is_open())
		{

			while (in >> ID >> Login >> F >> I >> O >> Phone >> e_mail)
			{
						m[ID] = Login;
			}
			in.close();

			cout << "�������� ����� ID ��������, ��� ������ ������� exit :  ";									
			cin >> ID;
			if (m.find(ID) != m.end())
			{
				lin.open(server.getPath() + m[ID] + ".ttt");
				if (lin.is_open())
				{
					while (!lin.eof())
					{
						getline(lin, str);//��������������� ��������� ������(string)
						cout << str << endl;//� �������� �� � �������
					}
					cout << endl;
					lin.close();
				}
				else cout << "�� �������� ����\n";

			}
			else if(ID != "exit") cout << "������" << endl;
		}
		else
		{
			cout << "���� ������ ����������� ��� �� �������\n";
			ID = "exit";
		}
		system("pause");
		system("cls");
		} while (ID != "exit");
	}

	void UserDel()     /////////���� ��� ����������
	{
		in.open("Students_list.dbd");//��������� ��� ������ ����������� ��������
		if (in.is_open())
		{

			while (in >> ID >> Login >> F >> I >> O >> Phone >> e_mail)
			{
				m[ID] = Login;
			}
			in.close();

			cout << "�������� ����� ID ��������, ��� ��������  : ";									
			cin >> ID;
			if (m.find(ID) != m.end())
			{
				lin.open(server.getPath() + m[ID] + ".ttt");
				if (lin.is_open())
				{
					while (!lin.eof())
					{
						getline(lin, str);//��������������� ��������� ������(string)
						cout << str << endl;//� �������� �� � �������
					}
					cout << endl;
					lin.close();
				}
			}
		}
	
	}
};