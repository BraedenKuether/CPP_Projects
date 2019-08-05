#include <iostream>
#include "Instructor.hpp"
#include <string>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

Instructor::Instructor() {
	person_type = "Instructor";
}

double Instructor::get_rating() {
	return rating;
}

void Instructor::set_rating(double input) {
	rating = input;
}

void Instructor::do_work() {
	int work;
	work = rand() % 91;
	cout << name << " graded papers for " << work << " hours." << endl;
}

