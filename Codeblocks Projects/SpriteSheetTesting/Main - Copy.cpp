// Demonstrate creating a spritesheet
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
enum DIR{LEFT,RIGHT};
enum STATE{ON,OFF};
bool flipped = false;
DIR fire = LEFT;
DIR facing = LEFT;
int width = 22;
int height = 25;
void Animation(sf::Clock &clock,sf::IntRect &rectSourceSprite, sf::Sprite &sprite){
if (clock.getElapsedTime().asSeconds() > 0.16f){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        switch(rectSourceSprite.left){
            case 125:
            rectSourceSprite.top = 10; rectSourceSprite.left = 103; rectSourceSprite.width = 25;
            case 103:
            rectSourceSprite.top = 10; rectSourceSprite.left = 353; rectSourceSprite.width = 25;
            break;
            case 353:
            rectSourceSprite.top = 42; rectSourceSprite.left = 3; rectSourceSprite.width = 25;
            break;
            case 3:
            rectSourceSprite.top = 42; rectSourceSprite.left = 27; rectSourceSprite.width = 25;
            break;
            default:
            rectSourceSprite.top = 10; rectSourceSprite.left = 353; rectSourceSprite.width = 25;
            break;
            }
        }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        switch(rectSourceSprite.left){
            case 103:
            rectSourceSprite.top = 10; rectSourceSprite.left = 125; rectSourceSprite.width = -25;
            break;
            case 125:
            rectSourceSprite.top = 10; rectSourceSprite.left = 378; rectSourceSprite.width = -25;
            break;
            case 378:
            rectSourceSprite.top = 42; rectSourceSprite.left = 20; rectSourceSprite.width = -25;
            break;
            case 20:
            rectSourceSprite.top = 42; rectSourceSprite.left = 49; rectSourceSprite.width = -25;
            break;
            default:
            rectSourceSprite.top = 10; rectSourceSprite.left = 378; rectSourceSprite.width = -25;
            break;
            }
        }
sprite.setTextureRect(rectSourceSprite);
clock.restart();
    }
}

int main(int argc, char ** argv){
  sf::RenderWindow window(sf::VideoMode(1000, 1000), "Demo Game");
  sf::Event event;
  sf::Texture texture;
  // height: 25 pixels
  // width: 22 pixels
  // rect.top 1st row = 10
  texture.loadFromFile("MegaMan Player Spritesheet.png");
  sf::IntRect rectSourceSprite(103, 10, width, height);
  sf::Sprite sprite(texture,rectSourceSprite);
  sprite.setScale(2,2);
  sprite.scale(2,2);
  sprite.setPosition(300, 300);
  window.setVerticalSyncEnabled(true);
  sf::Clock clock;
  while (window.isOpen()){
    while (window.pollEvent(event)){
      if (event.type == sf::Event::EventType::Closed)
        window.close();
if (event.type == sf::Event::EventType::KeyReleased)
{
    if (event.key.code == sf::Keyboard::Key::Right)
    {
    rectSourceSprite.top = 10; rectSourceSprite.left = 103; rectSourceSprite.width = 25; sprite.setTextureRect(rectSourceSprite);
    }
    if (event.key.code == sf::Keyboard::Key::Left)
    {
    rectSourceSprite.top = 10; rectSourceSprite.left = 125; rectSourceSprite.width = -25; sprite.setTextureRect(rectSourceSprite);
    }
}
    }
    Animation(clock,rectSourceSprite,sprite);
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Z))){
		rectSourceSprite.top = 10; rectSourceSprite.left = 353; rectSourceSprite.width = 25; sprite.setTextureRect(rectSourceSprite);}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::X))){
		rectSourceSprite.top = 42; rectSourceSprite.left = 3; rectSourceSprite.width = 17; sprite.setTextureRect(rectSourceSprite);}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::C))){
		rectSourceSprite.top = 42; rectSourceSprite.left = 27; rectSourceSprite.width = 22; sprite.setTextureRect(rectSourceSprite);}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::V))){
		rectSourceSprite.top = 74; rectSourceSprite.left = 105; rectSourceSprite.width = 32; sprite.setTextureRect(rectSourceSprite);}
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::B))){
		rectSourceSprite.top = 10; rectSourceSprite.left = 125; rectSourceSprite.width = -32; sprite.setTextureRect(rectSourceSprite);}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::F))){
        flipped = !flipped;
		rectSourceSprite.left += rectSourceSprite.width;
		rectSourceSprite.width = -rectSourceSprite.width;
        sprite.setTextureRect(rectSourceSprite);}
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::L))){
                rectSourceSprite.left += 1;
				sprite.setTextureRect(rectSourceSprite);}
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::J))){
				rectSourceSprite.left -= 1;
				sprite.setTextureRect(rectSourceSprite);}
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::I))){
                rectSourceSprite.top += 1;
				sprite.setTextureRect(rectSourceSprite);}
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::K))){
				rectSourceSprite.top -= 1;
				sprite.setTextureRect(rectSourceSprite);}
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right))){
        sprite.move(+4.0,+0.0);}
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left))){
        sprite.move(-4.0,+0.0);}
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down))){
        sprite.move(+0.0,+4.0);}
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up))){
        sprite.move(+0.0,-4.0);}
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D))){
        cout << "rect left " << rectSourceSprite.left;
        cout << " rect top " << rectSourceSprite.top << endl;}
    window.clear();
	window.draw(sprite);
    window.display();
  }
}
