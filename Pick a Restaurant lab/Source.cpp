#include <iostream>
#include <vector>
#include <string>
#include <time.h> 

using namespace std;

/*
***************TEST CASE 1*****************
INPUT:3
INPUT:Subway
INPUT: 5
OUTPUT: "Please make sure there are 2^n restaurants."
Then brought back to the menu.

this happened because we started only with 6 restaurants, which is compatible with 2^n

***************TEST CASE 2*****************
INPUT: 2
INPUT: Taco Bell
INPUT: 2
INPUT: Sonic
INPUT: 5
(now we have 2^n so we start tournament)
(During tournament, only option 1 is picked the whole time)
OUTPUT:
Your family will be eating dinner tonight at:
Sonic

***************TEST CASE 3*****************
INPUT: 1
OUTPUT: Burger King,McDonalds,Wendy's,Panda Express,Subway,Cafe Rio,Buffalo Wild Wings,Zaxby's

(prints the array so that you can see what restaurants are in it.)

*/

const int not_there = -1;

void Start_addNames(vector<string>& restaurant)
{
	string start_names[] = { "Burger King", "McDonalds", "Wendy's", "Panda Express", "Subway", "Cafe Rio", "Buffalo Wild Wings", "Zaxby's" };
	int sizestart = 8;
	int size = sizestart;
	for (int i = 0; i < size; i++)
		restaurant.push_back(start_names[i]); // push names into vector
}

void addName(vector<string>& restaurant, string input)
{
	restaurant.push_back(input); // push names into vector
}


void print_vector(vector<string> restaurant)
{
	int oneFromEnd = restaurant.size() - 1;
	int size = restaurant.size();
	string a = ",";
	for (int i = 0; i < size; i++)
	{
		if (i == oneFromEnd)//take away comma if the last one
			a = "";
		cout << restaurant[i] << a; // print with commas until end
	}
}

void print_2vectors(vector<string> restaurant, int step)//print for tournament
{

	int right = step; // right guy
	int left = step - 1; // left guy
	int winnerOfLastRound = right + 1; // skips the winner from last round to not repeat
	string a = "\t\tor ";
	int number = 1;
	int number2 = 2;
	for (int i = left; i < winnerOfLastRound; i++) // runs through the next two guys in tournament
	{
		if (i == right)
		{
			a = "? ";
			number = number2;
		}
		cout << number << ": " << restaurant[i] << a;
	}
}



bool findName(vector<string>& restaurant, string input)// find the name
{
	int size = restaurant.size();
	for (int i = 0; i < size; i++)
	{
		if (restaurant[i] == input)// check if string is in vector
		{

			return true; // yes found
		}
	}
	return false; // not found
}

int findNameInteger(vector<string>& restaurant, string input) // find name and return integer
{
	int size = restaurant.size();
	int negative_one = -1;
	for (int i = 0; i < size; i++)
	{
		if (restaurant[i] == input)// check if string is in vector
		{

			return i;// return spot it is in
		}
	}
	return negative_one;// not in vector
}

void removeName(vector<string>& restaurant, string input)//take name out
{
	int size = restaurant.size();
	for (int i = 0; i < size; i++)
	{
		if (restaurant[i] == input)// check if string is in vector
		{

			restaurant.erase(restaurant.begin() + i); // erase the name
			i = size;// reset i to exit for loop
		}
	}

}

void shuffle_vec(vector<string>& restaurant) // random shuffle_vec
{
	int shuffle_size = restaurant.size() - 1;
	int shuffle_total_size = restaurant.size();
	string temp, temp2;
	int index = 0;
	for (int i = shuffle_size; i>0; --i)// shuffle through vector
	{
		index = rand() % shuffle_total_size; // random number from 0 to size of vector
		temp = restaurant[i]; 
		restaurant[i] = restaurant[index]; // switch
		restaurant[index] = temp; // replace with old
	}
	
	cout << "The list was now shuffled. " << endl << endl;
}

int total_rounds(int numberOfrestaurants)// find total number of rounds
{
	bool done = false, yes = true;
	double divide_by_two = numberOfrestaurants;
	int integer_divide_by_two = numberOfrestaurants, one = 1, two = 2;
	int count = 0;
	bool returnTheCount = false;

	while (done != yes)
	{
		count++;
		divide_by_two = divide_by_two / two;
		integer_divide_by_two = integer_divide_by_two / two;
		int count0 = 0;
		if (divide_by_two != integer_divide_by_two) // if not divisible by 2
		{
			done = yes;
			count = count0;
		}
		else if (divide_by_two == one) // is equal to 2^n
		{
			done = yes;
		}
	}
	return count;
}

bool test_to_begin(int numberOfrestaurants)// test to see if 2^n numbers
{
	bool done = false, yes = true;
	double divide_by_two = numberOfrestaurants;
	int integer_divide_by_two = numberOfrestaurants, one = 1, two = 2;
	bool whatToReturn = false;
	while (done != yes)
	{
		divide_by_two = divide_by_two / two;
		integer_divide_by_two = integer_divide_by_two / two;
		if (divide_by_two != integer_divide_by_two)// if int doesnt equal variable, reset, and it doesnt work
		{
			done = yes;
			whatToReturn = false;
		}
		else if (divide_by_two == one)// if it is a power of 2, then it enters here
		{
			whatToReturn = true;
			done = yes;
		}
	}
	return whatToReturn;
}

void tournament_round(vector<string>& restaurant, int input_t, int step)// round of tourney
{
	int first = 1, second = 2, first_listed = 0, second_listed = 0;
	int tourney_step_less_one = step - 1;
	string loser;


	first_listed = tourney_step_less_one;// first printed
	second_listed = step;//second printed
	//check for input and assign loser
	if (input_t == first) 
		loser = restaurant[second_listed];
	if (input_t == second)
		loser = restaurant[first_listed];

	removeName(restaurant, loser);

}

void tournament(bool begin, vector<string>& restaurant)
{
	// variables

	if (begin)
	{
		bool tournament = true, over = false;
		int first = 1, second = 2, first_listed = 0, second_listed = 0;
		int step = 0, step0 = 0, winner = 1;
		int steps_in_round = 0;
		int match_number = 0, total_matches_for_round = 0;
		int total_rounds_in_tournament = 0, current_round = 0;
		bool round_failed = false;
		total_rounds_in_tournament = total_rounds(restaurant.size());
		while (tournament != over)
		{
			int input_t = 0;


			if (step == step0) // get the amount of steps in this round and resets everything for new round
			{
				int two_divider = 2;
				current_round++;// update round
				if (round_failed)
				{
					current_round--;// keep round the same
					round_failed = false;
				}
				steps_in_round = restaurant.size() / two_divider; // steps is total number / 2
				total_matches_for_round = steps_in_round; // find total matches
			}
			step++;// Step up


			cout << "Match " << step << "/" << total_matches_for_round << ","
				<< " Round " << current_round << "/" << total_rounds_in_tournament << " --- ";
			print_2vectors(restaurant, step);



			cin >> input_t;//get input
			if ((cin.fail()) || ((input_t != first) && (input_t != second)))// test if it is not a number
			{
				int alot = 1000;
				cin.clear();// clear the cin values
				cin.ignore(alot, '\n');//ignore cin values
				over = false;
				step--; // start over
				round_failed = true;

				
			}
			else if (restaurant.size() != winner)// no winner yet? then enter here
			{

				tournament_round(restaurant, input_t, step);
				if (step == steps_in_round)// checks if round is over and resets
				{
					int step_reset = 0;
					step = step_reset; // reset steps for next round
					cout << endl << " End of round " << endl << endl << endl;
				}
			}

			if (restaurant.size() == winner)// if one left, then we have a winner
			{
				cout << "Your family will be eating dinner tonight at: ";
				print_vector(restaurant);
				cout << endl << endl << endl << endl;
				over = true;// exit while looop
				step--;
			}


		}//end while tournament loop

	}//end if begin statement
}

int main()
{
	srand(time(0)); // defines random time
	// set variables
	vector<string> restaurant;
	string input;


	Start_addNames(restaurant);//put intital names in

	// run the program
	bool family = true, happy = false;
	while (family != happy)
	{
		// initialize variables
		int option = 0, option1 = 1, option2 = 2, option3 = 3, option4 = 4, option5 = 5, option6 = 6;

		// menu
		cout << "MENU: Please select one of the following options:" << endl // Menu
			<< "1 -" << " Display all restaurants" << endl
			<< "2 -" << " Add a restaurant" << endl
			<< "3 -" << " Remove a restaurant" << endl
			<< "4 -" << " Shuffle the vector" << endl
			<< "5 -" << " Begin the tournament" << endl
			<< "6 -" << " Quit the program" << endl
			<< "Enter your selection now: ";
		cin >> option;
		if (cin.fail() == true)// test if it is not a number
		{
			int alot = 1000;
			// clear the cin values
			cin.clear();
			//ignore cin values
			cin.ignore(alot, '\n');
			family = true;
		}
		if (option == option6)// quit
		{
			happy = true;
		}
		else if (option == option1)// option 1 print
		{
			cout << endl << "List of all Restaurants:" << endl;
			print_vector(restaurant);
			cout << endl << endl;
		}
		else if (option == option2)// option 2 add restaurant
		{

			cout << "What is the name of the restaurant you would like to add? " << endl;
			cin.sync(); // sync
			getline(cin, input); // get input


			if (findName(restaurant, input) || (findNameInteger(restaurant, input) != not_there))
			{
				cout << "The restaurant is already in the vector. " << endl;
			}
			else{
				addName(restaurant, input);
				cout << input << " was added to the vector." << endl << endl;
			}
		}
		else if (option == option3)// remove restaurant
		{
			cout << "What is the name of the restaurant you would like to remove? " << endl;
			cin.sync(); // sync
			getline(cin, input); // get input

			if (findName(restaurant, input) || (findNameInteger(restaurant, input) != not_there))
			{
				removeName(restaurant, input);
				cout << "The restaurant " << input << " was removed from the vector. " << endl;
			}
			else{
				cout << "The restaurant " << input << " is not in the vector." << endl << endl;
			}

		}
		else if (option == option4)// shuffle vector
		{
			shuffle_vec(restaurant);//shuffle vector
		}
		else if (option == option5)// begin tournament
		{
			bool begin = false;
			int numberOfrestaurants = 0;
			numberOfrestaurants = restaurant.size();

			begin = test_to_begin(numberOfrestaurants);
			if (begin == false)
				cout << endl << "Please make sure there are 2^n restaurants." << endl << endl;
			else
			{
				tournament(begin, restaurant);
				happy = true;
			}
		}

	} // end while




	// pause
	system("pause");
	// end the program
	return 0;
}











