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

void menu () {
	string temp;
	int input;
	string temp2;
	int input2;

	cout << endl << "Welcome to the Fantasy Combat Game!" << endl << endl;
	do {
		cout << "Pick a fighter: " << endl;
		cout << "1. Barbarian" << endl << "2. Blue Men" << endl << "3. Vampire" << endl << "4. Medusa" << endl << "5. Harry Potter" << endl;
		getline(cin,temp);
	} while (!menu_input_validation(temp));		//Input Validation
	input = get_int(temp);
	do {
		cout << "Pick another fighter: " << endl;
		cout << "1. Barbarian" << endl << "2. Blue Men" << endl << "3. Vampire" << endl << "4. Medusa" << endl << "5. Harry Potter" << endl;
		getline(cin,temp2);
	} while (!menu_input_validation(temp2));
	input2 = get_int(temp2);
	fight(input,input2);
}


//Initiates Fights
// 1 corresponds to Barbarian, 2 corresponds to Blue Men, 3 corresponds to Vampire and so on..
void fight (int input, int input2) {
	if (input == 1 && input2 == 1) {
		one_v_one();
	}
	else if ((input == 1 && input2 == 2) || (input == 2 && input2 == 1)) {
		one_v_two();
	}
	else if ((input == 1 && input2 == 3) || (input == 3 && input2 == 1)) {
		one_v_three();
	}
	else if ((input == 1 && input2 == 4) || (input == 4 && input2 == 1)) {
		one_v_four();
	}
	else if ((input == 1 && input2 == 5) || (input == 5 && input2 == 1)) {
		one_v_five();
	}
	else if (input == 2 && input2 == 2) {
		two_v_two();
	}
	else if ((input == 2 && input2 == 3) || (input == 3 && input2 == 2)) {
		two_v_three();
	}
	else if ((input == 2 && input2 == 4) || (input == 4 && input2 == 2)) {
		two_v_four();
	}
	else if ((input == 2 && input2 == 5) || (input == 5 && input2 == 2)) {
		two_v_five();
	}
	else if (input == 3 && input2 == 3) {
		three_v_three();
	}
	else if ((input == 3 && input2 == 4) || (input == 4 && input2 == 3)) {
		three_v_four();
	}
	else if ((input == 3 && input2 == 5) || (input == 5 && input2 == 3)) {
		three_v_five();
	}
	else if (input == 4 && input2 == 4) {
		four_v_four();
	}
	else if ((input == 4 && input2 == 5) || (input == 5 && input2 == 4)) {
		four_v_five();
	}
	else if (input == 5 && input2 == 5) {
		five_v_five();
	}
}


//Barbarian vs Barabarian
// one corresponds to Barbarian, two corresponds to Blue Men, three corresponds to Vampire and so on..
void one_v_one() {
	Barbarian* A = new Barbarian;		//Creating objects
	Barbarian* B = new Barbarian;
	int attack = 0;
	int defense = 0;
	int init_hp = 0;
	int final_hp = 0;
	int counter = 1;
	cout << "Barbarian vs. Barbarian " << endl;
	do {
		cout << endl << " *** Round " << counter << " *** " << endl;
		cout << "Attacker type: Barbarian. Defender type: Barbarian." << endl;
		cout << "Defender armor: " << B->get_armor() << endl;			//Using class functions to return stats
		cout << "Defender strength: " << B->get_strength() << endl;
		attack = A->attack_roll();						//Rolling dice for attack
		defense = B->defense_roll();						//Rolling dice for defense
		cout << "Attack roll: " << attack << endl;
		cout << "Defense roll: " << defense << endl;
		init_hp = B->get_strength();
		attack = attack - defense - B->get_armor();				//Calculating total damage with class functions
		if (attack > 0) {
			cout << "Total inflicted damage: " << attack << endl;
			final_hp = init_hp - attack;
			B->set_strength(final_hp);					//Setting new strength
		} 
		else {
			cout << "Total inflicted damage: 0" << endl;
			final_hp = init_hp;
		}
		cout << "Updated defender strength: " << B->get_strength() << endl;	//Updating defender strength
		if (final_hp <= 0) {
			cout << "The first Barbarian has won!" << endl;			//Win condition
			delete [] A;
			delete [] B;
			return;
		}

		cout << endl << "Attacker type: Barbarian. Defender type: Barbarian." << endl;		//Attacker and defender switch, and then repeats. 
		cout << "Defender armor: " << A->get_armor() << endl;
		cout << "Defender strength: " << A->get_strength() << endl;
		attack = B->attack_roll();
		defense = A->defense_roll();
		cout << "Attack roll: " << attack << endl;
		cout << "Defense roll: " << defense << endl;
		init_hp = A->get_strength();
		attack = attack - defense - A->get_armor();
		if (attack > 0) {
			cout << "Total inflicted damage: " << attack << endl;
			final_hp = init_hp - attack;
			A->set_strength(final_hp);
		} 
		else {
			cout << "Total inflicted damage: 0" << endl;
			final_hp = init_hp;
		}
		cout << "Updated defender strength: " << A->get_strength() << endl;
		if (final_hp <= 0) {
			cout << "The second Barbarian has won!" << endl;
			delete [] A;
			delete [] B;
			return;
		}
		counter++;
	} while (A->get_strength() > 0 && B->get_strength() > 0);
}

//Barbarian vs Blue Men
void one_v_two() {
	Barbarian* A = new Barbarian;
	Blue_Men* B = new Blue_Men;
	int attack = 0;
	int defense = 0;
	int init_hp = 0;
	int final_hp = 0;
	int counter = 1;
	cout << "Barbarian vs. Blue Men " << endl;
	do {
		B->mob();									//mob() function checks to update class defense variable
		cout << endl << " *** Round " << counter << " *** " << endl;
		cout << "Attacker type: Barbarian. Defender type: Blue Men." << endl;
		cout << "Defender armor: " << B->get_armor() << endl;
		cout << "Defender strength: " << B->get_strength() << endl;
		attack = A->attack_roll();
		defense = B->defense_roll();
		cout << "Attack roll: " << attack << endl;
		cout << "Defense roll: " << defense << endl;
		init_hp = B->get_strength();
		attack = attack - defense - B->get_armor();
		if (attack > 0) {
			cout << "Total inflicted damage: " << attack << endl;
			final_hp = init_hp - attack;
			B->set_strength(final_hp);
		} 
		else {
			cout << "Total inflicted damage: 0" << endl;
			final_hp = init_hp;
		}
		cout << "Updated defender strength: " << B->get_strength() << endl;
		if (final_hp <= 0) {
			cout << "The Barbarian has won!" << endl;
			delete [] A;
			delete [] B;
			return;
		}

		cout <<  endl << "Attacker type: Blue Men. Defender type: Barbarian." << endl;
		cout << "Defender armor: " << A->get_armor() << endl;
		cout << "Defender strength: " << A->get_strength() << endl;
		attack = B->attack_roll();
		defense = A->defense_roll();
		cout << "Attack roll: " << attack << endl;
		cout << "Defense roll: " << defense << endl;
		init_hp = A->get_strength();
		attack = attack - defense - A->get_armor();
		if (attack > 0) {
			cout << "Total inflicted damage: " << attack << endl;
			final_hp = init_hp - attack;
			A->set_strength(final_hp);
		} 
		else {
			cout << "Total inflicted damage: 0" << endl;
			final_hp = init_hp;
		}
		cout << "Updated defender strength: " << A->get_strength() << endl;
		if (final_hp <= 0) {
			cout << "The Blue Men have won!" << endl;
			delete [] A;
			delete [] B;
			return;
		}
		counter++;
	} while (A->get_strength() > 0 && B->get_strength() > 0);
}

void one_v_three() {
	Barbarian* A = new Barbarian;
	Vampire* B = new Vampire;
	int attack = 0;
	int defense = 0;
	int init_hp = 0;
	int final_hp = 0;
	int counter = 1;
	cout << "Barbarian vs. Vampire " << endl;
	do {
		cout << endl << " *** Round " << counter << " *** " << endl;
		cout << "Attacker type: Barbarian. Defender type: Vampire." << endl;
		cout << "Defender armor: " << B->get_armor() << endl;
		cout << "Defender strength: " << B->get_strength() << endl;
		attack = A->attack_roll();
		defense = B->defense_roll();
		cout << "Attack roll: " << attack << endl;
		cout << "Defense roll: " << defense << endl;
		init_hp = B->get_strength();
		if (B->charm()) {							//Implementation of class charm() function for vampires. 
			attack = 0;
		} 
		else {
			attack = attack - defense - B->get_armor();
		}
		if (attack > 0) {
			cout << "Total inflicted damage: " << attack << endl;
			final_hp = init_hp - attack;
			B->set_strength(final_hp);
		} 
		else {
			cout << "Total inflicted damage: 0" << endl;
			final_hp = init_hp;
		}
		cout << "Updated defender strength: " << B->get_strength() << endl;
		if (final_hp <= 0) {
			cout << "The Barbarian has won!" << endl;
			delete [] A;
			delete [] B;
			return;
		}

		cout <<  endl << "Attacker type: Vampire. Defender type: Barbarian." << endl;
		cout << "Defender armor: " << A->get_armor() << endl;
		cout << "Defender strength: " << A->get_strength() << endl;
		attack = B->attack_roll();
		defense = A->defense_roll();
		cout << "Attack roll: " << attack << endl;
		cout << "Defense roll: " << defense << endl;
		init_hp = A->get_strength();
		attack = attack - defense - A->get_armor();
		if (attack > 0) {
			cout << "Total inflicted damage: " << attack << endl;
			final_hp = init_hp - attack;
			A->set_strength(final_hp);
		} 
		else {
			cout << "Total inflicted damage: 0" << endl;
			final_hp = init_hp;
		}
		cout << "Updated defender strength: " << A->get_strength() << endl;
		if (final_hp <= 0) {
			cout << "The Vampire has won!" << endl;
			delete [] A;
			delete [] B;
			return;
		}
		counter++;
	} while (A->get_strength() > 0 && B->get_strength() > 0);
}

void one_v_four() {
	Barbarian* A = new Barbarian;
	Medusa* B = new Medusa;
	int attack = 0;
	int defense = 0;
	int init_hp = 0;
	int final_hp = 0;
	int counter = 1;
	cout << "Barbarian vs. Medusa " << endl;
	do {
		cout << endl << " *** Round " << counter << " *** " << endl;
		cout << "Attacker type: Barbarian. Defender type: Medusa." << endl;
		cout << "Defender armor: " << B->get_armor() << endl;
		cout << "Defender strength: " << B->get_strength() << endl;
		attack = A->attack_roll();
		defense = B->defense_roll();
		cout << "Attack roll: " << attack << endl;
		cout << "Defense roll: " << defense << endl;
		init_hp = B->get_strength();
		attack = attack - defense - B->get_armor();
		if (attack > 0) {
			cout << "Total inflicted damage: " << attack << endl;
			final_hp = init_hp - attack;
			B->set_strength(final_hp);
		} 
		else {
			cout << "Total inflicted damage: 0" << endl;
			final_hp = init_hp;
		}
		cout << "Updated defender strength: " << B->get_strength() << endl;
		if (final_hp <= 0) {
			cout << "The Barbarian has won!" << endl;
			delete [] A;
			delete [] B;
			return;
		}

		cout <<  endl << "Attacker type: Medusa. Defender type: Barbarian." << endl;
		cout << "Defender armor: " << A->get_armor() << endl;
		cout << "Defender strength: " << A->get_strength() << endl;
		attack = B->attack_roll();
		defense = A->defense_roll();
		cout << "Attack roll: " << attack << endl;
		cout << "Defense roll: " << defense << endl;
		init_hp = A->get_strength();
		if (B->glare(attack)) {								//Implementation of class glare() function for Medusa
			attack = init_hp;
		} 
		else {
			attack = attack - defense - A->get_armor();
		}
		if (attack > 0) {
			cout << "Total inflicted damage: " << attack << endl;
			final_hp = init_hp - attack;
			A->set_strength(final_hp);
		} 
		else {
			cout << "Total inflicted damage: 0" << endl;
			final_hp = init_hp;
		}
		cout << "Updated defender strength: " << A->get_strength() << endl;
		if (final_hp <= 0) {
			cout << "Medusa has won!" << endl;
			delete [] A;
			delete [] B;
			return;
		}
		counter++;
	} while (A->get_strength() > 0 && B->get_strength() > 0);
}

void one_v_five() {
	Barbarian* A = new Barbarian;
	Harry_Potter* B = new Harry_Potter;
	int attack = 0;
	int defense = 0;
	int init_hp = 0;
	int final_hp = 0;
	int counter = 1;
	cout << "Barbarian vs. Harry_Potter " << endl;
	do {
		cout << endl << " *** Round " << counter << " *** " << endl;
		cout << "Attacker type: Barbarian. Defender type: Harry_Potter." << endl;
		cout << "Defender armor: " << B->get_armor() << endl;
		cout << "Defender strength: " << B->get_strength() << endl;
		attack = A->attack_roll();
		defense = B->defense_roll();
		cout << "Attack roll: " << attack << endl;
		cout << "Defense roll: " << defense << endl;
		init_hp = B->get_strength();
		attack = attack - defense - B->get_armor();
		if (attack > 0) {
			cout << "Total inflicted damage: " << attack << endl;
			final_hp = init_hp - attack;
			B->set_strength(final_hp);
		} 
		else {
			cout << "Total inflicted damage: 0" << endl;
			final_hp = init_hp;
		}
		B->hogwarts();									//Implementation of hogwarts function
		final_hp = B->get_strength();
		cout << "Updated defender strength: " << B->get_strength() << endl;
		if (final_hp <= 0) {
			cout << "The Barbarian has won!" << endl;
			delete [] A;
			delete [] B;
			return;
		}

		cout <<  endl << "Attacker type: Harry Potter. Defender type: Barbarian." << endl;
		cout << "Defender armor: " << A->get_armor() << endl;
		cout << "Defender strength: " << A->get_strength() << endl;
		attack = B->attack_roll();
		defense = A->defense_roll();
		cout << "Attack roll: " << attack << endl;
		cout << "Defense roll: " << defense << endl;
		init_hp = A->get_strength();
		attack = attack - defense - A->get_armor();
		if (attack > 0) {
			cout << "Total inflicted damage: " << attack << endl;
			final_hp = init_hp - attack;
			A->set_strength(final_hp);
		} 
		else {
			cout << "Total inflicted damage: 0" << endl;
			final_hp = init_hp;
		}
		cout << "Updated defender strength: " << A->get_strength() << endl;
		if (final_hp <= 0) {
			cout << "Harry Potter has won!" << endl;
			delete [] A;
			delete [] B;
			return;
		}
		counter++;
	} while (A->get_strength() > 0 && B->get_strength() > 0);
}

void two_v_two() {
	Blue_Men* A = new Blue_Men;
	Blue_Men* B = new Blue_Men;
	int attack = 0;
	int defense = 0;
	int init_hp = 0;
	int final_hp = 0;
	int counter = 1;
	cout << "Blue Men vs. Blue Men " << endl;
	do {
		B->mob();
		cout << endl << " *** Round " << counter << " *** " << endl;
		cout << "Attacker type: Blue Men. Defender type: Blue Men." << endl;
		cout << "Defender armor: " << B->get_armor() << endl;
		cout << "Defender strength: " << B->get_strength() << endl;
		attack = A->attack_roll();
		defense = B->defense_roll();
		cout << "Attack roll: " << attack << endl;
		cout << "Defense roll: " << defense << endl;
		init_hp = B->get_strength();
		attack = attack - defense - B->get_armor();
		if (attack > 0) {
			cout << "Total inflicted damage: " << attack << endl;
			final_hp = init_hp - attack;
			B->set_strength(final_hp);
		} 
		else {
			cout << "Total inflicted damage: 0" << endl;
			final_hp = init_hp;
		}
		cout << "Updated defender strength: " << B->get_strength() << endl;
		if (final_hp <= 0) {
			cout << "The first Blue Men have won!" << endl;
			delete [] A;
			delete [] B;
			return;
		}

		A -> mob();
		cout <<  endl << "Attacker type: Blue Men. Defender type: Blue Men." << endl;
		cout << "Defender armor: " << A->get_armor() << endl;
		cout << "Defender strength: " << A->get_strength() << endl;
		attack = B->attack_roll();
		defense = A->defense_roll();
		cout << "Attack roll: " << attack << endl;
		cout << "Defense roll: " << defense << endl;
		init_hp = A->get_strength();
		attack = attack - defense - A->get_armor();
		if (attack > 0) {
			cout << "Total inflicted damage: " << attack << endl;
			final_hp = init_hp - attack;
			A->set_strength(final_hp);
		} 
		else {
			cout << "Total inflicted damage: 0" << endl;
			final_hp = init_hp;
		}
		cout << "Updated defender strength: " << A->get_strength() << endl;
		if (final_hp <= 0) {
			cout << "The second Blue Men have won!" << endl;
			delete [] A;
			delete [] B;
			return;
		}
		counter++;
	} while (A->get_strength() > 0 && B->get_strength() > 0);
}

void two_v_three() {
	Blue_Men* A = new Blue_Men;
	Vampire* B = new Vampire;
	int attack = 0;
	int defense = 0;
	int init_hp = 0;
	int final_hp = 0;
	int counter = 1;
	cout << "Blue Men vs. Vampire " << endl;
	do {
		cout << endl << " *** Round " << counter << " *** " << endl;
		cout << "Attacker type: Blue Men. Defender type: Vampire." << endl;
		cout << "Defender armor: " << B->get_armor() << endl;
		cout << "Defender strength: " << B->get_strength() << endl;
		attack = A->attack_roll();
		defense = B->defense_roll();
		cout << "Attack roll: " << attack << endl;
		cout << "Defense roll: " << defense << endl;
		init_hp = B->get_strength();
		if (B->charm()) {
			attack = 0;
		} 
		else {
			attack = attack - defense - B->get_armor();
		}
		if (attack > 0) {
			cout << "Total inflicted damage: " << attack << endl;
			final_hp = init_hp - attack;
			B->set_strength(final_hp);
		} 
		else {
			cout << "Total inflicted damage: 0" << endl;
			final_hp = init_hp;
		}
		cout << "Updated defender strength: " << B->get_strength() << endl;
		if (final_hp <= 0) {
			cout << "The Blue Men have won!" << endl;
			delete [] A;
			delete [] B;
			return;
		}

		A -> mob();
		cout <<  endl << "Attacker type: Vampire. Defender type: Blue Men." << endl;
		cout << "Defender armor: " << A->get_armor() << endl;
		cout << "Defender strength: " << A->get_strength() << endl;
		attack = B->attack_roll();
		defense = A->defense_roll();
		cout << "Attack roll: " << attack << endl;
		cout << "Defense roll: " << defense << endl;
		init_hp = A->get_strength();
		attack = attack - defense - A->get_armor();
		if (attack > 0) {
			cout << "Total inflicted damage: " << attack << endl;
			final_hp = init_hp - attack;
			A->set_strength(final_hp);
		} 
		else {
			cout << "Total inflicted damage: 0" << endl;
			final_hp = init_hp;
		}
		cout << "Updated defender strength: " << A->get_strength() << endl;
		if (final_hp <= 0) {
			cout << "The Vampire has won!" << endl;
			delete [] A;
			delete [] B;
			return;
		}
		counter++;
	} while (A->get_strength() > 0 && B->get_strength() > 0);
}

void two_v_four() {
	Blue_Men* A = new Blue_Men;
	Medusa* B = new Medusa;
	int attack = 0;
	int defense = 0;
	int init_hp = 0;
	int final_hp = 0;
	int counter = 1;
	cout << "Blue Men vs. Medusa " << endl;
	do {
		cout << endl << " *** Round " << counter << " *** " << endl;
		cout << "Attacker type: Blue Men. Defender type: Medusa." << endl;
		cout << "Defender armor: " << B->get_armor() << endl;
		cout << "Defender strength: " << B->get_strength() << endl;
		attack = A->attack_roll();
		defense = B->defense_roll();
		cout << "Attack roll: " << attack << endl;
		cout << "Defense roll: " << defense << endl;
		init_hp = B->get_strength();
		attack = attack - defense - B->get_armor();
		if (attack > 0) {
			cout << "Total inflicted damage: " << attack << endl;
			final_hp = init_hp - attack;
			B->set_strength(final_hp);
		} 
		else {
			cout << "Total inflicted damage: 0" << endl;
			final_hp = init_hp;
		}
		cout << "Updated defender strength: " << B->get_strength() << endl;
		if (final_hp <= 0) {
			cout << "The Blue Men have won!" << endl;
			delete [] A;
			delete [] B;
			return;
		}

		A -> mob();
		cout <<  endl << "Attacker type: Medusa. Defender type: Blue Men." << endl;
		cout << "Defender armor: " << A->get_armor() << endl;
		cout << "Defender strength: " << A->get_strength() << endl;
		attack = B->attack_roll();
		defense = A->defense_roll();
		cout << "Attack roll: " << attack << endl;
		cout << "Defense roll: " << defense << endl;
		init_hp = A->get_strength();
		if (B->glare(attack)) {
			attack = init_hp;
		} 
		else {
			attack = attack - defense - A->get_armor();
		}
		if (attack > 0) {
			cout << "Total inflicted damage: " << attack << endl;
			final_hp = init_hp - attack;
			A->set_strength(final_hp);
		} 
		else {
			cout << "Total inflicted damage: 0" << endl;
			final_hp = init_hp;
		}
		cout << "Updated defender strength: " << A->get_strength() << endl;
		if (final_hp <= 0) {
			cout << "Medusa has won!" << endl;
			delete [] A;
			delete [] B;
			return;
		}
		counter++;
	} while (A->get_strength() > 0 && B->get_strength() > 0);
}

void two_v_five() {
	Blue_Men* A = new Blue_Men;
	Harry_Potter* B = new Harry_Potter;
	int attack = 0;
	int defense = 0;
	int init_hp = 0;
	int final_hp = 0;
	int counter = 1;
	cout << "Blue Men vs. Harry_Potter " << endl;
	do {
		cout << endl << " *** Round " << counter << " *** " << endl;
		cout << "Attacker type: Blue Men. Defender type: Harry_Potter." << endl;
		cout << "Defender armor: " << B->get_armor() << endl;
		cout << "Defender strength: " << B->get_strength() << endl;
		attack = A->attack_roll();
		defense = B->defense_roll();
		cout << "Attack roll: " << attack << endl;
		cout << "Defense roll: " << defense << endl;
		init_hp = B->get_strength();
		attack = attack - defense - B->get_armor();
		if (attack > 0) {
			cout << "Total inflicted damage: " << attack << endl;
			final_hp = init_hp - attack;
			B->set_strength(final_hp);
		} 
		else {
			cout << "Total inflicted damage: 0" << endl;
			final_hp = init_hp;
		}
		B->hogwarts();
		final_hp = B->get_strength();
		cout << "Updated defender strength: " << B->get_strength() << endl;
		if (final_hp <= 0) {
			cout << "The Blue Men have won!" << endl;
			delete [] A;
			delete [] B;
			return;
		}

		A->mob();
		cout <<  endl << "Attacker type: Harry Potter. Defender type: Blue Men." << endl;
		cout << "Defender armor: " << A->get_armor() << endl;
		cout << "Defender strength: " << A->get_strength() << endl;
		attack = B->attack_roll();
		defense = A->defense_roll();
		cout << "Attack roll: " << attack << endl;
		cout << "Defense roll: " << defense << endl;
		init_hp = A->get_strength();
		attack = attack - defense - A->get_armor();
		if (attack > 0) {
			cout << "Total inflicted damage: " << attack << endl;
			final_hp = init_hp - attack;
			A->set_strength(final_hp);
		} 
		else {
			cout << "Total inflicted damage: 0" << endl;
			final_hp = init_hp;
		}
		cout << "Updated defender strength: " << A->get_strength() << endl;
		if (final_hp <= 0) {
			cout << "Harry Potter has won!" << endl;
			delete [] A;
			delete [] B;
			return;
		}
		counter++;
	} while (A->get_strength() > 0 && B->get_strength() > 0);
}

void three_v_three() {
	Vampire* A = new Vampire;
	Vampire* B = new Vampire;
	int attack = 0;
	int defense = 0;
	int init_hp = 0;
	int final_hp = 0;
	int counter = 1;
	cout << "Vampire vs. Vampire " << endl;
	do {
		cout << endl << " *** Round " << counter << " *** " << endl;
		cout << "Attacker type: Vampire. Defender type: Vampire." << endl;
		cout << "Defender armor: " << B->get_armor() << endl;
		cout << "Defender strength: " << B->get_strength() << endl;
		attack = A->attack_roll();
		defense = B->defense_roll();
		cout << "Attack roll: " << attack << endl;
		cout << "Defense roll: " << defense << endl;
		init_hp = B->get_strength();
		if (B->charm()) {
			attack = 0;
		} 
		else {
			attack = attack - defense - B->get_armor();
		}
		if (attack > 0) {
			cout << "Total inflicted damage: " << attack << endl;
			final_hp = init_hp - attack;
			B->set_strength(final_hp);
		} 
		else {
			cout << "Total inflicted damage: 0" << endl;
			final_hp = init_hp;
		}
		cout << "Updated defender strength: " << B->get_strength() << endl;
		if (final_hp <= 0) {
			cout << "The first Vampire has won!" << endl;
			delete [] A;
			delete [] B;
			return;
		}

		cout <<  endl << "Attacker type: Vampire. Defender type: Vampire." << endl;
		cout << "Defender armor: " << A->get_armor() << endl;
		cout << "Defender strength: " << A->get_strength() << endl;
		attack = B->attack_roll();
		defense = A->defense_roll();
		cout << "Attack roll: " << attack << endl;
		cout << "Defense roll: " << defense << endl;
		init_hp = A->get_strength();
		if (A->charm()) {
			attack = 0;
		} 
		else {
			attack = attack - defense - A->get_armor();
		}
		if (attack > 0) {
			cout << "Total inflicted damage: " << attack << endl;
			final_hp = init_hp - attack;
			A->set_strength(final_hp);
		} 
		else {
			cout << "Total inflicted damage: 0" << endl;
			final_hp = init_hp;
		}
		cout << "Updated defender strength: " << A->get_strength() << endl;
		if (final_hp <= 0) {
			cout << "The second Vampire has won!" << endl;
			delete [] A;
			delete [] B;
			return;
		}
		counter++;
	} while (A->get_strength() > 0 && B->get_strength() > 0);
}

void three_v_four() {
	Vampire* A = new Vampire;
	Medusa* B = new Medusa;
	int attack = 0;
	int defense = 0;
	int init_hp = 0;
	int final_hp = 0;
	int counter = 1;
	cout << "Vampire vs. Medusa " << endl;
	do {
		cout << endl << " *** Round " << counter << " *** " << endl;
		cout << "Attacker type: Vampire. Defender type: Medusa." << endl;
		cout << "Defender armor: " << B->get_armor() << endl;
		cout << "Defender strength: " << B->get_strength() << endl;
		attack = A->attack_roll();
		defense = B->defense_roll();
		cout << "Attack roll: " << attack << endl;
		cout << "Defense roll: " << defense << endl;
		init_hp = B->get_strength();
		attack = attack - defense - B->get_armor();
		if (attack > 0) {
			cout << "Total inflicted damage: " << attack << endl;
			final_hp = init_hp - attack;
			B->set_strength(final_hp);
		} 
		else {
			cout << "Total inflicted damage: 0" << endl;
			final_hp = init_hp;
		}
		cout << "Updated defender strength: " << B->get_strength() << endl;
		if (final_hp <= 0) {
			cout << "The Vampire has won!" << endl;
			delete [] A;
			delete [] B;
			return;
		}

		cout <<  endl << "Attacker type: Medusa. Defender type: Vampire." << endl;
		cout << "Defender armor: " << A->get_armor() << endl;
		cout << "Defender strength: " << A->get_strength() << endl;
		attack = B->attack_roll();
		defense = A->defense_roll();
		cout << "Attack roll: " << attack << endl;
		cout << "Defense roll: " << defense << endl;
		init_hp = A->get_strength();
		if (B->glare(attack)) {
			attack = init_hp;
		} 
		else if (A->charm()) {
			attack = 0;
		} 
		else {
			attack = attack - defense - A->get_armor();
		}
		if (attack > 0) {
			cout << "Total inflicted damage: " << attack << endl;
			final_hp = init_hp - attack;
			A->set_strength(final_hp);
		} 
		else {
			cout << "Total inflicted damage: 0" << endl;
			final_hp = init_hp;
		}
		cout << "Updated defender strength: " << A->get_strength() << endl;
		if (final_hp <= 0) {
			cout << "Medusa has won!" << endl;
			delete [] A;
			delete [] B;
			return;
		}
		counter++;
	} while (A->get_strength() > 0 && B->get_strength() > 0);
}

void three_v_five() {
	Vampire* A = new Vampire;
	Harry_Potter* B = new Harry_Potter;
	int attack = 0;
	int defense = 0;
	int init_hp = 0;
	int final_hp = 0;
	int counter = 1;
	cout << "Vampire vs. Harry Potter " << endl;
	do {
		cout << endl << " *** Round " << counter << " *** " << endl;
		cout << "Attacker type: Vampire. Defender type: Harry Potter." << endl;
		cout << "Defender armor: " << B->get_armor() << endl;
		cout << "Defender strength: " << B->get_strength() << endl;
		attack = A->attack_roll();
		defense = B->defense_roll();
		cout << "Attack roll: " << attack << endl;
		cout << "Defense roll: " << defense << endl;
		init_hp = B->get_strength();
		attack = attack - defense - B->get_armor();
		if (attack > 0) {
			cout << "Total inflicted damage: " << attack << endl;
			final_hp = init_hp - attack;
			B->set_strength(final_hp);
		} 
		else {
			cout << "Total inflicted damage: 0" << endl;
			final_hp = init_hp;
		}
		B->hogwarts();
		final_hp = B->get_strength();
		cout << "Updated defender strength: " << B->get_strength() << endl;
		if (final_hp <= 0) {
			cout << "The Vampire has won!" << endl;
			delete [] A;
			delete [] B;
			return;
		}

		cout <<  endl << "Attacker type: Harry Potter. Defender type: Vampire." << endl;
		cout << "Defender armor: " << A->get_armor() << endl;
		cout << "Defender strength: " << A->get_strength() << endl;
		attack = B->attack_roll();
		defense = A->defense_roll();
		cout << "Attack roll: " << attack << endl;
		cout << "Defense roll: " << defense << endl;
		init_hp = A->get_strength();
		if (A->charm()) {
			attack = 0;
		} 
		else {
			attack = attack - defense - A->get_armor();
		}
		if (attack > 0) {
			cout << "Total inflicted damage: " << attack << endl;
			final_hp = init_hp - attack;
			A->set_strength(final_hp);
		} 
		else {
			cout << "Total inflicted damage: 0" << endl;
			final_hp = init_hp;
		}
		cout << "Updated defender strength: " << A->get_strength() << endl;
		if (final_hp <= 0) {
			cout << "Harry Potter has won!" << endl;
			delete [] A;
			delete [] B;
			return;
		}
		counter++;
	} while (A->get_strength() > 0 && B->get_strength() > 0);
}

void four_v_four() {
	Medusa* A = new Medusa;
	Medusa* B = new Medusa;
	int attack = 0;
	int defense = 0;
	int init_hp = 0;
	int final_hp = 0;
	int counter = 1;
	cout << "Medusa vs. Medusa " << endl;
	do {
		cout << endl << " *** Round " << counter << " *** " << endl;
		cout << "Attacker type: Medusa. Defender type: Medusa." << endl;
		cout << "Defender armor: " << B->get_armor() << endl;
		cout << "Defender strength: " << B->get_strength() << endl;
		attack = A->attack_roll();
		defense = B->defense_roll();
		cout << "Attack roll: " << attack << endl;
		cout << "Defense roll: " << defense << endl;
		init_hp = B->get_strength();
		if (A->glare(attack)) {
			attack = init_hp;
		} 
		else {
			attack = attack - defense - B->get_armor();
		}
		if (attack > 0) {
			cout << "Total inflicted damage: " << attack << endl;
			final_hp = init_hp - attack;
			B->set_strength(final_hp);
		} 
		else {
			cout << "Total inflicted damage: 0" << endl;
			final_hp = init_hp;
		}
		cout << "Updated defender strength: " << B->get_strength() << endl;
		if (final_hp <= 0) {
			cout << "The first Medusa has won!" << endl;
			delete [] A;
			delete [] B;
			return;
		}

		cout <<  endl << "Attacker type: Medusa. Defender type: Medusa." << endl;
		cout << "Defender armor: " << A->get_armor() << endl;
		cout << "Defender strength: " << A->get_strength() << endl;
		attack = B->attack_roll();
		defense = A->defense_roll();
		cout << "Attack roll: " << attack << endl;
		cout << "Defense roll: " << defense << endl;
		init_hp = A->get_strength();
		if (B->glare(attack)) {
			attack = init_hp;
		} 
		else {
			attack = attack - defense - A->get_armor();
		}
		if (attack > 0) {
			cout << "Total inflicted damage: " << attack << endl;
			final_hp = init_hp - attack;
			A->set_strength(final_hp);
		} 
		else {
			cout << "Total inflicted damage: 0" << endl;
			final_hp = init_hp;
		}
		cout << "Updated defender strength: " << A->get_strength() << endl;
		if (final_hp <= 0) {
			cout << "the second Medusa has won!" << endl;
			delete [] A;
			delete [] B;
			return;
		}
		counter++;
	} while (A->get_strength() > 0 && B->get_strength() > 0);
}

void four_v_five() {
	Medusa* A = new Medusa;
	Harry_Potter* B = new Harry_Potter;
	int attack = 0;
	int defense = 0;
	int init_hp = 0;
	int final_hp = 0;
	int counter = 1;
	cout << "Medusa vs. Harry Potter " << endl;
	do {
		cout << endl << " *** Round " << counter << " *** " << endl;
		cout << "Attacker type: Medusa. Defender type: Harry Potter." << endl;
		cout << "Defender armor: " << B->get_armor() << endl;
		cout << "Defender strength: " << B->get_strength() << endl;
		attack = A->attack_roll();
		defense = B->defense_roll();
		cout << "Attack roll: " << attack << endl;
		cout << "Defense roll: " << defense << endl;
		init_hp = B->get_strength();
		if (A->glare(attack)) {
			attack = init_hp;
		} 
		else {
			attack = attack - defense - B->get_armor();
		}
		if (attack > 0) {
			cout << "Total inflicted damage: " << attack << endl;
			final_hp = init_hp - attack;
			B->set_strength(final_hp);
		} 
		else {
			cout << "Total inflicted damage: 0" << endl;
			final_hp = init_hp;
		}
		B->hogwarts();
		final_hp = B->get_strength();
		cout << "Updated defender strength: " << B->get_strength() << endl;
		if (final_hp <= 0) {
			cout << "Medusa has won!" << endl;
			delete [] A;
			delete [] B;
			return;
		}

		cout <<  endl << "Attacker type: Harry Potter. Defender type: Medusa." << endl;
		cout << "Defender armor: " << A->get_armor() << endl;
		cout << "Defender strength: " << A->get_strength() << endl;
		attack = B->attack_roll();
		defense = A->defense_roll();
		cout << "Attack roll: " << attack << endl;
		cout << "Defense roll: " << defense << endl;
		init_hp = A->get_strength();
		attack = attack - defense - A->get_armor();
		if (attack > 0) {
			cout << "Total inflicted damage: " << attack << endl;
			final_hp = init_hp - attack;
			A->set_strength(final_hp);
		} 
		else {
			cout << "Total inflicted damage: 0" << endl;
			final_hp = init_hp;
		}
		cout << "Updated defender strength: " << A->get_strength() << endl;
		if (final_hp <= 0) {
			cout << "Harry Potter has won!" << endl;
			delete [] A;
			delete [] B;
			return;
		}
		counter++;
	} while (A->get_strength() > 0 && B->get_strength() > 0);
}

void five_v_five() {
	Harry_Potter* A = new Harry_Potter;
	Harry_Potter* B = new Harry_Potter;
	int attack = 0;
	int defense = 0;
	int init_hp = 0;
	int final_hp = 0;
	int counter = 1;
	cout << "Harry Potter vs. Harry Potter " << endl;
	do {
		cout << endl << " *** Round " << counter << " *** " << endl;
		cout << "Attacker type: Harry Potter. Defender type: Harry Potter." << endl;
		cout << "Defender armor: " << B->get_armor() << endl;
		cout << "Defender strength: " << B->get_strength() << endl;
		attack = A->attack_roll();
		defense = B->defense_roll();
		cout << "Attack roll: " << attack << endl;
		cout << "Defense roll: " << defense << endl;
		init_hp = B->get_strength();
		attack = attack - defense - B->get_armor();
		if (attack > 0) {
			cout << "Total inflicted damage: " << attack << endl;
			final_hp = init_hp - attack;
			B->set_strength(final_hp);
		} 
		else {
			cout << "Total inflicted damage: 0" << endl;
			final_hp = init_hp;
		}
		B->hogwarts();
		final_hp = B->get_strength();
		cout << "Updated defender strength: " << B->get_strength() << endl;
		if (final_hp <= 0) {
			cout << "The first Harry Potter has won!" << endl;
			delete [] A;
			delete [] B;
			return;
		}

		cout <<  endl << "Attacker type: Harry Potter. Defender type: Harry Potter." << endl;
		cout << "Defender armor: " << A->get_armor() << endl;
		cout << "Defender strength: " << A->get_strength() << endl;
		attack = B->attack_roll();
		defense = A->defense_roll();
		cout << "Attack roll: " << attack << endl;
		cout << "Defense roll: " << defense << endl;
		init_hp = A->get_strength();
		attack = attack - defense - A->get_armor();
		if (attack > 0) {
			cout << "Total inflicted damage: " << attack << endl;
			final_hp = init_hp - attack;
			A->set_strength(final_hp);
		} 
		else {
			cout << "Total inflicted damage: 0" << endl;
			final_hp = init_hp;
		}
		A->hogwarts();
		final_hp = A->get_strength();
		cout << "Updated defender strength: " << A->get_strength() << endl;
		if (final_hp <= 0) {
			cout << "The second Harry Potter has won!" << endl;
			delete [] A;
			delete [] B;
			return;
		}
		counter++;
	} while (A->get_strength() > 0 && B->get_strength() > 0);
}

//Input Validation function.
bool menu_input_validation(string input){
	if (input.length() == 1 && (input[0] == 49 || input[0] == 50 || input[0] == 51 || input[0] == 52 || input[0] == 53)) {
		return true;
	}
	return false;
}

//Turns string into integer.
int get_int (string input){
 	int returnValue = 0;
 	for (int i = 0; i < input.length(); i++) {
		returnValue += ((input[i] - '0') * (pow(10, input.length() - i - 1)));
	}
	return returnValue;
}

//Input Validation function.
bool play_input_validation(string input){
	if (input.length() == 1 && (input[0] == 49 || input[0] == 50)) {
		return true;
	}
	return false;
}