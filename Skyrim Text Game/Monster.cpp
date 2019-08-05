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
#include "Monster.hpp"

using namespace std;

//Sets monster type and strength called in constructor.
void Monster::set_type() {
	int temp;
	temp = rand() % 10 + 1;
	if (temp == 1) {
		type = "Dragon";
		set_strength(100);
	}
	else if (temp == 2) {
		type = "Giant";
		set_strength(80);
	}
	else if (temp == 3) {
		type = "Frost Troll";
		set_strength(50);
	}
	else if (temp == 4) {
		type = "Frostbite Spider";
		set_strength(15);
	}
	else if (temp == 5) {
		type = "Falmer";
		set_strength(30);
	}
	else if (temp == 6) {
		type = "Chaurus";
		set_strength(20);
	}
	else if (temp == 7) {
		type = "Draugr";
		set_strength(35);
	}
	else if (temp == 8) {
		type = "Hired Thug";
		set_strength(40);
	}
	else if (temp == 9) {
		type = "Bandit";
		set_strength(25);
	}
	else if (temp == 10) {
		type = "Bandit Chief";
		set_strength(65);
	}
}

void Monster::set_dragon(){
	type = "Alduin";
	set_strength(115);
}

Monster::Monster() {
	space_type = "Monster";
	set_type();
	set_item();
}

int Monster::get_strength() {
	return strength;
}

void Monster::set_strength(int val) {
	strength = val;
}

string Monster::get_name() {
	return type;
}

//Sets monster item called in constructor.
void Monster::set_item() {
	int temp;
	temp = rand() % 10 + 1;
	if (temp == 1) {
		drop.type = "Daedric Armor";
		drop.strength = 30;
	}
	else if (temp == 2) {
		drop.type = "Dragonscale Armor";
		drop.strength = 27;
	}
	else if (temp == 3) {
		drop.type = "Ebony Armor";
		drop.strength = 24;
	}
	else if (temp == 4) {
		drop.type = "Orcish Armor";
		drop.strength = 21;
	}
	else if (temp == 5) {
		drop.type = "Glass Armor";
		drop.strength = 25;
	}
	else if (temp == 6) {
		drop.type = "Glass Dagger";
		drop.strength = 21;
	}
	else if (temp == 7) {
		drop.type = "Ebony Battleaxe";
		drop.strength = 24;
	}
	else if (temp == 8) {
		drop.type = "Daedric Sword";
		drop.strength = 27;
	}
	else if (temp == 9) {
		drop.type = "Ghostblade";
		drop.strength = 24;
	}
	else if (temp == 10) {
		drop.type = "Chillrend";
		drop.strength = 30;
	}
}

//Fight function.
bool Monster::fight(int player_strength) {
	cout << "The foe is: " << type << " || Strength: " << strength << endl;
	cout << "Player strength: " << player_strength << endl;
	int temp;
	int temp2;
	int temp3;
	int temp4;
	temp = rand() % player_strength + 1;
	temp2 = rand() % player_strength + 1;
	temp3 = rand() % strength + 1;
	temp4 = rand() % strength + 1;
	
	if (temp + temp2 > temp3 + temp4) {					//Based on the rand function is determines the winner and returns boolean value. 
		cout << "You defeated the enemy!" << endl;
		return true;
	}

	else {
		cout << "You were eliminated in battle!" << endl;
		return false;
	}

}

//Loot function if a monster is defeated
Item Monster::loot(vector <Item> inventory) {
	string temp; 
	cout << "The foe dropped: " << drop.type << " || Strength: " << drop.strength << endl;
	cout << "Would you like to pick it up? You have " << inventory.size() << " items in your inventory. You can have a maximum of 6 items." << endl;
	
	do {
		cout << "Enter 1 to pick it up. Enter 2 to continue." << endl;
		getline(cin,temp);
	} while (!input_validation(temp));
	
	if (temp == "1") {
		return drop;
	}

	else {
		Item temp;
		temp.strength = -1;
		return temp;
	}
}