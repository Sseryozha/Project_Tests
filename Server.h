#pragma once
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include "User.h"
#include"Setting.h"
#define symbol str.at(i) //чтобы не рябило
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
			system("md " const_path);															//создаст папку Admin в каталоге диска C:
		}																						//если программу запускать с флешки, на каждой машине будет свой админ и свои студенты.
		else if (adddel == false)																//при этом файл базы данных со всеми студентами хранится на флешке, но без полного доступа,
		{																						//а только с доступом тех студентов, которые залогинились на конкретной машине
			system("erase " const_path "*.adm");											//удалит  файлы админа. База и все файлы студентов останутся 
		}
		Sleep(1000);
		system("cls");
	}
	void Shifr()
	{
		
		cout << "Авторизация пользователя. Запоминайте логин и пароль\n";						//двойное действие. Здесь и регистрация и авторизация пользователей
		cout << "(Используйте латиницу, цифры и подчеркивание)\n";
		cout << "\tВведите логин:  ";
		cin >> str;
		cout << "\tВведите пароль: ";
		set.SetColor(8,8);
		cin >> pass;
		set.SetColor(15, 0);
		num = hash(pass);																		//создает хеш сумму пароля (в исходнике 64 битная версия!)
		n_n = (num % 12 + 1);																	//Задает размер в пределах 1-13 от хэша, для сдвига символов в логине(шифрование логина от хэша пароля)
		for (int i = 0; i < str.length(); i++)
		{
			if (int(symbol >= 65) && int(symbol <= 90))				//ЛАТИНИЦА
			{
				if (int(symbol <= 77))
				{																				//сдвигает последовательно каждый символ в логине на заданное число("шифрует")
					symbol = char(int(symbol) + n_n);											//Понимаю, что защита логина так себе
				}
				else if (int(symbol >= 78))														//Хотелось просто попробовать свой алгоритм
				{
					symbol = char(int(symbol) - n_n);											//В реальном проекте шифровал бы серьезнее
				}
			}
			else if (int(symbol >= 97) && int(symbol <= 122))		//латиница
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
			else if (int(symbol >= 48) && int(symbol <= 57))		//цифры
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
			else if (int(symbol == 95))								//подчеркивание
			{
				symbol = char(int(symbol)-1);

			}
			else
			{
				cout << "Ошибка в логине\n";
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