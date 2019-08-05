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
#include "Harry_Potter.hpp"

using namespace std;

Harry_Potter::Harry_Potter() {
	attack = 26;
	defense = 26;
	armor = 0;
	strength = 10;
	life = 1;
}

//Hogwarts function, resets strength to 20, only while still on the first life.
void Harry_Potter::hogwarts(){
	if (life == 1 && strength < 1){
		cout << "Harry Potter's strength dropped below 1. He used Hogwarts, which restored his strength to 20." << endl;
		life++;
		strength = 20;
	}
 }

int Harry_Potter::attack_roll() {
	int temp = rand() % 6 + 1;
	int temp2 = rand() % 6 + 1;
	return (temp + temp2);
}

int Harry_Potter::defense_roll() {
	int temp = rand() % 6 + 1;
	int temp2 = rand() % 6 + 1;
	return temp + temp2;
}