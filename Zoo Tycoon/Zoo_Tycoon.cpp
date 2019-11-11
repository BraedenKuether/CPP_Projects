
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include "Zoo.hpp"

using namespace std;

class Zoo;

int main() {
  srand(time(NULL));
  Zoo zoo1;
  zoo1.game();
  return 0;
}
