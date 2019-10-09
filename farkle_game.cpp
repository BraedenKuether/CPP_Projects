#include <iostream>
#include <string.h>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

int welcome_to_farkle();
bool welcome_validity(string);
float get_float(string);
int one_turn(int*, int*);
int get_int(string);
int dice_removal_score(int*, int);
bool valid_dice_removed(int*, int, int*, int);
bool valid_dice_removed_input(int, string);
int dice_removed(int*, int, int* input_dice[]);
int play_again();
bool one_one(int*, int);
bool one_five(int*, int);
bool three_ones(int*, int);
bool three_twos(int*, int);
bool three_threes(int*, int);
bool three_fours(int*, int);
bool three_fives(int*, int);
bool three_sixes(int*, int);
bool four_of_a_kind(int*, int);
bool five_of_a_kind(int*, int);
bool six_of_a_kind(int*, int);
bool straight(int*, int);
bool three_pairs(int*, int);
bool four_of_a_kind_and_a_pair(int*, int);
bool two_triplets(int*, int);
int dice_removal_score_1(int* input_dice, int input_length);
int dice_removal_score_2(int* input_dice, int input_length);
int dice_removal_score_3(int* input_dice, int input_length);
bool valid_dice_removed_scoring(int* input_dice, int input_length);
bool farkle(int*, int);
void game(int* scoreboard, int* dice, int* input_dice, int player_count);


int main (){
  srand(time(NULL));
  int* scoreboard = NULL;
  int* dice = NULL;
  int* input_dice = NULL;
  game(scoreboard, dice, input_dice, welcome_to_farkle());
  delete [] scoreboard;
  delete [] dice;
  delete [] input_dice;
  return 0;
}

/*********************************************************************
** Function: welcome_to_farkle
** Description: Welcomes user to Farkle and prompts for number of players.
** Parameters: none
** Pre-Conditions: Input is a string.
** Post-Conditions: Returns int value.
*********************************************************************/
int welcome_to_farkle() {
  string input;
  do {
    cout << "Welcome to Farkle! How many players are playing? ";
    getline(cin,input);
  } while (!welcome_validity(input));
  return get_int(input);
}

/*********************************************************************
** Function: welcome_validity
** Description: Indicates if the string is valid input.
** Parameters: string input
** Pre-Conditions: Input is a string.
** Post-Conditions: Returns boolean value.
*********************************************************************/
bool welcome_validity(string input) {
  for (int i = 0; i < input.length(); i++) {
    if (input[i] < 48 || input[i] > 57) {
      return false;
    }
    if (input.length() == 1) {
      if (input[i] < 50) {
        return false;
      }
    }
  }
  return true;
}

/*********************************************************************
** Function: game
** Description: Plays game.
** Parameters: int* scoreboard, int* dice, int* input_dice, int player_count
** Pre-Conditions: Input are arrays and ints.
** Post-Conditions: Returns int value.
*********************************************************************/
void game(int* scoreboard, int* dice, int* input_dice, int player_count){
  scoreboard = new int[player_count];
  bool winner = false;
  do {
    for (int i = 0; i < player_count; i++) {
      cout << "Player " << i + 1 << "'s turn: " << endl;
      scoreboard[i] += one_turn(dice, input_dice);
      cout << "*** Scoreboard *** " << endl;
      for (int j = 0; j < player_count; j++) {
        if (scoreboard[j] >= 500) {
          cout << "Player " << j + 1 << ": " << scoreboard[j] << endl;
        }
      }
      if (scoreboard[i] >= 500){
        cout << "Player " << i + 1 << " wins with a score of: " << scoreboard[i] << endl;
        winner = true;
        break;
      }
    }
  } while (!winner);
  delete [] scoreboard;
}

/*********************************************************************
** Function: one_turn
** Description: Performs one singular turn.
** Parameters: int* dice, int* input_dice
** Pre-Conditions: Input are pointers.
** Post-Conditions: Returns integer.
*********************************************************************/
int one_turn(int* dice, int* input_dice){
  int total_score = 0;
  int number_of_dice = 6;
  int dice_removed_length = 0;
  dice = new int[number_of_dice];
  do {
    int* input_dice;
    number_of_dice = 6;
    while (number_of_dice != 0) {
      cout << "You rolled: ";
      for (int i = 0; i < number_of_dice; i++) {
        dice[i] = rand() % 6 + 1;
        cout << dice[i];
      }
      if (farkle(dice,number_of_dice)) {
        cout << endl << "Farkle! Your score for this turn is 0." << endl;
        delete [] input_dice;
        delete [] dice;
        return 0;
      }
      string input;
      dice_removed_length = dice_removed(dice,number_of_dice,&input_dice);
      number_of_dice = number_of_dice - dice_removed_length;
      total_score += dice_removal_score(input_dice,dice_removed_length);
      cout << endl << "Your score is: " << total_score << endl;
      if (total_score < 500 && number_of_dice == 0){
        cout << "You did not have enough points to get on the scoreboard " << endl;
        delete [] input_dice;
        delete [] dice;
        return 0;
      }
      if (total_score >= 500 && number_of_dice > 0) {
        cout << "Would you like to stop rolling and add your score to the scoreboard? (Yes: enter 1, No: enter 0) ";
        getline(cin,input);
        if (input == "1") {
          delete [] input_dice;
          delete [] dice;
          return total_score;
        }
      }
      delete [] input_dice;
    }
  } while (play_again() == 1);
  delete [] dice;
  return total_score;
}

/*********************************************************************
** Function: farkle
** Description: Says if roll was a farkle.
** Parameters: int* dice, int number_of_dice
** Pre-Conditions: Pointer to array.
** Post-Conditions: boolean value
*********************************************************************/
bool farkle(int* dice, int number_of_dice){
  int dice_copy[number_of_dice];
  int counter = 0;
  if (three_pairs(dice,number_of_dice)){
    return false;
  }
  for (int a = 0; a < number_of_dice; a++) {
    dice_copy[a] = dice[a];
  }
  for (int i = 0; i < number_of_dice; i++) {
    if (dice_copy[i] == 1 || dice_copy[i] == 5) {
      return false;
    }
    for (int j = 0; j < number_of_dice; j++) {
      if (dice_copy[i] == dice_copy[j]) {
        counter++;
        if (counter > 2){
          return false;
        }
      }
    }
    counter = 0;
  }
  return true;
}

/*********************************************************************
** Function: dice_removed
** Description: Returns the amount of dice removed after a roll.
** Parameters: int* dice
** Pre-Conditions: Input is an array of integers.
** Post-Conditions: Returns an integer.
*********************************************************************/
int dice_removed(int* dice, int number_of_dice, int* input_dice[]){
  string input;
  int input_length;
  bool bool1;
  bool bool2;
  bool bool3;
  do {
    cout << endl << "Which dice would you like to remove? Please enter the values of those dice without using spaces: ";
    getline(cin,input);
    int input_length = input.length();
    *input_dice = new int[input_length];
    for (int i = 0; i < input_length; i++){
      (*input_dice)[i] = (input[i] - '0');
    }
    bool1 = valid_dice_removed_input(number_of_dice,input);
    bool2 = valid_dice_removed(dice,number_of_dice,*input_dice,input_length);
    bool3 = valid_dice_removed_scoring(*input_dice,input_length);
  } while (bool1 == false || bool2 == false || bool3 == false);
  return input.length();
}

/*********************************************************************
** Function: valid_dice_removed
** Description: Says if dice removed after a roll is valid.
** Parameters: int* dice, string input
** Pre-Conditions: Input is an array of integers, and a string.
** Post-Conditions: Returns a boolean value.
*********************************************************************/
bool valid_dice_removed(int* dice, int number_of_dice, int* input_dice, int input_length) {
  int counter = 0;
  int input_dice_copy[input_length];
  for (int a = 0; a < input_length; a++) {
    input_dice_copy[a] = input_dice[a];
  }
  for (int i = 0; i < number_of_dice; i++){
    for (int j = 0; j < input_length; j++) {
      if (dice[i] == input_dice_copy[j]) {
        counter++;
        input_dice_copy[j] = 0;
        break;
      }
    }
  }
  if (counter == input_length) {
    return true;
  }
  return false;
}

/*********************************************************************
** Function: valid_dice_removed_input
** Description: Says if dice removed after a roll is valid.
** Parameters: int* dice, string input
** Pre-Conditions: Input is an array of integers, and a string.
** Post-Conditions: Returns a boolean value.
*********************************************************************/
bool valid_dice_removed_input(int number_of_dice, string input) {
  for (int j = 0; j < input.length(); j++){
    if (input[j] < 48 || input[j] > 54){
      return false;
    }
  }
  if (input.length() > number_of_dice) {
    return false;
  }
  return true;
}

/*********************************************************************
** Function: play_again
** Description: Returns string as an integer.
** Parameters: String input.
** Pre-Conditions: Input is a string.
** Post-Conditions: Returns integer.
*********************************************************************/
int play_again() {
  string decision;
  bool flag;
  do {
    flag = true;
    cout << "Would you like to roll again? (Yes: enter 1, No: enter 0) ";
    getline(cin,decision);
    cout << endl;
    if (decision.length() > 1){
      flag = false;
    } else if (decision[0] == '1'){
      return 1;
    } else if (decision[0] == '0'){
      return 0;
    } else {
      flag = false;
    }
  } while (flag == false);
}

/*********************************************************************
** Function: dice_removal_score
** Description: Returns string as an integer.
** Parameters: String input.
** Pre-Conditions: Input is a string.
** Post-Conditions: Returns integer.
*********************************************************************/
int dice_removal_score(int* input_dice, int input_length) {
  return dice_removal_score_1(input_dice, input_length) + dice_removal_score_2(input_dice, input_length) + dice_removal_score_3(input_dice, input_length);
}

/*********************************************************************
** Function: dice_removal_score_1
** Description: Returns string as an integer.
** Parameters: String input.
** Pre-Conditions: Input is a string.
** Post-Conditions: Returns integer.
*********************************************************************/
int dice_removal_score_1(int* input_dice, int input_length) {
  if (three_ones(input_dice, input_length))
    return 300;
  if (three_twos(input_dice, input_length))
    return 200;
  if (three_threes(input_dice, input_length))
    return 300;
  if (three_fours(input_dice, input_length))
    return 400;
  if (three_fives(input_dice, input_length))
    return 500;
  if (three_sixes(input_dice, input_length))
    return 600;
  else {
    return 0;
  }
}

/*********************************************************************
** Function: dice_removal_score_2
** Description: Returns string as an integer.
** Parameters: String input.
** Pre-Conditions: Input is a string.
** Post-Conditions: Returns integer.
*********************************************************************/
int dice_removal_score_2(int* input_dice, int input_length) {
  if (one_one(input_dice, input_length))
    return 100;
  if (one_five(input_dice, input_length))
    return 50;
  if (four_of_a_kind(input_dice, input_length))
    return 1000;
  if (five_of_a_kind(input_dice, input_length))
    return 2000;
  if (six_of_a_kind(input_dice, input_length))
    return 3000;
  else
    return 0;
}

/*********************************************************************
** Function: dice_removal_score_3
** Description: Returns string as an integer.
** Parameters: String input.
** Pre-Conditions: Input is a string.
** Post-Conditions: Returns integer.
*********************************************************************/
int dice_removal_score_3(int* input_dice, int input_length) {
  if (straight(input_dice, input_length))
    return 1500;
  if (three_pairs(input_dice, input_length))
    return 1500;
  if (four_of_a_kind_and_a_pair(input_dice, input_length))
    return 1500;
  if (two_triplets(input_dice, input_length))
    return 2500;
  else
    return 0;
}

/*********************************************************************
** Function: valid_dice_removed_scoring
** Description: Returns if the dice removed are valid.
** Parameters: int* input_dice, int input_length.
** Pre-Conditions: Input is a pointer to an array, and an int.
** Post-Conditions: Returns boolean value.
*********************************************************************/
bool valid_dice_removed_scoring(int* input_dice, int input_length) {
  if (one_one(input_dice, input_length) || one_five(input_dice, input_length) || four_of_a_kind(input_dice, input_length) || five_of_a_kind(input_dice, input_length) || six_of_a_kind(input_dice, input_length) || three_ones(input_dice, input_length) || three_twos(input_dice, input_length) || three_threes(input_dice, input_length) || three_fours(input_dice, input_length) || three_fives(input_dice, input_length) || three_sixes(input_dice, input_length)
  || straight(input_dice, input_length) || three_pairs(input_dice, input_length) || four_of_a_kind_and_a_pair(input_dice, input_length) || four_of_a_kind_and_a_pair(input_dice, input_length) || two_triplets(input_dice, input_length)) {
    return true;
  }
  return false;
}

/*********************************************************************
** Function: one_one
** Description: Scores one one.
** Parameters: int* input_dice, int input_length
** Pre-Conditions: Input is an array of integers.
** Post-Conditions: Returns boolean value.
*********************************************************************/
bool one_one(int* input_dice, int input_length){
  if (input_length == 1 && input_dice[0] == 1) {
    return true;
  } else {
    return false;
  }
}

/*********************************************************************
** Function: one_five
** Description: Scores one five.
** Parameters: int* input_dice, int input_length
** Pre-Conditions: Input is an array of integers.
** Post-Conditions: Returns boolean value.
*********************************************************************/
bool one_five(int* input_dice, int input_length){
  if (input_length == 1 && input_dice[0] == 5) {
    return true;
  } else {
    return false;
  }
}

/*********************************************************************
** Function: three_ones
** Description: Scores three ones.
** Parameters: int* input_dice, int input_length
** Pre-Conditions: Input is an array of integers.
** Post-Conditions: Returns boolean value.
*********************************************************************/
bool three_ones(int* input_dice, int input_length){
  if (input_length == 3 && input_dice[0] == 1 && input_dice[1] == 1 && input_dice[2] == 1) {
    return true;
  } else {
    return false;
  }
}

/*********************************************************************
** Function: three_twos
** Description: Scores three twos.
** Parameters: int* input_dice, int input_length
** Pre-Conditions: Input is an array of integers.
** Post-Conditions: Returns boolean value.
*********************************************************************/
bool three_twos(int* input_dice, int input_length){
  if (input_length == 3 && input_dice[0] == 2 && input_dice[1] == 2 && input_dice[2] == 2) {
    return true;
  } else {
    return false;
  }
}

/*********************************************************************
** Function: three_threes
** Description: Scores three threes.
** Parameters: int* input_dice, int input_length
** Pre-Conditions: Input is an array of integers.
** Post-Conditions: Returns boolean value.
*********************************************************************/
bool three_threes(int* input_dice, int input_length){
  if (input_length == 3 && input_dice[0] == 3 && input_dice[1] == 3 && input_dice[2] == 3) {
    return true;
  } else {
    return false;
  }
}

/*********************************************************************
** Function: three_fours
** Description: Scores three fours.
** Parameters: int* input_dice, int input_length
** Pre-Conditions: Input is an array of integers.
** Post-Conditions: Returns boolean value.
*********************************************************************/
bool three_fours(int* input_dice, int input_length){
  if (input_length == 3 && input_dice[0] == 4 && input_dice[1] == 4 && input_dice[2] == 4) {
    return true;
  } else {
    return false;
  }
}

/*********************************************************************
** Function: three_fives
** Description: Scores three fives.
** Parameters: int* input_dice, int input_length
** Pre-Conditions: Input is an array of integers.
** Post-Conditions: Returns boolean value.
*********************************************************************/
bool three_fives(int* input_dice, int input_length){
  if (input_length == 3 && input_dice[0] == 5 && input_dice[1] == 5 && input_dice[2] == 5) {
    return true;
  } else {
    return false;
  }
}

/*********************************************************************
** Function: three_sixes
** Description: Scores three sixes.
** Parameters: int* input_dice, int input_length
** Pre-Conditions: Input is an array of integers.
** Post-Conditions: Returns boolean value.
*********************************************************************/
bool three_sixes(int* input_dice, int input_length){
  if (input_length == 3 && input_dice[0] == 6 && input_dice[1] == 6 && input_dice[2] == 6) {
    return true;
  } else {
    return false;
  }
}

/*********************************************************************
** Function: four_of_a_kind
** Description: Scores four of any number.
** Parameters: int* input_dice, int input_length
** Pre-Conditions: Input is an array of integers.
** Post-Conditions: Returns boolean value.
*********************************************************************/
bool four_of_a_kind(int* input_dice, int input_length){
  if (input_length == 4 && input_dice[0] == 1 && input_dice[1] == 1 && input_dice[2] == 1 && input_dice[3] == 1) {
    return true;
  } else if (input_length == 4 && input_dice[0] == 2 && input_dice[1] == 2 && input_dice[2] == 2 && input_dice[3] == 2) {
    return true;
  } else if (input_length == 4 && input_dice[0] == 3 && input_dice[1] == 3 && input_dice[2] == 3 && input_dice[3] == 3) {
    return true;
  } else if (input_length == 4 && input_dice[0] == 4 && input_dice[1] == 4 && input_dice[2] == 4 && input_dice[3] == 4) {
    return true;
  } else if (input_length == 4 && input_dice[0] == 5 && input_dice[1] == 5 && input_dice[2] == 5 && input_dice[3] == 5) {
    return true;
  } else if (input_length == 4 && input_dice[0] == 6 && input_dice[1] == 6 && input_dice[2] == 6 && input_dice[3] == 6) {
    return true;
  } else {
    return false;
  }
}

/*********************************************************************
** Function: five_of_a_kind
** Description: Scores five of any number.
** Parameters: int* input_dice, int input_length
** Pre-Conditions: Input is an array of integers.
** Post-Conditions: Returns boolean value.
*********************************************************************/
bool five_of_a_kind(int* input_dice, int input_length){
  if (input_length == 5 && input_dice[0] == 1 && input_dice[1] == 1 && input_dice[2] == 1 && input_dice[3] == 1 && input_dice[4] == 1) {
    return true;
  } else if (input_length == 5 && input_dice[0] == 2 && input_dice[1] == 2 && input_dice[2] == 2 && input_dice[3] == 2 && input_dice[4] == 2) {
    return true;
  } else if (input_length == 5 && input_dice[0] == 3 && input_dice[1] == 3 && input_dice[2] == 3 && input_dice[3] == 3 && input_dice[4] == 3) {
    return true;
  } else if (input_length == 5 && input_dice[0] == 4 && input_dice[1] == 4 && input_dice[2] == 4 && input_dice[3] == 4 && input_dice[4] == 4) {
    return true;
  } else if (input_length == 5 && input_dice[0] == 5 && input_dice[1] == 5 && input_dice[2] == 5 && input_dice[3] == 5 && input_dice[4] == 5) {
    return true;
  } else if (input_length == 5 && input_dice[0] == 6 && input_dice[1] == 6 && input_dice[2] == 6 && input_dice[3] == 6 && input_dice[4] == 6) {
    return true;
  } else {
    return false;
  }
}

/*********************************************************************
** Function: six_of_a_kind
** Description: Scores six of any number.
** Parameters: int* input_dice, int input_length
** Pre-Conditions: Input is an array of integers.
** Post-Conditions: Returns boolean value.
*********************************************************************/
bool six_of_a_kind(int* input_dice, int input_length){
  if (input_length == 6 && input_dice[0] == 1 && input_dice[1] == 1 && input_dice[2] == 1 && input_dice[3] == 1 && input_dice[4] == 1 && input_dice[5] == 1) {
    return true;
  } else if (input_length == 6 && input_dice[0] == 2 && input_dice[1] == 2 && input_dice[2] == 2 && input_dice[3] == 2 && input_dice[4] == 2 && input_dice[5] == 2) {
    return true;
  } else if (input_length == 6 && input_dice[0] == 3 && input_dice[1] == 3 && input_dice[2] == 3 && input_dice[3] == 3 && input_dice[4] == 3 && input_dice[5] == 3) {
    return true;
  } else if (input_length == 6 && input_dice[0] == 4 && input_dice[1] == 4 && input_dice[2] == 4 && input_dice[3] == 4 && input_dice[4] == 4 && input_dice[5] == 4) {
    return true;
  } else if (input_length == 6 && input_dice[0] == 5 && input_dice[1] == 5 && input_dice[2] == 5 && input_dice[3] == 5 && input_dice[4] == 5 && input_dice[5] == 5) {
    return true;
  } else if (input_length == 6 && input_dice[0] == 6 && input_dice[1] == 6 && input_dice[2] == 6 && input_dice[3] == 6 && input_dice[4] == 6 && input_dice[5] == 6) {
    return true;
  } else {
    return false;
  }
}

/*********************************************************************
** Function: straight
** Description: Scores a 1-6 straight.
** Parameters: int* input_dice, int input_length
** Pre-Conditions: Input is an array of integers.
** Post-Conditions: Returns boolean value.
*********************************************************************/
bool straight(int* input_dice, int input_length){
  int counter = 0;
  for (int i = 0; i < input_length; i++){
    for (int j = 0; j < input_length; j++){
      if (input_dice[i] == input_dice[j]){
        counter++;
      }
    }
  }
  if (counter == 6){
    return true;
  } else {
    return false;
  }
}

/*********************************************************************
** Function: three_pairs
** Description: Scores three pairs.
** Parameters: int* input_dice, int input_length
** Pre-Conditions: Input is an array of integers.
** Post-Conditions: Returns boolean value.
*********************************************************************/
bool three_pairs(int* input_dice, int input_length){
  int counter = 0;
  for (int i = 0; i < input_length; i++){
    for (int j = 0; j < input_length; j++){
      if (input_dice[i] == input_dice[j]){
        counter++;
      }
    }
  }
  if (counter == 12){
    return true;
  } else {
    return false;
  }
}

/*********************************************************************
** Function: four_of_a_kind_and_a_pair
** Description: Scores four of a kind and a pair.
** Parameters: int* input_dice, int input_length
** Pre-Conditions: Input is an array of integers.
** Post-Conditions: Returns boolean value.
*********************************************************************/
bool four_of_a_kind_and_a_pair(int* input_dice, int input_length){
  int counter = 0;
  for (int i = 0; i < input_length; i++){
    for (int j = 0; j < input_length; j++){
      if (input_dice[i] == input_dice[j]){
        counter++;
      }
    }
  }
  if (counter == 20){
    return true;
  } else {
    return false;
  }
}

/*********************************************************************
** Function: two_triplets
** Description: Scores two triplets.
** Parameters: int* input_dice, int input_length
** Pre-Conditions: Input is an array of integers.
** Post-Conditions: Returns boolean value.
*********************************************************************/
bool two_triplets(int* input_dice, int input_length){
  int counter = 0;
  for (int i = 0; i < input_length; i++){
    for (int j = 0; j < input_length; j++){
      if (input_dice[i] == input_dice[j]){
        counter++;
      }
    }
  }
  if (counter == 18){
    return true;
  } else {
    return false;
  }
}

/*********************************************************************
** Function: get_int
** Description: Returns string as an integer.
** Parameters: String input.
** Pre-Conditions: Input is a string.
** Post-Conditions: Returns integer.
*********************************************************************/
int get_int (string input){
  int returnValue = 0;
  for (int i = 0; i < input.length(); i++) {
    returnValue += ((input[i] - '0') * (pow(10, input.length() - i - 1)));
  }
  return returnValue;
}
