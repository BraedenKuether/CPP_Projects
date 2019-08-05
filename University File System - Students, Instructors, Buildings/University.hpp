#ifndef UNIVERSITY_HPP_
#define UNIVERSITY_HPP_
#include "Person.hpp"
#include "Student.hpp"
#include "Instructor.hpp"
#include "Building.hpp"
#include <vector>

using namespace std;

class University {
	private:
		string name;
		vector <Building> buildings;
		vector <Person*> people;
	public:
		University();
		string get_name();
		void print_buildings();
		void print_people();
		void add_person();
		void load_people();
		bool input_validation(string);
		int get_int (string);
		void do_work_menu();
		void menu();
		bool do_work_input_validation(string);
		bool menu_input_validation(string);
};

#endif
