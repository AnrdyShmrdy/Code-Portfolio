#include <windows.h>
#include <iostream >
using namespace std;

bool IsPressed(int vk)
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

void LeftClick()
{
	INPUT    Input = { 0 };

	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	SendInput(1, &Input, sizeof(INPUT));
	ZeroMemory(&Input, sizeof(INPUT));
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	SendInput(1, &Input, sizeof(INPUT));
}
void MyLeftClick() {
	INPUT    Input = { 0 };

	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	SendInput(1, &Input, sizeof(INPUT));
	ZeroMemory(&Input, sizeof(INPUT));
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	SendInput(1, &Input, sizeof(INPUT));
}
int main()
{
	bool control;
	bool shift;
	int amount;

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

		Sleep(100);
	}

	return 0;
}