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
int main(int argc, char ** argv){
	//create a font
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
  sf::Font font;
    if (!font.loadFromFile("sansation.ttf"))
        return EXIT_FAILURE;
    sf::Text pauseMessage;
    pauseMessage.setFont(font);
    pauseMessage.setCharacterSize(40);
    pauseMessage.setPosition(100.f, 80.f);
    pauseMessage.setFillColor(sf::Color::White);
    pauseMessage.setString("Welcome to the test of a game!\nThis text is just a test example");
  while (window.isOpen()){
    while (window.pollEvent(event)){
      if (event.type == sf::Event::EventType::Closed)
        window.close();
    }
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Z))){
		rectSourceSprite.top = 10; rectSourceSprite.left = 353; rectSourceSprite.width = 25; sprite.setTextureRect(rectSourceSprite);}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::X))){
		rectSourceSprite.top = 42; rectSourceSprite.left = 3; rectSourceSprite.width = 17; sprite.setTextureRect(rectSourceSprite);}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::C))){
		rectSourceSprite.top = 42; rectSourceSprite.left = 27; rectSourceSprite.width = 22; sprite.setTextureRect(rectSourceSprite);}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::V))){
		rectSourceSprite.top = 74; rectSourceSprite.left = 105; rectSourceSprite.width = 32; sprite.setTextureRect(rectSourceSprite);}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract))){
		fire = LEFT;}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Add))){
		fire = RIGHT;}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::F))){
	flipped = !flipped;
		rectSourceSprite.left += rectSourceSprite.width;
		rectSourceSprite.width = -rectSourceSprite.width;
	sprite.setTextureRect(rectSourceSprite);}

/*switch(fire){

case LEFT:
		if(facing == RIGHT){
			rectSourceSprite.left = 100;}
		if(facing == LEFT){
			rectSourceSprite.left = 100;}sprite.setTextureRect(rectSourceSprite);
break;
case RIGHT:
		if(facing == RIGHT){
			rectSourceSprite.left = 100;}
		if(facing == LEFT){ // do not go past 1600 or less than 1340
			rectSourceSprite.left = 100;}sprite.setTextureRect(rectSourceSprite);
break;}*/

if (clock.getElapsedTime().asSeconds() > 1.0f){
switch(rectSourceSprite.left){
	case 103:
	rectSourceSprite.top = 10; rectSourceSprite.left = 353; rectSourceSprite.width = 25;
	break;
	case 353:
	rectSourceSprite.top = 42; rectSourceSprite.left = 3; rectSourceSprite.width = 17;
	break;
	case 3:
	rectSourceSprite.top = 42; rectSourceSprite.left = 27; rectSourceSprite.width = 22;
	break;
	case 125:
	rectSourceSprite.top = 10; rectSourceSprite.left = 378; rectSourceSprite.width = 25;
	break;
	case 378:
    rectSourceSprite.top = 42; rectSourceSprite.left = 3; rectSourceSprite.width = 17;
	break;
	case 20:
	rectSourceSprite.top = 42; rectSourceSprite.left = 27; rectSourceSprite.width = 22;
	break;
default:
rectSourceSprite.left = 103; rectSourceSprite.top = 10;
break;
}
      sprite.setTextureRect(rectSourceSprite);
      clock.restart();

    }
				if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right))){
facing = RIGHT;
					sprite.move(+4.0,+0.0);}

				if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left))){
facing = LEFT;
					sprite.move(-4.0,+0.0);}

				if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down))){
					sprite.move(+0.0,+4.0);}
				if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up))){
					sprite.move(+0.0,-4.0);}
				if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D))){
					rectSourceSprite.left += 1;
				sprite.setTextureRect(rectSourceSprite);}
				if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A))){
				rectSourceSprite.left -= 1;
				sprite.setTextureRect(rectSourceSprite);}
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W))){
					rectSourceSprite.top += 1;
				sprite.setTextureRect(rectSourceSprite);}
				if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S))){
				rectSourceSprite.top -= 1;
				sprite.setTextureRect(rectSourceSprite);}
				if ((sf::Keyboard::isKeyPressed(sf::Keyboard::I))){
					pauseMessage.move(+0.0,+4.0);}
				if ((sf::Keyboard::isKeyPressed(sf::Keyboard::K))){
					pauseMessage.move(+0.0,-4.0);}
				cout << "rect left " << rectSourceSprite.left;
				cout << " rect top " << rectSourceSprite.top << endl;
    window.clear();
    window.draw(pauseMessage);
	window.draw(sprite);
    window.display();
  }
}
