#pragma once
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include"Setting.h"
#include<vector>
#include <memory>
#include"Student.h"
#include"Server.h"

using namespace std;

struct Quest
{
	int count = 0;
	bool a = false;
	bool b = false;
	bool c = false;
	bool d = false;

};
struct Answer
{
	int count = 0;
	bool a = false;
	bool b = false;
	bool c = false;
	bool d = false;

};
shared_ptr<Answer[]> A(new Answer);			//не могу объявить в классе Test. Почему?			
shared_ptr<Quest[]> Q(new Quest);
class Test
{
	Quest QC;
	Answer AC;
	Server server;
	vector<string> menu_bar;
	int menu = 0;
	Setting ms;
	ifstream testIn;
	ofstream out;
	string testStr = "NULL";
	string nameTest = "NULL";
	string voidStr = "NULL";
	string quest = "NULL";
	int Ball = -1;
	int NPP = 0;
	int SQ = 0;
	int NumTest = 0;
	int TrueAns = 0;
	int FalseAns = 0;
	char ch = ' ';
public:

	Test() {}

	int UserAnswer()
	{
		TrueAns = 0;
		FalseAns = 0;
		for (size_t i = 0; i < SQ; i++)													//проверяет соответствие правильных ответов и ответов пользователя
		{

			if (Q[i].a == true && A[i].a == true)
				TrueAns++;
			else if (Q[i].a == false && A[i].a == true)
				FalseAns++;
			if (Q[i].b == true && A[i].b == true)
				TrueAns++;
			else if (Q[i].b == false && A[i].b == true)
				FalseAns++;
			if (Q[i].c == true && A[i].c == true)
				TrueAns++;
			else if (Q[i].c == false && A[i].c == true)
				FalseAns++;
			if (Q[i].d == true && A[i].d == true)
				TrueAns++;
			else if (Q[i].d == false && A[i].d == true)
				FalseAns++;
		}
		return TrueAns;

	}
	int CorrectAnswer()
	{
		TrueAns = 0;
		for (size_t i = 0; i < SQ; i++)													//проверяет количество правильных ответов в документе
		{

			if (Q[i].a == true)TrueAns++;
			if (Q[i].b == true)TrueAns++;
			if (Q[i].c == true)TrueAns++;
			if (Q[i].d == true)TrueAns++;

		}
		return TrueAns;
	}
	void TestInPut()
	{

		system("cls");
		NumTest = 0;
		cout << "Выбрать тест \n0 - Пустой тест\n1 - Английский \n2 - Математика\n3 - Психология\n :  ";
		cin >> NumTest;
		system("cls");
		testIn.open("Test " + to_string(NumTest) + ".tst");
		if (testIn.is_open())
		{
			testIn >> SQ; testIn.ignore();
			getline(testIn, testStr);
			getline(testIn, voidStr);
			for (size_t i = 0; i < SQ; i++)
			{
				testIn >> ch;
				testIn >> Q[i].a;
				testIn >> Q[i].b;
				testIn >> Q[i].c;
				testIn >> Q[i].d;
				//QC.count++;
			}
			testIn.ignore();
			cout << "\t\t\tТест по дисциплине : " + testStr << endl;
			nameTest = testStr;
			for (int i = 0; i < SQ; i++)
			{
				testIn >> NPP; testIn.ignore();
				cout << NPP << endl;
				getline(testIn, testStr);
				cout << "\n\n" + testStr;
				getline(testIn, quest);
				cout << "\na)\t" + quest;
				getline(testIn, quest);
				cout << "\nb)\t" + quest;
				getline(testIn, quest);
				cout << "\nc)\t" + quest;
				getline(testIn, quest);
				cout << "\nd)\t" + quest << endl;
				MenuTest(i);
				//AC.count++;
				system("cls");
			}
			testIn.close();
			cout << "Количество верных позиций : " << UserAnswer() << " из " << CorrectAnswer() << "  Количество неверных  позиций : " << this->FalseAns << endl;

			if (CorrectAnswer() != 0) Ball = ((double)UserAnswer() / (double)CorrectAnswer()) * 12;
			cout << "Оценка за данный тест : " << Ball << endl;
		}
		else
		{
			cout << "Подходящий тест не найден, но мы работаем над этим вопросом\n";
			Sleep(3000); system("cls");
		}
	}

	void MenuTest(int i)
	{

		int col = 13;
		string VAR = "  *  Выбрано";
		string var = "     Вариант";
		string var1, var2, var3, var4;
		var1 = var2 = var3 = var4 = var;
		do
		{
			ms.color = col;
			menu = 0;
			menu_bar = { "     Пропустить вопрос ^",var1 + " a", var2 + " b",var3 + " c",var4 + " d","     Дать ответ" };
			menu = ms.row_selection(menu_bar, 29, 13) +1;
			switch (menu)
			{
			case 1:
				A[i].a = A[i].b = A[i].c = A[i].d = false;
				break;
			case 2:
				A[i].a = true;
				col = 2;
				var1 = VAR;
				break;
			case 3:
				A[i].b = true;
				col = 2;
				var2 = VAR;
				break;
			case 4:
				A[i].c = true;
				col = 2;
				var3 = VAR;
				break;
			case 5:
				A[i].d = true;
				col = 2;
				var4 = VAR;
				break;
			case 6:
				break;
			}


		} while (menu != 1 && menu != 6);
	}

	void SaveTest()
	{

		out.open(server.getPath() + server.getSTR() + ".ttt", ios::app);
		if (out.is_open())
		{
			out << "\tТест по дисциплине : " + nameTest << endl;
			out << "Количество правильных позиций : " << UserAnswer() << " из " << CorrectAnswer() << endl;
			out << "Оценка за данный тест : " << Ball << endl;
		}
		else cout << "Доступа нет.\n";

		out.close();
	}

};

