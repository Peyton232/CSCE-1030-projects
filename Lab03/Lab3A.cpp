#include <iostream>
using namespace std;

int main( )
{


    /* Declare variables var1 through var5, a constant OFFSET
       and initialize them with the values provided in the instructions.
    */


    /* Now write an expression using var1 through var4 and constant OFFSET
       so the result, when compiled and run, equals 1012 (note
       that you will use this information for declaring
       the variable var5). Replace each '?' with a variable/constant that were
       previously initialized.
    */


	//variables
	const double OFFSET = 0.5;
	int var1 = 17;
	char var2 = 't';
	float var3 = 20.5;
	float var4 = 4.5;
	int var5;

	//computation, (((17 + 116) - 20.5) * 4.5) / 0.5 
	// parenthesis will hav ethe computations be performed left to right
	var5 = ( ( ( var1 + var2 ) - var3 ) * var4 ) / OFFSET;

	cout << var5 << endl; // This should print 1012

    return 0;
}

