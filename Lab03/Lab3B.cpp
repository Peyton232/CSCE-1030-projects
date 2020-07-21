#include <iostream>
#include <math.h>
using namespace std;

int main( )
{
    	/* 
	Author: Peyton Thibodeaux (Peytonthibodeaux@my.unt.edu)
 	Date:   9/12/2019
 	Instructor: Shrestha,Pradhumna Lal
 	Description: This program will read input from the keyboard and using thos evalues claculate the surface are aof a cone
	*/

	//variables
	const double PI = 3.14;
	int radius, height;
	double  surface_area;

	//prompts for user input and store the values
	cout << "Input the radius of the cone:";
	cin >> radius;
	cout << "Input the vertical height of the cone:";
	cin >> height;

	//computations
	surface_area = PI * (double) radius * (radius + sqrt((pow(radius, 2.0) + pow(height, 2.0))));

	//output result to screen
	cout << "The surface area of the cone is " << surface_area << endl;

    return 0;
}
