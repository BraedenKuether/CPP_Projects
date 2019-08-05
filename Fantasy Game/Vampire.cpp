/*
	
	Fantasy Combat Game
	Created by Braeden Kuether
	Monday, August 6 2018

*/ 

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include "Vampire.hpp"
#include "Character.hpp"

using namespace std;

Vampire::Vampire(){
	attack = 112;
	defense = 16;
	armor = 1;
	strength = 18;
}

bool Vampire::charm (){
	int random;
	random = rand() % 2;
	if (random == 1) {
		cout << "The Vampire used charm! It took no damage this turn. " << endl;
		return true;
	} 
	else {
		return false;
	}
}

int Vampire::attack_roll() {
	int temp = rand() % 12 + 1;
	return (temp);
}

int Vampire::defense_roll() {
	int temp = rand() % 6 + 1;
	return temp;
}