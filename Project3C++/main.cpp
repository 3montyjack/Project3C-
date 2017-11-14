//This is the main file that goes and asks you to add the file names that you are going to eddit

#include <iostream>
#include <fstream>
#include <iomanip>

#include "SortIntoTrees.cpp"
#include "AVLTree.h"
#include "LinkedList.cpp"

using namespace std;

int main(int argc, char const *argv[]) {

	bool firstFile = false;
	bool secondFile = false;

	SortIntoTrees writer;
	ifstream in_file;

	string x;
	string fileName = "";

	//Initializing the first file
	while (!firstFile) {
		cout << "Input the file name that you want to inport first: ";
		cin >> fileName;
		in_file.open(fileName);
		if (!in_file) {
			cout << "Unable to open file" << endl;
		} else {
			firstFile = true;
		}

	}

	//Iterate through the first file
	while (in_file >> x) {
		writer.insertFirstList(x);
	}

	in_file.close();

	//Initializing the second file
	while (!secondFile) {
		cout << "Input the file name that you want to inport second: ";
		cin >> fileName;
		in_file.open(fileName);
		if (!in_file) {
			cout << "Unable to open file" << endl;
		} else {
			secondFile = true;
		}
	}

	//Itterate through the second file
	while (in_file >> x) {
		writer.insertSecondList(x);
	}

	in_file.close();
	writer.display();
	cout << "DONE";

	return 0;
}
