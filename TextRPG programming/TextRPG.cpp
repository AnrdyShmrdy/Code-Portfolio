#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
bool no = false;
int p_max = 10; // this is the maximum attack the player can deal
int p_min = 1; // this is the base attack stat. Note that this is the minimum attack the player can deal
int p_health_max = 50; // max health for player at current level
int p_health = 50;
int p_exp = 0;
int p_level = 1;
std::string e1_name = "Enemy1";
std::string e2_name = "Enemy2";
std::string e3_name = "Enemy3";
const int max_e1_health = 15;
const int max_e2_health = 30;
const int max_e3_health = 45;
std::vector<int> expLevel;
void LevelXPset(float constant, int level_max){
for(int i = 0; i <= level_max; i++){
    int e = pow(constant, i) - 1;
    expLevel.push_back(e);
}
}
void LevelUp(int &player_health, int& player_xp, int &player_level,int &player_min, int &player_max, int rand_limit){
int rand_stat1 = rand() % rand_limit;
int rand_stat2 = rand() % rand_limit;
p_health_max +=  rand_stat1;
player_min += rand_stat2;
player_max += rand_stat2;
player_level += 1;
player_health = p_health_max;
std::cout << "Level Up!" << std::endl;
std::cout << "Attack raised by: " << rand_stat2 << std::endl;
std::cout << "Health raised by: " << rand_stat1 << std::endl;
std::cout << "Attack: " << p_min << std::endl;
std::cout << "Health: " << p_health << std::endl;
std::cout << "Level: " << p_level << std::endl;
}
void AttackOrFlee(int max, int min, bool &flee, int &enemy_health, std::string e_name) {
	char input;
	int r1;
	int r2;
	std::cout << "Attack(a)		or		Flee(f)?" << std::endl;
	std::cin >> input;
switch (input){
	case 'a':
	    srand(time(NULL));
		r1 = rand() % p_max + p_min;
		enemy_health -= r1;
		std::cout << "You did " << r1 << " damage to " << e_name << std::endl;
		if(enemy_health <= 0){
        std::cout << "You have slain the enemy!" << std::endl;
        switch(e_name.at(5)){
            case '1':
                p_exp += 1;
                std::cout << "Gained 1 exp." << std::endl;
                break;
            case '2':
                p_exp += 2;
                std::cout << "Gained 2 exp." << std::endl;
                break;
            case '3':
            p_exp += 3;
            std::cout << "Gained 3 exp." << std::endl;
            break;
    }
    while(expLevel.at(p_level + 1) <= p_exp){
    if(expLevel.at(p_level + 1) <= p_exp){
    LevelUp(p_health,p_exp,p_level,p_min, p_max,3);
    }}
        break;
		}
		std::cout << e_name << "'s health: " << enemy_health << std::endl;
        r2 = rand() % max + min;
		p_health -= r2;
		std::cout << "You took " << r2 << " damage from " << e_name << std::endl;
        if(p_health <= 0){
        std::cout << "You have been slain. Game Over!" << std::endl;
        break;
		}
		std::cout << "Your health: " << p_health << std::endl;
		break;
	case 'f':
		flee = true;
		std::cout << "You fled from the battle" << std::endl;
		break;
	}
}
void YesOrNo() {
	bool flee = false;
	char input;
	int r1;
	int e1_health = max_e1_health;
	int e2_health = max_e2_health;
	int e3_health = max_e3_health;
	std::cout << "Continue?" << std::endl;
	std::cout << "Yes(y)		or		No(n)?" << std::endl;
	std::cin >> input;
	if (input == 'y') {
		r1 = rand() % 4 + 1;
		switch (r1) {
		case 1:
			std::cout << e1_name << " appears!" << std::endl;
			while (flee == false && e1_health > 0 && p_health > 0) {
				AttackOrFlee(6, 1, flee, e1_health, e1_name);
			}
			break;
		case 2:
			std::cout << e2_name << " appears!" << std::endl;
			while (flee == false && e2_health > 0 && p_health > 0) {
				AttackOrFlee(7, 2, flee, e2_health, e2_name);
			}
			break;
		case 3:
			std::cout << e3_name << " appears!" << std::endl;
			while (flee == false && e3_health > 0 && p_health > 0) {
				AttackOrFlee(8, 3, flee, e3_health, e3_name);
			}
			break;
		case 4:
			std::cout << "No enemies appeared" << std::endl;
			break;
		}
	}
	else if (input == 'n') {
		no = true;
	}
}
int main() {
LevelXPset((3.0/2.0),10);
srand(time(NULL));
	while (no == false && p_health > 0) {
		YesOrNo();
	}
	return 0;
}
