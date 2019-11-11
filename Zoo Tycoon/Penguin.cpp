
#include <iostream>
#include <string>
#include <cstdlib>
#include "Animal.hpp"
#include "Penguin.hpp"

using namespace std;

Penguin::Penguin():Animal(){
  cost = 1000;
  num_babies = 5;
  payoff = 0.1;
  age = 0;
}
