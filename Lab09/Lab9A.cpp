/* Author: Peyton Thibodeaux (peytonthibodeaux@my.unt.edu)
 Date: 11/14/2019
 Instructor: Dr. Pradhumna Shrestha
 Description: This program calculate sif someone has a healthy bmi
 */
#include <iostream>
#include <fstream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <cstring>
#include <ctime>
#include <cmath>
using namespace std;

struct Patient{
	string name;	//person's name
	float weight;	//weight of person in pounds
	int feet;		//number of feet
	int inches;		//number of inches
};

bool checkBMI(Patient);

int main() {
	//person variable
	Patient person;
	
	//get inputs
	cout << "Enter the person's name: ";
	getline(cin, person.name);
	
	cout << "Enter the person's weight in pounds: ";
	cin >> person.weight;
	
	cout << "Enter he person's height in feet and inches: ";
	cin >> person.feet >> person.inches;
	
	//if statement
	if (checkBMI(person))
	{
		cout << "The BMI of " << person.name << " is within range." << endl;
	}
	else 
	{
		cout << "The BMI of " << person.name << " is not within range." << endl;
	}
return 0;
}

bool checkBMI(Patient person)
{
	//combine height for bmi calculation
	int totalHeight = person.feet * 12 + person.inches;
	//calculate bmi
	float bmi = (703 * person.weight)/pow(totalHeight,2);
	//return true or false
	return(bmi>=18.5 && bmi <=24.9);
	
}
