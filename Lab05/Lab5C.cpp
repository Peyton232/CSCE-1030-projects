/* Author: Peyton Thibodeaux (Peytonthibodeaux@my.unt.edu)
 Date: 10/3/19
 Instructor:Dr. Pradhumna Shrestha
 Description:This program adds upp the sum of n natural numbers, n being inputed by the user
*/

#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main () {
	//variables
	int n, sum = 0;

	//prompt for input of n
	cout << "input a value for n:";
	cin >> n;

	//calulations using for loop
	for (int i = 1; i <= n; i++)
	{
		sum += i;
		cout << i << endl;
	}

	//output
	cout << "The sum from 1 to"<< n << " is: " << sum << endl;




	return 0;
}

