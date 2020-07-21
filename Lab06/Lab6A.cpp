/* Author: Peyton Thibodeaux (peytonthibodeaux@my.unt.edu)
 Date: 10/17/2019
 Instructor: Dr. Pradhumna Shrestha
 Description: This program picks the first 5 vowels from a string and displays them
 */
#include <iostream>
using namespace std;

int main() {
	const int SIZE = 10; //10 students
	int grade[SIZE]; // array to store 10 grades
	int pass[SIZE]; //arrays to store pass
	int fail[SIZE]; //arrays to store fail
	int passCount = 0, failCount = 0;

	for (int i = 0; i < SIZE; i++) {
		cout << "Enter grade of student #" << i + 1 << ":";
		cin >> grade[i];
	}

	//loop to read through and sort grades
	for (int i = 0; i < SIZE; i++) {
		//test if grade is passing or failing
		if (grade[i] >= 60) {
			pass[passCount] = grade[i]; //pass
			passCount++; // increment counter
		} else {
			fail[failCount] = grade[i]; //pass
			failCount++; // increment counter

		}
	}

	//display passing results
	cout << passCount << " students passed and their grades are\n"; //pass
	for (int i = 0; i < passCount; i++) {
		cout << pass[i] << endl; //display passing grades
	}

	//display failing results
	cout << failCount << " students failed and their grades are\n"; //pass
	for (int i = 0; i < failCount; i++) {
		cout << fail[i] << endl; //display passing grades
	}








return 0;
}
