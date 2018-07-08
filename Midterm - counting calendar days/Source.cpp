// search algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::search
#include <vector>       // std::vector
#include <cstdlib>
#include <string>
#include <stdlib.h>     /* atoi */
#include <cstring>

using namespace std;

/* test cases

test 1*************
input:
January 1, 2000
December 25, 1600

output:
There are 145738 days between December 25, 1600 and January 1, 2000

test 2*************
input:
dec 1, 2000

output:
[invalid MONTH]

test 3*************
input:
December 40, 2001

output:
[invalid DAY]

test 4*************
input: February 29, 2015

output:
[invalid DAY]


*/


int main() {

	// initialize variables
	int quit = 1;
	// while (quit != 0){
		int good = 1, bad = 0;
		int month_check = bad, day_check = bad, year_check = bad;
		int month_end1 = 0;
		int year1 = 0;
		int day1 = 0;
		string month1;
		int month2_number = 0;
		int month1_number = 0;
		string is = " is ";
		string are = " are ";
		int zero = 0;
		int one = 1, two = 2, three = 3, four = 4, five = 5, six = 6, seven = 7, eight = 8, nine = 9,
			ten = 10, eleven = 11, twelve = 12, thousand = 1000;
		int January = 1, February = 2, March = 3, April = 4, May = 5, June = 6, July = 7, August = 8,
			September = 9, October = 10, November = 11, December = 12;
		int last_year = 1582;
		int thirty_one_days = 31, thirty_days = 30, twenty_eight_days = 28, twenty_nine_days = 29;
		int year_total_days = 365, leap_year_total_days = 366;
		// close variables

		// check first input if good with while loop
		while ((month_check != good) || (day_check != good) || (year_check != good))
		{

			// get input
			string input1, input11, input111;
			cin >> input1 >> input11 >> input111;
			month_end1 = 0;
			year1 = 0;
			// divide up input
			string comma = ",";
			int comma_find1 = input11.find(comma);
			day1 = atoi(input11.substr(zero, comma_find1).c_str());
			month_end1 = two;
			if (input11.length() == two)
			{
				day1 = atoi(input11.substr(zero, comma_find1).c_str()); // take out comma and make into an integer
				month_end1 = one;
			}
			month1 = input1;
			year1 = atoi(input111.substr(zero, input111.length()).c_str()); // get the year into integer




			// check statements 1
			//year check
			if (year1 >= last_year)
				year_check = good;
			else
				year_check = bad;

			//month check
			if ((month1 == "January") || (month1 == "February") || (month1 == "March") || (month1 == "April")
				|| (month1 == "May") || (month1 == "June") || (month1 == "July") || (month1 == "August")
				|| (month1 == "September") || (month1 == "October") || (month1 == "November") || (month1 == "December"))
			{
				month_check = good;
			}
			else
				month_check = bad;

			// day check
			int hundred = 100, fourhundred = 400;

			if ((day1 > thirty_one_days) || (day1 <= zero)) // too big of day
				day_check = bad;
			else if (month1 == "February") // feb check
			{
				if ((day1 == twenty_eight_days) && (year1 % four != zero)) // 28 days good
					day_check = good;
				else if ((day1 == twenty_nine_days) && (year1 % four == zero)) // 29 check
				{
					if ((year1 % hundred == zero) && (year1 % fourhundred != zero) && (year1 % four == zero)) // not leap year check
						day_check = bad;
					else
						day_check = good;
				}
				else if ((day1 < twenty_eight_days) && (day1 > zero)) // under 28 days check
					day_check = good;
				else
					day_check = bad;

			}
			else if (day1 == thirty_one_days)// months with 31 days
			{
				if ((month1 == "September") || (month1 == "April") || (month1 == "June") || (month1 == "November"))
					day_check = bad;
				else if (month1 == "February")
					day_check = bad;
				else
					day_check = good;
			}
			else if (day1 == 29) // check for february again
			{
				if ((year1 % hundred == zero) && (year1 % fourhundred != zero) && (year1 % four == zero))
					day_check = bad;
				else
					day_check = good;
			}
			else
				day_check = good;

			/*	// check for dates later this year (2016) that are not valid
			if((year1 == 2016)&&(month1_number > 2)){
			year_check = bad;
			month_check = bad;
			} else if((day1 > 19)&&(year1 == 2016)&&(month1_number == 2)){
			year_check = bad;
			day_check = bad;
			month_check = bad;
			}
			*/
			// end check for dates later this year (2016) not valid
			// notify user if bad input
			if ((month_check != good) || (day_check != good) || (year_check != good)){
				int thousand1 = 1001;
				if ((month_check != good))
					cout << endl << "[invalid MONTH]" << endl;
				else if ((day_check != good))
					cout << endl << "[invalid DAY]" << endl;
				else if ((year_check != good))
					cout << endl << "[invalid YEAR]" << endl;
				// clear the cin values
				cin.clear();
				//ignore cin values
				cin.ignore(thousand1, '\n');
			}

		}// End while loop to check for input

		// end check statements 1

		//						check statements 2222222222222222222222222222222
		month_check = bad;
		day_check = bad;
		year_check = bad;
		int month_end2 = 0;
		int year2 = 0;
		int day2 = 0;
		string month2;
		while ((month_check != good) || (day_check != good) || (year_check != good)) // while loop check statements 2
		{

			// get input
			string input2, input22, input222;
			cin >> input2 >> input22 >> input222;
			month_end2 = 0;
			year2 = 0;

			string comma = ",";
			int comma_find2 = input22.find(comma);
			day2 = atoi(input22.substr(zero, comma_find2).c_str()); // get day2 without comma and make into integer
			month_end2 = two;
			if (input22.length() == two){
				day2 = atoi(input22.substr(zero, comma_find2).c_str()); // get day2 without comma and make into integer
				month_end2 = one;
			}
			month2 = input2; // .substr(zero,comma_find2-month_end2);
			year2 = atoi(input222.substr(zero, input222.length()).c_str()); // get year2 and make into integer


			//year check2
			if (year2 >= last_year)
				year_check = good;
			else
				year_check = bad;

			//month check2
			if ((month2 == "January") || (month2 == "February") || (month2 == "March") || (month2 == "April")
				|| (month2 == "May") || (month2 == "June") || (month2 == "July") || (month2 == "August")
				|| (month2 == "September") || (month2 == "October") || (month2 == "November") || (month2 == "December"))
			{
				month_check = good;
			}
			else
				month_check = bad;

			// day check2
			int hundred = 100, fourhundred = 400;
			if ((day2 > thirty_one_days) || (day2 <= zero))
				day_check = bad;
			else if (month2 == "February")
			{
				if ((day2 == twenty_eight_days) && (year2 % four != zero))
					day_check = good;
				else if ((day2 == twenty_nine_days) && (year2 % four == zero))
				{
					if ((year2 % hundred == zero) && (year2 % fourhundred != zero) && (year2 % four == zero))
						day_check = bad;
					else
						day_check = good;
				}
				else if ((day1 < twenty_eight_days) && (day1 > zero))
					day_check = good;
				else
					day_check = bad;

			}
			else if (day2 == thirty_one_days)// months with 31 days
			{
				if ((month2 == "September") || (month2 == "April") || (month2 == "June") || (month2 == "November"))
					day_check = bad;
				else if (month2 == "February")
					day_check = bad;
				else
					day_check = good;
			}
			else if (day1 == twenty_nine_days) // 29 days
			{
				if ((year2 % hundred == zero) && (year2 % fourhundred != zero) && (year2 % four == zero))
					day_check = bad;
				else
					day_check = good;
			}
			else
				day_check = good;
			/*
			// check for dates later this year (2016) that are not valid
			if((year2 == 2016)&&(month2_number > 2)){
			year_check = bad;
			month_check = bad;
			} else if((day2 > 19)&&(year2 == 2016)&&(month2_number == 2)){
			year_check = bad;
			day_check = bad;
			month_check = bad;
			}
			*/
			// notify if invalid
			if ((month_check != good) || (day_check != good) || (year_check != good)){
				if ((month_check != good))
					cout << endl << "[invalid MONTH]" << endl;
				else if ((day_check != good))
					cout << endl << "[invalid DAY]" << endl;
				else if ((year_check != good))
					cout << endl << "[invalid YEAR]" << endl;
				// clear the cin values
				cin.clear();
				//ignore cin values
				cin.ignore(1000, '\n');
			}

		}// close while loop check statements 2


		// correct order
		if (year1 > year2) // flips year1 with year2 values, vice versa
		{
			int year11 = year2;
			string month11 = month2;
			int day11 = day2;
			year2 = year1;
			month2 = month1;
			day2 = day1;
			year1 = year11;
			month1 = month11;
			day1 = day11;
		}



		// if statements to turn month into number

		if (month1 == "January")
			month1_number = January;
		if (month1 == "February")
			month1_number = February;
		if (month1 == "March")
			month1_number = March;
		if (month1 == "April")
			month1_number = April;
		if (month1 == "May")
			month1_number = May;
		if (month1 == "June")
			month1_number = June;
		if (month1 == "July")
			month1_number = July;
		if (month1 == "August")
			month1_number = August;
		if (month1 == "September")
			month1_number = September;
		if (month1 == "October")
			month1_number = October;
		if (month1 == "November")
			month1_number = November;
		if (month1 == "December")
			month1_number = December;
		//close if statements
		// if statements to turn month into number

		if (month2 == "January")
			month2_number = January;
		if (month2 == "February")
			month2_number = February;
		if (month2 == "March")
			month2_number = March;
		if (month2 == "April")
			month2_number = April;
		if (month2 == "May")
			month2_number = May;
		if (month2 == "June")
			month2_number = June;
		if (month2 == "July")
			month2_number = July;
		if (month2 == "August")
			month2_number = August;
		if (month2 == "September")
			month2_number = September;
		if (month2 == "October")
			month2_number = October;
		if (month2 == "November")
			month2_number = November;
		if (month2 == "December")
			month2_number = December;
		// close if 



		// Switch just months if month1>month2
		if ((year1 == year2) && (month1_number > month2_number)) // Switch just months if month1>month2
		{
			string month11 = month2;
			int day11 = day2;
			int month1_number11 = month2_number;
			month2 = month1;
			day2 = day1;
			month2_number = month1_number;
			month1 = month11;
			day1 = day11;
			month1_number = month1_number11;
		}

		const int month1_number_constant = month1_number;
		// close switch order stuff

		// initialize variables
		int hundred = 100, fourhundred = 400;
		int year_days = zero;
		int i = 0;
		int year1_plus = year1 + one;
		int end = year2 - one;
		i = year1_plus;
		// year count 
		if (year1 < year2) // day count for years different
		{
			for (i; i <= end; i++)
			{
				if ((i % four) == zero)
				{
					if ((i % hundred == zero) && (i % fourhundred != zero) && ((i % four) == zero)) // leap year check
						year_days += 365; // not leap year
					else
						year_days += 366; // leap year
				}
				else
				{
					year_days += 365;// not leap year
				}

			}// end for loop years
		}

		// start the big calculations





		// for day1 month1 year1
		// variables
		int days_in_month1 = 0, day_finish_month1 = day1, Days_finish_month_count1 = 0;

		//assign days in each month
		if ((month1 == "September") || (month1 == "April") || (month1 == "June") || (month1 == "November"))
		{
			days_in_month1 = thirty_days;
		}
		else if (month1 == "February")
		{
			days_in_month1 = twenty_eight_days;
			if (year1 % four == zero)
				days_in_month1 = twenty_nine_days;
			if ((year1 % hundred == zero) && (year1 % fourhundred != zero) && (year1 % four == zero))
				days_in_month1 = twenty_eight_days;
		}
		else
		{
			days_in_month1 = thirty_one_days;
		}
		// end assign days in each month

		// day count to end of month
		while (day_finish_month1 <= days_in_month1) // count till end of month
		{
			day_finish_month1 = day_finish_month1 + one;
			Days_finish_month_count1 += one;
		}
		Days_finish_month_count1;
		// end of count till end of month
		// variables
		int end_month = 12;
		int days_left_in_months_after = 0;
		int days_in_month_next = 0;
		if (year1 == year2)
			end_month = month2_number - one;
		int start = month1_number + 1;
		int add_month = 0;
		if (year1 != year2)
		{
			add_month = one;
		}

		// count up months with days
		while (start <= end_month) // count the months and add days in months till end of year
		{
			month1_number = start;
			days_in_month_next = 0; // re-assing to zero
			// cout << month1_number<<endl;
			if ((month1_number == September) || (month1_number == April) || (month1_number == June) || (month1_number == November)){
				days_in_month_next = thirty_days;
			}
			else if (month1_number == February)
			{
				days_in_month_next = twenty_eight_days;
				if (year1 % four == zero)
					days_in_month_next = twenty_nine_days;
				if ((year1 % hundred == zero) && (year1 % fourhundred != zero) && (year1 % four == zero))
					days_in_month1 = twenty_eight_days;
			}
			else{
				days_in_month_next = thirty_one_days;
			}

			days_left_in_months_after += days_in_month_next;
			start++;
		}
		// end of day1 month1 year1

		// for day2 month2 year2 countdown
		int days_in_month2 = 0, day_finish_month2 = day2, Days_finish_month_count2 = 0;
		int days_left_in_months_after2 = 0;
		int first_month = 1;
		int old_month2_number = month2_number;
		month2_number = month2_number - one;
		// countdown from second date
		if (year1 == year2)
			first_month = month1_number_constant;
		while (month2_number >= first_month) // count down while month2 is still bigger
		{
			days_in_month2 = zero; // reassign to zero
			if ((month2_number == September) || (month2_number == April) || (month2_number == June) || (month2_number == November))
				days_in_month2 = thirty_days;
			else if (month2_number == February)
			{
				days_in_month2 = twenty_eight_days;
				if (year2 % four == zero)
					days_in_month2 = twenty_nine_days;
				if ((year2 % hundred == zero) && (year2 % fourhundred != zero) && (year2 % four == zero))
					days_in_month2 = twenty_eight_days;
			}
			else{
				days_in_month2 = thirty_one_days;
			}

			days_left_in_months_after2 += days_in_month2;
			month2_number--;
		}
		month2_number = old_month2_number;
		if (year1 == year2)
			days_left_in_months_after2 = zero;

		// end of day2 month2 year2

		int difference = zero;
		int day2_less = day2 - one;
		difference = Days_finish_month_count1 + days_left_in_months_after + year_days + days_left_in_months_after2 + day2_less;

		// start to calculate differences
		if ((year1 == year2) && (month1 == month2)) // if same month and year
		{
			Days_finish_month_count1 = zero;
			days_left_in_months_after = zero;
			year_days = zero;
			days_left_in_months_after2 = zero;
			if (day1 < day2)
				difference = day2 - day1;
			if (day2 < day1)
				difference = day1 - day2;
			if (day2 == day1)
				difference = zero;
			// one day difference change grammar
			if (difference == one){
				cout << "There" << is << difference << " day between " << month1 << " " << day1 << "," << " " << year1
					<< " and " << month2 << " " << day2 << "," << " " << year2 << "." << endl;
			}
			else{
				cout << "There" << are << difference << " days between " << month1 << " " << day1 << "," << " " << year1
					<< " and " << month2 << " " << day2 << "," << " " << year2 << "." << endl;
			}
		}
		else
		{
			difference = Days_finish_month_count1 + days_left_in_months_after + year_days + days_left_in_months_after2 + day2_less;
			if (difference == one){
				cout << "There" << is << difference << " day between " << month1 << " " << day1 << "," << " " << year1
					<< " and " << month2 << " " << day2 << "," << " " << year2 << "." << endl;
			}
			else{
				cout << "There" << are << difference << " days between " << month1 << " " << day1 << "," << " " << year1
					<< " and " << month2 << " " << day2 << "," << " " << year2 << "." << endl;
			}
		}


	// }// end while loop big

	system("Pause");
}// end main function











