
#include <iostream>
#include <string>
#include <cstdlib>
#include "Zoo.hpp"
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"

using namespace std;

Animal::Animal(){
  base_food = 20;
}

void Animal::set_age(int input) {
  age = input;
}

int Animal::get_age(){
  return age;
}

int Animal::get_cost(){
  return cost;
}

int Animal::get_base_food(){
  return base_food;
}

int Animal::get_num_babies(){
  return num_babies;
}

double Animal::get_payoff(){
  return (payoff * cost);
}
