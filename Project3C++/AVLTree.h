
#pragma once

#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>

#define POW2(n) (1 << (n))

using namespace std;

/*
* Node Declaration
*/
struct avl_node {
	string data;
	struct avl_node *left = NULL;
	struct avl_node *right = NULL;
	//Need to update this everywhere
	struct avl_node *parent = NULL;
	//Same here
	int height = 1;
}*root;


/*
* Class Declaration
*/
class avlTree {
private:
	string* line = new string();

	void deleteTree(avl_node* root) {
		if (root != NULL) {
			deleteTree(root->left);
			deleteTree(root->right);
			delete(root);
		}
	}

public:


	avlTree() {
		root = NULL;
	}
	~avlTree() {
		deleteTree(root);
	}

	/*
	* Height of AVL Tree
	*/
	int height(avl_node *temp) {
		int h = 0;
		if (temp != NULL) {
			int l_height = height(temp->left);
			int r_height = height(temp->right);
			int max_height = max(l_height, r_height);
			h = max_height + 1;
		}
		return h;
	}

	/*
	* Height Difference
	*/
	int diff(avl_node *temp) {
		int l_height = height(temp->left);
		int r_height = height(temp->right);
		int b_factor = l_height - r_height;
		return b_factor;
	}

	/*
	* Right- Right Rotation
	*/
	avl_node* rr_rotation(avl_node *parent) {
		cout << "RR Rotation" << endl;
		avl_node* temp;
		temp = parent->right;
		parent->right = temp->left;
		temp->left = parent;
		return temp;
	}
	/*
	* Left- Left Rotation
	*/
	avl_node* ll_rotation(avl_node *parent) {
		cout << "LL Rotation" << endl;
		avl_node* temp;
		temp = parent->left;
		parent->left = temp->right;
		temp->right = parent;
		return temp;
	}

	/*
	* Left - Right Rotation
	*/
	avl_node* lr_rotation(avl_node *parent) {
		//take bottom, that is from root left right,  shift it to root, leave the left shift old root to right
		cout << "LR Rotation" << endl;
		avl_node* temp;
		avl_node* tempCh;
		temp = parent->left->right;
		tempCh = temp->right;

		parent->left->right = temp->left;
		temp->left = parent->left;

		temp->right = parent;
		parent->left = tempCh;

		return temp;
	}

	/*
	* Right- Left Rotation
	*/
	avl_node* rl_rotation(avl_node *parent) {
		//take bottom, that is from root right left,  shift it to root, leave the right shift old root to left
		//Mirror of lr rotation
		cout << "RL Rotation" << endl;
		avl_node* temp;
		avl_node* tempCh;
		temp = parent->right->left;
		tempCh = temp->left;

		parent->right->left = temp->right;
		temp->right = parent->right;

		temp->left = parent;
		parent->right = tempCh;

		return temp;
	}

	/*
	* Balancing AVL Tree
	*/
	avl_node* balance(avl_node *temp) {
		int bal_factor = diff(temp);
		if (bal_factor > 1) {
			if (diff(temp->left) > 0) {
				temp = ll_rotation(temp);
			} else {
				temp = lr_rotation(temp);
			}
		} else if (bal_factor < -1) {
			if (diff(temp->right) > 0) {
				temp = rl_rotation(temp);
			} else {
				temp = rr_rotation(temp);
			}
		}
		return temp;
	}

	/*
	* Insert Element into the tree
	*/
	avl_node* insert(avl_node *root, string value) {
		if (root == NULL) {
			root = new avl_node;
			root->data = value;
			root->left = NULL;
			root->right = NULL;
			return root;
		} else if (value < root->data) {
			root->left = insert(root->left, value);
			root = balance(root);
		} else if (value >= root->data) {
			root->right = insert(root->right, value);
			root = balance(root);
		}
		return root;
	}

	//Removing an item from the tree, 
	avl_node* remove(avl_node *root, string value) {
		if (root != NULL) {
			if (value < root->data) {
				root->left = remove(root->left, value);

			} else if (value > root->data) {
				root->right = remove(root->right, value);
			} else {
				if ((root->left == NULL) || (root->right == NULL)) {
					avl_node* temp = root;
					if (root->left == root->right) {

						root = NULL;

					} else {
						if (root->left != NULL) {

							root = root->left;

						} else {
							root = root->right;
						}
					}
					delete (temp);
				} else {
					avl_node* temp = root->right;
					while (temp->left != NULL) { temp = temp->left; }
					root->data = temp->data;
					root->right = remove(root->right, temp->data);
				}
			}

		}
		if (root != NULL)
			root = balance(root);
		return root;
	}

	//This class checks to see if a value is indeed inside of the tree
	bool locate(avl_node* root, string value) {

		bool flag = false;
		avl_node* temp = root;
		while (temp != NULL) {
			if (value < temp->data) {
				temp = temp->left;
			} else if (value > temp->data) {
				temp = temp->right;
			} else if (value == temp->data) {
				temp = NULL;
				flag = true;
			}
		}
		return flag;
	}

	/*
	* Display AVL Tree
	*/
	void display(avl_node *ptr, int level) {
		int i;
		if (ptr != NULL) {
			display(ptr->right, level + 1);
			printf("\n");
			if (ptr == root)
				cout << "Root -> ";
			for (i = 0; i < level && ptr != root; i++)
				cout << "        ";
			cout << ptr->data;
			display(ptr->left, level + 1);
		}
	}
	//This is the inorder function.
	string displayInOrder(avl_node* root, string* list) {
		if (root != NULL) {
			displayInOrder(root->left, list);
			*list += " " + root->data;
			displayInOrder(root->right, list);
			
		}
		return *list;

	}

};
