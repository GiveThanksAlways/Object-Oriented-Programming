#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/*
******************Test case 1************************
input1: 1 (option 1)
input2: 8 ( select slot 8)
The program then drops the chip in slot 8. 
The program displays the path of the chip and the chip does not leave the board.
displays the winnings

******************Test case 2************************
input1: -1 (not an option)
The program displays INVALID SLOT and returns the user to the main menu.

******************Test case 3************************
input1: 2 (option 2)
input2: 0 ( 0 chips selected)
The program displays INVALID NUMBER OF CHIPS and returns the user to the main menu
*/

int main()
{
	srand(time(0)); // defines random time
	// assign variables
	float choice = 0, input1 = 0, prize_money = 0, position = 0;
	const int Width = 8;
	const int Height = 13;
	const int Height_minusone = 12;
	const int left = 0;
	const int right = 8;
	int pos0 = 0, pos1 = 1, pos2 = 2, pos3 = 3, pos4 = 4, pos5 = 5, pos6 = 6, pos7 = 7, pos8 = 8;
	int dollars100 = 100, dollars500 = 500, dollars1000 = 1000, dollars0 = 0, dollars10000 = 10000;
	float chances = .5;
	int ton = 10000;
	int quit = 3, option2 = 2, option1 = 1;
	while (choice != quit){
		cout << "MENU: Please select one of the following options:" << endl // Menu
			<< "1 -" << " Drop a single chip into one slot" << endl
			<< "2 -" << " Drop multiple chips into one slot" << endl
			<< "3 -" << " Quit the program" << endl
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
			choice = 0;
			
		}
		if (choice == option1) // Run if option 1 is selected
		{
			cout << endl << "*** DROP SINGLE CHIP ***" << endl;
			cout << "Which slot do you want to drop the chip in (0-8)? ";
			int slot_number;
			cin >> slot_number;

			if ((left > slot_number) || (slot_number > right)) // test for invalid slot number
			{
				choice = 0;
				cout << "INVALID SLOT." << endl << endl;
			}
			else if ((left <= slot_number) && (slot_number <= right)) // Slot number selected right
			{
				cout <<endl<< "*** DROPPING CHIP INTO SLOT " << slot_number << " ***"<<endl<<endl;
				position = slot_number; // place cin here to put all chips here
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
				cout << "PATH:  [";
				for (int pathPoint = 0; pathPoint < Height; pathPoint++) // Print array of positions
				{
					if (pathPoint != Height_minusone)
					{
						cout << fixed << setprecision(1) << path[pathPoint] << " ";
					}
					else{ cout << fixed << setprecision(1) << path[pathPoint] << "]"; }
				}
				cout << endl << fixed << setprecision(2) << "WINNINGS: $" << prize_money << endl << endl;
			}// end of Slot number selected right


		} // end choice 1


		else if (choice == option2) // Slot number 2 selected
		{
			float prize_total = 0, prize_average = 0;
			cout << endl << "*** DROP MULTIPLE CHIPS ***" << endl;
			cout << "How many chips do you want to drop (>0)? ";
			int Num_Chip = 0;
			cin >> Num_Chip;

			if (Num_Chip > 0) // Number of chips are positive
			{
				cout << "Which slot do you want to drop the chip in (0-8)?";
				int slot_number2;
				int Position_old2 = 0;
				cin >> slot_number2;
				if ((left <= slot_number2) && (slot_number2 <= right)) // Slot number selected right
				{
					for (int chip = 0; chip < Num_Chip; chip++) // for each chip, loop 2.1
					{
						position = slot_number2; // position
						
						for (int row = left; row < Height; row++) // for each row, loop 2.2
						{
							// loops through position of chip without letting it go off the board
							Position_old2 = position;
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

						}//end of for loop 2.2
						// Check for prize money
						if ((Position_old2 == pos0) || (Position_old2 == pos8))
							prize_money = dollars100;
						if ((Position_old2 == pos1) || (Position_old2 == pos7))
							prize_money = dollars500;
						if ((Position_old2 == pos2) || (Position_old2 == pos6))
							prize_money = dollars1000;
						if ((Position_old2 == pos3) || (Position_old2 == pos5))
							prize_money = dollars0;
						if (Position_old2 == pos4)
							prize_money = dollars10000;

						prize_total += prize_money;
						

					}//end of for loop 2.1
					prize_average = prize_total / Num_Chip;
					cout << "Total Winnings on " << fixed << setprecision(2) << Num_Chip << " chips: \t$" << prize_total << endl
						<< "Average winnings per chip: \t$" << fixed << setprecision(2) << prize_average << endl << endl << endl;
				}// end of if loop that checks that slot number is between 0 and 8
				else{ cout << " Please select a slot number between 0 and 8"<<endl<<endl; }
			}// end of if loop that checks if manyChip is positive 
			else // if chips are less than 0 
			{
				cout << "INVALID NUMBER OF CHIPS."<<endl<<endl<<endl;
			}
		}//End of choice == 2
		else if (choice !=quit) // If choices are not 1, 2 or 3 then invalid selection
		{
			cout << "INVALID SELECTION. Please enter 1, 2 or 3"<<endl<<endl<<endl;
		}

	} // end while loop

	// have the system pause before ending
	system("pause");
	return 0;// stops the code

} //end main














