#ifndef PERSON_HPP_
#define PERSON_HPP_

using namespace std;

class Person {
	protected:
		string name;
		int age;
		string person_type;
	public:
		virtual string get_name();
		virtual void set_name(string);
		virtual int get_age();
		virtual void set_age(int);
		virtual double get_GPA() {}
		virtual void set_GPA(double) {}
		virtual double get_rating() {}
		virtual void set_rating(double) {}
		virtual string get_person_type();
		virtual void do_work() {}
};

#endif
