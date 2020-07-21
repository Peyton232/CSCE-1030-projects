
#include <iostream>
using namespace std;

int main( ) 
{
	//length and width for rectangle
	float length;
	float width;
	//height and base of trangle
	float height;
	float base;
	//variable to store area of the shaoe
	float area;

	//input length, wdith, and height
	cout << "What is the length of the rectangle? (in inches)\n";
	cin >> length;
	cout << "\nWhat is the wdith of the ractangle? (in inches)\n";
	cin >> width;
	cout << "\nWhat is the height of the triangle? (in inches)\n";
	cin >> height;

	//set base = to height
	base = width;

	//computations
	area = (width * length) + (0.5 * base * height);

	// output message for user
	cout << "The area of the shape with your given  measurements is " << area << " square inches";

	//space buffer for my own readability
	cout << endl << endl;
        return 0; 
}
