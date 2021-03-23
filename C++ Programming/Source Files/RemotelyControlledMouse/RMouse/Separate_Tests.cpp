#define WIN32_LEAN_AND_MEAN 
#include <SFML\My additions\sfml.h>
#include <iostream>
#include <SFML\Network.hpp>
#include <string>
#include <thread>
#include "Main.h"
void main()
{
	while (1) {
		if (GetLMouseB() == true) {
			RightClick();
		}
	}
}