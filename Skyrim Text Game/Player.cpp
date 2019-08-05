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
#include "Player.hpp"

using namespace std;

Player::Player() {
	steps = 0;
	strength = 45;
}

Player::~Player() {
	//beginning->delete_board();
}

int Player::get_strength() {
	return strength;
}

void Player::set_strength(int val) {
	strength = val;
}

//Adds items to the player's inventory
void Player::add_inventory(Item x) {
	string temp;
	int input;

	if (x.strength == -1) {		//This accounts for when player did not what to pick up the item. 
		return;
	}

	if (inventory.size() == 6) {		//Maximum inventory size.

		do {							//Dropping an item to pick one up.
			cout << "You will have to drop an item to pick one up. Enter the number of the item you would like to drop or enter 7 to continue: " << endl;
			print_inventory();
			getline(cin,temp);
		} while (!input_validation(temp));		// Input validation.
		input = atoi(temp.c_str());

		if (input == 7) {
			return;
		} 

		else {									//Adding item
			inventory.erase(inventory.begin() + input - 2);
			inventory.push_back(x);
			calculate_strength();
		}

	}

	else {
		inventory.push_back(x);
		calculate_strength();
	}

}

//Prints inventory
void Player::print_inventory() {
	for (int i = 0; i < inventory.size(); i++) {				//Runs through vector and prints each index
		cout << "Item Number " << i + 1 << ": " << inventory[i].type << " || ";
		cout << "Strength: " << inventory[i].strength << endl;
	}
	cout << endl;
}

//Calculates player strength
void Player::calculate_strength() {
	int temp = 0;
	for (int i = 0; i < inventory.size(); i++) {
		temp += inventory[i].strength;
	}
	strength = temp + 45;				//Accounts for starting strength
}

bool Player::input_validation(string input) {
	if (input.length() == 1 && (input[0] == 49 || input[0] == 50 || input[0] == 51 || input[0] == 52 || input[0] == 53 || input[0] == 54 || input[0] == 55)) {
		return true;
	} 
	else {
		return false;
	}
}

Space* Player::get_location() {
	return location;	
}

void Player::set_location(Space* x) {
	location = x;
}

void Player::move_top() {
	location = location->get_top();
}

void Player::move_bottom() {
	location = location->get_bottom();
}

void Player::move_left() {
	location = location->get_left();
}

void Player::move_right() {
	location = location->get_right();
}

//Game function
void Player::game() {
	bool top = false;
	bool bottom = false;
	bool left = false;
	bool right = false;
	string input;
	int num;
	beginning = location;

	//Beginning game statements.
	cout << endl << "Welcome to the Skyrim text based game!" << endl;
	cout << "You start on a space in the bottom left of a three (rows) by five (columns) room, with 15 available steps." << endl;
	cout << "There are three different types of spaces: Chests, Items, and Monsters." << endl;
	cout << "Items can be picked up, and Chests can be unlocked to yield an item, generally better than on an item space." << endl;
	cout << "Be careful fighting Monsters! Each one has different strengths and if you lose then the game is over! However, if you win they can drop powerful items." << endl;
	cout << "By picking up items you improve your strength, and ability to fight Monsters." << endl;
	cout << "To win the game, you must venture to the top right of the board and defeat Alduin before you run out of steps! Good luck!" << endl;

	do {								//Do while loop for maximum steps.
		calculate_strength();			//Calculate strength each turn.

		cout << endl << "*** Turn " << steps + 1 << " ***" << endl << endl;

		print_inventory();				//Print inventory each turn.

		if (location->get_top() != NULL) {				//Checks if this space exits, then prints the option to the user. 
			cout << "1) Top space: " << location->get_top()->space_type << endl;
			top = true;
		}

		if (location->get_bottom() != NULL) {
			cout << "2) Bottom space: " << location->get_bottom()->space_type << endl;
			bottom = true;
		}

		if (location->get_left() != NULL) {
			cout << "3) Left space: " << location->get_left()->space_type << endl;
			left = true;
		}

		if (location->get_right() != NULL) {
			cout << "4) Right space: " << location->get_right()->space_type << endl;
			right = true;
		}

		bool check = false;
		while (!check) {

			cout << "Enter the number of the space you would like to move to: " << endl;
			getline(cin,input);
			num = atoi(input.c_str());

			if (num == 1 && top) {				//Checks that space exists and that user entered that number. 
				check = true;					//Breaks while loop condition.
				move_top();						//Moves user. 
			}

			if (num == 2 && bottom) {
				check = true;
				move_bottom();
			}

			if (num == 3 && left) {
				check = true;
				move_left();
			}

			if (num == 4 && right) {
				check = true;
				move_right();
			}

		}

		if (location->space_type == "Chest") {					//Checks space type.
			add_inventory(location->open_chest(inventory));		//Completes action on space.
		}

		else if (location->space_type == "Item") {
			add_inventory(location->pickup(inventory));
		}

		else if (location->space_type == "Monster") {

			if (location->fight(strength)) {
				add_inventory(location->loot(inventory));

				if (location->get_name() == "Alduin") {				//Win condition check.
					cout << "You conquered Alduin and absorbed his soul! You win!" << endl;
					return;
				}
			}

			else {
				cout << "You lost" << endl;
				return;
			}
		}
		steps++;
	} while (steps < 15);
	cout << "You ran out of steps! Game Over." << endl;
}