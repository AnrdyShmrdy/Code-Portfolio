#include <SFML/Graphics.hpp>
#include <SFML\My Additions\sfml.h>
#include <vector>
#include <iostream>
#include "Inputs and Outputs.h"
using namespace std;
const int gravity = 500;
bool onGround = false;
float inAir;
float maxInAir = 0.3f;
int RanNum = 0;

int main()
{
	int MAX = ReturnLineValue(0, 1);
	sf::RenderWindow window(sf::VideoMode(1400, 900), "Level Display");

	// Loading player texture
	// Loading grass texture
	sf::Texture grassTexture;
	if (!grassTexture.loadFromFile("grass.png")) return 0;

	// Creating a vector because we have more blocks and we will need them into a container
	std::vector<sf::Sprite> grass;

	// Add 4 grass blocks to the container
	grass.resize(MAX / 2);
	// Last grass block will bo above the first one
	for (int i = 0; i < MAX / 2; i++) {

		for (int x = 1; x < (2 * i) + 1; x += 2) {
			for (int y = 2; y < (2 * i) + 2; y += 2) {
				grass[i].setTexture(grassTexture);
				grass[i].setPosition(ReturnLineValue(x, MAX), ReturnLineValue(y, MAX));
			}
		}
	}


	// Create a sf::Vector2f for player velocity and add to the y variable value gravity

	sf::Clock clock;
	while (window.isOpen())
	{
		// Get the frame elapsed time and restart the clock
		float dt = clock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		// Draw the grass
		for (std::size_t i = 0; i<grass.size(); ++i)
		{
			window.draw(grass[i]);
		}

		// Draw the player
		window.display();
	}

	return 0;
}