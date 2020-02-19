/* Author: Peyton Thibodeaux (Peytonthibodeaux@my.unt.edu)
 Date: 10/22/19
 Instructor:Dr. Pradhumna Shrestha
 Description:This program is an ant game

will hold the local include directive for the header file as
well as the main function for the program.
*/

#include "pwt0013HW4.h"
#include "pwt0013HW4func.cpp"


int main () {
	//display department id and information
	displayDepartment();
	//display instructions
	displayInstructions();
	
	//variables
	int ants = 0; 				//number of Anthonies ants
	int enemyAnts = 0; 			//number of enemy ants
	char colonyLetter;			//Colony letter
	bool playing = true;		//value to decide if the game is still being played
	int winLose = 1;			//value to determine if you have won or loss
	int userInput = 0;			//value to store user inputs
	bool found;					//value to detrmine if a colony was found
	int currentColumn = 0;		//value to store the colony Anthony is on
	int handicap = 0;			//add ants to Anthonies initial army
	bool rests = false;			//add an optional rest mode 
	int restsNumber;			//numbe rof rests you get to take, can change depending on difficulty
	int difficulty = 0;			//change the difficulty of the game
	bool cheatMode = false;		//toggle cheat mode
	int choice;					//choice for quit menu
	bool load = false;			//value to see if you are loading an old game
	int** matrix;				//dynamic matrix
	
	//main menu with different options for the game
	mainMenu(handicap, rests, difficulty, restsNumber, playing, cheatMode, load);
	
	if (load == false) {
		// dynamic allocation
		matrix = new int*[(SIZE + difficulty)];
		for(int i = 0; i < (SIZE + difficulty); i++){
			matrix[i] = new int[(SIZE + difficulty)];
		}
	}
	//load game if chosen
	if (load == true){
		matrix = loadGame(ants, enemyAnts, colonyLetter, currentColumn, handicap, rests, restsNumber, difficulty, cheatMode);
	}
		
	//only run if play has been chosen from user and not loading a previous game
	if (playing == true && load == false){
		//initialize the array
		initializeMatrix(matrix, ants, difficulty, handicap);
		
		//initialize enemy ants
		for (int i = 0; i < (SIZE + difficulty); i++){
			if(matrix[i][currentColumn+1] != -1) {
				enemyAnts += matrix[i][currentColumn+1];
			} 
		}
		
		//display the matrix initially
		displayMatrix(matrix, currentColumn, difficulty, cheatMode);
		
		//original prompt message
		cout << "\nNow let's begin... Anthony's army is " << ants << " strong\n\n";
	} else {
		//display the matrix initially after a load
		displayMatrix(matrix, currentColumn, difficulty, cheatMode);
		
		//original prompt message after a load
		cout << "\nAnthony's army is " << ants << " strong\n\n";
	}
	
	//cheat mode test for(int i = 0; i < (SIZE + difficulty); i++){for(int j = 0; j < (SIZE + difficulty); j++){std::cout << matrix[i][j] << "\t";}cout << endl;}
	
	//the game----------------------------------------------------------------------------------------------------------------------------------------------------
	while (playing) {
		//calculate enemyAnts
		enemyAnts = 0;
		for (int i = 0; i < (SIZE + difficulty); i++){
			if(matrix[i][currentColumn+1] != -1) {
				enemyAnts += matrix[i][currentColumn+1];
			} 
		}
		
		//figure out colony letter for this one
		colonyLetter = currentColumn + 66;
		
		//calculate rests 
		if (rests == true && restsNumber > 0) {
			//rest function
			takeRest(ants, restsNumber, difficulty);
		}
		
		
		//prompt for input and test for failure
		do {
			//message if reprompting
			if (userInput < 0 || userInput > ((SIZE + difficulty) - 1)){
				cout << "This value is out of range please try again\n";
			}
			//prompt
			cout << "\nEnter row position in column " << colonyLetter <<" to strike (or 99 to save the game):";
			cin >> userInput;
			
			//save the game option
			if (userInput == 99){
				//save the game to a file
				save(ants, enemyAnts, colonyLetter, playing, currentColumn, handicap, rests, restsNumber, difficulty, cheatMode, matrix);
				//dummy value
				userInput = 2; 
			}

		} while (userInput < 0 || userInput > ((SIZE + difficulty) - 1));
		
		//check if a colony is found, only run test if userInput is within range
		if (userInput >= 0 && userInput <= ((SIZE + difficulty) - 1)){
			found = checkColony(matrix, currentColumn, userInput);
		}
		
		//if a colony has already been visited don't do calculations
		if (matrix[userInput][currentColumn+1] == -1 && userInput != 99){
			cout << "\nThis Colony has already been visited\n";
		} else {
		
			//newly encountered patrol
			if (found == false && playing == true){
				//enemy ant patrol attack calculations and infrom the user.
				//also keeps a runnign tally of enemy ants left
				patrolAttack(matrix, ants, enemyAnts, currentColumn, userInput, difficulty);
				
			}
			
			//display message if a colony was found
			if (found && playing == true) {
				
				//add captured ants
				ants += antsCapture(difficulty, handicap, enemyAnts);
				//ants += enemyAnts;
				
				//display to user
				cout << "\nAnthony's army found ant colony in column " << colonyLetter; 
				cout <<", captured " << antsCapture(difficulty, handicap, enemyAnts) <<" ants.\n";
				
				//let the user know the total number of ants, I added this one for clarity
				cout << "\nYour army is now " << ants << " strong\n";
			}
		}
		
		//display the matrix with new results if still playing
		if (playing == true){
			displayMatrix(matrix, currentColumn, difficulty, cheatMode);
		}
		
		
		
		//check if game has been won or loss
		if (currentColumn == ((SIZE + difficulty) - 1)){
			winLose = 2;
		} else if (ants < 1){
			winLose = 0;
		}
		
		//if statement for win/loss
		if (winLose == 0) {
			cout << "\n\nAnthony's army has been defeated \nYou Lose\nGame Over\n\n";
			
			//quit menu
			//display rests options
			cout << "\t    +----------------------------------------------+\n";
			cout << "\t    |              Do you wish to quit             |\n";
			cout << "\t    |   1. No                                      |\n";
			cout << "\t    |   2. Yes                                     |\n";
			cout << "\t    +----------------------------------------------+\n";
			
			cin >> choice;
			if (choice == 1) {
				playing = true;
				
				//initialize a new game
				mainMenu(handicap, rests, difficulty, restsNumber, playing, cheatMode, load);
				initializeMatrix(matrix, ants, difficulty, handicap);
				newGame(matrix, ants, currentColumn, difficulty, enemyAnts, winLose);
				//display the matrix initially
				displayMatrix(matrix, currentColumn, difficulty, cheatMode);
			} else if (choice == 2) {
				cout << "\nNice Try, have a nice day\n";
				playing = false;
			} else {
				cout << "\nChoice invalid, quiting the game now\n";
				playing = false;
			}
		} else if (winLose == 2) {
			cout << "\n\nAnthony's army has taken over all the other colonies\nYou Win\n\n";
			
			//hidden message for beating expert mode
			if (difficulty == 10 && cheatMode == false){
				cout << "\n\n\nCongratulations, expert mode is very hard to overcome. \n You are an expert ant\n\n";
			}
			
			//hidden message for impossible mode
			if (difficulty == 10 && cheatMode == false){
				cout << "\n\n\nCongratulations, impossible mode, that is absolutely insane \n You are the ultimate ant\n\n";
			}
			
			
			cout << "\nThanks for playing, have a nice day\n";
			playing = false;
		}
		
	}
	
	
	//delete new memory created
	
	for(int i = 0; i < (SIZE + difficulty); ++i){
		delete [] matrix[i];
	}
	delete [] matrix;
	
	return 1;
}
