// CornerGrocer.cpp : Daniel Vidmar 02/20/24
//

#include <iostream>
#include "ItemTracker.h"

using namespace std;

//used to print our menu to console
void printMenu() {
    cout << "============ Choice Menu ============" << endl;
    cout << "|          Enter an Option          |" << endl;
    cout << "| 1. Search for a specific item     |" << endl;
    cout << "| 2. Display list of all items      |" << endl;
    cout << "| 3. Display histogram of all items |" << endl;
    cout << "| 4. Exit the program               |" << endl;
    cout << "=====================================" << endl;

    cout << "Enter menu choice: ";
}

int main()
{

    ItemTracker tracker;

    //our choice variable for menu option selection.
    int choice = 0;

    do {

        //print our menu
        printMenu();

        cin >> choice;

        //switch through our menu options and perform the correct action
        switch (choice) {

            case 1:

                //start the search engine.
                tracker.getItemInputAndFrequency();

                break;

            case 2:

                //Print the list of items with numerics
                tracker.printList(true);

                break;

            case 3:

                //print the list of items with asterisks
                tracker.printList(false);

                break;

            default:

                //exit/other stuff.

                break;
        }

    } while (choice != 4);

    return 0;
}