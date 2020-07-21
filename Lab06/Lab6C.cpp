/* Author: Peyton Thibodeaux (peytonthibodeaux@my.unt.edu)
 Date: 10/17/2019
 Instructor: Dr. Pradhumna Shrestha
 Description: This program takes a 2D array in as an input and then tells you the minimum in each row and column
 */
#include <iostream>
using namespace std;

int main() {

	const int ROW_SIZE = 3; // number of rows
	const int COLUMN_SIZE = 4; //number of columns
	int matrix[ROW_SIZE][COLUMN_SIZE]; //2D array
	int row_min[ROW_SIZE]; //array for minimum accross rows
	int col_min[COLUMN_SIZE]; // array for minimum across columns

	//for loops to fill matrix
	for(int i = 0; i < ROW_SIZE; i++){
		for (int h = 0; h < COLUMN_SIZE; h++){
			cout << "Enter data for row#" << i+1 << " and column#" << h+1 << ":";
			cin >> matrix[i][h];
		}
	}

	//ooutput results
	cout << "You entered:" << endl;
	for(int i = 0; i < ROW_SIZE; i++){
		for (int h = 0; h < COLUMN_SIZE; h++){
			cout << matrix[i][h] << "\t";
		}
		cout << endl;
	}

	//go through array to find minimum in each row
	for(int i = 0; i < ROW_SIZE; i++) {
		//initial row minimum
		row_min[i] = matrix[i][0];

		for (int j = 0; j < COLUMN_SIZE; j++){
			if (row_min[i] > matrix[i][j]){
				row_min[i] = matrix[i][j];
			}

		}
	}

	//go through array to find minimum in each column
	for(int i = 0; i < COLUMN_SIZE; i++) {
		//initial column minimum
		col_min[i] = matrix[0][i];

		for (int j = 0; j < ROW_SIZE; j++){
			if (col_min[i] > matrix[j][i]){
				col_min[i] = matrix[j][i];
			}

		}
	}

	//display results
	cout << "\nThe row miniums are:";
	for(int i = 0; i < ROW_SIZE; i++) {
		cout << endl << row_min[i];
	}


	cout << "\nThe column miniums are:";
	for(int i = 0; i < COLUMN_SIZE; i++) {
		cout << endl << col_min[i];
	}
	cout << endl;


return 0;
}

