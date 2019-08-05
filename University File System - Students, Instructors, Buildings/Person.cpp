#include <iostream>
#include "Person.hpp"
#include <string>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

string Person::get_name() {
	return name;
}

void Person::set_name(string input) {
	name = input;
}

int Person::get_age() {
	return age;
}

void Person::set_age(int input) {
	age = input;
}

string Person::get_person_type() {
	return person_type;
}
