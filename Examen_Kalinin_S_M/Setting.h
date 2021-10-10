#pragma once
#include <windows.h>
#include <iostream>
#include <string>
#include <memory>
#include<conio.h>
#include<vector>
using namespace std;
class Setting
{
	char step;
	int pos = 0;
	int font, size;
public:
	
	int color = 2;
	Setting() { SetColor(15,0); }
	int row_selection(vector <string> menu, int posX, int posY)
	{
		do
		{
			for (int i = 0; i < menu.size(); i++)
			{
				if (i == pos)
				{
					SetColor(15, color);																	//меняем цвет строки меню
					gotoxy(posX, posY - menu.size() / 2 + i);
					cout << "                             ";
					gotoxy(posX, posY - menu.size() / 2 + i);
					cout << menu[i] << endl;
					SetColor(15, 2);
				}
				else
				{
					SetColor(7, 8);
					gotoxy(posX, posY - menu.size() / 2 + i);
					cout << "                             ";
					int len = menu[i].length();
					gotoxy(posX, posY - menu.size() / 2 + i);
					cout << menu[i] << endl;
					SetColor(15, 2);
				}
			}
			step = _getch();
			switch (step)
			{
			case 72: //вверх
				if (pos > 0)
					pos--;
				break;
			case 80: // вниз
				if (pos < menu.size() - 1)
					pos++;
				break;
			case 13:
				break;
			default:
				break;
			}
		} while (step != 13);
		SetColor(7, 0);
		return pos;
	}
	void gotoxy(int x, int y)
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	}
	enum ConsoleColor
	{
		Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8,
		LightBlue = 9, LightGreen = 10, LightCyan = 11, LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15
	};
	void SetColor(int text, int background)
	{
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
	}
	void SetFont(int font, int size)
	{
		HANDLE Hout = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD font_size = { (int)font, (int)size };
		CONSOLE_FONT_INFOEX Font = { sizeof(Font) };
		Font.dwFontSize = font_size;
		SetCurrentConsoleFontEx(Hout, FALSE, &Font);
		GetCurrentConsoleFontEx(Hout, FALSE, &Font);
	}

};
