//This is a standard linked list, only with the functionality to add an object to the list and display.

#pragma once

#include <string>
#include <iostream>


using namespace std;
class linkedList {
private:
	//The Node setup
	struct node {
		node(string datum, node* prev) {
			data = datum;
			next = prev;
		}
		string data;
		node* next;
	};

	node* head;
public:
	//Constructor initializing all of the variables needed	
	linkedList() {
		head = NULL;
	}

	//Goes through and deconstructs the files
	~linkedList() {
		while (head != NULL) {
			node* next = head->next;
			delete (head);
			head = next;
		}
	}

	//Insert an object to the front of the linked list taking the item that you want to add
	void insert(string data) {
		head = new node(data, head);
	}


	//Display all of the elements inside of the linked list
	void display() {
		node*temp = head;
		cout << "[ ";
		while (temp != NULL) {
			cout << temp->data;
			temp = temp->next;
			if (temp != NULL) {
				cout << " , ";
			}
		}
		cout << " ]" << endl;
	}




};
