/* Author: Peyton Thibodeaux (Peytonthibodeaux@my.unt.edu)
 Date: 9/26/19
 Instructor:Dr. Pradhumna Shrestha
 Description:This program records a user input for an integer and compares it to a randomly generated number within the same range 
*/

#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main () {
//variables
int number, random;

//initilaiz random seed
srand(time(NULL));

//prompt the user
cout << "Enter a number between 50 and 100 (invlusively): ";
cin >> number;

//if else statement to check range

if (number >= 50 && number <= 100) {
	//calculate random number
	random = (rand() % 51) + 50;

	//output random number to user
	cout << "The random number is: " << random << endl;

	//compare the numbers
	if (number < random) {
		//result if random is greater
		printf("The random number %d is greater than your number %d \n", random, number);
	}else if (number > random) {
		//result if number is greater
		printf("The inputted number %d is greater than the random number %d \n", number, random);
	} else {
		//if the values are equal
		printf("The ranomd value %d is equal to your inputted value of %d \n", random, number);
	}

} else {
	//error message
	cout << "This number is not within range." << endl;
}




return 0;
}

