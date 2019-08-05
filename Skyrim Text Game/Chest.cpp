/*

Skyrim Text Game
Create by Braeden Kuether
8/16/2018

*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
#include "Chest.hpp"

using namespace std;

//Item in chest created and called in constructor.
void Chest::set_item() {
	int temp;
	temp = rand() % 16 + 1;
	if (temp == 1) {
		type.type = "Daedric Armor";
		type.strength = 30;
	}
	else if (temp == 2) {
		type.type = "Dragonscale Armor";
		type.strength = 27;
	}
	else if (temp == 3) {
		type.type = "Ebony Armor";
		type.strength = 24;
	}
	else if (temp == 4) {
		type.type = "Orcish Armor";
		type.strength = 21;
	}
	else if (temp == 5) {
		type.type = "Steel Plate Armor";
		type.strength = 18;
	}
	else if (temp == 6) {
		type.type = "Dwarven Armor";
		type.strength = 15;
	}
	else if (temp == 7) {
		type.type = "Glass Armor";
		type.strength = 25;
	}
	else if (temp == 8) {
		type.type = "Dwarven Mace";
		type.strength = 15;
	}
	else if (temp == 9) {
		type.type = "Elven Bow";
		type.strength = 18;
	}
	else if (temp == 10) {
		type.type = "Glass Dagger";
		type.strength = 21;
	}
	else if (temp == 11) {
		type.type = "Ebony Battleaxe";
		type.strength = 24;
	}
	else if (temp == 12) {
		type.type = "Daedric Sword";
		type.strength = 27;
	}
	else if (temp == 13) {
		type.type = "Scroll of Ebonyflesh";
		type.strength = 6;
	}
	else if (temp == 14) {
		type.type = "Scroll of Fireball";
		type.strength = 8;
	}
	else if (temp == 15) {
		type.type = "Ghostblade";
		type.strength = 24;
	}
	else if (temp == 16) {
		type.type = "Chillrend";
		type.strength = 30;
	}
}

//Function randomely sets the difficulty of the chest to open
void Chest::set_difficulty() {
	int temp;
	temp = rand() % 7 + 1;
	if (temp == 1 || temp == 2) {
		difficulty = 1;
	} 
	else if (temp == 3 || temp == 4) {
		difficulty = 2;
	} 
	else if (temp == 5) {
		difficulty = 3;
	} 
	else if (temp == 6) {
		difficulty = 4;
	} else if (temp == 7) {
		difficulty = 5;
	}
}

//Function determines if you are "able" to pick the lock based on the difficulty. 
bool Chest::lockpick() {
	int temp;
	temp = rand() % 10 + 1;
	if (difficulty == 1 && temp > 2) {
		cout << "You successfully picked the Novice lock!" << endl;
		return true;
	}
	else if (difficulty == 2 && temp > 3) {
		cout << "You successfully picked the Apprentice lock!" << endl;
		return true;
	}
	else if (difficulty == 3 && temp > 4) {
		cout << "You successfully picked the Adept lock!" << endl;
		return true;
	}
	else if (difficulty == 4 && temp > 5) {
		cout << "You successfully picked the Expert lock!" << endl;
		return true;
	}
	else if (difficulty == 5 && temp > 7) {
		cout << "You successfully picked the Master lock!" << endl;
		return true;
	}
	else {
		cout << "You were unable to pick the lock!" << endl;
		return false;
	}
}

//If the chest is opened this alloss the player to see whats inside and decided to pick it up. 
Item Chest::open_chest(vector<Item> inventory) {
	string temp;

	if (lockpick()) {
		cout << "Item: " << type.type << " || Strength: " << type.strength << endl;
		cout << "Would you like to pick it up? You have " << inventory.size() << " items in your inventory. You can have a maximum of 6 items." << endl;
		
		do {
			cout << "Enter 1 to pick it up. Enter 2 to continue.";
			getline(cin,temp);
		} while (!input_validation(temp));
		
		if (temp == "1") {
			return type;
		} 
		
		else {
			Item temp;
			temp.strength = -1;
			return temp;
		}

	}
	
	else {
			Item temp;
			temp.strength = -1;
			return temp;
	}
}

Chest::Chest() {
	space_type = "Chest";
	set_item();
	set_difficulty();
}

int Chest::get_difficulty() {
	return difficulty;
}