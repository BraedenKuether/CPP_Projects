/*

Skyrim Text Game
Create by Braeden Kuether
8/16/2018

*/

#ifndef CHEST_H_
#define CHEST_H_
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
#include "Space.hpp"

using namespace std;

class Chest : public Space {
	private:
		int difficulty;
		Item type;
	public:
		Chest();
		int get_difficulty();
		void set_difficulty();
		void set_item();
		bool lockpick();
		Item open_chest(vector <Item>);
};

#endif