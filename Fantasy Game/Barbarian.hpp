/*
	
	Fantasy Combat Game
	Created by Braeden Kuether
	Monday, August 6 2018

*/

#ifndef BARBARIAN_HPP_
#define BARBARIAN_HPP_
#include "Character.hpp"

using namespace std;

class Barbarian : public Character {
	public:
		Barbarian();
		int attack_roll();
		int defense_roll();
};

#endif