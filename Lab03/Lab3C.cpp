#include <iostream>
#include <math.h>
using namespace std;

int main( )
{
    	/*
	Author: Peyton Thibodeaux (Peytonthibodeaux@my.unt.edu)
 	Date:   9/12/2019
 	Instructor: Shrestha,Pradhumna Lal
 	Description: This program will compute the discounted price of a purchase
	*/

	//variables
	float markedPrice, discountedPrice;
	const float DISCOUNTRATE = 0.1275; //our discount rate of 12.75%

	//prompt user and get input
	cout << "Enter the marked price:";
	cin >> markedPrice;

	//computations
	discountedPrice = markedPrice * (1 - DISCOUNTRATE);

	//change cout to display 2 decimal places
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	//display result
	cout << "The discounted price is $" << discountedPrice << endl;




    return 0;
}
