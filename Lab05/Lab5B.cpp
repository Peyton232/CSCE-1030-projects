/* Author: Peyton Thibodeaux (Peytonthibodeaux@my.unt.edu)
 Date: 10/3/19
 Instructor:Dr. Pradhumna Shrestha
 Description:This program takes a user inputted string and counts the letters, numbers, spaces, and special characters in it and then displays them to the user.
*/

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
using namespace std;

int main () {
//variables
int index = 0, count_letter = 0, count_num = 0, count_space = 0, count_special = 0;
string my_str;

//get string
cout << "Enter a string ";
getline(cin, my_str);



while(index < my_str.length())
{

	if (isalpha(my_str.at(index)))
	{
		count_letter ++;
	}
	else if (isdigit(my_str.at(index)))
	{
		count_num ++;
	}
		else if (isspace(my_str.at(index)))
	{
		count_space ++;
	}
 	else
	{
		count_special ++;
	}

	//increase index
	index++;
}

//display results
printf ("\nThere are %d letters, %d numbers, %d spaces, and %d special characters\n.", count_letter, count_num, count_space, count_special );



return 0;
}

