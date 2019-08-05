/*
	
	Fantasy Combat Game
	Created by Braeden Kuether
	Monday, August 6 2018

*/

#ifndef BLUE_HPP_
#define BLUE_HPP_
#include "Character.hpp"

using namespace std;

class Blue_Men : public Character {
	public:
		Blue_Men();
		void mob();
		int attack_roll();
		int defense_roll();
};

#endif