#ifndef INSTRUCTOR_HPP_
#define INSTRUCTOR_HPP_
#include "Person.hpp"

using namespace std;

class Instructor : public Person {
	private:
		double rating;
	public: 
		Instructor();
		double get_rating();
		void set_rating(double);
		virtual void do_work();
};

#endif
