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
#include "Space.hpp"

using namespace std;


Space::Space() {
	top = NULL;
	bottom = NULL;
	left = NULL;
	right = NULL;
}

Space::~Space(){
	if (top != NULL) {
		delete top;
		top = NULL;
	}
	if (bottom != NULL) {
		delete bottom;
		bottom = NULL;
	}
	if (left != NULL) {
		delete left;
		left = NULL;
	}
	if (right != NULL) {
		delete right;
		right = NULL;
	}
}

Space* Space::get_top() {
	return top;
}

Space* Space::get_bottom() {
	return bottom;
}

Space* Space::get_left(){
	return left;
}

Space* Space::get_right() {
	return right;
}

void Space::set_top(Space* space) {
	top = space;
}

void Space::set_bottom(Space* space) {
	bottom = space;
}

void Space::set_left(Space* space) {
	left = space;
}

void Space::set_right(Space* space) {
	right = space;
}

bool Space::input_validation(string input) {
	if (input.length() == 1 && (input[0] == 49 || input[0] == 50)) {
		return true;
	} 
	else {
		return false;
	}
}


