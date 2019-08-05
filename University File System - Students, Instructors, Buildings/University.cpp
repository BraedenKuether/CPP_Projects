#include <iostream>
#include "University.hpp"
#include "Building.hpp"
#include "Person.hpp"
#include "Student.hpp"
#include "Instructor.hpp"
#include <string>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

University::University() {
	name = "Oregon State University";
	load_people();
	Building A;
	A.set_name("Buxton Hall");
	A.set_size(10000);
	A.set_address("310 SW Weatherford Pl, Corvallis, OR 97331");
	buildings.push_back(A);
	Building B;
	B.set_name("Hawley Hall");
	B.set_size(10000);
	B.set_address("311 SW Sackett Pl, Corvallis, OR 97331");
	buildings.push_back(B);
}

void University::print_buildings() {
	for (int i = 0; i < buildings.size(); i++) {
		cout << "Name: " << buildings[i].get_name() << " Size: " << buildings[i].get_size() << " Address: " << buildings[i].get_address() << endl;  
	}
}

void University::print_people() {
	for (int i = 0; i < people.size(); i++) {
		if (people[i]->get_person_type() == "Student") {
			cout << "Student Number: " <<  i << " Name: " << people[i]->get_name() << " Age: " << people[i]->get_age() << " GPA: " << people[i]->get_GPA() << endl;  
		}
		else {
			cout << "Instructor Number: " << i << " Name: " << people[i]->get_name() << " Age: " << people[i]->get_age() << " Rating: " << people[i]->get_rating() << endl;
		}
	}
}

string University::get_name(){
	return name;
}

void University::add_person(){
	string input;
	string name_input;
	int input_1;
	do {
		cout << "Enter 1 to add a student. Enter 2 to add an instructor." << endl;
		getline(cin, input);
	} while (!input_validation(input));
	input_1 = get_int(input);
	if (input_1 == 1) {
		Person* person = new Student;
		cout << "Enter the student's name: ";
		getline(cin,name_input);
		person->set_name(name_input);
		cout << endl << "Enter the student's age: ";
		getline(cin,name_input);
		person->set_age(get_int(name_input));
		cout << endl << "Enter the student's GPA: ";
		getline(cin,name_input);
		person->set_GPA(atof(name_input.c_str()));
		ofstream people_writer("file.txt");
		ifstream people_reader("people.txt");
		string line;
		while (getline(people_reader, line))
			{
				people_writer << line << endl;
			}
		people_writer << "Student" << " " << person->get_name()  << " " << person->get_age() << " " << person->get_GPA() << endl;
		people_writer.close();
		people_reader.close();
		people.push_back(person);
		remove("people.txt");
		rename("file.txt", "people.txt");
	}
	else if (input_1 == 2) {
		Person* person = new Instructor;
		cout << "Enter the Instructor's name: ";
		getline(cin,name_input);
		person->set_name(name_input);
		cout << endl << "Enter the Instructor's age: ";
		getline(cin,name_input);
		person->set_age(get_int(name_input));
		cout << endl << "Enter the Instructor's rating: ";
		getline(cin,name_input);
		cout << "rating input " << name_input << endl;
		cout << "A2F " << atof(name_input.c_str()) << endl;
		person->set_rating(atof(name_input.c_str()));
		cout << "Get " << person->get_rating() << endl;
		ofstream people_writer("file.txt");
		ifstream people_reader("people.txt");
		string line;
		while (getline(people_reader, line))
			{
				people_writer << line << endl;
			}
		people_writer << "Instructor" << " " << person->get_name()  << " " << person->get_age() << " " << person->get_rating() << endl;
		people_writer.close();
		people_reader.close();
		people.push_back(person);
		remove("people.txt");
		rename("file.txt", "people.txt");
	}
}

void University::load_people() {
	ifstream people_reader("people.txt");
	string line;
	while(people_reader.eof() == false){
		string temp_name, temp_type;
		int temp_age;
		double temp_gpa, temp_rating;
		people_reader >> temp_type;
		if(temp_type == "Student") {
			people_reader >> temp_name >> temp_age >> temp_gpa;
			Person* p = new Student;
			p->set_name(temp_name);
			p->set_age(temp_age);
			p->set_GPA(temp_gpa);
			people.push_back(p);
		} 
		else {
			people_reader >> temp_name >> temp_age >> temp_rating;
			Person* p = new Instructor;
			p->set_name(temp_name);
			p->set_age(temp_age);
			p->set_rating(temp_rating);
			people.push_back(p);
		}
	}
	people_reader.close();
}

void University::menu() {
	string input;
	int input_1;
	do {
		do {
			cout << "Enter 1 to print the building information." << endl << "Enter 2 to print the people information." << endl;
			cout << "Enter 3 to choose a person to do work." << endl << "Enter 4 add a person to the system." << endl << "Enter 5 to exit." << endl;
			getline(cin,input);
		} while (!menu_input_validation(input));
		input_1 = get_int(input);
		if (input_1 == 1) {
			print_buildings();
		} else if (input_1 == 2) {
			print_people();
		} else if (input_1 == 3) {
			print_people();
			do_work_menu();
		} else if (input_1 == 4) {
			add_person();
		} else {
			return;
		}
	} while (input_1 != 5);
}

void University::do_work_menu() {
	string input;
	int person_number;
	do {
		cout << "Enter the number of the person you would like to do work." << endl;
		getline(cin,input);
	} while (!do_work_input_validation(input));
	person_number = get_int(input);
	people[person_number]->do_work();
}

bool University::input_validation(string input){
  if (input.length() == 1 && (input[0] == 50 || input[0] == 49)) {
    return true;
  } else {
    return false;
  }
}

bool University::menu_input_validation(string input){
  if (input.length() == 1 && (input[0] == 53 || input[0] == 49 || input[0] == 50 || input[0] == 51 || input[0] == 52)) {
    return true;
  } else {
    return false;
  }
}

bool University::do_work_input_validation(string input){
	for (int i = 0; i < input.length(); i++) {
		if (input[i] < 48 || input[i] > 57) {
		return false;
		}
	}
	return true;
}


int University::get_int (string input){
  int returnValue = 0;
  for (int i = 0; i < input.length(); i++) {
    returnValue += ((input[i] - '0') * (pow(10, input.length() - i - 1)));
  }
  return returnValue;
}


