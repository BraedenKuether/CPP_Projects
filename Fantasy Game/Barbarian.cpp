/*
	
	Fantasy Combat Game
	Created by Braeden Kuether
	Monday, August 6 2018

*/

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include "Barbarian.hpp"
#include "Character.hpp"

using namespace std;

Barbarian::Barbarian(){
	attack = 26;
	defense = 36;
	armor = 0;
	strength = 12;
}

int Barbarian::attack_roll() {
	int temp = rand() % 6 + 1;
	int temp2 = rand() % 6 + 1;
	return (temp + temp2);
}

int Barbarian::defense_roll() {
	int temp = rand() % 6 + 1;
	int temp2 = rand() % 6 + 1;
	return temp + temp2;
}