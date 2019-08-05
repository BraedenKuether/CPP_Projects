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
#include "Item.hpp"

using namespace std;

//Item type and strength created and called in constructor
void Item_::set_type() {
	int temp;
	temp = rand() % 40 + 1;
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
		type.type = "Elven Armor";
		type.strength = 12;
	}
	else if (temp == 8) {
		type.type = "Steel Armor";
		type.strength = 9;
	}
	else if (temp == 9) {
		type.type = "Iron Armor";
		type.strength = 6;
	}
	else if (temp == 10) {
		type.type = "Glass Armor";
		type.strength = 25;
	}
	else if (temp == 11) {
		type.type = "Iron Greatsword";
		type.strength = 6;
	}
	else if (temp == 12) {
		type.type = "Steel Warhammer";
		type.strength = 9;
	}
	else if (temp == 13) {
		type.type = "Orcish War Axe";
		type.strength = 12;
	}
	else if (temp == 14) {
		type.type = "Dwarven Mace";
		type.strength = 15;
	}
	else if (temp == 15) {
		type.type = "Elven Bow";
		type.strength = 18;
	}
	else if (temp == 16) {
		type.type = "Glass Dagger";
		type.strength = 21;
	}
	else if (temp == 17) {
		type.type = "Ebony Battleaxe";
		type.strength = 24;
	}
	else if (temp == 18) {
		type.type = "Daedric Sword";
		type.strength = 27;
	}
	else if (temp == 19) {
		type.type = "Scroll of Ebonyflesh";
		type.strength = 6;
	}
	else if (temp == 20) {
		type.type = "Scroll of Fireball";
		type.strength = 8;
	}
	else if (temp == 21) {
		type.type = "Book: The Wolf Queen";
		type.strength = 0;
	}
	else if (temp == 22) {
		type.type = "Book: The Black Arrow";
		type.strength = 0;
	}
	else if (temp == 23) {
		type.type = "Book: The Lusty Argonian Maid";
		type.strength = 0;
	}
	else if (temp == 24) {
		type.type = "Corundum Ore";
		type.strength = 0;
	}
	else if (temp == 25) {
		type.type = "Iron Ore";
		type.strength = 0;
	}
	else if (temp == 26) {
		type.type = "Quicksilver Ingot";
		type.strength = 0;
	}
	else if (temp == 27) {
		type.type = "Clothes";
		type.strength = 0;
	}
	else if (temp == 28) {
		type.type = "Fine Clothes";
		type.strength = 0;
	}
	else if (temp == 29) {
		type.type = "Cabbage";
		type.strength = 0;
	}
	else if (temp == 30) {
		type.type = "Leek";
		type.strength = 0;
	}
	else if (temp == 31) {
		type.type = "Nord Mead";
		type.strength = 3;
	}
	else if (temp == 32) {
		type.type = "Mead with Juniper";
		type.strength = 3;
	}
	else if (temp == 33) {
		type.type = "Wine";
		type.strength = 3;
	}
	else if (temp == 34) {
		type.type = "Sweet Roll";
		type.strength = 0;
	}
	else if (temp == 35) {
		type.type = "Potion of Regeneration";
		type.strength = 8;
	}
	else if (temp == 36) {
		type.type = "Potion of Vigor";
		type.strength = 8;
	}
	else if (temp == 37) {
		type.type = "Potion of Plentiful Healing";
		type.strength = 12;
	}
	else if (temp == 38) {
		type.type = "Ghostblade";
		type.strength = 24;
	}
	else if (temp == 39) {
		type.type = "Poacher's Axe";
		type.strength = 5;
	}
	else if (temp == 40) {
		type.type = "Chillrend";
		type.strength = 30;
	}
}

Item_::Item_() {
	space_type = "Item";
	set_type();
}

//Item pick up function.
Item Item_::pickup(vector <Item> inventory) {
	string temp;
	cout << "Item: " << type.type << " || Strength: " << type.strength << endl;
	
	do {
		cout << "Enter 1 to pick it up. Enter 2 to continue." << endl;
		cout << "Would you like to pick it up? You have " << inventory.size() << " items in your inventory. You can have a maximum of 6 items." << endl;
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


