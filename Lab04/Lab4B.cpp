/* Author: Peyton Thibodeaux (Peytonthibodeaux@my.unt.edu)
 Date: 9/26/19
 Instructor:Dr. Pradhumna Shrestha
 Description: This program tells you te season based on the month entered
*/

#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main () {
//variables
int month;

//prompt user input
cout << "Enter the month as an integer (ie 5= may, 12 = december): ";
cin >>  month;

//switch statement
switch (month) {
	//winter months
	case 12:
	case 1:
	case 2:
	cout << "It's winter" << endl;
	break;
	//Spring months
	case 3:
	case 4:
	case 5:
	cout << "It's spring" << endl;
	break;
	//Summer months
	case 6:
	case 7:
	case 8:
	cout << "It's Summer" << endl;
	break;
	// Fall months
	case 9:
	case 10:
	case 11:
	cout << "It's Fall" << endl;
	break;
	//default statement
	default: 
	cout << "I do not recognize this month" << endl;
	break;
}








return 0;
}

