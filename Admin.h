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
		cout << "������� ������� ��� ��������\n";
		cin >> F >> I >> O;
		cout << "�������: ";
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
		
		cout << "���������� ������: \t";
		set.SetColor(8,8);
		cin >> pass;
		num = hash(pass);												//������� ��� ����� ������ 
		set.SetColor(15, 0);
		cout << "������� ������ ��� ���: ";
		set.SetColor(8,8);
		cin >> pass;
		set.SetColor(15, 0);
		snum = hash(pass);												//������� ��� ����� ��� �������� ������(� ��������� 64 ������ ������!)
		if (snum == num)												//�������� ������� �� ���-������
		{
			cout << "������ ��������!" << endl;
			server.Console(true);										//������� ����� C:\AcademySPU011_Test
		}
		else
		{
			cout << "������ �� ���������" << endl;
			Sleep(3000);
			system("cls");
			PassAdd();
		}
		server.Shifr();
	}
	void UserSave()override
	{
		in.open(server.getPath() + server.getSTR() + ".adm");			//��������� ��� ������ ������
		if (in.is_open())
		{
			cout << "����� �����\n";
			in.close();
		}
		else
		{
			out.open(server.getPath() + server.getSTR() + ".adm", ios::app);//��������� ���� � ������������� ������(�� ������), ��������� ���� ��� ������ � ����� ������
			if (out.is_open())											//���� ���� ���������� � ������
			{
				out << num << endl;
				out << F + " " << I + " " << O << endl;
				out << "�������:  " << Phone << endl;
				out << "e-mail:   " << e_mail << endl;
				log.open(server.getPath() + "admi1.adm");//������� ����������� ���� ��� ������� ������ ������ ������
				log << "qwerty";
				log.close();
			}
			else cout << "���� �� ������\n";
			out.close();
		}
	}
	void Open()override
	{
		server.Shifr();//������� �����(�������� �����)
		in.open(server.getPath() + server.getSTR() + ".adm");//��������� ��� ������ ������
		if (in.is_open())
		{
			in >> snum;
			if (snum == server.getNUM())//���� ��� ����� �� ������ ���������� � ������� � ����� ��������� � ����� ��������� 
			{
				system("cls");
				cout << "������ ��������!\n\n";
				while (!in.eof())
				{
					
					getline(in, str);//��������������� ��������� ������(string)
					cout << str << endl;//� �������� �� � �������
					check = true;
				}
				cout << endl;
				
			}
			else cout << "������� ���.\n";
		}
		else cout << "��������� ����� � ������!\n";//���� ����� ��� ��� ������ � ����� �� �������
		in.close();
	}
	void UserDel()//�������� ������ ��������������
	{
		server.Shifr();
		in.open(server.getPath() + server.getSTR() + ".adm");
		if (in.is_open())//���� ���� ���������� � ������
		{
			in >> snum;//������ ������ ������, ��� �������� ������
			if (snum == server.getNUM())//���� ��� ����� �� ������ ���������� � ������� � ����� ��������� � ����� ��������� 
			{
				cout << "������ �������!\n\n";
				in.close();
				server.Console(false);//������� ������ ������

			}
		}
		else cout << "������ ������������ �� ����������\n";
	}

};