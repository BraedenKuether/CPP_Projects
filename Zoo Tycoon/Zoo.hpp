
#ifndef ZOO_HPP_
#define ZOO_HPP_

#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"

using namespace std;

class Zoo {
  private:
    int feed_type;
    int bonus;
    int day;
    int money;
    int tiger_num;
    int penguin_num;
    int turtle_num;
    Tiger* tiger_arr;
    Penguin* penguin_arr;
    Turtle* turtle_arr;
    int tiger_arr_length;
    int penguin_arr_length;
    int turtle_arr_length;
  public:
    Zoo();
    void increment_ages();
    void game();
    void initial_animal_purchase();
    void animal_purchase();
    void feed_animals();
    void calculate_income();
    void set_tiger_num(int);
    int get_tiger_num();
    void set_penguin_num(int);
    int get_penguin_num();
    void set_turtle_num(int);
    int get_turtle_num();
    void resize_tiger_arr(int);
    void resize_penguin_arr(int);
    void resize_turtle_arr(int);
    void random_event();
    void random_sickness();
    void random_boom();
    void random_baby();
    bool keep_playing();
    bool menu_input_validation(string input);
    void delete_arrs();
    int get_int(string);
    void print();
    void buy();
    bool buy_input_validation(string input);
    void get_feed_type();
    bool feed_input_validation(string input);
};

#endif
