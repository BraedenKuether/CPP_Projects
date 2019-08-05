#include <iostream>
#include "Building.hpp"
#include <string>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

string Building::get_name() {
	return name;
}

void Building::set_name(string input) {
	name = input;
}

int Building::get_size() {
	return size;
}

void Building::set_size(int input) {
	size = input;
}

string Building::get_address() {
	return address;
}

void Building::set_address(string input){
	address = input;
}
