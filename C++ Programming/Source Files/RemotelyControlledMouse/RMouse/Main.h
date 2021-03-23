#pragma once
#define WIN32_LEAN_AND_MEAN 
#include <SFML\My additions\sfml.h>
#include <iostream>
#include <SFML\Network.hpp>
#include <string>
#include <thread>
char who;
bool client_connected = false;
bool server_connected = false;
bool quit = false;
int receive1;
int receive2;
bool recieve3;
bool press_lmouse;
int Hx;
int Hy;
int IsPressed(int vk)
{
	return GetAsyncKeyState(vk) >> 15;
}
void LeftClickDOWN()
{
	INPUT    Input = { 0 };
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	SendInput(1, &Input, sizeof(INPUT));
}
void LeftClickUP()
{
	INPUT    Input = { 0 };
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	SendInput(1, &Input, sizeof(INPUT));
}
void RightClickDOWN()
{
	INPUT    Input = { 0 };
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
	SendInput(1, &Input, sizeof(INPUT));
}
void RightClickUP()
{
	INPUT    Input = { 0 };
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
	SendInput(1, &Input, sizeof(INPUT));
}
void RightClick()
{
	INPUT    Input = { 0 };
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
	SendInput(1, &Input, sizeof(INPUT));

	ZeroMemory(&Input, sizeof(INPUT));
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
	SendInput(1, &Input, sizeof(INPUT));
}
bool GetLMouseB() {
	if (IsPressed(VK_SPACE)) {
		return true;
	}
	else {
		return false;
	}
}
bool GetRMouseB() {
	if (IsPressed(VK_RCONTROL)) {
		return true;
	}
	else {
		return false;
	}
}
POINT GetMouse()
{
	POINT p;

	GetCursorPos(&p);
	return p;
}
sf::IpAddress server = "127.0.0.1";
const unsigned short PORT = 5000;
void enterIP() {
	std::cout << "Enter the ip of server" << std::endl;
	std::cin >> server;
}
sf::TcpSocket socket;
sf::Mutex globalMutex;
void DoStuff(void)
{
	while (!quit)
	{
		sf::Packet packetSend;
		sf::Packet packetReceive;
		globalMutex.lock();
		packetSend << GetMouse().x;
		packetSend << GetMouse().y;
		packetSend << GetLMouseB();
		globalMutex.unlock();
		socket.send(packetSend);
		socket.receive(packetReceive);
		if (packetReceive >> receive1 >> receive2 >> recieve3) {
				Hx = receive1;
				Hy = receive2;
				press_lmouse = recieve3;
		}
	}
}
void Server(void)
{
	sf::TcpListener listener;
	listener.listen(PORT);
	listener.accept(socket);
	std::cout << "New client connected: " << socket.getRemoteAddress() << std::endl;
	client_connected = true;
}
void Client(void)
{
	if (socket.connect(server, PORT) == sf::Socket::Done)
	{
		std::cout << "Connected\n";
		server_connected = true;
	}
}
void setM() {
Sleep(1);
SetCursorPos(Hx, Hy);
}
void endM() {
		if (IsPressed(VK_ESCAPE)) { quit = true; }
}
void LClickDragFunction() {
	if (!press_lmouse) {
		LeftClickUP();
		Sleep(1.0); // THIS IS ABSOULUTLY NECESSARY!!! If you remove it, the program uses A LOT of processing power. 
		if (press_lmouse) {
			LeftClickDOWN();
		}
	}
}
void runGameC() {
	while (!quit) {
		std::thread first(endM);
		std::thread second(setM);
		std::thread third(LClickDragFunction);
		first.join();
		second.join();
		third.join();
	}
}
