/*

Skyrim Text Game
Create by Braeden Kuether
8/16/2018

*/

#ifndef WHITE_H_
#define WHITE_H_
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
#include "Space.hpp"
#include "Item.hpp"
#include "Chest.hpp"
#include "Monster.hpp"

using namespace std;

class WhiteSpace : public Space {
	public:
		WhiteSpace();
		void board();
		void delete_board();

};

#endif