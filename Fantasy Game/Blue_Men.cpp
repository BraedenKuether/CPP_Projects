/*
	
	Fantasy Combat Game
	Created by Braeden Kuether
	Monday, August 6 2018

*/

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include "Blue_Men.hpp"
#include "Character.hpp"

using namespace std;

Blue_Men::Blue_Men() {
	attack = 210;
	defense = 36;
	armor = 3;
	strength = 12;
}

void Blue_Men::mob() {
	if (strength < 9 && strength > 4) {
		set_defense(26);
	} 
	else if (strength < 5) {
		set_defense(16);
	}
}

int Blue_Men::attack_roll() {
	int temp;
	int temp2;
	temp = rand() % 10 + 1;
	temp2 = rand() % 10 + 1;
	return (temp + temp2);
}

int Blue_Men::defense_roll() {
	if (defense == 36) {
		int temp = rand() % 6 + 1;
		int temp2 = rand() % 6 + 1;
		int temp3 = rand() % 6 + 1;
		return temp + temp2 + temp3;
	} 

	else if (defense == 26) {
		int temp = rand() % 6 + 1;
		int temp2 = rand() % 6 + 1;
		return temp + temp2;
	}

	else if (defense == 16) {
		int temp = rand() % 6 + 1;
		return temp;
	}

}
