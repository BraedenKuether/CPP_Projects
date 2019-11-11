
#include <iostream>
#include <string>
#include <cstdlib>
#include "Zoo.hpp"
#include "Animal.hpp"
#include "Tiger.hpp"

using namespace std;

Tiger::Tiger():Animal(){
  cost = 10000;
  num_babies = 1;
  base_food = 5 * base_food;
  payoff = 0.2;
  age = 0;
}
