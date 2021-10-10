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
		cout << "������� ������� ��� ��������\n";
		cin >> F >> I >> O;
		cout << "������� ����� ����������\n\n�������: ";
		cin >> Oblast;
		cout << "���������� �����: ";
		cin >> Gorod;
		cout << "�����: ";
		cin >> Ulica;
		cout << "���: ";
		cin >> Dom;
		cout << "��������: ";
		cin >> Kvartira;
		cout << "�������: ";
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
		if (in.is_open())//���� ���� ���������� � ������
		{
			if (in.is_open())
			{
				while (!in.eof())
				{
					in >> IData >> voidSTR >> voidSTR >> voidSTR >> voidSTR >> voidSTR >> voidSTR;//��� ��������� ���������� ������ ��������
				}
				in.close();
			}
		}
		in.close();
	}
	void UserSave()override
	{
		in.open(server.getPath() + server.getSTR() + ".ttt");//��������� � ��������� ��� ������ ������
		if (in.is_open())
		{
			cout << "����� �����\n";											//���� ����� ����� ��� ���� �������� ������
			in.close();
		}
		else
		{
			out.open(server.getPath() + server.getSTR() + ".ttt", ios::app);//��������� ���� � ������������� ������(�� ������), ��������� ���� ��� ������ � ����� ������
			if (out.is_open())//���� ���� ���������� � ������
			{

				out << num << endl;
				out << F + " " << I + " " << O << endl;							//������ ����� ������ �� ��������� � ������ ���� ������, ��� �����������.
				out << "\tA���� ����������" << endl;
				out << "�������   : " << Oblast << endl;
				out << "���. �����: " << Gorod << endl;
				out << "�����     : " << Ulica << endl;
				out << "���       : " << Dom << endl;
				out << "��������  : " << Kvartira << endl;
				out << "�������   : " << Phone << endl;
				out << "e-mail    : " << e_mail << endl;
				out.close();
				log.open("Students_list.dbd", ios::app);//��������� ���� � ������� ���������
				if (log.is_open())//���� ���� ���������� � ������
				{
					log << ++IData << " ";										//�������������� ���������� ����� ID ��� ������ ������ �������� � ����� ID
					log << server.getSTR() << " \t ";							//��������� ������������� ����� ��� ������� � ����� ���������������
					log << F + " " << I + " " << O << " ";						//�� ��� ����� � �������� ��� ������ �������
					log << Phone << " ";
					log << e_mail << "\n";
					log.close();
				}
				else cout << "������ � ���� �� �����������\n";					//���� �� ������� ������ � ����� ������ ���������


			}
			else cout << "���� �� ������\n";									//�� ����� �� ����������

		}
	}
	void Open()override
	{
		server.Shifr();
		in.open(server.getPath() + server.getSTR() + ".ttt");					//��������� ��� ������ ���� � ������� ������������ 
		if (in.is_open())
		{
			in >> snum;															//��������� ��� ������
			if (snum == server.getNUM())										//���� ��� ����� �� ������ ���������� � ������� � ����� ��������� � ����� ��������� 
			{
				cout << "������ ��������!\n\n";
				nameDoc = server.getPath() + server.getSTR() + ".ttt";
				while (!in.eof())
				{
					str = "";
					getline(in, str);											//��������������� ��������� ������(string)
					cout << str << endl;										//� �������� �� � �������
				}
				cout << endl;
			}
			else cout << "������� ���.\n";										//���� ��� ����� �� �������
		}
		else cout << "��������� ����� � ������!\n";								//���� ����� ��� ��� ������ � ����� �� �������
		in.close();
	}
	void UserDel()//�������� ������ �������
	{
		server.Shifr();
		out.open(server.getPath() + server.getSTR() + ".ttt");
		if (out.is_open())//���� ���� ���������� � ������
		{

			out << "������ ������������ ���� ������� ���������������";  //���� �������� �� ������ � ��� ��������� � ����� ������� �� ������� ����������� ��� �� �����
			cout << "������ �������!\n\n";
			out.close();

		}
		else cout << "������ ������������ �� ����������\n";
	}
	string nameDoc;
	string getPhone() { return Phone; }
	string getF() { return F; }
	string getI() { return I; }
	string getO() { return O; }
	string getEmail() { return e_mail; }

};