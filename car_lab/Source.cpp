#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Car.h"
#include <fstream>

using namespace std;

/*
******************Test case 1************************
input: 3
output:"What is the name, color, and price of the car you want to buy? "
input: Camry red 9999999
output: Car price too high
(failed because we don't have enough money to buy)

******************Test case 2************************
input: 6
output: "Please enter the file name: "
input: cars1.txt
Menu
input: 1
output:
Name: Jalopy 
Color: Blue 
Price: 3402.99
Name:Rustbucket
Color:Brown
Price: 44.99
Name:Lemon
Color:Yellow
Price: 4226.99
(loaded the file correctly)

******************Test case 3************************
input: 4
output: " What is the name of the car you want to sell?"
input: camry
output: "Car not in inventory"

*/
// functions

// adds a car
void add_Car(vector<Car>& Cars, string name_in, string color_in, double price_in)
{
	Car newCar = Car(name_in, color_in, price_in);// make object
	Cars.push_back(newCar);// push into vector
}
// Show Current Inventory
void Show_Current_Inventory(vector<Car> Cars)
{
	for (int i = 0; i < Cars.size(); i++)// run through vector
	{
		cout << Cars[i].toString();// print
	}// end for loop

}
// Show Current Balance
void Show_Current_Balance(vector<Car>& Cars, double Balance)
{
	cout << endl << "Current Balance: $"<< fixed << setprecision(2)<< Balance << endl;// show balance
}
// buys a car
void Buy_a_car(vector<Car>& Cars, string name_in, string color_in, double price_in,double& Balance)
{
	Car newCar = Car(name_in, color_in, price_in);// make new car
	Cars.push_back(newCar);// put car in vector
	Balance -= newCar.getPrice();// take money away from balance to buy car
}
// sells a car
void Sell_a_car(vector<Car>& Cars, string CarToSell, double& Balance)
{
	bool error = true;
	for (int i = 0; i < Cars.size(); i++)//run through vector
	{
		if (CarToSell == Cars[i].getName())// if car name is there
		{
			Balance += Cars[i].getPrice();// add price to balance
			Cars.erase(Cars.begin()+i);// sell car by erasing it and saying goodbye
			error = false;
		}
	}
	if (error)
	{
		cout << " Error: Car not found in the inventory";// notify them car is not there, so you cant sell
	}


}
// will paint a car
void Paint_a_car(vector<Car>& Cars,string CarToPaint,string colorOfPaint)
{
	bool error = true;
	for (int i = 0; i < Cars.size(); i++)//run through vector
	{
		if (CarToPaint == Cars[i].getName())// if car name is there
		{
			Cars[i].paint(colorOfPaint);// paint the car
			error = false;// false because it was found
		}
	}
	if (error)
	{
		cout << " Error: Car not found in inventory";// notify them car is not there
	}

}
// loads from a txt file some car
void load_file(vector<Car>& Cars, double& Balance)
{
	string filenameInput;
	string name,color;
	double price = 0,file_balance = 0;
	cout << "Please enter the file name: ";
	cin >> filenameInput;// get filename
	ifstream in_file;// open stream
	in_file.open(filenameInput.c_str());// open it
	if (in_file.fail())// if file is not there
	{
		cout << "File not there";// tell them not there
	}
	else
	{
		in_file >> file_balance;// get balance to start
		Balance += file_balance;// add to current balance
		while (in_file >> name)// get names till no more left
		{
			in_file >> color >> price;// get color and price
			add_Car(Cars, name, color, price);// make object/car 
		}
	}

	in_file.close();// close the file
}
// saves to a txt file
void Save_file(vector<Car>& Cars, double Balance)
{
	string userinputName;
	cout << " What is the name of the output file you want? ";
	cin >> userinputName;// get filename
	string lab8outputTXT = userinputName;

	ofstream outputfile; // makes a file
	outputfile.open(lab8outputTXT); // name file and open

	outputfile << fixed << setprecision(2) << Balance << endl;// put balance in

	for (int i = 0; i < Cars.size(); ++i) // run through inventory
	{
		outputfile << Cars[i].getName() << " " << Cars[i].getColor() << " " 
		 << fixed << setprecision(2) << Cars[i].getPrice() << endl; // put inventory in
	}
	outputfile.close(); // close file

}
// checks to see if we should buy the car
bool Should_I_buy_the_car(vector<Car>& Cars,string name_in,double price_in,double Balance)
{
	bool car_already_in_inventory = false;
	bool price_above_current_balance = false;
	bool yes_buy_car = true;
	bool no_dont_buy_car = false;

	for (int i = 0; i < Cars.size(); i++)// run thorugh vector
	{
		if (name_in == Cars[i].getName())// if true, car is in vector
		{
			car_already_in_inventory = true;// it is there
			cout << "Car already in inventory"<< endl; // tell them it is there
		}
	}
	if (price_in > Balance)// if more money than we have
	{
		price_above_current_balance = true;
		cout << "Car price too high" << endl;// can't afford it
	}
	// if either price is too high or car already there
	if (!price_above_current_balance && !car_already_in_inventory)
	{
		return yes_buy_car;
	}
	else
	{
		return no_dont_buy_car;
	}


}
// checks to see if car is in the vector
bool check_for_car(vector<Car>& Cars, string name_in)
{
	bool error = true;
	bool car_in_vector = true;
	bool car_not_in_vector = false;
	for (int i = 0; i < Cars.size(); i++)// run through the vector
	{
		if (name_in == Cars[i].getName())// if name is in vector
		{
			error = false;// no error
		}
	}
	if (error)// if error, car not there
	{
		return car_not_in_vector;
	}
	if (!error)// if no error, car is there
	{
		return car_in_vector;
	}


}

int main()
{
	// make car vector
	vector<Car> Cars;
	// set variables
	double Balance = 10000;
	int choice = 0, quit = 8, ton = 1000,reset = 0;
	int Show_CurrentInventory = 1, Show_CurrentBalance = 2, Buy_a_Car = 3,
		Sell_a_Car = 4, Paint_a_Car = 5, Load_file_choice = 6, Save_file_choice = 7;

	while (choice != quit){
		// set menu
		cout << endl
			<< "MENU: Please select one of the following options:" << endl // Menu
			<< "1 -" << " Show Current Inventory" << endl
			<< "2 -" << " Show Current Balance" << endl
			<< "3 -" << " Buy a Car" << endl
			<< "4 -" << " Sell a Car" << endl
			<< "5 -" << " Paint a Car" << endl
			<< "6 -" << " Load File" << endl
			<< "7 -" << " Save File" << endl
			<< "8 -" << " Quit Program" << endl
			<< "Enter your selection now: ";

		cin >> choice;


		if (choice == quit)// quit while loop
		{
			cout << "GOODBYE!" << endl;// say goodbye
		}
		if (cin.fail() == true)// test if it is not a number
		{
			// clear the cin values
			cin.clear();
			//ignore cin values
			cin.ignore(ton, '\n');
			choice = reset; // reset choice
		}

		if (choice == Show_CurrentInventory)// Shows CurrentInventory
			Show_Current_Inventory(Cars);
		if (choice == Show_CurrentBalance)//  Shows CurrentBalance
			Show_Current_Balance(Cars,Balance);
		if (choice == Buy_a_Car)// buys a car
		{
			string name_in, color_in;// set variables
			double price_in;
			cout <<"What is the name, color, and price of the car you want to buy? " << endl;
			cin >> name_in >> color_in >> price_in;// get input
			// checks to see if you have enought money and don't have car yet
			if (Should_I_buy_the_car(Cars, name_in, price_in , Balance))
				Buy_a_car(Cars, name_in, color_in, price_in, Balance);//buys car


		}
		if (choice == Sell_a_Car)// sell a car
		{
			string CarToSell;
			cout << "What is the name of the car you want to sell ? " << endl;
			cin >> CarToSell;
			if (check_for_car(Cars, CarToSell))// check to see if car is there
			{
				Sell_a_car(Cars, CarToSell, Balance);//sell car
			}
			else
			{
				cout << "Car not in inventory";// notify user car not there
			}
		}
		if (choice == Paint_a_Car)// paints the car
		{
			string CarToPaint, colorOfPaint;
			cout << " What is the name of the car ? " << endl;
			cin >> CarToPaint;
			// paints the car if car is in array
			if (check_for_car(Cars, CarToPaint))// check if in array
			{
				cout << " What is the color you want to paint it ? " << endl;
				cin >> colorOfPaint;// get color to paint
				Paint_a_car(Cars, CarToPaint, colorOfPaint);// paint car
			}
			else
			{
				cout << "Car not in inventory";// notify user car not there
			}
		}
		if (choice == Load_file_choice)// load a file with .txt
			load_file(Cars, Balance);
		if (choice == Save_file_choice)// save a file with .txt
			Save_file(Cars, Balance);

	} // end while loop

	// have the system pause before ending
	system("pause");
	return 0;// stops the code

} //end main
















