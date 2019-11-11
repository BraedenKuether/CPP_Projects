
#include <iostream>
#include <string>
#include <cstdlib>
#include "Animal.hpp"
#include "Turtle.hpp"

using namespace std;

Turtle::Turtle():Animal(){
  cost = 100;
  num_babies = 10;
  base_food = 0.5 * base_food;
  payoff = 0.05;
  age = 0;
}
