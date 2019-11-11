#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include "Zoo.hpp"
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include <fstream>

using namespace std;

//Constructor. Created arrays of objects for each animal.
Zoo::Zoo(){
  feed_type = 1;
  money = 100000;
  day = 0;
  bonus = 0;
  tiger_arr_length = 10;
  penguin_arr_length = 10;
  turtle_arr_length = 10;
  tiger_arr = new Tiger[10];
  penguin_arr = new Penguin[10];
  turtle_arr = new Turtle[10];
}

//Game function.
void Zoo::game(){
  cout << endl << "Welcome to Zoo Tycoon!" << endl;
  initial_animal_purchase();
  do {
    if (money < 1) {
      cout << "You ran out of money. Game Over" << endl;
      break;
    }
    print();
    bonus = 0;
    increment_ages();
    get_feed_type();
    feed_animals();
    random_event();
    calculate_income();
    buy();
    day++;
  } while (keep_playing());
  delete_arrs();
}

//Prints game information.
void Zoo::print(){
  cout << endl << " *** Day Number " << (day + 1) << " ***" << endl << endl;
  cout << "You have " << money << " dollars in the bank." << endl;
  cout << "You have " << tiger_num << " tigers, " << penguin_num << " penguins, and " << turtle_num << " turtles in you zoo." << endl;
}

//Prompts user to play another day.
bool Zoo::keep_playing() {
  string input;
  do {
    cout << "Enter '1' to play another day. Enter '2' to quit." << endl;
    getline(cin,input);
  } while(!menu_input_validation(input));
  if (input[0] == 49) {
    return true;
  }
  else {
    return false;
  }
}

//Input validation.
bool Zoo::menu_input_validation(string input){
  if (input.length() == 1 && (input[0] == 49 || input[0] == 50)) {
    return true;
  } else {
    return false;
  }
}

//Initial purchase of animals to start game.
void Zoo::initial_animal_purchase() {
  string input;
  cout << "You will need to buy animals to start your Zoo. You will begin with 100,000 dollars to spend." << endl;
  do {
    cout << "Tigers cost $10,000. Enter 1 to buy one tiger. Enter 2 to buy two tigers: " << endl;
    getline(cin,input);
  } while (!menu_input_validation(input));
//Setting number of tigers to user input.
  tiger_num = get_int(input);
  for (int i = 0; i < tiger_num; i++) {
//Age set at 0.
    tiger_arr[i].set_age(0);
//Subtracting price.
    money -= tiger_arr[i].get_cost();
  }
  do {
    cout << "Penguins cost $1,000. Enter 1 to buy one penguin. Enter 2 to buy two penguins: " << endl;
    getline(cin,input);
  } while (!menu_input_validation(input));
  penguin_num = get_int(input);
  for (int j = 0; j < penguin_num; j++) {
    penguin_arr[j].set_age(0);
    money -= penguin_arr[j].get_cost();
  }
  do {
    cout << "Turtles cost $100. Enter 1 to buy one turtle. Enter 2 to buy two turtles: " << endl;
    getline(cin,input);
  } while (!menu_input_validation(input));
  turtle_num = get_int(input);
  for (int h = 0; h < turtle_num; h++) {
    turtle_arr[h].set_age(0);
    money -= turtle_arr[h].get_cost();
  }
}

//Making all the animals older for each day.
void Zoo::increment_ages(){
  for (int h = 0; h < tiger_num; h++) {
    tiger_arr[h].set_age(tiger_arr[h].get_age() + 1);
  }
  for (int j = 0; j < penguin_num; j++) {
    penguin_arr[j].set_age(penguin_arr[j].get_age() + 1);
  }
  for (int i = 0; i < turtle_num; i++) {
    turtle_arr[i].set_age(turtle_arr[i].get_age() + 1);
  }
}

//Prompting user for the type of feed they want.
void Zoo::get_feed_type(){
  string input;
  do {
    cout << "What type of feed would you like to use?" << endl;
    cout << "Cheap feed is half price but doubles the chances your animals get sick. Premium feed is twice as expensive, but halves the chances your animals get sick." << endl;
    cout << "Enter 0 for cheap feed. Enter 1 for generic feed. Enter 2 for premium feed." << endl;
    getline(cin, input);
  } while (!feed_input_validation(input));
  feed_type = get_int(input);
}

//Input validation.
bool Zoo::feed_input_validation(string input){
  if (input.length() == 1 && (input[0] == 48 || input[0] == 49 || input[0] == 50)) {
    return true;
  } else {
    return false;
  }
}

//Subrtracint cost of feed from total money.
void Zoo::feed_animals(){
  int temp = money;
//Separate statements for each type of feed.
  if (feed_type == 0) {
    for (int h = 0; h < tiger_num; h++) {
      money -= (tiger_arr[h].get_base_food() * 0.5);
    }
    for (int j = 0; j < penguin_num; j++) {
      money -= (penguin_arr[j].get_base_food() * 0.5);
    }
    for (int i = 0; i < turtle_num; i++) {
      money -= (turtle_arr[i].get_base_food() * 0.5);
    }
  }
  else if (feed_type == 1) {
    for (int h = 0; h < tiger_num; h++) {
      money -= tiger_arr[h].get_base_food();
    }
    for (int j = 0; j < penguin_num; j++) {
      money -= penguin_arr[j].get_base_food();
    }
    for (int i = 0; i < turtle_num; i++) {
      money -= turtle_arr[i].get_base_food();
    }
  }
  else if (feed_type == 2) {
    for (int h = 0; h < tiger_num; h++) {
      money -= (tiger_arr[h].get_base_food() * 2);
    }
    for (int j = 0; j < penguin_num; j++) {
      money -= (penguin_arr[j].get_base_food() * 2);
    }
    for (int i = 0; i < turtle_num; i++) {
      money -= (turtle_arr[i].get_base_food() * 2);
    }
  }
  temp -= money;
  cout << "You paid " << temp << " dollars to feed the animals in the zoo." << endl;
}

//Random event function which decides which event takes place.
void Zoo::random_event(){
  int temp = 0;
//Rand is used on different bounds for different types of feeds to control odds of animals being sick.
  if (feed_type == 0){
    temp = rand() % 5;
  }
  else if (feed_type == 1){
    temp = rand() % 4;
  }
  else if (feed_type == 2){
    temp = rand() % 14;
  }
//Extra credit portion, reading in from a file and outputting a text response.
  if (temp == 0 || temp == 4) {
    random_sickness();
    ifstream Random_reader("file.txt");
    int temp2 = 0;
    string temp3;
    while (getline(Random_reader, temp3)) {
      if (temp2 == 0) {
        cout << temp3 << endl;
        Random_reader.close();
        return;
      }
      temp2 ++;
    }
  }
  else if (temp == 1 || temp == 5 || temp == 6 || temp == 7) {
    random_boom();
    ifstream Random_reader("file.txt");
    int temp2 = 0;
    string temp3;
    while (getline(Random_reader, temp3)) {
      if (temp2 == 1) {
        cout << temp3 << endl;
        Random_reader.close();
        return;
      }
      temp2 ++;
    }
  }
  else if (temp == 2 || temp == 8 || temp == 9 || temp == 10) {
    random_baby();
    ifstream Random_reader("file.txt");
    int temp2 = 0;
    string temp3;
    while (getline(Random_reader, temp3)) {
      if (temp2 == 2) {
        cout << temp3 << endl;
        Random_reader.close();
        return;
      }
      temp2 ++;
    }
  }
}

//Sickness occurs, and an animal dies, as long as there is at least 1.
void Zoo::random_sickness() {
  int temp;
  temp = rand() % 3;
  if (temp == 0 && tiger_num > 0) {
    tiger_num --;
  }
  else if (temp == 1 && penguin_num > 0) {
    penguin_num --;
  }
  else if (temp == 2 && turtle_num > 0) {
    turtle_num --;
  }
}

//You get a random (250-500) dollar bonues per tiger.
void Zoo::random_boom() {
  int temp = 0;
  temp = rand() % 251 + 250;
  temp = temp * tiger_num;
  bonus += temp;
}

//A baby/babies are born.
void Zoo::random_baby() {
  int temp = 0;
  int temp2 = 0;
  if (day < 3) {
    cout << "No animals are old enough to have babies yet. " << endl;
    return;
  }
  temp = rand() % 3;
//Checking to make sure that there is at least on tiger, and if that is the only animal it will give birth to that animal type.
  if ((temp == 0 && tiger_num > 0) || (tiger_num > 0 && penguin_num == 0 || turtle_num == 0 )) {
    temp2 = tiger_num + tiger_arr[0].get_num_babies();
//Resizing array. Creating a copy array and then copying that to the new resized array.
    if (temp2 > tiger_arr_length){
      tiger_arr_length = temp2 * 2;
      Tiger* tiger_temp = new Tiger[tiger_arr_length];
      for (int i = 0; i < tiger_num; i++) {
        tiger_temp[i] = tiger_arr[i];
      }
//Deleting old array.
      delete [] tiger_arr;
      tiger_arr = tiger_temp;
    }
    tiger_num = temp2;
  }
  else if ((temp == 1 && penguin_num > 0) || (temp == 0 && penguin_num > 0)) {
    temp2 = penguin_num + penguin_arr[0].get_num_babies();
    if (temp2 > penguin_arr_length){
      penguin_arr_length = temp2 * 2;
      Penguin* penguin_temp = new Penguin[penguin_arr_length];
      for (int i = 0; i < penguin_num; i++) {
        penguin_temp[i] = penguin_arr[i];
      }
      delete [] penguin_arr;
      penguin_arr = penguin_temp;
    }
    penguin_num = temp2;
  }
  else if ((temp == 2 && turtle_num > 0) || (tiger_num == 0 && penguin_num == 0 && turtle_num > 0)) {
    temp2 = turtle_num + turtle_arr[0].get_num_babies();
    if (temp2 > turtle_arr_length){
      turtle_arr_length = temp2 * 2;
      Turtle* turtle_temp = new Turtle[turtle_arr_length];
      for (int i = 0; i < turtle_num; i++) {
        turtle_temp[i] = turtle_arr[i];
      }
      delete [] turtle_arr;
      turtle_arr = turtle_temp;
    }
    turtle_num = temp2;
  }
}

//Buying more animals. Like prvious function arrays are resized if the new animal purchases exceed the array size.
void Zoo::buy() {
  int temp = 0;
  int temp2 = 0;
  string input;
  do {
    cout << "You can now buy an adult animal if you like, for the same price as the beginning of the game. If you would not like to buy anything enter 0.";
    cout << " Enter 1 to buy a tiger. Enter 2 to buy a penguin. Enter 3 to buy a turtle." << endl;
    getline(cin, input);
  } while (!buy_input_validation(input));
  temp = get_int(input);
  if (temp == 1) {
    money -= 10000;
    cout << "An adult tiger has been added to your zoo." << endl;
    temp2 = tiger_num + 1;
    if (temp2 > tiger_arr_length){
      tiger_arr_length = temp2 * 2;
      Tiger* tiger_temp = new Tiger[tiger_arr_length];
      for (int i = 0; i < tiger_num; i++) {
        tiger_temp[i] = tiger_arr[i];
      }
      delete [] tiger_arr;
      tiger_arr = tiger_temp;
    }
//Animal age set at 3 after purhcase (adult).
    tiger_arr[tiger_num].set_age(3);
    tiger_num = temp2;
  }
  else if (temp == 2) {
    money -= 1000;
    cout << "An adult penguin has been added to your zoo." << endl;
    temp2 = penguin_num + 1;
    if (temp2 > penguin_arr_length){
      penguin_arr_length = temp2 * 2;
      Penguin* penguin_temp = new Penguin[penguin_arr_length];
      for (int i = 0; i < penguin_num; i++) {
        penguin_temp[i] = penguin_arr[i];
      }
      delete [] penguin_arr;
      penguin_arr = penguin_temp;
    }
    penguin_arr[penguin_num].set_age(3);
    penguin_num = temp2;
  }
  else if (temp == 3) {
    money -= 100;
    cout << "An adult turtle has been added to your zoo." << endl;
    temp2 = turtle_num + 1;
    if (temp2 > turtle_arr_length){
      turtle_arr_length = temp2 * 2;
      Turtle* turtle_temp = new Turtle[turtle_arr_length];
      for (int i = 0; i < turtle_num; i++) {
        turtle_temp[i] = turtle_arr[i];
      }
      delete [] turtle_arr;
      turtle_arr = turtle_temp;
    }
    turtle_arr[turtle_num].set_age(3);
    turtle_num = temp2;
  }
}

//Input validation.
bool Zoo::buy_input_validation(string input){
  if (input.length() == 1 && (input[0] == 48 || input[0] == 49 || input[0] == 50 || input[0] == 51)) {
    return true;
  } else {
    return false;
  }
}

//Calculates net income every day as well as adjusting money total.
void Zoo::calculate_income(){
  int temp = money;
  for (int h = 0; h < tiger_num; h++) {
    money += tiger_arr[h].get_payoff();
  }
  for (int q = 0; q < penguin_num; q++) {
    money += penguin_arr[q].get_payoff();
  }
  for (int i = 0; i < turtle_num; i++) {
    money += turtle_arr[i].get_payoff();
  }
  money += bonus;
  cout << "Your net income for the day is: " << money - temp << endl;
}

//Deletes arrays.
void Zoo::delete_arrs(){
  delete [] tiger_arr;
  delete [] penguin_arr;
  delete [] turtle_arr;
}

//Turns string to integer.
int Zoo::get_int (string input){
  int returnValue = 0;
  for (int i = 0; i < input.length(); i++) {
    returnValue += ((input[i] - '0') * (pow(10, input.length() - i - 1)));
  }
  return returnValue;
}
