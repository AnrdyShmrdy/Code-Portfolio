#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Defaults.h"
using namespace std;
using namespace sf;
void VECTORS(){
for (int i=0; i<12; i++){scenes.push_back(SCENE());}
scenes[1].enemies.push_back(ENEMY());
scenes[2].enemies.push_back(ENEMY());
scenes[2].enemies.push_back(ENEMY());
}

void Set_Enemy_Health(int num){
scenes[1].enemies[0].setHealth(num);
scenes[2].enemies[0].setHealth(num);
scenes[2].enemies[1].setHealth(num);
}
void setTexture(){
player.SetTexture();
scenes[1].enemies[0].SetTexture();
scenes[2].enemies[0].SetTexture();
scenes[2].enemies[1].SetTexture();
bullet.SetTexture(PlayerBullet);
bullet.sprite.setColor(Color::Red);
bullet.sprite.rotate(90);
ENEMYbullet.SetTexture(EnemyBullet);
ENEMYbullet.sprite.rotate(90);
}
void setSpriteBlank(){
scenes[1].enemies[0].Clear_Sprite();
scenes[2].enemies[0].Clear_Sprite();
scenes[2].enemies[1].Clear_Sprite();
bullet.Clear_Sprite();
ENEMYbullet.Clear_Sprite();}
void setFont(){
    if (!font.loadFromFile("sansation.ttf"))
		return;}
void Initialize_Dir(){
scenes[1].enemies[0].Initialize();
scenes[2].enemies[0].Initialize();
scenes[2].enemies[1].Initialize();
}
void Initialize_SceneVar(){
for(size_t i = 0; i <scenes.size(); i++){scenes[i].Initialize();}
}
void Initialize_Enemy(){
scenes[1].enemies[0].Begin_Intialize();
scenes[2].enemies[0].Begin_Intialize();
scenes[2].enemies[1].Begin_Intialize();
}
void Setup(){
	Initialize_SceneVar();
	Initialize_Enemy();
	Initialize_Dir();
	player.Other_Initialize();
	loadTexture();
	setTexture();
	setFont();}
void resetVariables(){
player.setLives(5);
Set_Enemy_Health(2);
player.Initialize();
Initialize_Enemy();
bullet.Initialize();
ENEMYbullet.Initialize();
Initialize_SceneVar();}
void Start_Scene(){
player.scene = 0;
scenes[0].grass.resize(4);
scenes[0].grass[0].Change_Position(Vector2f(0,756));
scenes[0].grass[1].Change_Position(Vector2f(128,756));
scenes[0].grass[2].Change_Position(Vector2f(256,756));
scenes[0].grass[3].Change_Position(Vector2f(384,756));}
void Scene1(){
player.scene = 1;
scenes[0].grass.clear();
scenes[1].grass.resize(12);
for(size_t i = 0; i<scenes[1].grass.size(); i++){
	scenes[1].grass[i].Change_Position(Vector2f(i*128,556));}
}
void Scene2(){
player.scene = 2;
scenes[1].grass.clear();
scenes[2].grass.resize(12);
for(size_t i = 0; i<scenes[2].grass.size(); i++){
scenes[2].grass[i].Change_Position(Vector2f(i*128,756));}
scenes[2].grass[3].clear_coordinates_AND_start(); // grass4
scenes[2].grass[4].clear_coordinates_AND_start(); // grass5
scenes[2].grass[7].clear_coordinates_AND_start(); // grass8
scenes[2].grass[8].clear_coordinates_AND_start(); // grass9
}
void Scene3_Coord(){
player.scene = 3;
scenes[3].grass.resize(19);
	for(size_t i = 0; i<scenes[3].grass.size(); i++){
		scenes[3].grass[i].Change_Position(Vector2f(i*128,756));}
	scenes[3].grass[11].Change_Position(Vector2f(200,656)); // grass12
	scenes[3].grass[12].Change_Position(Vector2f(300,556)); // grass13
	scenes[3].grass[13].Change_Position(Vector2f(400,456)); // grass14
	scenes[3].grass[14].Change_Position(Vector2f(500,356)); // grass15
	scenes[3].grass[15].Change_Position(Vector2f(700,356)); // grass16
	scenes[3].grass[16].Change_Position(Vector2f(800,456)); // grass17
	scenes[3].grass[17].Change_Position(Vector2f(900,556)); // grass18
	scenes[3].grass[18].Change_Position(Vector2f(1000,656)); // grass19
}
void Scene_Setup(){
Clear_SceneCoord();
Initialize_Dir();
setSpriteBlank();
bullet.Clear_Sprite();
ENEMYbullet.Clear_Sprite();}
void ChangeScene0(){
Scene_Setup();
player.sprite.setPosition(0,156);
Set_Enemy_Health(2);
Start_Scene();}
void ChangeScene1(){
Scene_Setup();
Enemy_Configure(1,0,Vector2f(556,666));
Scene1();
}
void ChangeScene2(){
Scene_Setup();
Scene2();
Enemy_Configure(2,0,Vector2f(500,450));
Enemy_Configure(2,1,Vector2f(1000,450));
}

void Player_and_Bullet_Collision(){
	if(player.getLives() == 0){ // When the player's lives run out
	resetVariables(); // this is the only point where all the variables must be reset.
	ChangeScene1();
	player.sprite.setPosition(50, 400);}
			Enemy_Hit(1,0,2);
			Enemy_Hit(2,0,2);
			Enemy_Hit(2,1,2);
			Player_BULLETHit();
			Player_Hit(1,0,Vector2f(0,428)); // have a boolean for Changing the respawn location like the fall config does
			Player_Hit(2,0,Vector2f(0,428));
			Player_Hit(2,1,Vector2f(0,428));
}
void Switch_Scene(int function){
switch(function){
case 0: ChangeScene0(); break;
case 1: ChangeScene1(); break;
case 2: ChangeScene2(); break;
}}
void Transition(DIRECTION direction, int scene, int scene_transition,float ChangePos, Vector2f Pos){
if(direction == DIRECTION::right){
if(player.sprite.getPosition().x > ChangePos && player.scene == scene){
	Switch_Scene(scene_transition);
	scenes[scene_transition].walk_forward = true;
	scenes[scene_transition].walk_back = false;
	scenes[scene].walk_back = false;
	player.sprite.setPosition(Pos.x, Pos.y);}}
if(direction == DIRECTION::left){
if(player.sprite.getPosition().x < ChangePos && player.scene == scene){
	Switch_Scene(scene_transition);
	scenes[scene_transition].walk_forward = false;
	scenes[scene_transition].walk_back = true;
	player.sprite.setPosition(Pos.x, Pos.y);}}
if(direction == DIRECTION::down){
if(player.sprite.getPosition().y > ChangePos && player.scene == scene){
	Switch_Scene(scene_transition);
	player.sprite.setPosition(Pos.x, Pos.y);}}
if(direction == DIRECTION::up){
if(player.sprite.getPosition().y < ChangePos && player.scene == scene){
	Switch_Scene(scene_transition);
	player.sprite.setPosition(Pos.x, Pos.y);}}}
void Screen_Change(){
	Transition(DIRECTION::down,0,1,900,Vector2f(148,257));
	Fall_Config(1,900,Vector2f(0,500),false,NULL_BOOL);
	Transition(DIRECTION::right,1,2,1315,Vector2f(0,556));
	Fall_Config(2,900,Vector2f(0,500),true,false);
	Transition(DIRECTION::left,2,1,0,Vector2f(1309,356));

}
void Player_Physics(){
	for(size_t v = 0; v < scenes.size(); v++)
	   for (size_t i=0; i<scenes[v].grass.size(); ++i)
        {
            // Affected area
			FloatRect area;
			FloatRect areaP = player.sprite.getGlobalBounds();
			FloatRect areaG = scenes[v].grass[i].sprite.getGlobalBounds();
			Player_and_Bullet_Collision();
	Screen_Change();
            if (areaP.intersects(areaG, area)) // grass tile collision detection
            {
                // Verifying if we need to apply collision to the vertical axis, else we apply to horizontal axis
                if (area.width > area.height)
                {
                    if (area.contains( area.left, player.sprite.getPosition().y ))
                    {
                        // Up side crash
                        player.sprite.setPosition( player.sprite.getPosition().x, player.sprite.getPosition().y + area.height );
                    }
                    else if (player.inAir == player.maxInAir)
                    {
                        // Down side crash
                        player.onGround = true;

                        player.inAir = 0.f;
                        player.sprite.setPosition( player.sprite.getPosition().x, player.sprite.getPosition().y - area.height );
                    }
                }
                else if (area.width < area.height)
                {
                    if (area.contains( player.sprite.getPosition().x + areaP.width - 1.f, area.top + 1.f ))
                    {
                        //Right side crash
                        player.sprite.setPosition( player.sprite.getPosition().x - area.width, player.sprite.getPosition().y );
                    }
                    else
                    {
                        //Left side crash
                        player.sprite.setPosition( player.sprite.getPosition().x + area.width, player.sprite.getPosition().y );
                    }
                }
            }
	   }}
