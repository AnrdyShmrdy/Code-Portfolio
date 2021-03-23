#include <SFML/Graphics.hpp>
#include <SFML\My Additions\sfml.h>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Inputs and Outputs.h"
using namespace std;
using namespace sf;
string grass_x = "GrassX: ";
string grass_y = "GrassY: ";
string block_no = "Block: ";
string BlockInUse = "Block in Use";
Texture grassTexture;
Texture Cursor_Texture;
Font font;
Text grassX;
Text grassY;
Text Block_Count;
Text Block_In_Use;
std::vector<Vector2i> grass;
Sprite Cursor;
Sprite Current_Texture;
vector<Sprite>Grass_Blocks;
int real_current_block = 0;
int current_block = 0;
int MaxBlocks;
void setFont() {
	if (!font.loadFromFile("sansation.ttf")) cout << "Unable to Open Font file " << endl;
		return;
}
void LoadTexture() {
	if (!grassTexture.loadFromFile("grass.png")) cout << "Unable to Open Grass file " << endl; return;
	if (!Cursor_Texture.loadFromFile("Cursor.png")) cout << "Unable to open Cursor file " << endl; return;
}
void Initialize_Grass() {
	grass.resize(MaxBlocks + 1);/* this must be adjusted by +2 for every new block */
	Grass_Blocks.resize(MaxBlocks + 1);
	for (size_t i = 0; i < Grass_Blocks.size(); i++) {
		Grass_Blocks[i].setTexture(grassTexture);
		Grass_Blocks[i].setPosition(-900, -900);
	}
}
void Define_grassX() {
	grassX.setFont(font);
	grassX.setCharacterSize(30);
	grassX.setPosition(400, 25);
	grassX.setColor(Color::White);
	grassX.setString(toString(grass_x) + toString(Cursor.getPosition().x));
}
void Define_grassY() {
	grassY.setFont(font);
	grassY.setCharacterSize(30);
	grassY.setPosition(700, 25);
	grassY.setColor(Color::White);
	grassY.setString(toString(grass_y) + toString(Cursor.getPosition().y));
}
void Define_Block_Count() {
	Block_Count.setFont(font);
	Block_Count.setCharacterSize(30);
	Block_Count.setPosition(550, 50);
	Block_Count.setColor(Color::White);
	Block_Count.setString(toString(block_no) + toString(current_block / 2));
}
void Define_Block_In_Use() {
	Block_In_Use.setFont(font);
	Block_In_Use.setCharacterSize(30);
	Block_In_Use.setPosition(150, 25);
	Block_In_Use.setColor(Color::White);
	Block_In_Use.setString(toString(BlockInUse));
}
void AskMaxBlocks() {
	cout << "How many blocks do you want to use?" << endl;
	cin >> MaxBlocks;
}
void main()
{
	AskMaxBlocks();
	sf::RenderWindow window(sf::VideoMode(1400, 900), "Level Creator");
	setFont();
	LoadTexture();
	Initialize_Grass();
	Cursor.setTexture(grassTexture);
	Current_Texture.setTexture(grassTexture);
	Current_Texture.setPosition(0, 0);
	Cursor.setPosition(0, 500);
	Cursor.setTexture(Cursor_Texture);
	// Create a sf::Vector2f for player velocity and add to the y variable value gravity

	while (window.isOpen())
	{
		// Get the frame elapsed time and restart the clock
		Define_grassX();
		Define_grassY();
		Define_Block_Count();
		Define_Block_In_Use();
		sf::Event event;
		window.setKeyRepeatEnabled(false);
		int PositionX = Cursor.getPosition().x;
		int PositionY = Cursor.getPosition().y;
		real_current_block = current_block / 2;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (Keyboard::isKeyPressed(Keyboard::W))
				Cursor.setPosition(Cursor.getPosition().x, Cursor.getPosition().y - 64);
			if (Keyboard::isKeyPressed(Keyboard::S))
				Cursor.setPosition(Cursor.getPosition().x, Cursor.getPosition().y + 64);
			if (Keyboard::isKeyPressed(Keyboard::A))
				Cursor.setPosition(Cursor.getPosition().x - 64, Cursor.getPosition().y);
			if (Keyboard::isKeyPressed(Keyboard::D))
				Cursor.setPosition(Cursor.getPosition().x + 64, Cursor.getPosition().y);
			if (Keyboard::isKeyPressed(Keyboard::R))
				Cursor.setPosition(0, 500);
			if (Keyboard::isKeyPressed(Keyboard::Space)) {
				grass[real_current_block].x = PositionX; grass[real_current_block].y = PositionY;
				Grass_Blocks[real_current_block].setPosition(PositionX, PositionY);
				current_block += 1;
			}
			if (Keyboard::isKeyPressed(Keyboard::I))
				Cursor.setPosition(Cursor.getPosition().x, Cursor.getPosition().y - 1);
			if (Keyboard::isKeyPressed(Keyboard::K))
				Cursor.setPosition(Cursor.getPosition().x, Cursor.getPosition().y + 1);
			if (Keyboard::isKeyPressed(Keyboard::J))
				Cursor.setPosition(Cursor.getPosition().x - 1, Cursor.getPosition().y);
			if (Keyboard::isKeyPressed(Keyboard::L))
				Cursor.setPosition(Cursor.getPosition().x + 1, Cursor.getPosition().y);
			if ((Keyboard::isKeyPressed(Keyboard::C) && real_current_block >= 1)) {
				current_block = 0;
				Cursor.setPosition(0, 500);
				for (size_t i = 0; i < grass.size(); i++) {
					grass[i].x = -900; grass[i].y = -900;
					Grass_Blocks[i].setPosition(-900, -900);
				}
			}
			if ((Keyboard::isKeyPressed(Keyboard::BackSpace) && real_current_block >= 1)) {
				grass[real_current_block - 1].x = -900; grass[real_current_block - 1].y = -900;
				Grass_Blocks[real_current_block - 1].setPosition(-900, -900);
				current_block -= 1;
			}
		}

		window.clear();
		if (Keyboard::isKeyPressed(Keyboard::Up))
			Cursor.setPosition(Cursor.getPosition().x, Cursor.getPosition().y - 1);
		if (Keyboard::isKeyPressed(Keyboard::Down))
			Cursor.setPosition(Cursor.getPosition().x, Cursor.getPosition().y + 1);
		if (Keyboard::isKeyPressed(Keyboard::Left))
			Cursor.setPosition(Cursor.getPosition().x - 1, Cursor.getPosition().y);
		if (Keyboard::isKeyPressed(Keyboard::Right))
			Cursor.setPosition(Cursor.getPosition().x + 1, Cursor.getPosition().y);
		if (real_current_block == MaxBlocks + 1) /* this must be adjusted by +2 for every new block */ {
			Input_ALL_Coordinates(grass);
			window.close();
		}
		for (std::size_t i = 0; i<Grass_Blocks.size(); ++i)
		{
			window.draw(Grass_Blocks[i]);
		}
		// Draw the grass
		// Draw the player
		window.draw(grassX);
		window.draw(grassY);
		window.draw(Block_Count);
		window.draw(Block_In_Use);
		window.draw(Current_Texture);
		window.draw(Cursor);
		window.display();
	}
}
