//Grocery List.cpp: This program allows the user to create and modify a list of grocery items.
//

/********************************************************************************
*ASSIGNMENT SPECIFICATIONS*
Without modifying the content of main(), create the following functions:
1)    add_item
2)    display_list
3)    get_item_name
4)    find_longest

Your finished code should (a) compile without errors, (b) function as
described by the comments in main(). You may ask the TAs for clarifications
about how the functions should work, but you may not ask them to help you
implement or debug the code.

YCode, Cplusplus.com, the class web page on LearningSuite, and your book may all be
used to help you with this exam. You may also refer to any of your own notes.


*EXTRA CREDIT #1*
Uncomment the code block labeled 'EXTRA CREDIT #1' in the function main().
Implement the function swap_items as described in the program comments

*EXTRA CREDIT #2*
Uncomment the code block labeled 'EXTRA CREDIT #2' in the function main().
Implement the function remove_item as described in the program comments


*HINTS*

Work on one function at a time. It's easier than trying to do them all at once.

Chapter 6 in your book focuses on arrays, and section 6.3 shows how to
pass an array to a function.

You may temporarily comment out sections of main() if it assists with your
development process. (For example, if you want to concentrate on implementing
the function add_item(), you may comment out the function calls for display_list(),
get_item_name(), and find_longest() in order to avoid compiler errors.)

You will be graded based on (A) How well you implement the functions as specified,
(B) Whether you use good coding practices, and (C) Whether your finished code compiles
properly when the TAs grade it. Remember that you should not make permanent changes
to the contents of main().
********************************************************************************/

#include <string>
#include <iostream>

const int MAXIMUM_LIST_SIZE = 100;

using namespace std;

// adds an item to the grocery list
void add_item(string grocery_list[MAXIMUM_LIST_SIZE], int& current_list_size, string grocery_item)
{
	int start = current_list_size; // start
	int end = current_list_size; // end 
	for(int i =start; i <= end; ++i) // run through the list
	{
		grocery_list[i] = grocery_item; // adds the item
		current_list_size++; // updates the size
	}

}
// print the list to console
void display_list(string grocery_list[MAXIMUM_LIST_SIZE], int& current_list_size)
{
	cout << "------------"<<endl; // print lines
	for(int i = 0; i < current_list_size; ++i) // runs through the list
	{
		cout << grocery_list[i] << endl; // prints
	}
	cout << "------------"<<endl; // prints lines
}
// returns the string of the item name associated with the index provided
string get_item_name(string grocery_list[MAXIMUM_LIST_SIZE], int& current_list_size, int index)
{
	string error = "INVALID INDEX"; // error message
	int start = 0; // start
	if (index >= current_list_size || index < start) // if index outside of range
		return error; // print error
	else
		return grocery_list[index]; // print the grocery item
}

// finds the item with the longest name and returns the item's name
string find_longest(string grocery_list[MAXIMUM_LIST_SIZE], int& current_list_size)
{
	int largest_index = 0, current_string_size = 0, largest = 0; // set variables
	for (int i = 0; i < current_list_size; ++i) // run through list
	{
		current_string_size = grocery_list[i].length(); // get legnth of item
		if (current_string_size > largest) // see if it is bigger than the previous items
		{
			largest = current_string_size;// only saves if it was bigger than all previous items
			largest_index = i; // saves the index that it is at
		}
	}
	return grocery_list[largest_index]; // returns the longest item
}
//swaps the position of the items at locations i1 and i2.
void swap_items(string grocery_list[MAXIMUM_LIST_SIZE], int& current_list_size, int i1, int i2)
{
	// check to make sure i1 and i2 are within the bounds of the array
	int beginning = 0;
	string temp_val = "";
	string error = "INVALID INDEX"; // error message
	bool start = false;
		if (i1 >= current_list_size || i1 < beginning) // check to see if i1 is within range
			start = false;
		else if (i2 >= current_list_size || i2 < beginning)// check to see if i2 is within range
			start = false;
		else
			start = true;
		// start if true that i1 and i2 in the range
		if (start)
		{
			temp_val = grocery_list[i1]; // temp
			grocery_list[i1] = grocery_list[i2]; // replace first one
			grocery_list[i2] = temp_val; // use temp to define second one
		}
		else
		{
			cout << error<<endl; // error message
		}
}
// removes the grocery item from the list
void remove_item(string grocery_list[MAXIMUM_LIST_SIZE], int& current_list_size, string grocery_item)
{
	string error = "ITEM NOT FOUND"; // error message
	bool notfound = true;
	string temp_grocery_list[MAXIMUM_LIST_SIZE];
	int one_less = current_list_size - 1;
	for (int i = 0; i < current_list_size; ++i) // runs through the list
	{
		if (grocery_list[i] == grocery_item) // checks to see if index item is the grocery item
		{
			for (int a = i; a < one_less; ++a) // swaps posistions to maintain order and put bad one last
			{
				int i1 = a;
				int i2 = a + 1;
				swap_items(grocery_list, current_list_size, i1, i2); // put item to remove at the end of array
			}
			grocery_list[one_less].clear(); // clears the last value
			current_list_size--; // resets the size of the list

			notfound = false;
			i = current_list_size; // exits loop
		}
		
	}
	if (notfound)
	{
		cout << error<<endl; // error message
	}
}
int main() //DO NOT CHANGE THIS FUNCTION (EXCEPT TO COMMENT OR UNCOMMENT VARIOUS SECTIONS)
{
	string input;
	string grocery_list[MAXIMUM_LIST_SIZE];
	int current_list_size = 0;

	cout << "**********************************************************" << endl;
	cout << "GROCERY LIST.CPP" << endl;
	cout << "**********************************************************" << endl;
	cout << endl;
	cout << "This program accepts the following commands: " << endl << endl;
	cout << "add [item name]: adds an item to the list" << endl;
	cout << "remove [item name]: removes an item from the list" << endl;
	cout << "display: shows the contents of the list" << endl;
	cout << "show [index]: shows the contents of list[index]" << endl;
	cout << "longest: outputs the list item with the most letters" << endl;
	cout << "swap [index 1] [index 2]: swaps the location of two items" << endl;
	cout << "quit: exits the program" << endl;
	cout << endl;
	cout << "Please enter a command." << endl << endl;

	while (input != "quit") {
		cin >> input;

		if (input == "add") {
			string grocery_item;
			getline(cin, grocery_item);
			grocery_item = grocery_item.substr(1, grocery_item.length() - 1); //removes leading space
			add_item(grocery_list, current_list_size, grocery_item);	//add grocery_item to the grocery_list array
			//(You may assume that the user will never add more items
			//than the array can comfortably hold.)
		}

		if (input == "display") display_list(grocery_list, current_list_size);	//display the grocery list, one item per line,
		//with a row of hyphens above and below the list

		if (input == "show") {
			int index;
			cin >> index;
			cout << get_item_name(grocery_list, current_list_size, index) << endl;	//get_item_name() returns the string content 
			//of the item stored in position index. If
			//the index is invalid, return "INVALID INDEX"
		}

		if (input == "longest") cout << find_longest(grocery_list, current_list_size) << endl;	//find_longest() returns the string content of 
		//the list item with the most letters. If there is
		//a "tie" between two or more words, the function should
		//return the first one found.

		/*EXTRA CREDIT #1*/
		if (input == "swap") {
		int i1, i2;
		cin >> i1 >> i2;
		swap_items(grocery_list, current_list_size, i1, i2);	//swaps the position of the items at locations i1 and i2.
		//If either location is invalid, output "INVALID INDEX"
		//followed by a new line.
		}

		/*EXTRA CREDIT #2*/
		if (input == "remove") {
		string grocery_item;
		getline(cin, grocery_item);
		grocery_item = grocery_item.substr(1, grocery_item.length() - 1); //removes leading space
		remove_item(grocery_list, current_list_size, grocery_item);	//remove this item from the grocery_list array without
		//changing the order of the other items on the list.
		//If the item to be deleted is not on the list,
		//output "ITEM NOT FOUND" followed by a new line.
		}

		cout << endl;
	}

	return 0;
}

