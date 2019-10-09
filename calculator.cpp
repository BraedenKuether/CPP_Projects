/*********************************************************************
** Program Filename: calculator.cpp
** Author: Braeden Kuether
** Date: February 20, 2018
** Description: Calculator, (standard, binary to decimal, decimal to binary, grade).
** Input: User interface requires limited amount of input (0s and 1s, or strings.)
** Output: Return calculation on strings input.
*********************************************************************/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool first_input_number(string);
bool correct_characters(string);
bool spacing(string);
bool operator_spacing(string);
bool float_point(string);
bool is_valid_calculator(string);
void decimal_to_binary();
void binary_to_decimal();
bool double_decimal_check_3 (string);
int second_decimal(int, int, string);
int first_decimal(string);
int first_space(string, int);
int number_of_spaces(string);
bool double_decimal_check_2(string);
bool double_decimal_check(string);
float get_float(string);
bool is_valid_grade(string);
float grade_calculator();
float third_string_calculation(string);
float second_string_calculation(string);
float first_string_calculation(string);
float second_string_second_number_return_value(string);
float first_string_second_number_return_value(string);
int first_string_operator_value(string);
float first_string_first_number_return_value(string);
string identify_second_string(string);
string identify_first_string(string);
float standard_calculator();
void standard_calculator_prompt();
void user_interface();
void string_to_int(int);
float calculator_return_value (float, float, int);
bool test_1_0(string);

int main(){
  user_interface();
  return 0;
}

/*********************************************************************
** Function: first_input_number
** Description: Indicates if the first input is a number.
** Parameters: string input
** Pre-Conditions: Input is a string.
** Post-Conditions: Returns boolean value.
*********************************************************************/
bool first_input_number(string input){
  for (int i = 0; i < 1; i++) {
    if (input[i] > 47 && input[i] < 58) {
      return true;
    } else {
      return false;
    }
  }
}

/*********************************************************************
** Function: correct_characters
** Description: Indicates if the string uses correct characters.
** Parameters: string input
** Pre-Conditions: Input is a string.
** Post-Conditions: Returns boolean value.
*********************************************************************/
bool correct_characters(string input){
  for (int i = 0; i < input.length(); i++) {
    if (input[i] < 46 || input[i] > 57) {
      if (input[i] != 47 && input[i] != 43 && input[i] != 45 && input[i] != 42){
        if (input[i] != 32){
          return false;
        }
      }
    }
  }
  return true;
}

/*********************************************************************
** Function: spacing
** Description: Indicates if there is one space before and after each operator.
** Parameters: string input
** Pre-Conditions: Input is a string.
** Post-Conditions: Returns boolean value.
*********************************************************************/
bool spacing(string input){
  for (int i = 0; i < input.length(); i++) {
    if (input[i] == 47 || input[i] == 43 || input[i] == 45 || input[i] == 42) {
      if (input[i - 1] == 32 && input[i + 1] == 32){
        if (input[i - 2] < 48 || input[i - 2] > 58) {
          return false;
        } else if (input[i + 2] < 48 || input[i + 2] > 58) {
          return false;
        }
      } else {
        return false;
      }
    }
  }
  return true;
}

/*********************************************************************
** Function: operator_spacing
** Description: Indicates if there is an operator after a number followed by a space.
** Parameters: string input
** Pre-Conditions: Input is a string.
** Post-Conditions: Returns boolean value.
*********************************************************************/
bool operator_spacing(string input){
  bool flag = true;
  int counter = 0;
  for (int i = 0; i < input.length(); i++) {
    if (input[i] == 32) {
      counter++;
    }
    if (input[i] == 32 && input[i - 1] > 47 && input[i - 1] < 58){
      if (input[i + 1] == 47 || input[i + 1] == 43 || input[i + 1] == 45 || input[i + 1] == 42){
        flag = true;
      } else {
        return false;
      }
    }
  }
  if (counter == 0) {
    return false;
  }
  if (flag == true){
    return true;
  }
}

/*********************************************************************
** Function: float_point
** Description: Indicates if there is a number before and after each '.' character.
** Parameters: string input
** Pre-Conditions: Input is a string.
** Post-Conditions: Returns boolean value.
*********************************************************************/
bool float_point(string input){
  bool flag = true;
  for (int i = 0; i < input.length(); i++) {
    if (input[i] == 46) {
      if (input[i - 1] < 48 || input[i - 1] > 57){
        return false;
      } else if (input[i + 1] < 48 || input[i + 1] > 58){
        return false;
      }
    }
  }
    return true;
}

/*********************************************************************
** Function: is_valid_calculator
** Description: Indicates if a given string is a valid input.
** Parameters: string input
** Pre-Conditions: Input is a string.
** Post-Conditions: Returns boolean value.
*********************************************************************/
bool is_valid_calculator(string input){
  if (first_input_number(input) && correct_characters(input) && float_point(input)){
  } else {
    return false;
  }
  if (spacing(input) && operator_spacing(input)) {
  } else {
    return false;
  }
  if (double_decimal_check(input) << double_decimal_check_2(input) << double_decimal_check_3(input)) {
  } else {
    return false;
  }
  return true;
}

/*********************************************************************
** Function: is_valid_binary_to_decimal
** Description: Indicates if a given string is a valid input.
** Parameters: string input
** Pre-Conditions: Input is a string.
** Post-Conditions: Returns boolean value.
*********************************************************************/
bool is_valid_binary_to_decimal(string input){
  bool flag = true;
  for (int i = 0; i < 1; i++) {
    if (input[i] != 49){
      return false;
    }
  }
  for (int i = 0; i < input.length(); i++){
    if (input[i] != 49 && input[i] != 48) {
      return false;
    }
  }
  return true;
}

/*********************************************************************
** Function: is_valid_decimal_to_binary
** Description: Indicates if a given string is a valid input.
** Parameters: string input
** Pre-Conditions: Input is a string.
** Post-Conditions: Returns boolean value.
*********************************************************************/
bool is_valid_decimal_to_binary(string input){
  for (int i = 0; i < input.length(); i++){
    if (input[i] < 48 || input[i] > 57) {
      return false;
    }
  }
  return true;
}

/*********************************************************************
** Function: decimal_to_binary
** Description: User inputs decimal and binary is returned.
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: Return type void.
*********************************************************************/
void decimal_to_binary() {
  int s_to_i = 0;
  string input = "";
  do {
    input = "";
    cout << "Enter a decimal value: " << endl;
    getline(cin,input);
  } while (is_valid_decimal_to_binary(input) == false);
  for (int i = 0; i < input.length(); i++) {
    s_to_i += ((input[i] - '0') * (pow(10, input.length() - i - 1)));
  }
  string_to_int(s_to_i);
}

/*********************************************************************
** Function: decimal_to_binary
** Description: User inputs decimal and binary is returned.
** Parameters: int s_to_i
** Pre-Conditions: input must be an int.
** Post-Conditions: Return type void.
*********************************************************************/
void string_to_int(int s_to_i) {
  int returnValue = 0;
  int loop_counter = 1;
  int x = 0;
  do {
    x = (s_to_i % 2);
    returnValue += (x * (pow(10, loop_counter - 1)));
    loop_counter ++;
    s_to_i = (s_to_i / 2);
  } while (s_to_i != 0);
  cout << returnValue << endl;
}


/*********************************************************************
** Function: binary_to_decimal
** Description: User inputs binary and decimal is returned.
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: Return type void.
*********************************************************************/
void binary_to_decimal() {
  int returnValue = 0;
  int x;
  string input = "";
  do {
    input = "";
    cout << "Enter a binary value: ";
    getline(cin,input);
  } while (is_valid_binary_to_decimal(input) == false);
  for (int i = 0; i < input.length(); i++) {
    x = (pow (2, (input.length() - i - 1)));
    returnValue += (x * (input[i] - '0'));
  }
  cout << returnValue << endl;
}

/*********************************************************************
** Function: double_decimal_check
** Description: Checks if an input has a float with multiple deecimal points.
** Parameters: string input
** Pre-Conditions: Must input a string.
** Post-Conditions: Return type boolean.
*********************************************************************/
bool double_decimal_check(string input){
  int number_of_points = 0;
  int x = 0;
  for (int m = 0; m < input.length(); m++){
    if (input[m] == 46){
      number_of_points++;
    }
  }
  if ((first_decimal(input) < first_space(input,first_decimal(input))) && (number_of_spaces(input) > 2)){
     if (number_of_points > (number_of_spaces(input) - 1)) {
       return false;
    }
  }
  if (first_decimal(input) < first_space(input,first_decimal(input))) {
    if ((number_of_spaces(input)) < number_of_points){
      return false;
    } else {
      return true;
    }
  }
  return true;
}

/*********************************************************************
** Function: double_decimal_check_2
** Description: Checks if an input has a float with multiple deecimal points.
** Parameters: string input
** Pre-Conditions: Must input a string.
** Post-Conditions: Return type boolean.
*********************************************************************/
bool double_decimal_check_2(string input){
  int number_of_points = 0;
  for (int m = 0; m < input.length(); m++){
    if (input[m] == 46){
      number_of_points++;
    }
  }
  if (number_of_points < 2) {
    return true;
  }
  if ((second_decimal(first_decimal(input),first_space(input,first_decimal(input)),input))
  < (first_space(input,first_decimal(input)))) {
    return false;
  }
  return true;
}

/*********************************************************************
** Function: double_decimal_check_3
** Description: Checks if an input has a float with multiple deecimal points.
** Parameters: string input
** Pre-Conditions: Must input a string.
** Post-Conditions: Return type boolean.
*********************************************************************/
bool double_decimal_check_3 (string input) {
  for (int b = 0; b < input.length(); b++){
    if (input[b] == 46){
      if (input[b + 1] == 46 || input[b + 2] == 46 || input[b + 3] == 46 || input[b + 4] == 46){
        return false;
      }
    }
  }
  return true;
}

/*********************************************************************
** Function: number_of_spaces
** Description: Identifies the number of spaces in a string.
** Parameters: string input
** Pre-Conditions: Must input a string.
** Post-Conditions: Return type integer.
*********************************************************************/
int number_of_spaces(string input) {
  int spaces = 0;
  for (int l = 0; l < input.length(); l++){
    if (input[l] == 32){
      spaces++;
    }
  }
  return spaces;
}

/*********************************************************************
** Function: first_space
** Description: Locates the position of the first space in a string.
** Parameters: string input, int first_decimal_place
** Pre-Conditions: Must input a string and an integer.
** Post-Conditions: Return type integer.
*********************************************************************/
int first_space(string input, int first_decimal_place) {
  int first_space_after = 0;
  for (int k = 0; k < input.length(); k++) {
    if (k > first_decimal_place && input[k] == 32){
      first_space_after = k;
      return first_space_after;
    }
  }
}

/*********************************************************************
** Function: first_decimal
** Description: Locates the position of the first decimal point in a string.
** Parameters: string input
** Pre-Conditions: Must input a string.
** Post-Conditions: Return type integer.
*********************************************************************/
int first_decimal(string input) {
  int first_decimal_place = 0;
  for (int i = 0; i < input.length(); i++) {
    if (input[i] == 46) {
      first_decimal_place = i;
      return first_decimal_place;
    }
  }
}

/*********************************************************************
** Function: second_decimal
** Description: Locates the position of the second decimal point in a string.
** Parameters: int first_decimal_place, int first_space_after, string input
** Pre-Conditions: Must input two valid integers, and a string.
** Post-Conditions: Return type integer.
*********************************************************************/
int second_decimal(int first_decimal_place, int first_space_after, string input) {
  int second_decimal_place = 0;
  for (int j = 0; j < input.length(); j++) {
    second_decimal_place = first_space_after + 1;
    if ((j > first_decimal_place) && input[j] == 46){
      second_decimal_place = j;
      return second_decimal_place;
    }
  }
}

/*********************************************************************
** Function: is_valid_grade
** Description: Determines if user input is valid.
** Parameters: string input
** Pre-Conditions: Must input a string.
** Post-Conditions: Return type boolean.
*********************************************************************/
bool is_valid_grade(string input) {
  int first_decimal_place = 0;
  first_decimal_place = first_decimal(input);
  for (int i = 0; i < input.length(); i++) {
    if ((input[i] < 48 || input[i] > 57) && input[i] != 46) {
      return false;
    }
    if (input[i] == 46 && i > first_decimal_place) {
      return false;
    }
  }
  return true;
}

/*********************************************************************
** Function: get_float
** Description: Takes a prompt from the user as a string literal, checks if input is a valid float, returns the provided float.
** Parameters: string prompt
** Pre-Conditions: Input is a string.
** Post-Conditions: Returns float.
*********************************************************************/
float get_float (string input){
  float leftSide = 0.0;
  float rightSide = 0.0;
  int leftSideLgth = 0;
  int rightSideLgth = 0;
  bool check = true;
  bool period = false;
  int periodSpot = 0;
  float returnValue = 0.0;
  for (int i = 0; i < input.length(); i++) {
    if (input[i] == 46) {
      period = true;
      periodSpot = i;
      continue;
    }
    if (!period) {
      leftSideLgth ++;

    } else {
      rightSideLgth ++;
    }
  } for (int j = 0; j < input.length(); j++) {
    if (periodSpot == 0) {
      periodSpot = leftSideLgth + 1;
      rightSideLgth = 0;
    }
  }
  for (int i = 0; i < input.length(); i++) {
    if (i == periodSpot) {
    }
    if (i < leftSideLgth) {
      leftSide += ((input[i] - '0') * (pow(10, leftSideLgth - i - 1)));
    }
    if (i > periodSpot){
        rightSide += ((input[i] - '0') / (pow(10, (i - leftSideLgth))));
    }
  }
  returnValue = leftSide + rightSide;
  return returnValue;
}

/*********************************************************************
** Function: grade_calculator
** Description: Takes prompts from user to calculate grade.
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: Returns float.
*********************************************************************/
float grade_calculator(){
  float total_grade = 0.0, grades_enterred = 0.0, final_grade = 0.0, weight = 100.0;
  string decision = "", input = "", input_cont = "";
  do {
    decision = "";
    input_cont = "";
    do {
      string input = "";
      cout << "Please enter a grade as a float: ";
      getline(cin,input);
      input_cont = input;
    } while (!is_valid_grade(input));
    total_grade += get_float(input_cont);
    do {
      cout << "Would you like to enter another grade (1 - yes, 0 - no)?";
      getline(cin,decision);
    } while (test_1_0(decision) == false);
    grades_enterred++;
  } while (decision == "1");
  final_grade = (total_grade / grades_enterred);
  cout << "Please enter a weight: ";
  cin >> weight;
  cout << "Total percentage = " << final_grade * (weight / 100) << endl;
  return final_grade;
}

/*********************************************************************
** Function: third_string_calculation
** Description: Takes a prompt from the user as a string literal,
calculates what user enterred.
** Parameters: string input
** Pre-Conditions: Input is a string.
** Post-Conditions: Returns float.
*********************************************************************/
float third_string_calculation(string input){
  float first_number = 0.0;
  first_number = second_string_calculation(identify_second_string(input));
  float second_number = 0.0;
  string second_operator = "";
  for (int i = 0; i < input.length(); i++){
    if (i >= (identify_second_string(input)).length() - 1) {
       second_operator = second_operator + input[i];
    }
  }
  int calc_operator = 0;
  calc_operator = first_string_operator_value(second_operator);
  second_number = second_string_second_number_return_value(second_operator);
  return calculator_return_value(first_number, second_number, calc_operator);
}

/*********************************************************************
** Function: second_string_calculation
** Description: Takes a prompt from the user as a string literal,
calculates what user enterred.
** Parameters: string input
** Pre-Conditions: Input is a string.
** Post-Conditions: Returns float.
*********************************************************************/
float second_string_calculation(string input){
  float first_number = 0.0;
  first_number = first_string_calculation(identify_first_string(input));
  float second_number = 0.0;
  string second_operator = "";
  for (int i = 0; i < input.length(); i++){
    if (i >= (identify_first_string(input)).length()) {
       second_operator = second_operator + input[i];
    }
  }
  int calc_operator = 0;
  calc_operator = first_string_operator_value(second_operator);
  second_number = second_string_second_number_return_value(second_operator);
  return calculator_return_value(first_number, second_number, calc_operator);
}

/*********************************************************************
** Function: first_string_calculation
** Description: Takes a prompt from the user as a string literal,
calculates what user enterred.
** Parameters: string input
** Pre-Conditions: Input is a string.
** Post-Conditions: Returns float.
*********************************************************************/
float first_string_calculation(string input){
  float first_number = 0.0;
  first_number = first_string_first_number_return_value(input);
  float second_number = 0.0;
  second_number = first_string_second_number_return_value(input);
  int calc_operator = 0;
  calc_operator = first_string_operator_value(input);
  return calculator_return_value(first_number, second_number, calc_operator);
}

/*********************************************************************
** Function: calculator_return_value
** Description: completes calculation of standard calculator.
** Parameters: float first_number, float second_number, int calc_operator
** Pre-Conditions: Input is two floats, and an integer
** Post-Conditions: Returns float.
*********************************************************************/
float calculator_return_value(float first_number, float second_number, int calc_operator){
  if (calc_operator == 1){
    return (first_number * second_number);
  } else if (calc_operator == 2){
    return (first_number + second_number);
  } else if (calc_operator == 3){
    return (first_number - second_number);
  } else if (calc_operator == 4){
    return (first_number / second_number);
  }
}

/*********************************************************************
** Function: second_string_second_number_return_value
** Description: Takes a prompt from the user as a string literal,
returns value of second float in string.
** Parameters: string input
** Pre-Conditions: Input is a string.
** Post-Conditions: Returns float.
*********************************************************************/
float second_string_second_number_return_value(string input){
  string second_float = "";
  string x = "";
  int counter = 0;
  int second_number = 0;
  for (int i = 0; i < input.length(); i++){
    if (input[i] == 32){
      counter++;
    }
    if (counter == 2){
      second_number = i;
      break;
    }
  }
  for (int j = 0; j < input.length(); j++){
    if (second_number < j){
      second_float = second_float + input[j];
    }
  }
  return get_float(second_float);
}

/*********************************************************************
** Function: first_string_second_number_return_value
** Description: Takes a prompt from the user as a string literal,
returns value of second float in string.
** Parameters: string input
** Pre-Conditions: Input is a string.
** Post-Conditions: Returns float.
*********************************************************************/
float first_string_second_number_return_value(string input){
  string second_float = "";
  string x = "";
  int counter = 0;
  int second_number = 0;;
  for (int i = 0; i < input.length(); i++){
    if (input[i] == 32){
      counter++;
    }
    if (counter == 2){
      second_number = i;
      break;
    }
  }
  for (int j = 0; j < input.length(); j++){
    if (second_number < j){
      second_float = second_float + input[j];
    }
  }
  return get_float(second_float);
}

/*********************************************************************
** Function: first_string_operator_value
** Description: Takes a prompt from the user as a string literal,
returns first operator.
** Parameters: string input
** Pre-Conditions: Input is a string.
** Post-Conditions: Returns int.
*********************************************************************/
int first_string_operator_value(string input){
  for (int i = 0; i < input.length(); i++) {
    if (input[i] == 42) {
      return 1;
    }
    if (input[i] == 43) {
      return 2;
    }
    if (input[i] == 45) {
      return 3;
    }
    if (input[i] == 47) {
      return 4;
    }
  }
}

/*********************************************************************
** Function: first_string_first_number_return_value
** Description: Takes a prompt from the user as a string literal,
returns value of first float in string.
** Parameters: string input
** Pre-Conditions: Input is a string.
** Post-Conditions: Returns float.
*********************************************************************/
float first_string_first_number_return_value(string input){
  string first_float = "";
  int second_number = 0;
  for (int i = 0; i < input.length(); i++){
    if (input[i] == 32){
      second_number = i;
      break;
    }
  }
  for (int j = 0; j < second_number; j++){
    first_float = first_float + input[j];
  }
  return get_float(first_float);
}

/*********************************************************************
** Function: identify_second_string
** Description: Takes a prompt from the user as a string literal, identifies
second calculation string.
** Parameters: string input
** Pre-Conditions: Input is a string.
** Post-Conditions: Returns string.
*********************************************************************/
string identify_second_string(string input){
  string first_string = "";
  int counter = 0;
  int second_number = 0;
    for (int i = 0; i < input.length(); i++){
      if (input[i] == 32){
        counter++;
      }
      if (counter == 5){
        second_number = i - 1;
        break;
      }
    }
    for (int i = 0; i < input.length(); i++){
      first_string = first_string + input[i];
      if (i == (second_number)){
        break;
      }
    }
  return first_string;
}

/*********************************************************************
** Function: identify_first_string
** Description: Takes a prompt from the user as a string literal, identifies
first calculation string.
** Parameters: string input
** Pre-Conditions: Input is a string.
** Post-Conditions: Returns string.
*********************************************************************/
string identify_first_string(string input){
  string first_string = "";
  int counter = 0;
  int second_number = 0;
    for (int i = 0; i < input.length(); i++){
      if (input[i] == 32){
        counter++;
      }
      if (counter == 3){
        second_number = i - 1;
        break;
      }
    }
    for (int i = 0; i < input.length(); i++){
      first_string = first_string + input[i];
      if (i == (second_number)){
        break;
      }
    }
  return first_string;
}

/*********************************************************************
** Function: standard_calculator
** Description: Takes a prompt from the user as a string literal, returns float of calculation.
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: Returns float.
*********************************************************************/
float standard_calculator(){
  string input_1 = "";
  string input = "";
  bool check = false;
  int numb_of_spaces = 0;
  do {
    check = false;
    input_1 = "";
    input = "";
    cout << "Please enter a standard calculation: ";
    getline(cin,input_1);
    cout << endl;
    check = is_valid_calculator(input_1);
    input = input_1;
  } while (!check);
  numb_of_spaces = number_of_spaces(input);
  if (numb_of_spaces == 0){
    return get_float(input);
  } else if (numb_of_spaces == 2){
    return first_string_calculation(input);
  } else if (numb_of_spaces == 4){
    return second_string_calculation(input);
  } else if (numb_of_spaces == 6){
    return third_string_calculation(input);
  } else {
    cout << "Calculator can only handle 3 operators" << endl;
  }
}

/*********************************************************************
** Function: standard_calculator_prompt
** Description: Prompts standard calculator.
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: Void.
*********************************************************************/
void standard_calculator_prompt(){
  string decision = "";
  do {
    cout << standard_calculator() << endl;
    do {
      cout << "Would you like to do another standard calculation? (1 - yes, 0 - no): ";
      getline(cin,decision) >> decision;
    } while (test_1_0(decision) == false);
    cout << endl;
  } while (decision == "1");
}

/*********************************************************************
** Function: user_interface()
** Description: Prompts user for which calculator to use.
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: Void.
*********************************************************************/
void user_interface() {
  bool check = true;
  do {
    int user_input = 0;
    bool check = true;
    cout << "Enter 1 to do a standard calculation, 2 to convert from binary to decimal, "
    << "3 to convert from decimal to binary, or 4 to calculate a grade: ";
    cin >> user_input;
    cin.clear();
    cin.ignore();
    cout << endl;
    if (user_input == 1) {
      standard_calculator_prompt();
    } else if (user_input == 2) {
      binary_to_decimal();
    } else if (user_input == 3) {
      decimal_to_binary();
    } else if (user_input == 4) {
      grade_calculator();
    } else {
      check = false;
    }
  } while (check == false);
}

/*********************************************************************
** Function: test_1_0
** Description: Checks user input if they would like to repeat.
** Parameters: string input
** Pre-Conditions: string
** Post-Conditions: boolean return type. 
*********************************************************************/
bool test_1_0(string input) {
  if (input.length() > 1) {
    return false;
  }
  for (int i = 0; i < 1; i++) {
    if (input[i] != 49 && input[i] != 48){
      return false;
    }
  }
  return true;
}
