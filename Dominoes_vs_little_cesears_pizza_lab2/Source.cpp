// Test case #1
// number of guests = 505 
// tip = 99%
// large pizzas = 72, medium pizzas = 0, small pizzas = 1, Area = 22732.5 in^2, Area/person = 45.0149 in/person
// cost=$2118

// Test case #2
// number of guests = 2
// tip = 20%
// large pizzas = 0, medium pizzas = 0, small pizzas = 2, Area = 226.194 in^2, Area/person = 113.097 in/person
// cost=$17

// Test case #3
// number of guests = 6
// tip = 50%
// large pizzas = 0, medium pizzas = 2, small pizzas = 0, Area = 402.124 in^2, Area/person = 67.0206 in/person
// cost=$34
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int guests = 0, large_Pizza = 0, medium_Pizza = 0, small_Pizza = 0;
	double tip_Percent = 0, tip_Decimal = 0, tip = 0, total_Cost = 0, total_Area = 0, Area_Per_Person = 0, Area_Large = 0, Area_Medium = 0, Area_Small = 0;
	double small_radius = 0, medium_radius = 0, large_radius = 0, small_diameter = 0, medium_diameter = 0, large_diameter = 0;
	double large_price = 0, medium_price = 0, small_price = 0, total_Cost_with_tip = 0;
	// prompt the user for the number of guests who will be eating
	cout << "Please enter the number of guests: ";
	cin >> guests; // store their input as the variable guests
	// Determine how many large, medium, and small pizzas by using if statements
	if (guests > 7){                //if it is larger than 7, then buy guests/7 large pizzas
		large_Pizza = guests / 7;
	}
	if ((guests % 7) >= 3){         //if after dividing by 7, if you have more than three left over than order leftover/3 medium pizzas
		medium_Pizza = (guests % 7) / 3;
	}
	if ((guests % 7) % 3 >= 1){        //after ordering large and medium pizzas, order one pizza for every person left over.
		small_Pizza = ((guests % 7) % 3) / 1;
	}
	const double PI = 3.14159;     //Define what Pi the constant is
	small_diameter = 12;             //assign the diamters of each pizza
	medium_diameter = 16;
	large_diameter = 20;
	small_radius = small_diameter / 2;     //finds the radius of each size of pizza by dividing the diameter by 2
	medium_radius = medium_diameter / 2;
	large_radius = large_diameter / 2;
	Area_Large = large_radius * large_radius * PI; // use Pi r^2 to compute the area of each size of pizza in in^2
	Area_Medium = medium_radius * medium_radius * PI;
	Area_Small = small_radius * small_radius * PI;

	// add up the total area by taking the amount of the size of the pizza times the area of that size of pizza and
	// add them all together.
	double total_large = 0, total_medium = 0, total_small = 0;
	total_large = large_Pizza * Area_Large;
	total_medium = Area_Medium * medium_Pizza;
	total_small = Area_Small*small_Pizza;
	total_Area = total_large + total_medium + total_small;

	// compute area per person by taking the total area and divide by the number of guests
	Area_Per_Person = total_Area / guests;
	// assign the given prices for each size of pizza
	large_price = 14.68;
	medium_price = 11.48;
	small_price = 7.28;

	// compute the cost by taking the number of that size of pizza, multiply by the cost per pizza, and then add each size up
	total_Cost = large_Pizza * large_price + medium_Pizza * medium_price + small_Pizza * small_price;
	// prompts user to input the amount of tip they would like to give
	cout << "Please enter the percent tip you would like to give: ";
	cin >> tip_Percent; // assign the input to tip_percent

	tip_Decimal = tip_Percent / 100; // convert number to decimal by dividing by 100
	tip = total_Cost*tip_Decimal;// find amount of tip by multiplying the total cost by the tip decimal amount
	total_Cost_with_tip = tip + total_Cost; // add the tip to the cost to find your total cost including the tip

	// Prints the input and output in the table that is found on learningSuite so that you can see all of the output at once
	cout
		<< "People:" << "\t\t\t" << guests << endl
		<< "Tip:" << "\t\t\t" << tip_Percent << "%" << endl
		<< "Larges:" << "\t\t\t" << large_Pizza << endl
		<< "mediums:" << "\t\t" << medium_Pizza << endl
		<< "smalls:" << "\t\t\t" << small_Pizza << endl
		<< "Total Area:" << "\t\t" << total_Area << endl
		<< "Area Per Person:" << "\t" << Area_Per_Person << endl
		<< "Cost ($):" << "\t\t$" << setprecision(0) << fixed << total_Cost_with_tip << endl << endl;

	// have the system pause before ending
	system("pause");
	return 0;// stops the code
}





