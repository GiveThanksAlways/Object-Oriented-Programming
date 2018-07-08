#include <iostream>
#include <iomanip>  
#include <iostream>
#include <fstream>

using namespace std;

const int size = 20;

void print(double heat_plate[size][size]) // print array
{

	int width = 20, height = 20;

	for (int i = 0; i < height; ++i) // rows
	{
		for (int j = 0; j < width; ++j) // columns
		{
			cout << setprecision(5) << heat_plate[i][j] << " "; // prints
		}
		cout << endl << endl;
	}
}
void print_CSV(double heat_plate[size][size]) // send to CSV file format
{
	int width = 20, height = 20;
	ofstream outputfile; // make file
	outputfile.open("lab6output.csv"); // name file and open ofstream

	for (int i = 0; i < height; ++i) // rows
	{
		for (int j = 0; j < width; ++j) // columns
		{
			outputfile << heat_plate[i][j] << ','; // put values in with commas

		}
		outputfile << '\n'; // start new line
	}
	outputfile.close(); // close ofstream

}
void make_array(double heat_plate[size][size], double heat_plate_new_averaged[size][size])// helps generate arrays
{
	// set variables
	int first_row = 0, last_row = 19, first_column = 0, last_column = 19;
	const int top_row = 100, bottom_row = 100, left_side = 0, right_side = 0;
	for (int i = first_row; i <= last_row; ++i) // rows
	{
		for (int j = first_column; j <= last_column; ++j) // columns
		{
			heat_plate[i][j] = 0;
			heat_plate_new_averaged[i][j] = 0;
		}
	}
}

void update_array(double heat_plate[size][size], double heat_plate_new_averaged[size][size]) // switch array values
{
	int first_row = 0, last_row = 19, first_column = 0, last_column = 19;
	const int top_row = 100, bottom_row = 100, left_side = 0, right_side = 0;
	for (int i = first_row; i <= last_row; ++i) // rows
	{
		for (int j = first_column; j <= last_column; ++j) // columns
		{
			heat_plate[i][j] = heat_plate_new_averaged[i][j];
		}
	}
}
// fill the rows
void fill_rows(double heat_plate[size][size], int row, double value)
{
	// set variables
	int first_row = 0, last_row = 19, first_column = 0, last_column = 19;
	const int top_row = 100, bottom_row = 100, left_side = 0, right_side = 0;

	for (int i = first_row; i <= last_row; i++) // set rows to 100
	{
		heat_plate[row][i] = value; // set row value to value
	}
}
// find average values of surroudning cells
double average_of_surrouding_cells(double top, double right, double bottom, double left)
{
	double sum = 0, average = 0, total = 4;
	sum = top + right + bottom + left;
	average = sum / total;
	return average;
}
void iterate(double heat_plate[size][size], double heat_plate_new_averaged[size][size])
{
	double top = 0, right = 0, bottom = 0, left = 0;
	double largest = 0, difference = 0, largest_change_allowed = 0.1, temp_value = 0;
	int first_row_small = 1, first_column_small = 1, last_row_small = 18, last_column_small = 18;
	for (int i = first_row_small; i <= last_row_small; ++i)    // rows
	{
		for (int j = first_column_small; j <= last_column_small; ++j) // columns
		{
			// set array index to the ones on top, right, bottom, and left of current value
			int i_up = i - 1, j_right = j + 1, i_bottom = i + 1, j_left = j - 1;
			top = heat_plate[i_up][j];      // same j
			right = heat_plate[i][j_right];    // same i
			bottom = heat_plate[i_bottom][j];    // same j
			left = heat_plate[i][j_left];     // same i

			heat_plate_new_averaged[i][j] = average_of_surrouding_cells(top, right, bottom, left);

		}

	}
}
double get_max_value(double heat_plate[size][size], double heat_plate_new_averaged[size][size])
{
	double top = 0, right = 0, bottom = 0, left = 0;
	double largest = 0, difference = 0, largest_change_allowed = 0.1, temp_value = 0;
	int first_row_small = 1, first_column_small = 1, last_row_small = 18, last_column_small = 18;
	for (int i = first_row_small; i <= last_row_small; ++i)    // rows
	{
		for (int j = first_column_small; j <= last_column_small; ++j) // columns
		{
			
			// get max value
			difference = heat_plate_new_averaged[i][j] - heat_plate[i][j];
			if (difference > temp_value)
				temp_value = difference;

		}

	}//end for

	return temp_value;
}

int main()
{
	// set variables
	double heat_plate[size][size], heat_plate_new_averaged[size][size];
	int first_row = 0, last_row = 19, first_column = 0, last_column = 19;
	double top = 0, right = 0, bottom = 0, left = 0;
	const int top_row = 100, bottom_row = 100, left_side = 0, right_side = 0;
	int first_print = 1, on = 1, off = 0;

	// make the array with zeros
	make_array(heat_plate, heat_plate_new_averaged);
	// put in the constant values of 100 on tops and 0 on sides
	fill_rows(heat_plate, first_row, top_row);
	fill_rows(heat_plate, last_row, bottom_row);
	fill_rows(heat_plate_new_averaged, first_row, top_row);
	fill_rows(heat_plate_new_averaged, last_row, bottom_row);
	// put in the zeros 
	for (int i = 0; i <= last_column; i++) // set columns to 0
	{
		heat_plate[i][first_column] = left_side;
		heat_plate[i][last_column] = right_side;
		heat_plate_new_averaged[i][first_column] = left_side;
		heat_plate_new_averaged[i][last_column] = right_side;
	}
	// print intitalized array
	print(heat_plate);

	// loop for iterations to find the heat_plate steady state
	bool temp = true, stable = false;
	// keep running while temperature is not stable
	while (temp != stable)
	{
		double largest = 0, difference = 0, largest_change_allowed = 0.1, temp_value = 0;
		int first_row_small = 1, first_column_small = 1, last_row_small = 18, last_column_small = 18;
		



		iterate(heat_plate, heat_plate_new_averaged);

		temp_value = get_max_value(heat_plate, heat_plate_new_averaged);

		// print first iteration
		if (first_print == on)// if on, then print
		{
			print(heat_plate_new_averaged);
			first_print = off; // turn off
		}
		// update the array after the iteration to begin next iteration with new array
		update_array(heat_plate, heat_plate_new_averaged);

		/* checks to see if the largest difference was above .1, if it is, then keep going
		 if they all changed less than .1, then we are done looping. */
		if (temp_value > largest_change_allowed)
		{
			stable = false; // if stable is false, then stable is false, so keep trying
		}
		else
		{
			stable = true; // if stable is true, then stable is true, so exit loop
		}

	} // end while
	
	// send array to a csv file for excel to read
	print_CSV(heat_plate_new_averaged);

	// pause
	system("pause");
	// end the program
	return 0;
}



