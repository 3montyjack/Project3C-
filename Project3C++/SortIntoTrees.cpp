#pragma once
#include <fstream>
#include <string>
#include <vector>

#include "AVLTree.h"
#include "LinkedList.cpp"


using namespace std;
class SortIntoTrees {
private:

	linkedList shared;
	linkedList unshared;
	avlTree tree1;
	avl_node* newRoot;
public:

	SortIntoTrees() {
		newRoot = NULL;
	}


	void insertFirstList(string value) {
		newRoot = tree1.insert(newRoot, value);
	}

	void insertSecondList(string value) {
		if (!tree1.locate(newRoot, value)) {
			unshared.insert(value);
		} else {
			newRoot = tree1.remove(newRoot, value);
			shared.insert(value);
		}
	}

	void display() {
		string* list = new string();
		tree1.display(newRoot, 1);
		cout << endl;
		cout << "Shared List: ";
		shared.display();
		cout << "List they have in common: ";	
		unshared.display();
		cout << tree1.displayInOrder(newRoot, list);
	}

};
