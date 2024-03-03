#include "ItemTracker.h"

ItemTracker::ItemTracker()
{
	//loado ur data on initialization.
	this->loadData();

	//backup our data after loading on initialization.
	this->backupData();
}

//Used to add an item into the item map
void ItemTracker::addItem(string t_item)
{
	//get iterator using the .find method
	auto iter = this->m_itemFrequency.find(t_item);

	//if the iter doesn't equal the .end() then the element exists.
	if (iter != this->m_itemFrequency.end())
	{

		this->m_itemFrequency[iter->first] = (iter->second + 1);
	} else {

		this->m_itemFrequency.insert(make_pair(t_item, 1));
	}
}

//print a number of asterisks to the console.
void ItemTracker::printAsterisks(int t_number) {

	//loop for the correct number of times and print an asterisk for each loop
	for (int i = 0; i < t_number; ++i) {
		cout << "*";
	}
}

//returns the frequency
int ItemTracker::frequency(string t_item)
{
	//get iterator using the .find method
	auto iter = this->m_itemFrequency.find(t_item);

	//if the iter doesn't equal the .end() then the element exists.
	if (iter != this->m_itemFrequency.end())
	{

		return iter->second; // return the value if it exists.
	}
	return 0; //return 0 if the item doesn't exist
}

//Used to load the list of items from the data file.
void ItemTracker::loadData()
{
	//Our input file stream variable
	ifstream inFS;

	//open our input stream
	inFS.open("CS210_Project_Three_Input_File.txt");

	//Check if input file was opened successfully.
	if (!inFS.is_open())
	{

		//output error message and return 1 since we errored out.
		cout << "Error: Unable to open input file." << endl;
		return;
	}

	string item;
	while (inFS >> item)
	{
		this->addItem(item);
	}
	inFS.close();
}

//Used to backup the frequency amounts to the data file.
void ItemTracker::backupData()
{
	//Our output file stream variable
	ofstream outFS;

	//open our output stream
	outFS.open("frequency.dat");

	//Check if output file was opened successfully.
	if (!outFS.is_open())
	{

		//output error message and return 1 since we errored out.
		cout << "Error: Unable to open output file." << endl;
		return;
	}

	//initialize an iterator variable at the start of the map.
	auto iter = this->m_itemFrequency.begin();
	
	//loop through map until we get to end
	do
	{

		outFS << iter->first << " " << iter->second << endl; // output the first and second value of the map pair into our output file

		iter++; //get our next entry in the map.
	} while (iter != this->m_itemFrequency.end());

	outFS.close();

}

//Used to get the item input from console to use for an item search.
void ItemTracker::getItemInputAndFrequency()
{
	string item;

	cout << "Enter name of item to get frequency: ";

	cin >> item;

	cout << "Frequency for " << item << " is " << this->frequency(item) << endl;
}

//Used to print the item list to console, takes bool parameter,
//which outputs the numeric when true, or asterisk-style histogram when false.
void ItemTracker::printList(bool t_numeric)
{
	//initialize an iterator variable at the start of the map.
	auto iter = this->m_itemFrequency.begin();

	//loop through map until we get to end
	do
	{

		cout << iter->first << " ";

		//if this is numeric, simply print the amount of the item occurences.
		if (t_numeric)
		{
			cout << iter->second;
		} else {
			//if not numeric, print that amount of asterisk out.
			this->printAsterisks(iter->second);
		}
		cout << endl;

		iter++; //get our next entry in the map.

	} while (iter != this->m_itemFrequency.end());
}