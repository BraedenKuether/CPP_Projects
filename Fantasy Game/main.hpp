#ifndef MAIN_HPP_
#define MAIN_HPP_
#include "Character.hpp"

using namespace std;

void menu();

void fight(int,int);

void one_v_one();

void one_v_two();

void one_v_three();

void one_v_four();

void one_v_five();

void two_v_two();

void two_v_three();

void two_v_four();

void two_v_five();

void three_v_three();

void three_v_four();

void three_v_five();

void four_v_four();

void four_v_five();

void five_v_five();

bool menu_input_validation(string);

int get_int(string);

bool play_input_validation(string);

#endif