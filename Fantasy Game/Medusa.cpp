/*
	
	Fantasy Combat Game
	Created by Braeden Kuether
	Monday, August 6 2018

*/

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include "Medusa.hpp"
#include "Character.hpp"

using namespace std;

Medusa::Medusa() {
	attack = 26;
	defense = 16;
	armor = 3;
	strength = 8;
}

int Medusa::attack_roll() {
	int temp = rand() % 6 + 1;
	int temp2 = rand() % 6 + 1;
	return (temp + temp2);
}

int Medusa::defense_roll() {
	int temp = rand() % 6 + 1;
	return temp;
}

//Determines if glare kills combatent.
bool Medusa::glare(int input) {
	if (input == 12) {
		cout << "Medusa rolled a 12, and used glare! The enemy has been turned to stone, and their strength set to 0." << endl;
		return true;
	} 
	else {
		return false;
	}
}