/*

Skyrim Text Game
Create by Braeden Kuether
8/16/2018

*/

#ifndef SPACE_H_
#define SPACE_H_
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
#include "PlayerStruct.hpp"

using namespace std;

class Space {
	protected:
		Space* top;
		Space* bottom;
		Space* left;
		Space* right;
	public:
		string space_type;
		Space();
		virtual ~Space();
		virtual Space* get_top();
		virtual Space* get_bottom();
		virtual Space* get_left();
		virtual Space* get_right();
		virtual void set_top(Space*);
		virtual void set_bottom(Space*);
		virtual void set_left(Space*);
		virtual void set_right(Space*);
		virtual int get_strength() {} ;
		virtual string get_name() {} ;
		virtual void set_strength(int) {} ;
		virtual void set_type() {} ;
		virtual bool fight(int) {} ;
		virtual Item loot(vector<Item>) {} ;
		virtual int get_difficulty() {} ;
		virtual void set_difficulty() {} ;
		virtual string get_item() {} ;
		virtual void set_item() {} ;
		virtual bool lockpick() {} ;
		virtual Item open_chest(vector<Item>) {} ;
		virtual Item get_type() {} ;
		virtual Item pickup(vector<Item>) {} ;
		virtual bool get_looted() {} ;
		virtual void set_dragon() {} ;
		virtual void board() {} ;
		virtual bool input_validation(string);
		virtual void delete_board() {} ;
};

#endif







