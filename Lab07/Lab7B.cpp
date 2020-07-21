/* Author: Peyton Thibodeaux (peytonthibodeaux@my.unt.edu)
 Date: 10/24/2019
 Instructor: Dr. Pradhumna Shrestha
 Description: This program creates two random numbers then swaps them and subtracts
 */
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

/* Function: subtract
Parameters: none
Return: an integer value
Description: This function creates 2 random integer values and subtracts them*/
int subtract();
/* Function: swap
Parameters: int a a number
			int b a number
Return: nothing
Description: This function swaps two values using pass by reference*/
void swap(int& a, int& b);

int main() {
	//call function and print
	cout << subtract() << endl;
return 0;
}

int subtract(){
	//seed random
	srand(time(NULL));
	//get random numbers
	int a = (rand() % 30) + 1;
	int b = (rand() % 61) + 40;
	
	//call swap function
	swap(a, b);
	
	return(a-b);
}

void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}
