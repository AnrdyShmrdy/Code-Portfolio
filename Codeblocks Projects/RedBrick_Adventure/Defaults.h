#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
using namespace sf;
const float gravity = 500;
const int pos_vel = 6;
const int neg_vel = -6;
int grass_block_num;
const float clear_x = -900;
const float clear_y = -900;
bool NULL_BOOL;
float speed = 0.5;
const float neg_speed = -0.5;
const float pos_speed = 0.5;
enum DIRECTION{up,down,left,right};
enum STATE{ON,OFF};
DIRECTION fire = DIRECTION::left;
STATE shoot = OFF;
template <typename T>
string toString(T arg)
{
    stringstream ss;
    ss << arg;
    return ss.str();
}
string lives_left = "lives: ";
string what_scene = "scene ";
Texture playerTexture,grassTexture,enemyTexture,PlayerBullet,EnemyBullet;
Font font;
Text LeftCorner;
Text RightCorner;
void loadTexture(){
	// load textures from files
	if(!enemyTexture.loadFromFile("player.png")) return;
	if (!playerTexture.loadFromFile("player.png")) return;
	 if(!PlayerBullet.loadFromFile("player 1-8th size green.png")) return;
	  if(!EnemyBullet.loadFromFile("player 1-8th size red.png")) return;
	 if (!grassTexture.loadFromFile("grass.png")) return;}
class PLAYER {
public:
bool onGround;
float inAir,maxInAir;
int vel,scene;
Sprite sprite;
DIRECTION direction;
void SetTexture(){
sprite.setTexture(playerTexture);
}
void Initialize(){
direction = DIRECTION::right;
onGround = false;}
void Other_Initialize(){
// initializing not used in reseting variable function
	maxInAir = 0.35f;
	vel = 6;}
PLAYER(int lives = 5);
int getLives() const;
void setLives(int lives);
void minusLives(int lives);
void addLives(int lives);

private:
int m_Lives;};
PLAYER::PLAYER(int lives):
m_Lives(lives){}
int PLAYER::getLives() const
{
    return m_Lives;
}

void PLAYER::setLives(int lives)
{
        m_Lives = lives;
}
void PLAYER::minusLives(int lives)
{
 m_Lives -= lives;
}
void PLAYER::addLives(int lives)
{
 m_Lives += lives;
}

class BULLET {

public:

Sprite sprite;
bool bullet_inAir;
Clock clock;
DIRECTION direction;
float vel;
void SetTexture(Texture texture){

sprite.setTexture(texture);

}
void Clear_Sprite(){
	sprite.setPosition(clear_x, clear_y);}
void Initialize(){
	bool bullet_inAir = false;
	direction = DIRECTION::right;
	vel = 6;}
};

class ENEMY {
public:
bool reverse_dir,forward,enemy_killed;
DIRECTION direction;
Sprite sprite;
float BulletVel;
Clock clock;
void Begin_Intialize(){
	forward = false;
	enemy_killed = false;}
void Initialize(){
	reverse_dir = false;}
void SetTexture(){

sprite.setTexture(enemyTexture);

}
void Clear_Sprite(){
	sprite.setPosition(clear_x, clear_y);}
ENEMY(int health = 2);
int getHealth() const;
void setHealth(int health);
void minusHealth(int health);
void addHealth(int health);

private:

int m_Health;};
ENEMY::ENEMY(int health):
m_Health(health){}
int ENEMY::getHealth() const
{
    return m_Health;
}

void ENEMY::setHealth(int health)
{
        m_Health = health;
}
void ENEMY::minusHealth(int health)
{
 m_Health -= health;
}
void ENEMY::addHealth(int health)
{
 m_Health += health;
}

class GRASS{
public:
int number;
float x,y;
Sprite sprite;
void clear_coordinates_AND_start(){
	sprite.setTexture(grassTexture);
	sprite.setPosition(-900,-900);}
void clear_coordinates(){
	sprite.setPosition(-900,-900);}
void Change_Position(Vector2f position){
	sprite.setPosition(position.x,position.y);
	sprite.setTexture(grassTexture);}
};
class SCENE{
	// Class for the variables of specific scenes
public:
vector<GRASS> grass;
vector<ENEMY> enemies;
	bool walk_back; // for walking left to the scene
	bool walk_forward; // for walking right to the
DIRECTION direction;
void Initialize(){
	walk_back = false;
	walk_forward = false;}
void Walk_Initialize(){
walk_back = false;
walk_forward = false;}
SCENE(){
Walk_Initialize();
Initialize();}};
vector<SCENE>scenes;
PLAYER player;
BULLET bullet;
BULLET ENEMYbullet;



void Display_Values(){
cout << "player.x " << player.sprite.getPosition().x;
cout << " player.y " << player.sprite.getPosition().y << endl;
}
void Define_LeftCorner(){
LeftCorner.setFont(font);
LeftCorner.setCharacterSize(30);
LeftCorner.setPosition(25, 25);
LeftCorner.setFillColor(Color::White);
LeftCorner.setString(toString(lives_left) + toString(player.getLives()));}
void Define_RightCorner(){
RightCorner.setFont(font);
RightCorner.setCharacterSize(30);
RightCorner.setPosition(1075, 25);
RightCorner.setFillColor(Color::White);
RightCorner.setString(
 toString(what_scene) + toString(player.scene));}
void move(Vector2f &playerVelocity, float dt)
{
    if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        playerVelocity.x = -gravity;
		player.direction = DIRECTION::left;
    }
    else if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        playerVelocity.x = gravity;
		player.direction = DIRECTION::right;
    }
    else if (playerVelocity.x != 0)
    {
        playerVelocity.x = 0;
    }

    if (Keyboard::isKeyPressed(Keyboard::Up) && (player.onGround || player.inAir < player.maxInAir))
    {
        playerVelocity.y = -gravity;
        player.inAir += dt;
    }
    else
    {
        playerVelocity.y = gravity;
        player.inAir = player.maxInAir;
    }
}
void Enemy_Configure(int scene,int enemy, Vector2f Pos){
	if(scenes[scene].enemies[enemy].enemy_killed == false){
		scenes[scene].enemies[enemy].sprite.setPosition(Pos.x, Pos.y);}
	if(scenes[scene].enemies[enemy].enemy_killed == true){
		scenes[scene].enemies[enemy].Clear_Sprite();}}

void Clear_SceneCoord(){
	for(size_t i = 0; i<scenes.size(); i++){
scenes[i].grass.clear();}}

void Enemy_Hit(int scene, int enemy, int reset_health){
FloatRect area2;
if(bullet.sprite.getGlobalBounds().intersects(scenes[scene].enemies[enemy].sprite.getGlobalBounds(), area2)){
scenes[scene].enemies[enemy].minusHealth(1);
bullet.Clear_Sprite();
if(scenes[scene].enemies[enemy].getHealth() == 0){
scenes[scene].enemies[enemy].enemy_killed = true;
scenes[scene].enemies[enemy].Clear_Sprite();
scenes[scene].enemies[enemy].setHealth(reset_health);}}}
void Player_Hit(int scene,int enemy, Vector2f Pos){
FloatRect area2;
if(player.sprite.getGlobalBounds().intersects(scenes[scene].enemies[enemy].sprite.getGlobalBounds(), area2)){
player.sprite.setPosition(Pos.x, Pos.y);
player.minusLives(1);}}
void Player_BULLETHit(){
FloatRect area2;
if(player.sprite.getGlobalBounds().intersects(ENEMYbullet.sprite.getGlobalBounds(), area2)){
ENEMYbullet.Clear_Sprite();
player.minusLives(1);}}
void horizontal_movements(float frames, int scene, int enemy, float MinPos, float MaxPos){
	if(scenes[scene].enemies[enemy].clock.getElapsedTime().asMilliseconds() > frames && player.scene == scene){
		if(scenes[scene].enemies[enemy].sprite.getPosition().x < MinPos && scenes[scene].enemies[enemy].reverse_dir == false){
				scenes[scene].enemies[enemy].reverse_dir = true;}
			if(scenes[scene].enemies[enemy].sprite.getPosition().x > MaxPos){
				scenes[scene].enemies[enemy].reverse_dir = false;}
			if(scenes[scene].enemies[enemy].reverse_dir == true){
				scenes[scene].enemies[enemy].sprite.move(30, 0);
				scenes[scene].enemies[enemy].clock.restart();}
			if(scenes[scene].enemies[enemy].reverse_dir == false){
			scenes[scene].enemies[enemy].sprite.move(-30, 0);
			scenes[scene].enemies[enemy].clock.restart();}}}
void vertical_movements(float frames, int scene, int enemy, float MinPos, float MaxPos){
	if(scenes[scene].enemies[enemy].clock.getElapsedTime().asMilliseconds() > frames && player.scene == scene){
		if(scenes[scene].enemies[enemy].sprite.getPosition().y < MinPos && scenes[scene].enemies[enemy].reverse_dir == false){
				scenes[scene].enemies[enemy].reverse_dir = true;}
			if(scenes[scene].enemies[enemy].sprite.getPosition().y > MaxPos){
				scenes[scene].enemies[enemy].reverse_dir = false;}
			if(scenes[scene].enemies[enemy].reverse_dir == true){
				scenes[scene].enemies[enemy].sprite.move(0, 30);
				scenes[scene].enemies[enemy].clock.restart();}
			if(scenes[scene].enemies[enemy].reverse_dir == false){
			scenes[scene].enemies[enemy].sprite.move(0, -30);
			scenes[scene].enemies[enemy].clock.restart();}}}
void Bullet_Config(float MaxPos,float MinPos){
if(bullet.sprite.getPosition().x > MaxPos){
		bullet.Clear_Sprite();
		bullet.bullet_inAir = false;
}
if(bullet.sprite.getPosition().x < MinPos){
		bullet.Clear_Sprite();
		bullet.bullet_inAir = false;
}}
void Bullet_Fire(float speed){
if(Keyboard::isKeyPressed(Keyboard::Space)){
if(bullet.clock.getElapsedTime().asMilliseconds() > speed && bullet.bullet_inAir == false){
	bullet.bullet_inAir = true;
				// at 600 milliseconds vel must be 5
				// at 500 milliseconds vel must be 6
				// at 400 milliseconds vel must be 7
bullet.sprite.setPosition(player.sprite.getPosition().x + 80, player.sprite.getPosition().y + 55);
bullet.clock.restart();}
bullet.sprite.move(0,0);}}
void Bullet_Config_ENEMY(float MaxPos,float MinPos){
if(ENEMYbullet.sprite.getPosition().x > MaxPos){
		ENEMYbullet.Clear_Sprite();
		ENEMYbullet.bullet_inAir = false;
}
if(ENEMYbullet.sprite.getPosition().x < MinPos){
		ENEMYbullet.Clear_Sprite();
		ENEMYbullet.bullet_inAir = false;
}}
void Bullet_Fire_ENEMY(int scene,int enemy){
if(ENEMYbullet.clock.getElapsedTime().asMilliseconds() > 500.0f){
				// at 600 milliseconds vel must be 5
				// at 500 milliseconds vel must be 6
				// at 400 milliseconds vel must be 7
ENEMYbullet.sprite.setPosition(scenes[scene].enemies[enemy].sprite.getPosition().x + 75, scenes[scene].enemies[enemy].sprite.getPosition().y);
ENEMYbullet.clock.restart();
ENEMYbullet.sprite.move(0,0);}}
void Fall_Config(int scene, float changePos, Vector2f Pos, bool Test, bool testValue){
if(Test == true){
if(player.sprite.getPosition().y > changePos && player.scene == scene && scenes[scene].walk_back == testValue){ // THIS IS IT!!!!!!!!!!!!!!!!!!!! Controls falling off edge restore point
		player.minusLives(1);
		player.sprite.setPosition(Pos.x, Pos.y);}}
else{
	if(player.sprite.getPosition().y > changePos && player.scene == scene){
		player.minusLives(1);
		player.sprite.setPosition(Pos.x, Pos.y);}}}
Clock EnemyTime;
void BOSS1_AI(float d,int scene,int enemy){
	bool forward;
	bool backward;
	if(player.sprite.getPosition().x > scenes[scene].enemies[enemy].sprite.getPosition().x){
		forward = true; backward = false;}
	if(player.sprite.getPosition().x < scenes[scene].enemies[enemy].sprite.getPosition().x){
			forward = false; backward = true;}
	if(forward == true){
		if(player.sprite.getPosition().x < scenes[scene].enemies[enemy].sprite.getPosition().x + d + d){
		Bullet_Fire_ENEMY(11,0);}
		if(player.sprite.getPosition().x < scenes[scene].enemies[enemy].sprite.getPosition().x + d){
		speed = 0;}
		else{
			speed = pos_speed;}}
if(backward == true){
	if(player.sprite.getPosition().x > scenes[scene].enemies[enemy].sprite.getPosition().x - d - d){
		Bullet_Fire_ENEMY(scene,enemy);}
if(player.sprite.getPosition().x > scenes[scene].enemies[enemy].sprite.getPosition().x - d){
		speed = 0;}
else{
	speed = neg_speed;}}
	}
