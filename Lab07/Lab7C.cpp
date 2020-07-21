/* Author: Peyton Thibodeaux (peytonthibodeaux@my.unt.edu)
 Date: 10/24/2019
 Instructor: Dr. Pradhumna Shrestha
 Description: This program
 */
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstring>
using namespace std;

/* Function: string_replace
Parameters: char array with user input in it 
			char array with first option to replace 
			char array with second option to replace 
Return: void
Description: This function changes a user input to one of two options*/
void string_replace(char input[], char option1[], char option2[]);

int main() {
	//variables
	char input[10] = {0};
	char option1[] = "yellow";
	char option2[] = "cyan";
	
	//get input
	cout << "Enter a color " << endl;
	cin.getline(input, 10);
	
	//call the string replace function
	string_replace(input, option1, option2);
	
	cout << "It has changed to " << input << endl;



return 0;
}

void string_replace(char input[], char option1[], char option2[]){
	//if statement
	if(strcmp (input, "red") == 0 || strcmp (input, "blue") == 0 || strcmp (input, "black") == 0){
		strcpy(input, option1);
	} else {
		strcpy(input, option2);
	}
}