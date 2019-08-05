/*
	
	Fantasy Combat Game
	Created by Braeden Kuether
	Monday, August 6 2018

*/

#ifndef HARRY_HPP_
#define HARRY_HPP_
#include "Character.hpp"

using namespace std;

class Harry_Potter : public Character{
	private:
		int life;		//Specific to Harry Potter for hogwarts function.
	public:
		Harry_Potter();
		void hogwarts();
		int attack_roll();
		int defense_roll();
};

#endif