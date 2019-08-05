/*

Linked List Project
Created by Braeden Kuether
Sunday, August 5th 2018

*/

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include "QueueNode.hpp"
#include "Queue.hpp"
#include "main.hpp"

using namespace std;

int main() {
	menu();
	return 0;
}

void menu() {

	Queue Q;						//Create Queue object.

	string input;
	int input_num;
	cout << endl << "Welcome to my queue!" << endl;

	do {							//Queue menu.

		do {
			cout << "Choose from the following options: " << endl;
			cout << "1. Enter a value to be added to the back of queue." << endl;
			cout << "2. Display first node value." << endl;
			cout << "3. Remove first node value." << endl;
			cout << "4. Display the queue contents." << endl;
			cout << "5. Exit." << endl;
			getline(cin,input);
		} while (!input_validation(input));		//Input validation.

		input_num = get_int(input);

		if (input_num == 1) {
			string input2;
			int input2_num;

			do {
				cout << "Enter a value: ";
				getline(cin, input2);
			} while (!input2_validation(input2));	//Input validation.

			input2_num = get_int(input2);
			Q.addBack(input2_num);			//Add memeber to back of queue.

		} 

		else if (input_num == 2) {
			cout << Q.getFront() << endl;		//Print front of the queue.
		} 

		else if (input_num == 3) {
			Q.removeFront();			//Remove front number in queue.
		} 

		else if (input_num == 4) {
			Q.printQueue();				//Print entire queue.
		}

		cout << endl;

	} while (input_num != 5);				//Exit game.
}


//Input Validation function.
bool input_validation(string input){
	if (input.length() == 1 && (input[0] == 50 || input[0] == 49 || input[0] == 51 || input[0] == 52 || input[0] == 53)) {
		return true;
	} 
	else {
		return false;
	}
}

//Input Validation function.
bool input2_validation(string input){
	for (int i = 0; i < input.length(); i++) {
		if (input[0] == 48 || (input[i] < 48 || input[i] > 57)) {
			return false;
		} 
	}
	return true;
}

//Turns string into integer.
int get_int (string input){
 	int returnValue = 0;
 	for (int i = 0; i < input.length(); i++) {
		returnValue += ((input[i] - '0') * (pow(10, input.length() - i - 1)));
	}
	return returnValue;
}