#define WIN32_LEAN_AND_MEAN 
#include <iostream>
#include <SFML\Network.hpp>
#include <string>
#include <thread>
#include "Main.h"
void main()
{
	std::cout << "Do you want to be a server (s) or a client (c) ? ";
	std::cin >> who;
	if (who == 's') {
		Server();
		if (client_connected == true) {
			DoStuff();
		}
	}
	if (who == 'c') {
		enterIP();
		Client();
		std::thread first(runGameC);
		std::thread second(DoStuff);
		first.join();
		second.join();
	}

	
}