/*

Linked List Project
Created by Braeden Kuether
Sunday, August 5th 2018

*/

#include <iostream>
#include "QueueNode.hpp"
#include "Queue.hpp"

using namespace std;

//Constructor, sets the head of the queue to null.
Queue::Queue(){
	head = NULL;
}

//Returns whether of not the queue is empty, base on the status of the head. 
bool Queue::isEmpty() {
	if (head == NULL) {				//If head is null, queue is empty. 
		return true;
	} 
	else {
		return false;
	}
}

void Queue::addBack(int val) {
	QueueNode* node = new QueueNode;		//Create pointer.
	cout << endl;
	node -> next = NULL;				//Making the fallowing value null.
	node -> val = val;				//Setting the value of the node.

	if (isEmpty()){					//Checks to see if queue is empty.
		head = node;
		return;
	} 

	else {
		QueueNode* temp = head;			//Set temp value equal to head. 

		while (temp -> next != NULL) {
			temp = temp -> next;		//While loop until you find the end of the list, replacing temp with following node.  
		}

		temp -> next = node;			//Next value is set equal to node. 
		node -> prev = temp;
	}
}

//Getter function for head value.
int Queue::getFront(){
	return head -> val;
}

//Removes from the front of the list. 
void Queue::removeFront(){
	QueueNode* temp;
	temp = head;					//Temp variable set equal to head. 
	head = temp -> next;
	head -> prev = NULL;				//Setting front to null.
	delete [] temp;
}

//Prints queue.
void Queue::printQueue(){
	if (isEmpty()) {				//Checks to see if list is empty.
		cout << "Empty list." << endl;
		return;
	}

	else {
		cout << "Your queue is: ";		
		cout << head -> val;
		QueueNode* temp = head -> next;		//Temp variable equal to next value after head.

		while (temp != NULL) {			//While loop until end of list printing out values at each position. 
			cout << " " << temp -> val;
			temp = temp -> next;
		}

		cout << endl;
	}
}

//Deconstructor, deletes all of the pointers. 
Queue::~Queue() {
	QueueNode* temp = head;
	QueueNode* temp2;

	while (temp != NULL) {
		temp2 = temp -> next;
		delete [] temp;
		temp = NULL;
		temp = temp2;
	}
}
