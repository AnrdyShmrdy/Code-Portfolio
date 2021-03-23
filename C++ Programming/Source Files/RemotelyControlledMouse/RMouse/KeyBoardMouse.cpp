#include <windows.h>
#include <iostream >
#include <Winuser.h>
#include <functional>
#include <SFML\Graphics.hpp>
using namespace std;
bool control;
bool shift;
int amount;
const int a = 65;
const int d = 68;
const int w = 87;
const int s = 83;

void CheckMouseButtonStatus()
{
	//Check the mouse left button is pressed or not
	if ((GetKeyState(VK_LBUTTON) & 0x80) != 0)
	{
		cout << "LButton pressed" << endl;
	}
	//Check the mouse right button is pressed or not
	if ((GetKeyState(VK_RBUTTON) & 0x80) != 0)
	{
		cout << "RButton pressed" << endl;
	}
}
int IsPressed(int vk)
{
	return GetAsyncKeyState(vk) >> 15;
}

void MoveMouse(int dx, int dy)
{
	POINT p;

	GetCursorPos(&p);

	p.x += dx;
	p.y += dy;

	SetCursorPos(p.x, p.y);
}
INPUT    Input = { 0 };
void LeftClick()
{


	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	SendInput(1, &Input, sizeof(INPUT));

		ZeroMemory(&Input, sizeof(INPUT));
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	SendInput(1, &Input, sizeof(INPUT));
}
void LeftClickDOWN()
{

	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	SendInput(1, &Input, sizeof(INPUT));
}
void LeftClickUP()
{
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	SendInput(1, &Input, sizeof(INPUT));
}
void ClickFunction() {
	if (!IsPressed(VK_SPACE)) {
		Sleep(1); // THIS IS ABSOULUTLY NECESSARY!!! If you remove it, the program uses A LOT of processing power. 
		if (IsPressed(VK_SPACE)) {
			LeftClick();
		}
	}
}
void ClickDragFunction() {
	if (!IsPressed(VK_SPACE)) {
		LeftClickUP();
		Sleep(1); // THIS IS ABSOULUTLY NECESSARY!!! If you remove it, the program uses A LOT of processing power. 
		if (IsPressed(VK_SPACE)) {
			LeftClickDOWN();
		}
	}
}
void OrigLoop() {
	while (true)
	{
		if (IsPressed(VK_ESCAPE)) break;

		control = false;
		shift = false;
		amount = 10;
		if (IsPressed(VK_CONTROL)) control = true;
		if (IsPressed(VK_SHIFT)) shift = true;
		if (control) amount = 100;
		if (shift) amount = 1;
		if (IsPressed(VK_UP)) MoveMouse(0, -amount);
		if (IsPressed(VK_DOWN)) MoveMouse(0, amount);
		if (IsPressed(VK_LEFT)) MoveMouse(-amount, 0);
		if (IsPressed(VK_RIGHT)) MoveMouse(amount, 0);
		if (IsPressed(VK_SPACE)) LeftClick();
		Sleep(100); // DONT REMOVE THIS. Adjusts timing
	}
}

void Loop3() {
	while (true)
	{
		if (IsPressed(VK_ESCAPE)) break;

		control = false;
		shift = false;
		amount = 10;
		if (IsPressed(VK_CONTROL)) control = true;
		if (IsPressed(VK_SHIFT)) shift = true;

		if (control) amount = 100;
		if (shift) amount = 1;
		if (IsPressed(VK_UP)) MoveMouse(0, -amount);
		if (IsPressed(VK_DOWN)) MoveMouse(0, amount);
		if (IsPressed(VK_LEFT)) MoveMouse(-amount, 0);
		if (IsPressed(VK_RIGHT)) MoveMouse(amount, 0);
		ClickDragFunction();
		}
		//Sleep(10); // DONT REMOVE THIS. Adjusts timing
	}
void MouseTests() {
	while (true)
	{
		if (IsPressed(VK_ESCAPE)) break;
		ClickDragFunction();
	}
	//Sleep(10); // DONT REMOVE THIS. Adjusts timing
}
void main()
{
	MouseTests();
}    