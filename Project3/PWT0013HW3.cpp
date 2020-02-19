/* Author: Peyton Thibodeaux (Peytonthibodeaux@my.unt.edu)
 Date: 10/22/19
 Instructor:Dr. Pradhumna Shrestha
 Description:This program simulates ant pherimones
*/

#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdio.h>
using namespace std;

//global variables (that are allowed)
const int SIZE = 10;
enum antColony {A, B, C, D, E, F, G, H, I, J};
//enum antColony {A = 0, B = 1, C = 2, D = 3, E = 4, F = 5, G = 6, H = 7, I = 8, J = 9};

//display sudent information
void display() {
	//display information
	cout << "+----------------------------------------------+\n";
	cout << "|	 Computer Science and Engineering	|\n";
	cout << "|	 CSCE 1030 - Computer Science I	 	|\n";
	cout << "| Peyton Thibodeaux PWT0013 PWT0013@my.unt.edu |\n";
	cout << "+----------------------------------------------+\n";
	//end of display
}

//description
void describe() {
	//brief description of the program
	cout << "Description:This program simulates ant pherimones. Our ant Anthony starts at ant colony A and travels to another colony that he has not visited. He will follow a path always going towards the lowest pheromone level of a new location.";
	cout << "\n\n\n\n\n";
}

//create the matrix function
void getMatrix(int mat[][SIZE]){
	//random seed time
	srand(time(NULL));

	//variables
	int pheromone; //variable hold the value to be put into the colony matrix

	//random seed time
	srand(time(NULL));

	//loops
	for (int i = 0; i < SIZE; i++){
		//get random number
		pheromone = (rand() % 20) + 1;

		//set value
		if (i == 0) {
			//if it's in the diagnol it equals 0
			mat[0][0] = 0;
		} else {
			mat[i][0] = pheromone;
		}

		//create columns loop
		for (int j = 1; j < 10; j++){
			//get random number
			pheromone = (rand() % 20) + 1;
			//assign value
			if ((i) == j) {
				//if it's in the diagnol it equals 0
				mat[i][j] = 0;
			} else {
				mat[i][j] = pheromone;
			}
		}
	}
}

//print matrix function
void printMatrix(int mat[][SIZE]){
	//formatting
	cout << "\tA\tB\tC\tD\tE\tF\tG\tH\tI\tJ\n";
	cout << "      ------------------------------------------------------------------------------\n";

	//variables
	char col; // easy way to print out letters without repeating

	//loops
	for (int i = 0; i < SIZE; i++){
		//incriment character for colony
		col = i + 65; //65 is ASCI value for capital A
		cout << col << "    |";

		//if it is only one digit long add a 0 in front
		if (mat[i][0] < 10) {
			cout << "0";
		}
		//print value
		cout << mat[i][0] << "\t";

		//print columns loop
		for (int j = 1; j < 10; j++){
			//if it is only one digit long add a 0 in front
			if (mat[i][j] < 10) {
				cout << "0";
			}
			//print value
			cout << mat[i][j] << "\t";
		}
		//formatting
		cout << endl;
	}
}

//check if location has been visited
bool visit(int visited[], int colony){
	//variable
	bool answer; //what will hold the value to be returned

	//loop
	for(int i = 0; i < SIZE; i++){
		//if statement
		if (visited[i] == colony){
			answer = true;
			//test cases
			//cout << "visited is" << visited[i];
			//cout << "|||true for " << i << " and " << colony << endl;
			break;
		} else {
			//default false until proven to be true and break the loop
			answer = false;
		}

	}
	//return final answer
	return answer;
}

//compute lowest pheromone level function
void compute(int colonyMatrix[][SIZE],int visited[], int row){
	//variables
	int lowest; //lowest value found in the row
	row = 0; //start on row 0 (colony A)
	int temp = -1; //temp value to be pushed into the visited array
	bool result; //store the result from running the visit function

	//loop
	for(int i = 1; i < SIZE; i++){
		//set lowest for now
		lowest = 21;

		//loop to find lowest in the row
		for (int j = 1; j < SIZE; j++){
			//find lowest value so far
			if(colonyMatrix[row][j] < lowest && colonyMatrix[row][j] > 0){
				//check if visited
				result = visit(visited, j);
				if(!result){
					//if not visited then this is the new lowest value
					lowest = colonyMatrix[row][j];
					temp = j;
				}
			}
		}
	row = temp; // store temp into row so we know which row to process next
	//set lowest for current row
	visited[i] = row; //store the new row into visited array
	}



}

//display path Anthony takes
void displayPath(int visited[]){
	//loop
	for(int i = 0; i < SIZE; i++){
		//switch statement for each colony number in the array.
		//switch statement is readable so no need for comments in it.
		switch (visited[i]){
			case A:
			cout << "A------->";
			break;
			case B:
			cout << "B------->";
			break;
			case C:
			cout << "C------->";
			break;
			case D:
			cout << "D------->";
			break;
			case E:
			cout << "E------->";
			break;
			case F:
			cout << "F------->";
			break;
			case G:
			cout << "G------->";
			break;
			case H:
			cout << "H------->";
			break;
			case I:
			cout << "I------->";
			break;
			case J:
			cout << "J------->";
			break;
			default:
			cout << "error\n";
			break;
		}
	}
	//end of path message
	cout << "Complete\n\n\n";


}

int main () {
	//display student information
	display();

	//display brief description
	describe();

	//variables main
	int colonyMatrix[SIZE][SIZE]; 	//2d matrix to hold and display all colony phermon level paths
	int visited[SIZE] = {-1}; 		//array to hold visited colonies. sets all values to -1 making it easier to find bugs/errors during development
	int colony;						//current colony location (A, B, etc...)

	//anthony starts at colony A
	visited[0] = 0; //note this would still work even if this statement was not in the main function

	//call the matrix function
	getMatrix(colonyMatrix);

	//print contents of the matrix
	printMatrix(colonyMatrix);

	//compute lowest values in the array
	compute(colonyMatrix, visited, colony);

	//print visited
	displayPath(visited);
	return 0;
}
