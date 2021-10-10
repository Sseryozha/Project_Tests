#include"Menu.h"
#include"Classroom.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//setlocale(0, "");
	SetConsoleTitleW(L"Academy STEP SPU011-Group Kalinin S. M.");
	//																	//ключ продукта           Academy
	Menu menu;
	menu.ScreenSetting();
	menu.MenuGeneral();
	remove("AcademySPU011_Test\\mnojkhn1.ttt");

	return 0;
}

