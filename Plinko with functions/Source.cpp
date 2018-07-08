#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/*
******************Test case 1************************
input1: 1 (option 1)
input2: asdfasdfasdf
The program returns to the main menu because of invalid input.

******************Test case 2************************
input1: $$$$
The program returns to the main menu because of invalid input.

******************Test case 3************************
input1: 2 (option 2)
input2: 1 ( 1 chips selected)
input3: 9 ( slot 9 selected)
The program returns to the main menu because of invalid input.
*/


// assign variables
float choice = 0, input1 = 0, prize_money = 0, position = 0;
const int Width = 8;
const int Height = 13;
const int Height_minusone = 12;
float chances = .5;
int ton = 10000;
int quit = 3, option2 = 2, option1 = 1;
// end assign variables

//drop function
float drop_function(float position, bool print)
{
	int left = 0;
	int right = 8;
	float Position_old = 0; // initialize position
	float path[Height]; // make array of 13

	for (int row = left; row < Height; row++) // for each row, loop 1.1
	{
		// loops through position of chip without letting it go off the board
		path[row] = position;
		Position_old = position;
		int leftOrRight = rand() % 2;
		if (position == left)
			position += chances;
		else if (position == right)
			position -= chances;
		else if (leftOrRight == left)
		{
			position -= chances;
		}
		else
		{
			position += chances;
		}

	}//end of for loop 1.1
	if (print == true)
	{
		cout << "PATH:  [";
		for (int pathPoint = 0; pathPoint < Height; pathPoint++) // Print array of positions
		{
			if (pathPoint != Height_minusone)
			{
				cout << fixed << setprecision(1) << path[pathPoint] << " ";
			}
			else{ cout << fixed << setprecision(1) << path[pathPoint] << "]"; }
		}
	}
	return Position_old;
}

float single_chip_drop(float slot_number)
{
	cout << endl << "*** DROPPING CHIP INTO SLOT " << slot_number << " ***" << endl << endl;
	int left = 0;
	int right = 8;
	position = slot_number; // place cin here to put all chips here
	float Position_old = 0; // initialize position
	float path[Height]; // make array of 13
	bool print;
	print = true;

	Position_old = drop_function(position, print);

	return Position_old;
}
int Calculate_Prize_Money(int Position_old)
{
	int pos0 = 0, pos1 = 1, pos2 = 2, pos3 = 3, pos4 = 4, pos5 = 5, pos6 = 6, pos7 = 7, pos8 = 8;
	int dollars100 = 100, dollars500 = 500, dollars1000 = 1000, dollars0 = 0, dollars10000 = 10000;
	// Check for prize money
	if ((Position_old == pos0) || (Position_old == pos8))
		prize_money = dollars100;
	if ((Position_old == pos1) || (Position_old == pos7))
		prize_money = dollars500;
	if ((Position_old == pos2) || (Position_old == pos6))
		prize_money = dollars1000;
	if ((Position_old == pos3) || (Position_old == pos5))
		prize_money = dollars0;
	if (Position_old == pos4)
		prize_money = dollars10000;
	return prize_money;
}
float multiple_chip_drop(float Num_Chip, float How_Many_slots, float turn_on, float Pre_Slot_Number)
{
	int left = 0;
	int pos0 = 0, pos1 = 1, pos2 = 2, pos3 = 3, pos4 = 4, pos5 = 5, pos6 = 6, pos7 = 7, pos8 = 8;
	int dollars100 = 100, dollars500 = 500, dollars1000 = 1000, dollars0 = 0, dollars10000 = 10000;
	int right = 8, end = 9;
	int zero_chips = 0;
	int slot_number_2 = 0, slot_number_f = 0;
	int big = 500;
	int fail = -1;

	for (int i = How_Many_slots; i < end; i++)
	{
		float prize_total = 0, prize_average = 0;
		int slot_number_2 = i;
		if (Num_Chip > zero_chips) // Number of chips are positive
		{
			if (turn_on != pos1)
			{
				cout << "Which slot do you want to drop the chip in (0-8)?";
				cin >> slot_number_f;
				if ((cin.fail() == true) || (slot_number_f < pos0) || (slot_number_f > pos8))// test if it is not a number
				{
					// clear the cin values
					cin.clear();
					//ignore cin values
					cin.ignore(ton, '\n');
					choice = pos0;
					slot_number_f = big;
					slot_number_2 = big;
				}
				else
				{
					i = end;
					slot_number_2 = slot_number_f;
				}
			}
			if (Pre_Slot_Number != big) // for drop into all slots, for loop in main function
				slot_number_2 = Pre_Slot_Number;

			if ((left <= slot_number_2) && (slot_number_2 <= right)) // Slot number selected right
			{
				int Position_old2 = 0;
				for (int chip = 0; chip < Num_Chip; chip++) // for each chip, loop 2.1
				{
					position = slot_number_2; // position

					bool print = false;

					Position_old2 = drop_function(position, print);

					prize_money = Calculate_Prize_Money(Position_old2);

					prize_total += prize_money;

				}//end of for loop 2.1
				
			}// end of if loop that checks that slot number is between 0 and 8


		}// end of if chips are positive
		if (slot_number_2 == big)
			return fail;
		else
		{
			return prize_total;
		}
	}// end of for loop


}// end function mult chip

int main()
{
	srand(time(0)); // defines random time
	// assign variables
	float choice = 0, input1 = 0, prize_money = 0, position = 0;
	const int Width = 8;
	const int Height = 13;
	const int Height_minusone = 12;
	int left = 0;
	int right = 8;
	int beyond_right = 9;
	int zero_chips = 0;
	int fail = -1;
	int big = 500;
	int pos0 = 0, pos1 = 1, pos2 = 2, pos3 = 3, pos4 = 4, pos5 = 5, pos6 = 6, pos7 = 7, pos8 = 8;
	int dollars100 = 100, dollars500 = 500, dollars1000 = 1000, dollars0 = 0, dollars10000 = 10000;
	float chances = .5;
	float prize_total = 0, prize_average = 0;
	int ton = 10000;
	int quit = 4, option3 = 3, option2 = 2, option1 = 1, option0 = 0;
	// end assign variables
	while (choice != quit){
		cout << endl << "MENU: Please select one of the following options:" << endl // Menu
			<< "1 -" << " Drop a single chip into one slot" << endl
			<< "2 -" << " Drop multiple chips into one slot" << endl
			<< "3 -" << " Drop multiple chips into each of the slots" << endl
			<< "4 -" << " Quit the program" << endl
			<< "Enter your selection now: ";
		cin >> choice;
		if (choice == quit)
			cout << "GOODBYE!" << endl;
		if (cin.fail() == true)// test if it is not a number
		{
			// clear the cin values
			cin.clear();
			//ignore cin values
			cin.ignore(ton, '\n');
			choice = option0;

		}
		if (choice == option1) // Run if option 1 is selected
		{
			cout << endl << "*** DROP SINGLE CHIP ***" << endl;
			cout << "Which slot do you want to drop the chip in (0-8)? ";
			int slot_number;
			cin >> slot_number;
			if (cin.fail() == true)// test if it is not a number
			{
				// clear the cin values
				cin.clear();
				//ignore cin values
				cin.ignore(ton, '\n');
				choice = option0;
				slot_number = beyond_right;
			}

			if ((left > slot_number) || (slot_number > right)) // test for invalid slot number
			{
				choice = option0;
				// cout << "INVALID SLOT." << endl << endl;
			}
			else if ((left <= slot_number) && (slot_number <= right)) // Slot number selected right
			{

				// function for one drop
				int Position_old = single_chip_drop(slot_number);

				// function to check for prize money
				prize_money = Calculate_Prize_Money(Position_old);

				// print out earnings
				cout << endl << fixed << setprecision(2) << "WINNINGS: $" << prize_money << endl << endl;

			}// end of Slot number selected right

		} // end choice 1


		else if (choice == option2) // Slot number 2 selected
		{
			cout << endl << "*** DROP MULTIPLE CHIPS ***" << endl;
			cout << "How many chips do you want to drop (>0)? ";
			int Num_Chip = 0;
			cin >> Num_Chip;

			if ((cin.fail() == true) || (Num_Chip <= zero_chips))// test if it is not a number
			{
				// clear the cin values
				cin.clear();
				//ignore cin values
				cin.ignore(ton, '\n');
				choice = option0;
				Num_Chip = zero_chips;
			}
			else
			{
				prize_total = multiple_chip_drop(Num_Chip, pos8, pos0, big);
				if (prize_total == fail)
				{
					choice = option0;
				}
				else
				{

					prize_average = prize_total / Num_Chip;
					cout << "Total Winnings on " << fixed << setprecision(2) << Num_Chip << " chips: \t$" << prize_total << endl
						<< "Average winnings per chip: \t$" << fixed << setprecision(2) << prize_average << endl << endl << endl;
				}
			}

			
		}//End of choice == 2
		else if (choice == option3)
		{
			cout << endl << "*** DROP MULTIPLE CHIPS INTO MULTIPLE SLOTS ***" << endl;
			cout << "How many chips do you want to drop (>0)? ";
			int Num_Chip = 0;
			cin >> Num_Chip;
			if ((cin.fail() == true) || (Num_Chip <= zero_chips))// test if it is not a number
			{
				// clear the cin values
				cin.clear();
				//ignore cin values
				cin.ignore(ton, '\n');
				choice = option0;
				Num_Chip = zero_chips;
			}
			else
			{
				cout << "Money won from dropping " << Num_Chip << " into each slot" << endl << endl;
			}

			if (Num_Chip > zero_chips)
			{
				float total_winnings_Tons_Slots = 0;
				for (int j = 0; j < beyond_right; j++)
				{
					prize_total = multiple_chip_drop(Num_Chip, pos8, pos1, j);
					prize_average = prize_total / Num_Chip;
					cout << "Slot number " << j << " dropping " << Num_Chip << " Chips." << endl;
					cout << "Total Winnings on " << fixed << setprecision(2) << Num_Chip << " chips: \t$" << prize_total << endl
						<< "Average winnings per chip: \t$" << fixed << setprecision(2) << prize_average << endl << endl << endl;
					total_winnings_Tons_Slots += prize_total;
				}

				// cout << "Total winnings of all drops with all chips: " << total_winnings_Tons_Slots<<endl<<endl;

			}

		}
		else if (choice != quit || choice == option0) // If choices are not 1, 2 or 3 then invalid selection
		{
			// cout << "INVALID SELECTION. Please enter 1, 2, 3, or 4"<<endl<<endl<<endl;
		}



	} // end while loop

	// have the system pause before ending
	system("pause");
	return 0;// stops the code

} //end main





















