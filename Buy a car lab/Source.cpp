#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
/* Extra Credit

 gas milage of hybrid would have to be
      mpg = 166.6666666666666;

*/

/*unique test cases
***************Test case 1****************
The estimated miles driven per year = 10000
The estimated price of a gallon of gas during the 5 years of ownership = 3.5
The initial cost of a hybrid car = 40000
The efficiency of the hybrid car in miles per gallon = 1000
The estimated resale value (a dollar amount) for a hybrid after 5 years = 4000
The initial cost of a non-hybrid car = 20000
The efficiency of the non-hybrid car in miles per gallon = 30
The estimated resale value (a dollar amount) for a non-hybrid after 5 years = 2000
The user's buying criterion = Total

Results:
non-hybrid
Fuel consumption:	1666.67
Total cost:			23833.3
hybrid
Fuel consumption:	50
Total cost:			36175

***************Test case 2****************
The estimated miles driven per year = 12000
The estimated price of a gallon of gas during the 5 years of ownership = 10
The initial cost of a hybrid car = 25000
The efficiency of the hybrid car in miles per gallon = 50
The estimated resale value (a dollar amount) for a hybrid after 5 years = 17000
The initial cost of a non-hybrid car = 25000
The efficiency of the non-hybrid car in miles per gallon = 25
The estimated resale value (a dollar amount) for a non-hybrid after 5 years = 15000
The user's buying criterion = Gas

Results:
hybrid
Fuel consumption:	1200
Total cost:			20000
non-hybrid
Fuel consumption:	2400
Total cost:			34000

***************Test case 3****************
The estimated miles driven per year = 200
The estimated price of a gallon of gas during the 5 years of ownership = 50
The initial cost of a hybrid car = 35000
The efficiency of the hybrid car in miles per gallon = 500
The estimated resale value (a dollar amount) for a hybrid after 5 years = 1000
The initial cost of a non-hybrid car = 25000
The efficiency of the non-hybrid car in miles per gallon = 25
The estimated resale value (a dollar amount) for a non-hybrid after 5 years = 15000
The user's buying criterion = Total

Results:
non-hybrid
Fuel consumption:	40
Total cost:			12000
hybrid
Fuel consumption:	2
Total cost:			34100

*/ 

int main()
{
	// initialize variables
	float miles_driven_per_year = 0, price_of_a_gallon_of_gas = 0, initial_cost_hybrid = 0, efficiency_hybrid = 0;
	float resale_value_hybrid = 0, initial_cost_non_hybrid = 0, efficiency_non_hybrid = 0, resale_value_non_hybrid = 0;
	string minimized_amount;
	// Prompt user for input
	cout << "What is the estimated miles driven per year? ";
	cin >> miles_driven_per_year;
	// If statement to test to see if input is positive.
	if (miles_driven_per_year <= 0){
		cout << "Only positive numbers are valid" << endl;
		cout << "What is the estimated miles driven per year? ";
		cin >> miles_driven_per_year;
	}
	// Prompt user for input
	cout << "What is the estimated price of a gallon of gas during the 5 years of ownership? ";
	cin >> price_of_a_gallon_of_gas;
	// If statement to test to see if input is positive.
	if (price_of_a_gallon_of_gas <= 0){
		cout << "Only positive numbers are valid" << endl;
		cout << "What is the estimated price of a gallon of gas during the 5 years of ownership? ";
		cin >> price_of_a_gallon_of_gas;
	}
	// Prompt user for input
	cout << "What is the initial cost of a hybrid car? ";
	cin >> initial_cost_hybrid;
	// If statement to test to see if input is positive.
	if (initial_cost_hybrid <= 0){
		cout << "Only positive numbers are valid" << endl;
		cout << "What is the initial cost of a hybrid car? ";
		cin >> initial_cost_hybrid;
	}
	// Prompt user for input
	cout << "What is the efficiency of the hybrid car in miles per gallon? ";
	cin >> efficiency_hybrid;
	// If statement to test to see if input is positive.
	if (efficiency_hybrid <= 0){
		cout << "Only positive numbers are valid" << endl;
		cout << "What is the efficiency of the hybrid car in miles per gallon? ";
		cin >> efficiency_hybrid;
	}
	// Prompt user for input
	cout << "What is the estimated resale value (a dollar amount) for a hybrid after 5 years? ";
	cin >> resale_value_hybrid;
	// If statement to test to see if input is positive.
	if (resale_value_hybrid <= 0){
		cout << "Only positive numbers are valid" << endl;
		cout << "What is the estimated resale value (a dollar amount) for a hybrid after 5 years? ";
		cin >> resale_value_hybrid;
	}
	// Prompt user for input
	cout << "What is the initial cost of a non-hybrid car? ";
	cin >> initial_cost_non_hybrid;
	// If statement to test to see if input is positive.
	if (initial_cost_non_hybrid <= 0){
		cout << "Only positive numbers are valid" << endl;
		cout << "What is the initial cost of a non-hybrid car? ";
		cin >> initial_cost_non_hybrid;
	}
	// Prompt user for input
	cout << "What is the efficiency of the non-hybrid car in miles per gallon? ";
	cin >> efficiency_non_hybrid;
	// If statement to test to see if input is positive.
	if (efficiency_non_hybrid <= 0){
		cout << "Only positive numbers are valid" << endl;
		cout << "What is the efficiency of the non-hybrid car in miles per gallon? ";
		cin >> efficiency_non_hybrid;
	}
	// Prompt user for input
	cout << "What is the estimated resale value (a dollar amount) for a non-hybrid after 5 years? ";
	cin >> resale_value_non_hybrid;
	// If statement to test to see if input is positive.
	if (resale_value_non_hybrid <= 0){
		cout << "Only positive numbers are valid" << endl;
		cout << "What is the estimated resale value (a dollar amount) for a non-hybrid after 5 years? ";
		cin >> resale_value_non_hybrid;
	}
	//The user's buying criterion, either  minimized "Gas" consumption or minimized "Total" cost. assume one of two strings.;
	cout << "Minimized Gas consumption or minimized Total cost?" <<endl;
	cin >> minimized_amount;


	//Initialize variables
	double fuel_consumption_hybrid = 0, total_cost_hybrid = 0, fuel_consumption_non_hybrid = 0, total_cost_non_hybrid = 0, years_owned = 0;
	years_owned = 5; // How many years you have owned the car;

	// compute total fuel consumption for hybrid and non hybrid for 5 years;
	fuel_consumption_hybrid = miles_driven_per_year / efficiency_hybrid*years_owned; 
	fuel_consumption_non_hybrid = miles_driven_per_year / efficiency_non_hybrid*years_owned; 

	// take total gallons consumed and multiply by the price per gallon to find total cost of fuel and add to the cost of the car minus the resale value
	total_cost_hybrid = fuel_consumption_hybrid * price_of_a_gallon_of_gas
		+ initial_cost_hybrid - resale_value_hybrid;

	total_cost_non_hybrid = fuel_consumption_non_hybrid * price_of_a_gallon_of_gas
		+ initial_cost_non_hybrid - resale_value_non_hybrid;

	// determines which car to list first. The one with lower gas consupmtion or lower cost.
	// if Gas, list the one that uses the least amount of Gas first
	if (minimized_amount == "Gas"){
		if (fuel_consumption_hybrid >= fuel_consumption_non_hybrid){
			cout << "non-hybrid" << endl << "Fuel consumption:""\t" << fuel_consumption_non_hybrid << endl << "Total cost:""\t\t" << total_cost_non_hybrid <<endl << endl
				<< "hybrid" << endl << "Fuel consumption:""\t" << fuel_consumption_hybrid << endl << "Total cost:""\t\t" << total_cost_hybrid << endl << endl;
		}
		else {
			cout << "hybrid" << endl << "Fuel consumption:""\t" << fuel_consumption_hybrid << endl << "Total cost:""\t\t" << total_cost_hybrid << endl << endl
				<< "non-hybrid" << endl << "Fuel consumption:""\t" << fuel_consumption_non_hybrid << endl << "Total cost:""\t\t" << total_cost_non_hybrid << endl;
		}

	}
	// if Total, then list the cheapest one first
	if (minimized_amount == "Total"){
		if (total_cost_hybrid >= total_cost_non_hybrid){
			cout << "non-hybrid" << endl << "Fuel consumption:""\t" << fuel_consumption_non_hybrid << endl << "Total cost:""\t\t" << total_cost_non_hybrid <<endl << endl
				 << "hybrid" << endl << "Fuel consumption:""\t" << fuel_consumption_hybrid << endl << "Total cost:""\t\t" << total_cost_hybrid << endl << endl;
				
		}
		else {
			cout << "hybrid" << endl << "Fuel consumption:""\t" << fuel_consumption_hybrid << endl << "Total cost:""\t\t" << total_cost_hybrid << endl << endl
				 << "non-hybrid" << endl << "Fuel consumption:""\t" << fuel_consumption_non_hybrid << endl << "Total cost:""\t\t" << total_cost_non_hybrid << endl;
		}

	}
	// Pause
	system("pause");
	// Exit or end program.
	return 0;
}





