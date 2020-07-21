/* Author: Peyton Thibodeaux (peytonthibodeaux@my.unt.edu)
 Date: 11/14/2019
 Instructor: Dr. Pradhumna Shrestha
 Description: This program tests out various pointer features
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
	int my_int = 25;
	
	//int pointers
	int* my_iptr1;
	int* my_iptr2; 
	
	//assign address
	my_iptr1 = &my_int;
	
	//display results
	cout << "my_int: " << my_int << endl;
	cout << "&my_int: " << &my_int << endl;
	cout << "my_iptr1: " << my_iptr1 << endl;
	cout << "*my_iptr1: " << *my_iptr1<< endl;
	
	//dereference pointer
	*my_iptr1 = 35;
	
	//display my int
	cout << "dereference pointer" << endl;
	cout << "my_int: " << my_int << endl;
	
	//dynamic memory
	cout << "dynamic memory" << endl;
	 my_iptr1 = new int;
	 cout << "my_iptr1: " << my_iptr1 << endl;
	 
	//dereference pointer
	*my_iptr1 = 20;
	
	//display my int after new memory
	cout << "dereference pointer after new memory" << endl;
	cout << "my_int: " << my_int << endl;
	
	//dynamic memory ptr 2
	my_iptr2 = new int;
	my_iptr2 = my_iptr1;
	 cout << "my_iptr2: " << my_iptr2 << endl;
	 
	 //value that ptr2 holds
	cout << "*my_iptr2: " << *my_iptr2<< endl;
	
	
	cout << endl;
return 0;
}
