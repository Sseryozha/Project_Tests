#pragma once
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include "User.h"
#include"Setting.h"
#define symbol str.at(i) //����� �� ������
#define const_path "AcademySPU011_Test\\"
using namespace std;
static string pass, str;
class Server
{
private:
	Setting set;
	string path ="AcademySPU011_Test\\";
	size_t snum = 0;
	size_t num = 0;
	int n_n = -1;
	
	string key = "Academy";
	hash<string>hash;
public:
	
	void Console(bool adddel)
	{
		if (adddel == true)
		{
			system("md " const_path);															//������� ����� Admin � �������� ����� C:
		}																						//���� ��������� ��������� � ������, �� ������ ������ ����� ���� ����� � ���� ��������.
		else if (adddel == false)																//��� ���� ���� ���� ������ �� ����� ���������� �������� �� ������, �� ��� ������� �������,
		{																						//� ������ � �������� ��� ���������, ������� ������������ �� ���������� ������
			system("erase " const_path "*.adm");											//������  ����� ������. ���� � ��� ����� ��������� ��������� 
		}
		Sleep(1000);
		system("cls");
	}
	void Shifr()
	{
		
		cout << "����������� ������������. ����������� ����� � ������\n";						//������� ��������. ����� � ����������� � ����������� �������������
		cout << "(����������� ��������, ����� � �������������)\n";
		cout << "\t������� �����:  ";
		cin >> str;
		cout << "\t������� ������: ";
		set.SetColor(8,8);
		cin >> pass;
		set.SetColor(15, 0);
		num = hash(pass);																		//������� ��� ����� ������ (� ��������� 64 ������ ������!)
		n_n = (num % 12 + 1);																	//������ ������ � �������� 1-13 �� ����, ��� ������ �������� � ������(���������� ������ �� ���� ������)
		for (int i = 0; i < str.length(); i++)
		{
			if (int(symbol >= 65) && int(symbol <= 90))				//��������
			{
				if (int(symbol <= 77))
				{																				//�������� ��������������� ������ ������ � ������ �� �������� �����("�������")
					symbol = char(int(symbol) + n_n);											//�������, ��� ������ ������ ��� ����
				}
				else if (int(symbol >= 78))														//�������� ������ ����������� ���� ��������
				{
					symbol = char(int(symbol) - n_n);											//� �������� ������� �������� �� ���������
				}
			}
			else if (int(symbol >= 97) && int(symbol <= 122))		//��������
			{
				if (int(symbol <= 109))
				{
					symbol = char(int(symbol) + n_n);
				}
				else if (int(symbol >= 110))
				{
					symbol = char(int(symbol) - n_n);
				}
			}
			else if (int(symbol >= 48) && int(symbol <= 57))		//�����
			{
				if (int(symbol <= 52))
				{
					symbol = char(int(symbol) + (num % 5));
				}
				else if (int(symbol >= 53))
				{
					symbol = char(int(symbol) - (num % 5));
				}
			}
			else if (int(symbol == 95))								//�������������
			{
				symbol = char(int(symbol)-1);

			}
			else
			{
				cout << "������ � ������\n";
				Shifr();
				break;
			}
		}
	}

	void setPath(string path){this->path = path;}

	string getPath(){return path;}

	string getSTR(){return str;}

	size_t getNUM(){return num;}

	string getKey(){return key;}

};