/* Author: Peyton Thibodeaux (peytonthibodeaux@my.unt.edu)
 Date: 11/07/2019
 Instructor: Dr. Pradhumna Shrestha
 Description: This program reads through a file and finds the max value
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
	
	ifstream in_stream; //Declare the stream variable
	int max =0, num;
	
	in_stream.open ("act8A.txt");//open file
	
	
	
	for(int i = 0; i < 10; i++){
		in_stream >> num; 
		
		if (num > max){
			max = num;
		}
	}
	
	
	
	
	cout << "max value is:" << max << endl;
	
	
	
return 0;
}
