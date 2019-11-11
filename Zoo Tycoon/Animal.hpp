
#ifndef ANIMAL_HPP_
#define ANIMAL_HPP_

using namespace std;

class Animal {
  protected:
    int age;
    int cost;
    int num_babies;
    double base_food;
    double payoff;
  public:
    Animal();
    virtual void set_age(int);
    virtual int get_age();
    virtual int get_cost();
    virtual int get_base_food();
    virtual int get_num_babies();
    virtual double get_payoff();
};

#endif

