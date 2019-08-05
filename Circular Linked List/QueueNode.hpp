/*

Linked List Project
Created by Braeden Kuether
Sunday, August 5th 2018

*/

#ifndef NODEBOI_HPP
#define NODEBOI_HPP
#include "Queue.hpp"

using namespace std;

class Queue {
	private:
		QueueNode* head;
	public:
		Queue();
		~Queue();
		bool isEmpty();
		void addBack(int val);
		int getFront();
		void removeFront();
		void printQueue();
};

#endif
