/*
	
	Fantasy Combat Game
	Created by Braeden Kuether
	Monday, August 6 2018

*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

using namespace std;

class Character {
	protected:
		int attack;
		int defense;
		int armor;
		int strength;
		int attack_number;
		int defense_number;
		int life;
	public:
		virtual int get_armor();
		virtual int get_strength();
		virtual void set_strength(int);
		virtual int attack_roll();
		virtual int defense_roll();
		virtual void set_defense(int);
		virtual bool charm();
		virtual void mob();
		virtual bool glare(int);
};

#endif