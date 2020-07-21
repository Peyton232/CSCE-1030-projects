/* Author: Peyton Thibodeaux (peytonthibodeaux@my.unt.edu)
 Date: 10/17/2019
 Instructor: Dr. Pradhumna Shrestha
 Description:
 */
#include <iostream>
#include <string>
using namespace std;

int main() {
	//variables
	char vowels[5];
	string my_str;
	int counter = 0;

	//store string and prompt user
	cout << "Please enter a string\n";
	getline (cin , my_str);


	//loop
	for (int i = 0; i < my_str.length(); i++){
	//if statement
		if (isalpha(my_str.at(i))){
			//if statement to decide if it's a vowel
			if (my_str.at(i) == 'A' ||
			    my_str.at(i) == 'a' ||
			    my_str.at(i) == 'E' ||
			    my_str.at(i) == 'e' ||
		    	    my_str.at(i) == 'I' ||
			    my_str.at(i) == 'i' ||
			    my_str.at(i) == 'O' ||
			    my_str.at(i) == 'o' ||
			    my_str.at(i) == 'U' ||
		    	    my_str.at(i) == 'u' ){
				//increment counter and store vowel
				vowels[counter] = my_str.at(i);
				counter++;

				//test if there are already 5 vowels
				if (counter >= 5){
					break;
				}
			}
		}
	}

//display results
for (int i = 0; i < counter; i++) {
	cout << endl << vowels[i] << endl;
}





return 0;
}
