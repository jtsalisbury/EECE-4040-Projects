// HW3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Book.h"
#include "UserInterface.h"

using namespace std;

int main() {
	UserInterface* ui = new UserInterface();
	int option = -1;
	Book* book;

	// Option to create the new tree based off a file or not
	while (option != 1 && option != 2) {
		cout << "Would you like to create a blank tree (1) or one based off a file (2)? ";
		cin >> option;
		
		// In case cin resolves to a fail state
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	if (option == 2) {
		// Create the tree via a file
		string filepath;

		cout << "Please enter the full path to the tree file: ";
		cin >> filepath;

		book = new Book(filepath);
	} else {
		// Create the tree with nothing
		book = new Book();
	}
	
	// UI class will provide a quit state
	while (!ui->shouldQuit()) {
		option = -1;

		// While the validation option is not valid
		while (!ui->validateOption(option)) {
			ui->printOptions();

			cout << "Please enter an option: ";
			cin >> option;

			// Ensure the cin isn't in a fail state. If it is, fix it
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}

		// Execute an option 
		ui->executeOption(book, option);
	}
}