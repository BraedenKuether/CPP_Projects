#ifndef STUDENT_HPP_
#define STUDENT_HPP_
#include "Person.hpp"

using namespace std;

class Student : public Person {
	private:
		double GPA;
	public:
		Student();
		double get_GPA();
		void set_GPA(double);
		virtual void do_work();
};

#endif
