/* Author: Peyton Thibodeaux (Peytonthibodeaux@my.unt.edu)
 Date: 9/26/19
 Instructor:Dr. Pradhumna Shrestha
 Description: This program tells you which direction you move based on IJKL movement system
*/

#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

//directions
enum Diections {UP = 'I', LEFT = 'J', DOWN = 'K', RIGHT = 'L'};

int main () {
//variables
char ch;

cout << "Enter direction to move (I = UP, J = LEFT, K = DOWN, L = Right):";
cin >> ch;

if (ch == UP)
{
	cout << "You moved UP!" << endl;
}
else if (ch == LEFT)
{
	cout << "You moved LEFT" << endl;
}
else if (ch == DOWN)
{
	cout << "You moved DOWN" << endl;
}
else if(ch == RIGHT)
{
	cout << "You moved RIGHT" << endl;
}
else
{
	cout << "Unknown direction" << endl;
}



return 0;
}

