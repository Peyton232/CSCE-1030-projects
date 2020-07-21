/* Author: Peyton Thibodeaux (Peytonthibodeaux@my.unt.edu)
 Date: 10/3/19
 Instructor:Dr. Pradhumna Shrestha
 Description:This program displays a random character from a string then tells you what kind of character it is.
*/

#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main () {
	//random seed time
	srand(time(NULL));

	//string
	string my_str = "This is a strng, It contains punctuation, numbers (3348798787928236996286556), and spaces    I wrote it for @Lab5 of CCE1030................................................";

	//display string
	cout << my_str << "\nThis is the string we are using above " << endl;

	//initiliaze random seed
	int index = rand() % (my_str.length());
	char extracted = my_str.at(index);

	//display character
	cout << "The random character is "  << extracted << " at index "  << index <<  endl;

	//cout for random string
	if (isalpha(extracted))
	{
		cout << "Letter."<<endl;
	}
	else if (isdigit(extracted))
	{
		cout << "number" << endl;
	} else if (isspace(extracted))
	{
		cout << "Space." << endl;
	} else
	{
		cout << "special character" << endl;
	}


	return 0;
}

