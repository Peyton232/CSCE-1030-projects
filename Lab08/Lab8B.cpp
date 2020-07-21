/* Author: Peyton Thibodeaux (peytonthibodeaux@my.unt.edu)
 Date: 11/07/2019
 Instructor: Dr. Pradhumna Shrestha
 Description: This program reads the content of a file and displays it as it appears
 */
#include <iostream>
#include <fstream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cstdlib>
using namespace std;

void get_stream(ifstream& in_s, ofstream& out_s);


int main() {
	char c;
	ifstream in_s; // declare the input stream
	ofstream out_s; //declare output stream
	get_stream(in_s, out_s);
	in_s.get(c);

	while(!in_s.eof()) // read all characters till end of file
	{
		out_s.put(c);
		in_s.get(c);
	}

	in_s.close(); // close the file
	out_s.close(); // close the file
return 0;
}

void get_stream(ifstream& in_s, ofstream& out_s)
{
	//input
	char input_file[15];

	cout << "Enter the name of the input file: ";
	cin >> input_file;

	in_s.open(input_file); // connect to the input file and test
	if (in_s.fail())
	{
		cout << "Unable to open input file " << input_file << endl;
		exit(EXIT_FAILURE); // exit if cannot open file
	}

	//output
	char output_file[15];

	cout << "Enter the name of the output file: ";
	cin >> output_file;

	out_s.open(output_file); // connect to the output file and test
	if (out_s.fail())
	{
		cout << "Unable to open output file " << output_file << endl;
		exit(EXIT_FAILURE); // exit if cannot open file
	}
}






