/*
	
	Fantasy Combat Game
	Created by Braeden Kuether
	Monday, August 6 2018

*/

#ifndef MEDUSA_HPP_
#define MEDUSA_HPP_
#include "Character.hpp"

using namespace std;

class Medusa : public Character {
	public:
		Medusa();
		int attack_roll();
		int defense_roll();
		bool glare(int);
};

#endif