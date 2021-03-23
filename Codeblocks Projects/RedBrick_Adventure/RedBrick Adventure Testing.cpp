#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Scenes.h"
using namespace std;
using namespace sf;
RectangleShape rectangle(sf::Vector2f(90, 128));
float velTOtime;
const int VelChange() {
	if (bullet.direction == DIRECTION::right)
		return velTOtime;
	else
		return -velTOtime;
}
const int EnemyVelChange(){
	if (ENEMYbullet.direction == DIRECTION::right)
	return velTOtime;
	else
		return -velTOtime;
}
int main()
{
	VECTORS();
    RenderWindow window(VideoMode(1400,900), "Redbrick Adventure");
   Setup();
   ChangeScene0();
   bullet.direction = DIRECTION::right;
   player.direction = DIRECTION::right;
   // Create a Vector2f for player velocity and add to the y variable value gravity
	Vector2f playerVelocity(0, gravity);
	Clock clock; // for player movement
// player height = 128 pixels, player width = 90 pixels
rectangle.setPosition(Vector2f(400,628));
    while (window.isOpen())
    {
		Define_LeftCorner();
		Define_RightCorner();
		Display_Values();
        // Get the frame elapsed time and restart the clock
        float dt = clock.restart().asSeconds();
		float EnT = EnemyTime.getElapsedTime().asSeconds();
		bullet.vel = VelChange();
        Event event;
        float timeTOsize = window.getSize().x / 2;
		velTOtime = timeTOsize  / 116.6666666666667;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
			if ((Keyboard::isKeyPressed(Keyboard::Add)) && (bullet.bullet_inAir == false))
				bullet.direction = DIRECTION::right;
			if ((Keyboard::isKeyPressed(Keyboard::Subtract)) && (bullet.bullet_inAir == false))
				bullet.direction = DIRECTION::left;
			if (bullet.direction == DIRECTION::right)
			bullet.vel = pos_vel;
			if (bullet.direction == DIRECTION::left)
			bullet.vel = neg_vel;
        }
		horizontal_movements(20.0f,1,0,0,1250);
			vertical_movements(20.0f,2,0,-300,900);
			vertical_movements(20.0f,2,1,-300,900);
			bullet.bullet_inAir = true;
			bullet.sprite.move(bullet.vel, 0);// This is for preventing the bullet changing path while moving
			Bullet_Config(1450,-100);
			Bullet_Fire(timeTOsize);
        // Apply physics to player
        player.sprite.setPosition(player.sprite.getPosition().x + playerVelocity.x * dt, player.sprite.getPosition().y + playerVelocity.y * dt);
        player.onGround = false; // THIS IS NECESSARY. DO NOT REMOVE OR MOVE.
       Player_Physics();
        move(playerVelocity, dt);

        window.clear();

        // Draw the grass
		for (size_t i=0; i<scenes[player.scene].grass.size(); ++i)
        {
			window.draw(scenes[player.scene].grass[i].sprite);
        }


	window.draw(player.sprite);
		window.draw(bullet.sprite);
		window.draw(ENEMYbullet.sprite);
		window.draw(LeftCorner);
		window.draw(RightCorner);
		window.draw(scenes[1].enemies[0].sprite);
window.draw(scenes[2].enemies[0].sprite);
window.draw(scenes[2].enemies[1].sprite);
window.draw(rectangle);
        window.display();
    }
return 0;
}
