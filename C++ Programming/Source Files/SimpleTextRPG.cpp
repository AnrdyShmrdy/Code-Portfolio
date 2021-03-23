#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <time.h>
#include <Windows.h>
using namespace std;
string l = "left";
string r = "right";
string at = "attack";
string flee = "flee";
string heal = "heal";
string shop = "shop";
string leave = "leave";
string buy = "buy";
string input;
string choice;
string shop_choice;
int character = 70;
int swamp_ogre = 10;
int forest_goblin = 20;
int meadow_gremlin = 30;
int river_monster = 40;
int mountain_orc = 50;
int graveyard_zombie = 10;
int castle_evil_guard = 20;
int catacomb_mummy = 30;
int ruins_stone_mage = 40;
int desert_sand_monster = 50;
int gold_coins = 0;
int MAX_HEALTH;
int health_potion = 60;
int health_potions_left = 2;
int encounter;
int enemy_has_appeared;
int before_attack_prompt;
int after_attack_prompt;
int level = 1;
int experience_points = 0;
int level_up = 0;
int RRRRandIndex;
int RRRandIndex;
int RRandIndex;
int RandIndex;
int leave_shop = 0;
void Shop() {
	cout << "You enter the shop" << endl;
	cout << "What will you do?" << endl;
	cout << "Buy		or		leave?" << endl;
	cin >> shop_choice;
	do {
		if (shop_choice == buy && input == shop) {
			cout << "What will you buy?" << endl;
		}
		if (shop_choice == leave || input == r || input == l) {
			cout << "You left the shop" << endl;
			leave_shop = 1;
		}
		else if (shop_choice != buy && shop_choice != leave) {
			cout << "Please chose buy or leave" << endl;
		}
	} while (leave_shop = 0);
}
void Random_Number_Refresh2_For_RRR_And_RRRR() {
	RRRandIndex = rand() % 2;
	RRRRandIndex = rand() % 2;
}
void Random_Number_Refresh5_For_R() {
	RandIndex = rand() % 5;
}
void Random_Number_Refresh5_For_RR() {
	RRandIndex = rand() % 5;
}
void Refresh_Enemies() {
	swamp_ogre = 10;
	forest_goblin = 20;
	meadow_gremlin = 30;
	river_monster = 40;
	mountain_orc = 50;
	graveyard_zombie = 10;
	castle_evil_guard = 20;
	catacomb_mummy = 30;
	ruins_stone_mage = 40;
	desert_sand_monster = 50;
}
void WELCOME_TO_GAME() {
	cout << "Welcome to Simple RPG" << endl;
	cout << "This is my first attempt at an RPG game" << endl;
	cout << "Before you begin, here is what you should know:" << endl;
	cout << "When you get 50 exp, you reach the next level and your health is restored" << endl;
	cout << "Once you instigate an enemy, you cannot flee" << endl;
	cout << "You can heal twice while fighting an enemy" << endl;
	cout << "This game is completely text based." << endl;
	cout << "You will make choices by typing in text" << endl;
	cout << "Good luck, and have fun!" << endl;
}
void Begin() {
	cout << "You begin walking down a dirt road." << endl;
	cout << "You come to a fork in the road." << endl;
	cout << "Which path do you chose?" << endl;
	cout << "Right			or			left?" << endl;
}
void Begin_Again() {
	cout << "You continue on until you reach another fork in the road" << endl;
	cout << "Which path do you chose?" << endl;
	cout << "Right			or			left?" << endl;
}
void choice_make() {
	cin >> input;
	if (input == r) {
		cout << "You have chosen the right path." << endl;
	}
	if (input == l) {
		cout << "You have chosen the left path." << endl;
	}
	if (input != r && input != l) {
		cout << "Please affirm your choice by typing left or right" << endl;
	}
}
void You_at_Forest() {
	cout << "You arrive at a forest" << endl;
	cout << "You are surrounded by trees and green shrubbery" << endl;
}
void You_at_Swamp() {
	cout << "You arrive at a swamp" << endl;
	cout << "You are surrounded by flies and swamp wildlife" << endl;
}
void You_at_Meadow() {
	cout << "You arrive at a meadow" << endl;
	cout << "You are surrounded by green grass and beautiful flowers" << endl;
}
void You_at_River() {
	cout << "You arrive at a river" << endl;
	cout << "You are surrounded by rushing water and aquatic wildlife" << endl;
}
void You_at_Mountain() {
	cout << "You arrive at a mountain" << endl;
	cout << "You are surrounded by large rocks and mountain wildlife" << endl;
}
void You_at_Graveyard() {
	cout << "You arrive at a graveyard" << endl;
	cout << "You are surrounded by dozens of old tombstones" << endl;
}
void You_at_Castle() {
	cout << "You arrive at a castle" << endl;
	cout << "You are surrounded by mideavil architecture" << endl;
}
void You_at_Catacombs() {
	cout << "You arrive at the catacombs" << endl;
	cout << "You are surrounded by thousands of old corridors" << endl;
}
void You_at_Ruins() {
	cout << "You arrive at the ruins" << endl;
	cout << "You are surrounded by ancient stone structures" << endl;
}
void You_at_Desert() {
	cout << "You arrive at a desert" << endl;
	cout << "You are surrounded by miles of endless sand" << endl;
}
void continue_walking_this_path() {
	cout << "You continue on walking this path." << endl;
	Random_Number_Refresh5_For_R();
	if (RandIndex == 0)
		You_at_Swamp();
	if (RandIndex == 1)
		You_at_Forest();
	if (RandIndex == 2)
		You_at_Meadow();
	if (RandIndex == 3)
		You_at_River();
	if (RandIndex == 4)
		You_at_Mountain();
}
void continue_walking_this_path2() {
	cout << "You continue on walking this path." << endl;
	Random_Number_Refresh5_For_RR();
	if (RRandIndex == 0)
		You_at_Graveyard();
	if (RRandIndex == 1)
		You_at_Castle();
	if (RRandIndex == 2)
		You_at_Catacombs();
	if (RRandIndex == 3)
		You_at_Ruins();
	if (RRandIndex == 4)
		You_at_Desert();
}
void Encountered_Mountain_Orc() {
	cout << "You came across a Mountain Orc" << endl;
	cout << "The orc walks thunderously toward you" << endl;
}
void Encountered_Forest_Goblin() {
	cout << "You came across a Forest Goblin" << endl;
	cout << "The goblin stares soulessly at you" << endl;
}
void Encountered_Swamp_Ogre() {
	cout << "You came across a Swamp Ogre" << endl;
	cout << "The ogre looks threateningly and menacingly towards you" << endl;
}
void Encountered_River_Monster() {
	cout << "You came across a River Monster" << endl;
	cout << "The river monster begins to sliver towards you" << endl;
}
void Encountered_Meadow_Gremlin() {
	cout << "You came across a Meadow Gremlin" << endl;
	cout << "The gremlin begins to crawl slowly toward you" << endl;
}
void Encountered_Graveyard_Zombie() {
	cout << "You came across a Graveyard Zombie" << endl;
	cout << "The zombie looks hungrily towards you" << endl;
}
void Encountered_Castle_Evil_Guard() {
	cout << "You came across a Castle Evil Guard" << endl;
	cout << "The evil guard walks towards you with an evil look" << endl;
}
void Encountered_Catacomb_Mummy() {
	cout << "You came across a Catacomb Mummy" << endl;
	cout << "The mummy walks towards you with a hateful vengence" << endl;
}
void Encountered_Ruins_Stone_Mage() {
	cout << "You came across a Ruins Stone Mage" << endl;
	cout << "The stone mage walks toward you with a lust for power" << endl;
}
void Encountered_Desert_Sand_Monster() {
	cout << "You came across a Desert Sand Monster" << endl;
	cout << "The sand monster approaches you with unafraid purpose" << endl;
}
void Encounter_Monster() {
	if (RandIndex == 0 && RRRandIndex == 0 && input == r) {
		Encountered_Swamp_Ogre();
		encounter = 1;
		enemy_has_appeared = 1;
	}
	if (RandIndex == 1 && RRRandIndex == 0 && input == r) {
		Encountered_Forest_Goblin();
		encounter = 2;
		enemy_has_appeared = 1;
	}
	if (RandIndex == 2 && RRRandIndex == 0 && input == r) {
		Encountered_Meadow_Gremlin();
		encounter = 3;
		enemy_has_appeared = 1;
	}
	if (RandIndex == 3 && RRRandIndex == 0 && input == r) {
		Encountered_River_Monster();
		encounter = 4;
		enemy_has_appeared = 1;
	}
	if (RandIndex == 4 && RRRandIndex == 0 && input == r) {
		Encountered_Mountain_Orc();
		encounter = 5;
		enemy_has_appeared = 1;
	}
	if (RRandIndex == 0 && RRRRandIndex == 0 && input == l) {
		Encountered_Graveyard_Zombie();
		encounter = 6;
		enemy_has_appeared = 1;
	}
	if (RRandIndex == 1 && RRRRandIndex == 0 && input == l) {
		Encountered_Castle_Evil_Guard();
		encounter = 7;
		enemy_has_appeared = 1;
	}
	if (RRandIndex == 2 && RRRRandIndex == 0 && input == l) {
		Encountered_Catacomb_Mummy();
		encounter = 8;
		enemy_has_appeared = 1;
	}
	if (RRandIndex == 3 && RRRRandIndex == 0 && input == l) {
		Encountered_Ruins_Stone_Mage();
		encounter = 9;
		enemy_has_appeared = 1;
	}
	if (RRandIndex == 4 && RRRRandIndex == 0 && input == l) {
		Encountered_Desert_Sand_Monster();
		encounter = 10;
		enemy_has_appeared = 1;
	}
	if (RRRandIndex == 1 && input == r) {
		cout << "You encountered nothing." << endl;
		enemy_has_appeared = 0;
	}
	if (RRRRandIndex == 1 && input == l) {
		cout << "You encountered nothing." << endl;
		enemy_has_appeared = 0;
	}
}
int potion_gone = 0;
void Attack_Prompt() {
	if (enemy_has_appeared == 1 && swamp_ogre == 10 && graveyard_zombie == 10 && forest_goblin == 20 && castle_evil_guard == 20 && meadow_gremlin == 30 && catacomb_mummy == 30 && river_monster == 40 && ruins_stone_mage == 40 && mountain_orc == 50 && desert_sand_monster == 50) {
		do {
			if (health_potions_left > 0) {
				cout << "Attack, heal, or flee" << endl;
				cin >> choice;
			}
			if (health_potions_left == 0) {
				cout << "Attack or flee" << endl;
				cin >> choice;
			}
			if (choice == heal && choice != at && choice != flee && health_potions_left > 0) {
				cout << "You used your health potion" << endl;
				character += health_potion;
				if (character > 70 && level == 1) {
					character = 70;
				}
				if (character > 80 && level == 2) {
					character = 80;
				}
				if (character > 90 && level == 3) {
					character = 90;
				}
				health_potions_left -= 1;
			}
			if (choice == heal && choice != at && choice != flee && health_potions_left == 0) {
				cout << "You don't have any health potions left" << endl;
				potion_gone = 1;
			}
			after_attack_prompt = 1;
		} while (choice != flee && choice != at);
	}
	if (enemy_has_appeared == 1 && swamp_ogre < 10 || graveyard_zombie < 10 || forest_goblin < 20 || castle_evil_guard < 20 || meadow_gremlin < 30 || catacomb_mummy < 30 || river_monster < 40 || ruins_stone_mage < 40 || mountain_orc < 50 || desert_sand_monster < 50) {
		do {
			if (health_potions_left > 0) {
				cout << "Attack or heal" << endl;
				cin >> choice;
			}
			if (health_potions_left == 0 && swamp_ogre > 0 && graveyard_zombie > 0 && forest_goblin > 0 && castle_evil_guard > 0 && meadow_gremlin > 0 && catacomb_mummy > 0 && river_monster > 0 && ruins_stone_mage > 0 && mountain_orc > 0 && desert_sand_monster > 0) {
				cout << "Attack or die" << endl;
				cin >> choice;
			}
			if (choice == heal && choice != at && choice != flee && health_potions_left > 0) {
				cout << "You used your health potion" << endl;
				character += health_potion;
				if (character > 70 && level == 1) {
					character = 70;
				}
				if (character > 80 && level == 2) {
					character = 80;
				}
				if (character > 90 && level == 3) {
					character = 90;
				}
				health_potions_left -= 1;
			}
			if (choice == heal && choice != at && choice != flee && health_potions_left == 0) {
				cout << "You don't have any health potions" << endl;
			}
			after_attack_prompt = 1;
		} while (choice != flee && choice != at);
	}
}
void Level_Up_Exp() {
	if (swamp_ogre <= 0) {
		experience_points += 10;
	}
	if (graveyard_zombie <= 0) {
		experience_points += 10;
	}
	if (forest_goblin <= 0) {
		experience_points += 20;
	}
	if (castle_evil_guard <= 0) {
		experience_points += 20;
	}
	if (meadow_gremlin <= 0) {
		experience_points += 30;
	}
	if (catacomb_mummy <= 0) {
		experience_points += 30;
	}
	if (river_monster <= 0) {
		experience_points += 40;
	}
	if (ruins_stone_mage <= 0) {
		experience_points += 40;
	}
	if (mountain_orc <= 0) {
		experience_points += 50;
	}
	if (desert_sand_monster <= 0) {
		experience_points += 50;
	}
	if (experience_points >= 50 && level_up == 0) {
		level = 2;
		character = 80;
		level_up = 1;
	}
	if (experience_points >= 100 && level_up == 1) {
		level = 3;
		character = 90;
		level_up = 2;
	}
}
void test() {
	cout << "level = " << level << "		" << "exp = " << experience_points << endl;
}
void DoChoice() {
	do {
		choice_make();
		if (input == r)
			continue_walking_this_path();
		if (input == l)
			continue_walking_this_path2();
	} while (input != r && input != l);
}
void Attack_Or_Flee();
int main() {
	srand(static_cast<unsigned int>(time(0)));
	WELCOME_TO_GAME();
	Begin();
	DoChoice();
	Random_Number_Refresh2_For_RRR_And_RRRR();
	Encounter_Monster();
	// Whenever any enemy appears on the left, RRRRandIndex is zero and input is l
	// Whenever any enemy appears on the right, RRRandIndex is zero and input is r
	// swamp ogre occurs when pRandIndex is 0
	// forest goblin occurs when pRandIndex is 1
	// meadow gremlin occurs when pRandIndex is 2
	// river monster occurs when pRandIndex is 3
	// mountain Orc occurs when pRandIndex is 4
	// Graveyard Zombie occurs when pRRandIndex is 0
	// Castle Evil Guard occurs when pRRandIndex is 1
	// Catacomb Mummy occurs when pRRandIndex is 2
	// Ruins Stone Mage occurs when pRRandIndex is 3
	// Desert sand monster occurs when pRRandIndex is 4
	Attack_Prompt();
	Attack_Or_Flee();
	Level_Up_Exp();
	test();
	do {
		Begin_Again();
		Refresh_Enemies();
		// Do while loop
		DoChoice();
		// End of Do while loop
		Random_Number_Refresh2_For_RRR_And_RRRR();
		Encounter_Monster();
		// Whenever any enemy appears on the left, RRRRandIndex is zero and input is l
		// Whenever any enemy appears on the right, RRRandIndex is zero and input is r
		// swamp ogre occurs when pRandIndex is 0
		// forest goblin occurs when pRandIndex is 1
		// meadow gremlin occurs when pRandIndex is 2
		// river monster occurs when pRandIndex is 3
		// mountain Orc occurs when pRandIndex is 4
		// Graveyard Zombie occurs when pRRandIndex is 0
		// Castle Evil Guard occurs when pRRandIndex is 1
		// Catacomb Mummy occurs when pRRandIndex is 2
		// Ruins Stone Mage occurs when pRRandIndex is 3
		// Desert sand monster occurs when pRRandIndex is 4
		Attack_Prompt();
		Attack_Or_Flee();
		Level_Up_Exp();
		test();
	} while (character > 0);
	system("PAUSE");
	return 0;
}
vector<int>::const_iterator iter;
vector<int>::const_iterator iter2;
vector<int>enemy_damage;
vector<int>attack_damage;
void Attack_Or_Flee() {
	if (level == 1) {
		enemy_damage.push_back(1);
		enemy_damage.push_back(2);
		enemy_damage.push_back(3);
		enemy_damage.push_back(4);
		enemy_damage.push_back(5);
		attack_damage.push_back(1);
		attack_damage.push_back(2);
		attack_damage.push_back(3);
		attack_damage.push_back(4);
		attack_damage.push_back(5);
		random_shuffle(enemy_damage.begin(), enemy_damage.end());
		random_shuffle(attack_damage.begin(), attack_damage.end());
	}
	if (level == 2) {
		enemy_damage.clear();
		attack_damage.clear();
		enemy_damage.push_back(1);
		enemy_damage.push_back(2);
		enemy_damage.push_back(3);
		enemy_damage.push_back(4);
		attack_damage.push_back(2);
		attack_damage.push_back(3);
		attack_damage.push_back(4);
		attack_damage.push_back(5);
		attack_damage.push_back(6);
		random_shuffle(enemy_damage.begin(), enemy_damage.end());
		random_shuffle(attack_damage.begin(), attack_damage.end());
	}
	if (level == 3) {
		enemy_damage.clear();
		attack_damage.clear();
		enemy_damage.push_back(1);
		enemy_damage.push_back(2);
		enemy_damage.push_back(3);
		attack_damage.push_back(3);
		attack_damage.push_back(4);
		attack_damage.push_back(5);
		attack_damage.push_back(6);
		attack_damage.push_back(7);
		random_shuffle(enemy_damage.begin(), enemy_damage.end());
		random_shuffle(attack_damage.begin(), attack_damage.end());
	}
	if (health_potions_left <= 0) {
		cout << "You have no health potions left" << endl;
	}
	if (encounter == 1 && enemy_has_appeared == 1 && choice == at && input == r) {
		random_shuffle(enemy_damage.begin(), enemy_damage.end());
		random_shuffle(attack_damage.begin(), attack_damage.end());
		swamp_ogre -= attack_damage[0];
		cout << "You did " << attack_damage[0] << " damage to the swamp ogre. He now has " << swamp_ogre << " health left" << endl;
		character -= enemy_damage[0];
		cout << "You took " << enemy_damage[0] << " damage from the swamp ogre. You now have " << character << " health left" << endl;
		random_shuffle(enemy_damage.begin(), enemy_damage.end());
		random_shuffle(attack_damage.begin(), attack_damage.end());
		do {
			random_shuffle(enemy_damage.begin(), enemy_damage.end());
			random_shuffle(attack_damage.begin(), attack_damage.end());
			Attack_Prompt();
			if (encounter == 1 && enemy_has_appeared == 1 && choice == at && input == r) {
				swamp_ogre -= attack_damage[0];
				cout << "You did " << attack_damage[0] << " damage to the swamp ogre. He now has " << swamp_ogre << " health left" << endl;
				character -= enemy_damage[0];
				cout << "You took " << enemy_damage[0] << " damage from the swamp ogre. You now have " << character << " health left" << endl;
			}
		} while (swamp_ogre > 0 && character > 0);
	}
	if (encounter == 2 && enemy_has_appeared == 1 && choice == at) {
		random_shuffle(enemy_damage.begin(), enemy_damage.end());
		random_shuffle(attack_damage.begin(), attack_damage.end());
		forest_goblin -= attack_damage[0];
		cout << "You did " << attack_damage[0] << " damage to the forest goblin. He now has " << forest_goblin << " health left" << endl;
		character -= enemy_damage[0];
		cout << "You took " << enemy_damage[0] << " damage from the forest goblin. You now have " << character << " health left" << endl;
		do {
			random_shuffle(enemy_damage.begin(), enemy_damage.end());
			random_shuffle(attack_damage.begin(), attack_damage.end());
			Attack_Prompt();
			if (encounter == 2 && enemy_has_appeared == 1 && choice == at && input == r) {
				forest_goblin -= attack_damage[0];
				cout << "You did " << attack_damage[0] << " damage to the forest goblin. He now has " << forest_goblin << " health left" << endl;
				character -= enemy_damage[0];
				cout << "You took " << enemy_damage[0] << " damage from the forest goblin. You now have " << character << " health left" << endl;
			}
		} while (forest_goblin > 0 && character > 0);
	}
	if (encounter == 3 && enemy_has_appeared == 1 && choice == at && input == r) {
		random_shuffle(enemy_damage.begin(), enemy_damage.end());
		random_shuffle(attack_damage.begin(), attack_damage.end());
		meadow_gremlin -= attack_damage[0];
		cout << "You did " << attack_damage[0] << " damage to the meadow gremlin. He now has " << meadow_gremlin << " health left" << endl;
		character -= enemy_damage[0];
		cout << "You took " << enemy_damage[0] << " damage from the meadow gremlin. You now have " << character << " health left" << endl;
		do {
			random_shuffle(enemy_damage.begin(), enemy_damage.end());
			random_shuffle(attack_damage.begin(), attack_damage.end());
			Attack_Prompt();
			if (encounter == 3 && enemy_has_appeared == 1 && choice == at && input == r) {
				meadow_gremlin -= attack_damage[0];
				cout << "You did " << attack_damage[0] << " damage to the meadow gremlin. He now has " << meadow_gremlin << " health left" << endl;
				character -= enemy_damage[0];
				cout << "You took " << enemy_damage[0] << " damage from the meadow gremlin. You now have " << character << " health left" << endl;
			}
		} while (meadow_gremlin > 0 && character > 0);
	}
	if (encounter == 4 && enemy_has_appeared == 1 && choice == at && input == r) {
		random_shuffle(enemy_damage.begin(), enemy_damage.end());
		random_shuffle(attack_damage.begin(), attack_damage.end());
		river_monster -= attack_damage[0];
		cout << "You did " << attack_damage[0] << " damage to the river monster. He now has " << river_monster << " health left" << endl;
		character -= enemy_damage[0];
		cout << "You took " << enemy_damage[0] << " damage from the river monster. You now have " << character << " health left" << endl;
		do {
			random_shuffle(enemy_damage.begin(), enemy_damage.end());
			random_shuffle(attack_damage.begin(), attack_damage.end());
			Attack_Prompt();
			if (encounter == 4 && enemy_has_appeared == 1 && choice == at && input == r) {
				river_monster -= attack_damage[0];
				cout << "You did " << attack_damage[0] << " damage to the river monster. He now has " << river_monster << " health left" << endl;
				character -= enemy_damage[0];
				cout << "You took " << enemy_damage[0] << " damage from the river monster. You now have " << character << " health left" << endl;
			}
		} while (river_monster > 0 && character > 0);
	}
	if (encounter == 5 && enemy_has_appeared == 1 && choice == at) {
		random_shuffle(enemy_damage.begin(), enemy_damage.end());
		random_shuffle(attack_damage.begin(), attack_damage.end());
		mountain_orc -= attack_damage[0];
		cout << "You did " << attack_damage[0] << " damage to the mountain orc. He now has " << mountain_orc << " health left" << endl;
		character -= enemy_damage[0];
		cout << "You took " << enemy_damage[0] << " damage from the mountain orc. You now have " << character << " health left" << endl;
		do {
			random_shuffle(enemy_damage.begin(), enemy_damage.end());
			random_shuffle(attack_damage.begin(), attack_damage.end());
			Attack_Prompt();
			if (encounter == 5 && enemy_has_appeared == 1 && choice == at && input == r) {
				mountain_orc -= attack_damage[0];
				cout << "You did " << attack_damage[0] << " damage to the mountain orc. He now has " << mountain_orc << " health left" << endl;
				character -= enemy_damage[0];
				cout << "You took " << enemy_damage[0] << " damage from the mountain orc. You now have " << character << " health left" << endl;
			}
		} while (mountain_orc > 0 && character > 0);
	}
	if (encounter == 6 && enemy_has_appeared == 1 && choice == at) {
		random_shuffle(enemy_damage.begin(), enemy_damage.end());
		random_shuffle(attack_damage.begin(), attack_damage.end());
		graveyard_zombie -= attack_damage[0];
		cout << "You did " << attack_damage[0] << " damage to the graveyard zombie. He now has " << graveyard_zombie << " health left" << endl;
		character -= enemy_damage[0];
		cout << "You took " << enemy_damage[0] << " damage from the graveyard zombie. You now have " << character << " health left" << endl;
		do {
			random_shuffle(enemy_damage.begin(), enemy_damage.end());
			random_shuffle(attack_damage.begin(), attack_damage.end());
			Attack_Prompt();
			if (encounter == 6 && enemy_has_appeared == 1 && choice == at && input == l) {
				graveyard_zombie -= attack_damage[0];
				cout << "You did " << attack_damage[0] << " damage to the graveyard zombie. He now has " << graveyard_zombie << " health left" << endl;
				character -= enemy_damage[0];
				cout << "You took " << enemy_damage[0] << " damage from the graveyard zombie. You now have " << character << " health left" << endl;
			}
		} while (graveyard_zombie > 0 && character > 0);
	}
	if (encounter == 7 && enemy_has_appeared == 1 && choice == at && input == l) {
		random_shuffle(enemy_damage.begin(), enemy_damage.end());
		random_shuffle(attack_damage.begin(), attack_damage.end());
		castle_evil_guard -= attack_damage[0];
		cout << "You did " << attack_damage[0] << " damage to the evil guard. He now has " << castle_evil_guard << " health left" << endl;
		character -= enemy_damage[0];
		cout << "You took " << enemy_damage[0] << " damage from the evil guard. You now have " << character << " health left" << endl;
		do {
			random_shuffle(enemy_damage.begin(), enemy_damage.end());
			random_shuffle(attack_damage.begin(), attack_damage.end());
			Attack_Prompt();
			if (encounter == 7 && enemy_has_appeared == 1 && choice == at && input == l) {
				castle_evil_guard -= attack_damage[0];
				cout << "You did " << attack_damage[0] << " damage to the evil guard. He now has " << castle_evil_guard << " health left" << endl;
				character -= enemy_damage[0];
				cout << "You took " << enemy_damage[0] << " damage from the evil guard. You now have " << character << " health left" << endl;
			}
		} while (castle_evil_guard > 0 && character > 0);
	}
	if (encounter == 8 && enemy_has_appeared == 1 && choice == at && input == l) {
		random_shuffle(enemy_damage.begin(), enemy_damage.end());
		random_shuffle(attack_damage.begin(), attack_damage.end());
		catacomb_mummy -= attack_damage[0];
		cout << "You did " << attack_damage[0] << " damage to the catacomb mummy. He now has " << catacomb_mummy << " health left" << endl;
		character -= enemy_damage[0];
		cout << "You took " << enemy_damage[0] << " damage from the catacomb mummy. You now have " << character << " health left" << endl;
		do {
			random_shuffle(enemy_damage.begin(), enemy_damage.end());
			random_shuffle(attack_damage.begin(), attack_damage.end());
			Attack_Prompt();
			if (encounter == 8 && enemy_has_appeared == 1 && choice == at && input == l) {
				catacomb_mummy -= attack_damage[0];
				cout << "You did " << attack_damage[0] << " damage to the catacomb mummy. He now has " << catacomb_mummy << " health left" << endl;
				character -= enemy_damage[0];
				cout << "You took " << enemy_damage[0] << " damage from the catacomb mummy. You now have " << character << " health left" << endl;
			}
		} while (catacomb_mummy > 0 && character > 0);
	}
	if (encounter == 9 && enemy_has_appeared == 1 && choice == at && input == l) {
		random_shuffle(enemy_damage.begin(), enemy_damage.end());
		random_shuffle(attack_damage.begin(), attack_damage.end());
		ruins_stone_mage -= attack_damage[0];
		cout << "You did " << attack_damage[0] << " damage to the stone mage. He now has " << ruins_stone_mage << " health left" << endl;
		character -= enemy_damage[0];
		cout << "You took " << enemy_damage[0] << " damage from the stone mage. You now have " << character << " health left" << endl;

		do {
			random_shuffle(enemy_damage.begin(), enemy_damage.end());
			random_shuffle(attack_damage.begin(), attack_damage.end());
			Attack_Prompt();
			if (encounter == 9 && enemy_has_appeared == 1 && choice == at && input == l) {
				ruins_stone_mage -= attack_damage[0];
				cout << "You did " << attack_damage[0] << " damage to the stone mage. He now has " << ruins_stone_mage << " health left" << endl;
				character -= enemy_damage[0];
				cout << "You took " << enemy_damage[0] << " damage from the stone mage. You now have " << character << " health left" << endl;
			}
		} while (ruins_stone_mage > 0 && character > 0);
	}
	if (encounter == 10 && enemy_has_appeared == 1 && choice == at && input == l) {
		random_shuffle(enemy_damage.begin(), enemy_damage.end());
		random_shuffle(attack_damage.begin(), attack_damage.end());
		desert_sand_monster -= attack_damage[0];
		cout << "You did " << attack_damage[0] << " damage to the sand monster. He now has " << desert_sand_monster << " health left" << endl;
		character -= enemy_damage[0];
		cout << "You took " << enemy_damage[0] << " damage from the sand monster. You now have " << character << " health left" << endl;

		do {
			random_shuffle(enemy_damage.begin(), enemy_damage.end());
			random_shuffle(attack_damage.begin(), attack_damage.end());
			Attack_Prompt();
			if (encounter == 10 && enemy_has_appeared == 1 && choice == at && input == l) {
				desert_sand_monster -= attack_damage[0];
				cout << "You did " << attack_damage[0] << " damage to the sand monster. He now has " << desert_sand_monster << " health left" << endl;
				character -= enemy_damage[0];
				cout << "You took " << enemy_damage[0] << " damage from the sand monster. You now have " << character << " health left" << endl;
			}
		} while (desert_sand_monster && character > 0);
	}
	if (choice == flee && after_attack_prompt == 1 && enemy_has_appeared == 1) {
		cout << "You fleed from the monster" << endl;
	}
}


