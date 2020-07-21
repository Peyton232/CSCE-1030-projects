/* Author: Peyton Thibodeaux (peytonthibodeaux@my.unt.edu)
 Date: 11/14/2019
 Instructor: Dr. Pradhumna Shrestha
 Description: This program 
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


int main() {
	//variables
	double sum = 0;
	int size; // number of students
	
	cout << "How maany students?";
	cin >> size;
	
	
	//array 
	int *grades=new int[size];
	
	
	//calculate
	cout << "\nEnter grades";
	for (int i = 0; i < size; i++){
		cout << "Enter grade for student " << i+1 << ": ";
		cin >> grades[i];
		sum += grades[i];
	}
	
	cout << "Average grade:" << sum/size << endl;
	
	
	//clean up
	delete[] grades;
	cout << endl;
return 0;
}
