/*

Skyrim Text Game
Create by Braeden Kuether
8/16/2018

*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
#include "PlayerStruct.hpp"
#include "Space.hpp"

using namespace std;

class Player {
	private:
		int steps;
		int strength;
		Space* location;
		vector <Item> inventory;
		Space* beginning;
	public:
		Player();
		~Player();
		Space* get_location();
		void set_location(Space*);
		int get_strength();
		void set_strength(int);
		vector <string> get_inventory();
		void add_inventory(Item);
		void print_inventory();
		void calculate_strength();
		bool input_validation(string);
		void move_top();
		void move_bottom();
		void move_left();
		void move_right();
		void game();
};

#endif
