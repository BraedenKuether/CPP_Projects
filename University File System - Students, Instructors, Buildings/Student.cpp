#include <iostream>
#include "Student.hpp"
#include <string>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

Student::Student(){
	person_type = "Student";
}

double Student::get_GPA() {
	return GPA;
}

void Student::set_GPA(double input) {
        GPA = input;
}

void Student::do_work() {
	int work;
	work = rand() % 91;
	cout << name << " did " << work << " hours of homework." << endl;
}

