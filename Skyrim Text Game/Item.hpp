/*

Skyrim Text Game
Create by Braeden Kuether
8/16/2018

*/

#ifndef ITEM_H_
#define ITEM_H_
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
#include "Space.hpp"

using namespace std;


class Item_ : public Space {
	private:
		Item type;
	public:
		Item_();
		void set_type();
		Item pickup(vector <Item>);
};

#endif