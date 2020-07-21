/* Author: Peyton Thibodeaux (peytonthibodeaux@my.unt.edu)
 Date: 11/07/2019
 Instructor: Dr. Pradhumna Shrestha
 Description: This program reads the content of a file and displays it as it appears
 */
#include <iostream>
#include <fstream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cstdlib>
using namespace std;



int main() {
	int i, num, j = 1;
	cout << "Enter the number: ";
	cin >> num;
	
	for (i = 1; i <= num; i++)
	{
		j = j * i;
	}
	
	cout << "Factorial of " << num << " is " << j << ".\n";
return 0;
}

