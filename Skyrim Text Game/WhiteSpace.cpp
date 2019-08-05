/*

Skyrim Text Game
Create by Braeden Kuether
8/16/2018

*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
#include "WhiteSpace.hpp"

using namespace std;

WhiteSpace::WhiteSpace() {
	space_type = "White space";
}

//Function that creates the board.
//Used the this keyword, then setter function in different directions to link eack piece together. 
void WhiteSpace::board() {
	Space* current = this;
	Space* previous;
	Space* temp = new Chest;
	current->set_right(temp);
	previous = current;
	current = current->get_right();
	current->set_left(previous);
	Space* temp2 = new Monster;
	current->set_right(temp2);
	previous = current;
	current = current->get_right();
	current->set_left(previous);
	Space* temp3 = new Item_;
	current->set_right(temp3);
	previous = current;
	current = current->get_right();
	current->set_left(previous);
	Space* temp4 = new Monster;
	current->set_right(temp4);
	previous = current;
	current = current->get_right();
	current->set_left(previous);
	Space* temp5 = new Chest;
	current->set_top(temp5);
	previous = current;
	current = current->get_top();
	current->set_bottom(previous);
	Space* temp6 = new Item_;
	current->set_left(temp6);
	previous = current;
	current = current->get_left();
	current->set_right(previous);
	Space* temp7 = new Item_;
	current->set_left(temp7);
	previous = current;
	current = current->get_left();
	current->set_right(previous);
	Space* temp8 = new Monster;
	current->set_left(temp8);
	previous = current;
	current = current->get_left();
	current->set_right(previous);
	Space* temp9 = new Item_;
	current->set_left(temp9);
	previous = current;
	current = current->get_left();
	current->set_right(previous);
	Space* temp10 = new Chest;
	current->set_top(temp10);
	previous = current;
	current = current->get_top();
	current->set_bottom(previous);
	Space* temp11 = new Item_;
	current->set_right(temp11);
	previous = current;
	current = current->get_right();
	current->set_left(previous);
	Space* temp12 = new Monster;
	current->set_right(temp12);
	previous = current;
	current = current->get_right();
	current->set_left(previous);
	Space* temp13 = new Chest;
	current->set_right(temp13);
	previous = current;
	current = current->get_right();
	current->set_left(previous);
	Space* temp14 = new Monster;
	current->set_right(temp14);
	previous = current;
	current = current->get_right();
	current->set_dragon();
	current->set_left(previous);
	this->set_top(temp9);
	temp->set_top(temp8);
	temp2->set_top(temp7);
	temp3->set_top(temp6);
	temp4->set_top(temp5);
	temp9->set_bottom(this);
	temp8->set_bottom(temp);
	temp7->set_bottom(temp2);
	temp6->set_bottom(temp3);
	temp5->set_bottom(temp4);
	temp9->set_top(temp10);
	temp8->set_top(temp11);
	temp7->set_top(temp12);
	temp6->set_top(temp13);
	temp5->set_top(temp14);
	temp14->set_bottom(temp5);
	temp13->set_bottom(temp6);
	temp12->set_bottom(temp7);
	temp11->set_bottom(temp8);
	temp10->set_bottom(temp9);
}

void WhiteSpace::delete_board() {
	Space* current = this->get_right();
	Space* previous = this;
	for (int i = 0; i < 4; i++) {
		delete previous;
		previous = current;
		current = current->get_right();
	}
	previous = current;
	current = current->get_top();
	for (int k = 0; k < 4; k++) {
		delete previous;
		previous = current;
		current = current->get_left();
	}
	previous = current;
	current = current->get_top();
	for (int m = 0; m < 4; m++) {
		delete previous;
		previous = current;
		current = current->get_right();
	}
	delete current;
}