/*
	
	Fantasy Combat Game
	Created by Braeden Kuether
	Monday, August 6 2018

*/

#ifndef VAMPIRE_HPP_
#define VAMPIRE_HPP_
#include "Character.hpp"

using namespace std;

class Vampire : public Character {
	public:
		Vampire();
		bool charm();
		int attack_roll();
		int defense_roll();
};

#endif