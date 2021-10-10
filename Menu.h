#pragma once
#include <windows.h>
#include <iostream>
#include <string>
#include"Admin.h"
#include"Student.h"
#include"Server.h"
#include"Setting.h"
#include"Classroom.h"
#include <memory>
#include<conio.h>
#include<vector>

using namespace std;


class Menu
{

private:
	Admin admin;
	Student student;
	DataBase DB;
	Test test;
	Server server;
	Setting mp;
	vector<string> menu_bar;
	string key = "";
	ifstream log;
	char danet = 'n';
	int menu = 0;
public:
	void ScreenSetting()
	{
		cout << "\n\n\nВыберите размер окна";
		mp.color = 6;
		do
		{
			menu_bar = { "     Старт       ^","     Большое", "     Среднее", "     Маленькое", "     Минимум" };//строка меню для выбора режима
			menu = mp.row_selection(menu_bar, 29, 7) + 1;
			switch (menu)
			{
			case 1:
				system("cls");
				break;
			case 2:
				mp.SetFont(19, 32);//Выбор размера окна больше
				break;
			case 3:
				mp.SetFont(13, 24);//Выбор размера окна норм
				break;
			case 4:
				mp.SetFont(9, 16);//Выбор размера окна меньше
				break;
			case 5:
				mp.SetFont(5, 8);//Выбор размера окна меньше
				break;
			}
		} while (menu != 1);
		//Demo();

	}
	void Demo()
	{
		mp.SetColor(4, 0); //графическая DEMO
		system("TYPE 1112.txt");//файлы в папке с программой
		Sleep(200);
		system("cls");
		Sleep(1500);
		system("TYPE 1112.txt");//файлы в папке с программой
		Sleep(1000);
		system("cls");
		Sleep(500);
		mp.SetColor(6, 0);
		system("TYPE 1113.txt");
		Sleep(1500);
		system("cls");


		for (size_t i = 0; i < 4; i++)
		{
			mp.SetColor(4, 0);
			system("TYPE 1112.txt");//файлы в папке с программой
			Sleep(100);
			system("cls");
			Sleep(50);
			mp.SetColor(6, 0);
			system("TYPE 1113.txt");
			Sleep(100);
			system("cls");
			Sleep(50);

		}
		Sleep(700);
		mp.SetColor(1, 0);
		system("TYPE 1111.txt");
		Sleep(3000);
		system("cls");
	}
	void MenuGeneral()
	{
		string stepL = "\n";
		string stepR = "\t";
		do
		{
			mp.SetColor(1, 0);
			system("TYPE 1111.txt");
			mp.color = 2;//Выбор цвета активного меню
			menu_bar = { "     Администратор", "     Студент", "     Выход из программы" };
			menu = mp.row_selection(menu_bar, 29, 7) + 1;
			switch (menu)
			{
			case 1:
				system("cls");
				admin.Open();
				if (admin.check == true) //проверка входа админа
				MenuAdmin();
				break;
			case 2:
				system("cls");
				log.open(server.getPath() + "admi1.adm");
				if (log.is_open())
				{
					MenuStudent();
				}
				else
				{
					for (size_t i = 1; i < 8; i++)
					{

						mp.SetColor(14, 0);
						cout << "\n\n\n\n\t\t\tСначала администратор должен создать базу\n\t\t\tОбратитесь к администратору ";
						Sleep(400);
						system("cls");
						Sleep(100);
					}
				}
				break;
			case 3:

				exit(0); menu = 0;
				break;
			}
		} while (menu != 0);
	}
	void MenuAdmin()
	{
		do
		{
			mp.color = 12;
			log.open(server.getPath() + "admi1.adm");								//Проверка, если файл существует второго админа уже не добавить
			if (log.is_open())
			{
				menu = 0;
				menu_bar = { "     Вернуться     ^", "     Открыть данные", "     Удалить данные админа", "     Создать аккаунт гостя" , "     Удалить данные гостя" };
				menu = mp.row_selection(menu_bar, 29, 7) + 2; system("cls");
				log.close();
			}
			else
			{
				menu = 0;
				menu_bar = { "     Новый админ","     Вернуться     ^" };
				menu = mp.row_selection(menu_bar, 29, 7) + 1; system("cls");
			}

			switch (menu)
			{
			case 1:
				mp.SetColor(0, 15);
				cout << "\n\n\n\n\n\n\t\t\tВведите ключ продукта\n";
				mp.SetColor(15, 0);
				cout << "\t\t\t:  ";

				cin >> key;																				//Ключ  продукта "Academy"
				system("cls");																			//Продукт попадает в руки изначально админу и он априори владеет ключем продукта
				if (key == server.getKey())																//защита от случайного "админа", 
				{
					cout << "Добро пожаловать!\n";
					menu = 0;
					admin.UserAdd();
					menu_bar = { "     Вернуться     ^"," Сохранить данные админа" };
					menu = mp.row_selection(menu_bar, 29, 7) + 1;
					system("cls");
				}
				else break;
				switch (menu)
				{
				case 1:
					MenuGeneral();
					break;
				case 2:
					admin.UserSave(); 
					break;
				}
				break;
			case 2:
				MenuGeneral();
				break;
			case 3:
												
				if (admin.check == true)
					DB.Open();
				break;
			case 4:
				system("cls");
				mp.SetColor(4, 0);
				cout << "Данные введенные ранее будут утрачены. вы согласны? y/n\t";
				cin >> danet; system("cls");
				if (danet == 'y' || danet == 'Y')
				{
					admin.UserDel();										//Удаляется админ для смены админов, база студентов и личные данные студента сохраняются

				}
				break;
			case 5:
				student.UserAdd();
				system("cls");
				menu = 0;
				menu_bar = { "     Вернуться     ^" , "    Сохранить данные" };
				menu = mp.row_selection(menu_bar, 29, 7) + 1;
				switch (menu)
				{
				case 1:
					break;
				case 2:
					student.CheckID();
					student.UserSave();
					continue;
				}
				break;
			case 6:							// удалить студента
				
				system("cls");
				mp.SetColor(4, 0);
				cout << "Данные введенные ранее будут утрачены. вы согласны? y/n\t";
				cin >> danet; system("cls");
				if (danet == 'y' || danet == 'Y')
				{
					cout << "Введите логин и пароль студента данные которого нужно удалить\n\n";
					student.UserDel();
				}
				break;
			default:
				break;
			}
		} while (menu != 0);

	}
	void MenuStudent()
	{
		do
		{
			mp.color = 9;
			menu = 0;
			menu_bar = { "     Вернуться     ^","     Новый студент", "     Личный кабинет","     Изменить данные","     Тренировочный тест" };
			menu = mp.row_selection(menu_bar, 29, 7) + 1;
			system("cls");
			switch (menu)
			{
			case 1:
				menu = 0;
				break;
			case 2:
				student.UserAdd();
				system("cls");
				menu = 0;
				menu_bar = { "     Вернуться     ^" , "    Сохранить данные" };
				menu = mp.row_selection(menu_bar, 29, 7) + 1;
				switch (menu)
				{
				case 1:
					break;
				case 2:
					student.CheckID();
					student.UserSave();
					continue;
				}
				break;
			case 3:

				student.Open();
				do
				{
					menu = 0;
					menu_bar = { "     Вернуться     ^" , "    Пройти тест" };
					menu = mp.row_selection(menu_bar, 29, 7) + 1;
					switch (menu)
					{
					case 1:
						break;
					case 2:

						test.TestInPut();

						menu = 0;
						menu_bar = { "     Вернуться     ^" , "    Сохранить результат" };
						menu = mp.row_selection(menu_bar, 29, 7) + 1;
						switch (menu)
						{
						case 1:
							break;
						case 2:

							test.SaveTest();
							continue;
						}
					}
				} while (menu != 1);
				break;

			case 4:
				for (int i = 1; i < 9; i++)
				{
					mp.SetColor(i, 0);
					cout << "\n\n\n\n\n\n\n\n\t\t\t\tОБРАТИТЕСЬ К АДМИНИСТРАТОРУ\n";
					Sleep(500);
					system("cls");
				}
				break;
			case 5:

				test.TestInPut();
				break;
			default:
				break;
			}
		} while (menu != 0);
		MenuGeneral();
	}


};



