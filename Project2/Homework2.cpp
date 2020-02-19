/* Author: Peyton Thibodeaux (Peytonthibodeaux@my.unt.edu)
 Date: 10/3/19
 Instructor:Dr. Pradhumna Shrestha
 Description:This program calulates shipping cost off of a number of factors inputted by the user.
*/

#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main () {
	//display information
	cout << "+----------------------------------------------+\n";
	cout << "|	 Computer Science and Engineering	|\n";
	cout << "|	 CSCE 1030 - Computer Science I	 	|\n";
	cout << "| Peyton Thibodeaux PWT0013 PWT0013@my.unt.edu |\n";
	cout << "+----------------------------------------------+\n";

	//variables
	enum service {AIR = 1, TRUCK = 2, COURIER = 3, EXIT = 4};
	int zip_code_destination, zip_code_origin, option, zip_cost;
	double weight, ship_cost = -1;
	//note since zip_cost is an integer this means with close enough zip codes it would round down to 0 and total shipping cost would be $0

	//loop options
	do
	{
		cout << "+******************* M E N U ******************+\n";
		cout << "| Choose a Service for Package Delivery:        |\n";
		cout << "| 1. FastShip Air (EXPEDITED)	           	|\n";
		cout << "| 2. FastShip Freight Truck (PRIORITY)       	|\n";
		cout << "| 3. FastShip Local Courier (STANDARD)    	|\n";
		cout << "| 4. Exit				        |\n";
		cout << "+******************* M E N U ******************+\n";

		//get user input
		cin >> option;

		//switch statement to get ship_cost
		switch (option) {
			case AIR:
			ship_cost = 0.295;
			break;

			case TRUCK:
			ship_cost = 0.165;
			break;

			case COURIER:
			ship_cost = 0.085;
			break;

			case EXIT:
			ship_cost = -1;
			break;

			default:
			ship_cost = -1;
			cout << "\nThis is not a valid input, try again\n";
			break;
		}

		//perform calculations if valid input was given
		if (ship_cost != -1)
		{
			//zip code origin
			do
			{
				//Prompt for origin input and store in zip_code_origin;
				cout << "\nplease enter the zip code of the origin: ";
				cin >> zip_code_origin;
				//check if valid number
				if (zip_code_origin < 0 || zip_code_origin > 99999) 
				{
					cout << "\nthis zip code is out of range, please try again";
				}
			} while (zip_code_origin < 0 || zip_code_origin > 99999);

			//zip code of the destination
			do
			{
				//Prompt for origin input and store in zip_code_destination;
				cout << "\nplease enter the zip code of the destination: ";
				cin >> zip_code_destination;
				//check if valid number
				if (zip_code_destination < 0 || zip_code_destination > 99999) 
				{
					cout << "\nthis zip code is out of range, please try again";
				}
			} while (zip_code_destination < 0 || zip_code_destination > 99999);

			//calulate zip code cost
			zip_cost = fabs(zip_code_destination - static_cast<double>(zip_code_origin));
			zip_cost = zip_cost / 1000;
			//note you could use a ceil() to make sure zip_cost is never 0 and also raise shipping prices slightly if you wnated to do so

			//get weight
			do
			{
				cout << "\nEnter the weight of the package in pounds: ";
				cin >> weight;
				//check if valid number
				if (weight != fabs(weight))
				{
					cout << "\nThis is not a valid weight, please try again.";
				}

			} while (weight != fabs(weight));

			//calculate ship cost
			ship_cost = zip_cost * ship_cost * weight;

			//display with formatting
			printf("\nThe shipping cost of this delivery would be $%.2F \n", ship_cost);

		}

	} while (option != EXIT);

	cout << "\nThank you for using our service, have a great day." << endl;

	return 0;
}

