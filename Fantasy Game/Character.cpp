/*
	
	Fantasy Combat Game
	Created by Braeden Kuether
	Monday, August 6 2018

*/

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "Blue_Men.hpp"
#include "Medusa.hpp"
#include "Harry_Potter.hpp"

using namespace std;

int Character::get_armor() {
	return armor;
}

int Character::get_strength() {
	return strength;
}

void Character::set_strength(int input) {
	strength = input;
}

void Character::set_defense(int input) {
	defense = input;
}

int Character::attack_roll() {

}

int Character::defense_roll() {

}

bool Character::charm() {

}

void Character::mob() {

}

bool Character::glare(int) {

}