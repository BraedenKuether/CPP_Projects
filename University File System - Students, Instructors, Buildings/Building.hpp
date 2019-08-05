#ifndef BUILDING_HPP_
#define BUILDING_HPP_

using namespace std;

class Building {
	private:
		string name;
		int size;
		string address;
	public:
		string get_name();
		void set_name(string);
		int get_size();
		void set_size(int);
		string get_address();
		void set_address(string);
};

#endif