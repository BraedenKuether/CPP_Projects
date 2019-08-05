/*

Skyrim Text Game
Create by Braeden Kuether
8/16/2018

*/

#ifndef MONSTER_H_
#define MONSTER_H_
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
#include "Space.hpp"

using namespace std;


class Monster : public Space {
	private:
		int strength;
		string type;
		Item drop;
	public:
		Monster();
		int get_strength();
		string get_name();
		void set_strength(int);
		void set_type();
		void set_item();
		bool fight(int);
		Item loot(vector <Item>);
		void set_dragon();

};

#endif