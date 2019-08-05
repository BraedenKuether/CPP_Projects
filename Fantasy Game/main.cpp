/*
	
	Fantasy Combat Game
	Created by Braeden Kuether
	Monday, August 6 2018

*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include "Test_Driver.hpp"
#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "Blue_Men.hpp"
#include "Medusa.hpp"
#include "Harry_Potter.hpp"

using namespace std;

int main () {
	srand(time(NULL));		//Seed rand function.
	string temp;
	int input = 0;
	do {
		menu();
		do {
			cout << endl << "Enter 1 to play again. Enter 2 to quit." << endl;
			getline(cin,temp);
		} while (!play_input_validation(temp));
		input = get_int(temp);
	} while (input == 1);
	return 0; 
}


