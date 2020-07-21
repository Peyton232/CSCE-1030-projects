/* Author: Peyton Thibodeaux (peytonthibodeaux@my.unt.edu)
 Date: 10/24/2019
 Instructor: Dr. Pradhumna Shrestha
 Description: This program computes surface area of a hexagonal prism
 */
#include <iostream>
#include <cmath>
using namespace std;

//function prototypes
/* Function: calcSideArea
Parameters: float a representing length of base
			float b representing height of prism
Return: a float representing side area
Description: This function computes the side area*/
float calcSideArea(float a, float h);
/* Function: calcHexArea
Parameters: float a representing length of base
Return: a float representing hex area
Description: This function computes the hex area*/
float calcHexArea(float a);
/* Function: calcSideArea
Parameters: float hex_area representing hexagonal area
			float rect_area representing rectangle area
Return: void
Description: This function computes the total area and prints it*/
void printSurfArea(float hex_area, float rect_area);



int main() {
	float h; 			//height of the hexagonal prism
	float a;			//length of the base edge
	float hex_area;		//area of the hexagonal area
	float rect_area;	//area of the rectangular faces
	
	//inputs and prompts
	cout << "Enter the length of the base edge in feet: ";
	cin >> a;
	
	cout << "Enter the heght of the hexagonal prism in feet: ";
	cin >> h;
	
	//call function to get rectangle area
	rect_area = calcSideArea(a, h);
	cout << "total surface area of all six rectangular sides of the prism is " << rect_area << " square feet." << endl;
	
	//call hexagonal area sides of prism function
	hex_area = calcHexArea(a);
	cout << "total surface area of both hexagonal prism is " << hex_area << " square feet." << endl;
	
	//call function that prints the result
	printSurfArea(hex_area, rect_area);
	
	
	
return 0;
}

float calcSideArea(float a, float h){
	return (6 * a * h);
}

float calcHexArea(float a){
	return(3 * (sqrt(3.0)) * (pow(a, 2.0)));
}

void printSurfArea(float hex_area, float rect_area){
	cout << "The total surface area is " <<(hex_area + rect_area) << " square feet " << endl;;
}