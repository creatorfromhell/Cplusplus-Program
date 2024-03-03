#ifndef ITEM_TRACKER_H_
#define ITEM_TRACKER_H_

#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

class ItemTracker {

private:

	unordered_map<string, int> m_itemFrequency;

	//Used to add an item into the item map
	void addItem(string t_item);

	//print a number of asterisks to the console.
	void printAsterisks(int t_number);

	//returns the frequency
	int frequency(string t_item);

	//Used to load the list of items from the data file.
	void loadData();

	//Used to backup the frequency amounts to the data file.
	void backupData();

public:

	ItemTracker();

	//Used to get the item input from console to use for an item search.
	void getItemInputAndFrequency();

	//Used to print the item list to console, takes bool parameter,
	//which outputs the numeric when true, or asterisk-style histogram when false.
	void printList(bool t_numeric);
};

#endif //ITEM_TRACKER_H_