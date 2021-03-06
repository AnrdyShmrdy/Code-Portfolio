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

void move(sf::Vector2f &playerVelocity, float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		playerVelocity.x = -gravity;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		playerVelocity.x = gravity;
	}
	else if (playerVelocity.x != 0)
	{
		playerVelocity.x = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && (onGround || inAir < maxInAir))
	{
		playerVelocity.y = -gravity;
		inAir += dt;
	}
	else
	{
		playerVelocity.y = gravity;
		inAir = maxInAir;
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1400, 900), "Level Tester");

	// Loading player texture
	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("player.png")) return 0;

	// Creating player sprite
	sf::Sprite player;
	player.setTexture(playerTexture);

	// Loading grass texture
	sf::Texture grassTexture;
	if (!grassTexture.loadFromFile("grass.png")) return 0;

	// Creating a vector because we have more blocks and we will need them into a container
	std::vector<sf::Sprite> grass;
	int MAX = ReturnLineValue(0, 1);

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
	sf::Vector2f playerVelocity(0, gravity);
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
		if (Keyboard::isKeyPressed(Keyboard::R)) {
			player.setPosition(0, 0);
		}
		// Apply physics to player
		player.setPosition(player.getPosition().x + playerVelocity.x * dt, player.getPosition().y + playerVelocity.y * dt);
		onGround = false;
		for (std::size_t i = 0; i<grass.size(); ++i)
		{
			// Affected area
			sf::FloatRect area;
			if (player.getGlobalBounds().intersects(grass[i].getGlobalBounds(), area))
			{
				// Verifying if we need to apply collision to the vertical axis, else we apply to horizontal axis
				if (area.width > area.height)
				{
					if (area.contains(area.left, player.getPosition().y))
					{
						// Up side crash
						player.setPosition(player.getPosition().x, player.getPosition().y + area.height);
					}
					else if (inAir == maxInAir)
					{
						// Down side crash
						onGround = true;
						inAir = 0.f;
						player.setPosition(player.getPosition().x, player.getPosition().y - area.height);
					}
				}
				else if (area.width < area.height)
				{
					if (area.contains(player.getPosition().x + player.getGlobalBounds().width - 1.f, area.top + 1.f))
					{
						//Right side crash
						player.setPosition(player.getPosition().x - area.width, player.getPosition().y);
					}
					else
					{
						//Left side crash
						player.setPosition(player.getPosition().x + area.width, player.getPosition().y);
					}
				}
			}
		}

		move(playerVelocity, dt);

		window.clear();

		// Draw the grass
		for (std::size_t i = 0; i<grass.size(); ++i)
		{
			window.draw(grass[i]);
		}

		// Draw the player
		window.draw(player);
		window.display();
	}

	return 0;
}