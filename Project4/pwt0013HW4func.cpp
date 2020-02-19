/*
will hold the local include directive for the header file as
well as all function definitions (not including main, of course) used in the
program.
*/
#include "pwt0013HW4.h"


// function to display department id
void displayDepartment() {
	//display information
	cout << "\t    +----------------------------------------------+\n";
	cout << "\t    |	 Computer Science and Engineering          |\n";
	cout << "\t    |	 CSCE 1030 - Computer Science I	           |\n";
	cout << "\t    | Peyton Thibodeaux PWT0013 PWT0013@my.unt.edu |\n";
	cout << "\t    +----------------------------------------------+\n";
	//end of display
}

//function to display the instructions
void displayInstructions() {
	//display information
	cout << "\n\t\t\tWelcome to Anthony's Battle! \n\n";
	cout << "\t----------------------------------------------------------\n";
	cout << "\tAnthony the ant has decided that he wants to take over all\n";
	cout << "\tthe adjacent ant colonies with his army of ants from colo\n";
	cout << "\tny 'A'. To do this, Anthony's army will attempt to capture\n";
	cout << "\tants from columns 'B' through 'J', with at least 1 ant re\n";
	cout << "\tmaining when the column 'J' ant colony is found. Each col\n";
	cout << "\tumn's ant colony is identified with a 0 in one of the rows\n";
	cout << "\tfor that column, while patrols are represented by integers\n";
	cout << "\tbetween 1 and 10 for the number of ants in that particular\n";
	cout << "\tpatrol. On the way to column 'J' if Anthony's army encoun\n";
	cout << "\tters a patrol, the number in the patrol is subtracted from\n";
	cout << "\tAnthony's army total. Once his army finds the colony, how\n";
	cout << "\tever, any patrols not confronted will be added to his army\n";
	cout << "\ttotal. If Anthony makes really good decisions, then he can\n";
	cout << "\ttake over all of the adjacent ant colonies; otherwise, his\n";
	cout << "\tarmy will be defeated! \n";
	cout << "\t----------------------------------------------------------\n\n";
	//end of display
}

//initilize the array
void initializeMatrix(int** matrix, int &ants, int difficulty, int handicap){
	//test fill for(int i = 0; i < (SIZE + difficulty); i++){for(int j = 0; j < (SIZE + difficulty); j++){matrix[i][j] = i;}}
	
	//seed random numbers
	srand(time(NULL));
	
	//decide where the colony is
	int randomLocation = (rand() % (SIZE + difficulty)) + 1;
	
	//message
	cout << "Initializing board...\n\n";
	
	//fill matrix
	for(int i = 0; i < (SIZE + difficulty); i++){
		//decide location
		randomLocation = rand() % (SIZE + difficulty);
		for(int j = 0; j < (SIZE + difficulty); j++){
			if (j == randomLocation){
				matrix[j][i] = 0;
			} else {
				matrix[j][i] = (rand() % (SIZE + difficulty)) + 1;
			}
		}
	}
	
	//number of ants (Anthonies)
	for(int i = 0; i < (SIZE + difficulty); i++){
		ants += matrix[i][0];
	}
	ants += handicap;
	
	
}

void displayMatrix(int** matrix, int taken, int difficulty, bool cheatMode){
	//set 0 fill
	cout.fill('0');
	
	//style of grid letters
	char letter;
	//cout << "\tA\tB\tC\tD\tE\tF\tG\tH\tI\tJ\n";
	for (int i = 0; i < (SIZE + difficulty); i++) {
		letter = (i + 65);
		cout << "\t" << letter; 
	}
	cout << endl;
	
	//style for grid outline
	cout << "  +----";
	for (int i = 0; i < (SIZE + difficulty); i++){
		cout << "--------";
	}
	cout << "-+\n";
	
	//display matrix
	for(int i = 0; i < (SIZE + difficulty); i++){
		//leftside 
		if (i < 10){
			cout << "0";
		}
		cout << i << "|";
		for(int j = 0; j < (SIZE + difficulty); j++){
			//logical statements
			if (j <= taken && matrix[i][j] != -1){
				//if a colony is taken over display the ant soldiers taken
				cout << "\t" << setw(2) << matrix[i][j];
			}else if (matrix[i][j] == -1){
				//if a patrol is found it changes to "XX"
				cout << "\tXX";
			} else {
				//all non-visited locations show as **
				if (cheatMode == true){
					cout << "\t" <<matrix[i][j];
				} else {
					cout << "\t**";
				}
			}
		}
		cout << "\t|";
		cout << endl;
	}
	
	//style for grid outline
	cout << "  +----";
	for (int i = 0; i < (SIZE + difficulty); i++){
		cout << "--------";
	}
	cout << "-+\n";
}

//check if a colony is found
bool checkColony(int** matrix, int &currentColumn, int userInput){
	//Search matrix
	
	if (matrix[userInput][currentColumn + 1] == 0){
			//if colony return true and move to next row
			currentColumn ++;
			return true;
			
		} else {

			return false;
		}	


}	

//patrol calculations and prompt
void patrolAttack(int** matrix,int &ants, int &enemyAnts, int currentColumn, int userInput, int difficulty){
	//assign value to enemy ants
	enemyAnts = matrix[userInput][currentColumn + 1];
	
	//calulate casualties
	if (difficulty == 11){
		ants -= (2 * enemyAnts);
	} else {
		ants -= enemyAnts;
	}
	//report casualties
	if (ants > 0) {
		cout << "\nAnthony's army suffered casualties and has " << ants <<" ants remaining.\n\n";
	} else {
		cout << "\nAnthony's army suffered casualties and has NO ants remaining \n\n";
	}
	
	//change value of colony
	matrix[userInput][currentColumn + 1] = -1;
	
	//change value of enemy ants
	enemyAnts = 0;
	for (int i = 0; i < (SIZE + difficulty); i++){
		if(matrix[i][currentColumn+1] != -1) {
			enemyAnts += matrix[i][currentColumn+1];
		} 
	}
}

void optionsMenu(int &handicap, bool &rests, int &difficulty, int &restsNumber, bool &cheatMode) {
	//display difficulty menu
	cout << "\t    +----------------------------------------------+\n";
	cout << "\t    |   Enter the difficulty you wish to play on,  |\n";
	cout << "\t    |Difficulty changes the ammount of ants in your|\n";
	cout << "\t    |initial army and also how long the game is.   |\n";
	cout << "\t    |Difficulty also changes how many ants you     |\n";
	cout << "\t    |capture from enemy colonies                   |\n";
	cout << "\t    |   1. Easy Mode                               |\n";
	cout << "\t    |   2. Normal mode                             |\n";
	cout << "\t    |   3. Hard Mode                               |\n";
	cout << "\t    |   4. Expert mode                             |\n";
	cout << "\t    |   5. Impossible mode                         |\n";
	cout << "\t    +----------------------------------------------+\n";

	//recieve input for difficulty
	cin >> difficulty;
	switch (difficulty)
	{
		case 1: 
		difficulty = -4;
		handicap = 15;
		restsNumber = 3;
		cout << "\nGame mode set to easy\n";
		break;
		
		case 2: 
		difficulty = 0;
		handicap = 0;
		restsNumber = 3;
		cout << "\nGame mode set to normal\n";
		break;
		
		case 3: 
		difficulty = 5;
		handicap = -15;
		restsNumber = 2;
		cout << "\nGame mode set to hard\n";
		break;
		
		case 4: 
		difficulty = 10;
		handicap = -40;
		restsNumber = 2;
		cout << "\nGame mode set to expert\n";
		break;
		
		case 5: 
		difficulty = 11;
		handicap = -80;
		restsNumber = 1;
		cout << "\nGame mode set to impossible\n";
		break;
		
		default: 
		difficulty = 0;
		handicap = 0;
		restsNumber = 3;
		cout << "\nChoice is out of range, therefore game mode set to normal\n";
		break;
	}
	
	int choice = 3;
	while (choice == 3)
	{
		//display rests options
		cout << "\t    +----------------------------------------------+\n";
		cout << "\t    |Do you wish to play with the optional rest    |\n";
		cout << "\t    |rule?                                         |\n";
		cout << "\t    |   1. Yes                                     |\n";
		cout << "\t    |   2. No                                      |\n";
		cout << "\t    |   3. What is the optional rest rule?         |\n";
		cout << "\t    +----------------------------------------------+\n";

		//recieve input for rest rules
		cin >> choice;
		switch (choice)
		{
			case 1: 
			rests = true;
			cout << "\nRest rule is set to true\n";
			break;
			
			case 2: 
			rests = false;
			cout << "\nRest rule is set to false\n";
			break;
			
			case 3: 
			cout << "\nThe optional rest rule allows Anthony's army to rest for some time and regain\n";
			cout << "lost ants. \n";
			break;
		
			default: 
			choice = 3;
			rests = false;
			cout << "\nInput is out of range try again\n";
			break;
		}
	}
	
	choice = 3;
	while (choice == 3)
	{
		//display rests options
		cout << "\t    +----------------------------------------------+\n";
		cout << "\t    |Do you wish to play with cheat mode           |\n";
		cout << "\t    |   1. Yes                                     |\n";
		cout << "\t    |   2. No                                      |\n";
		cout << "\t    |   3. What is the optional rest rule?         |\n";
		cout << "\t    +----------------------------------------------+\n";

		//recieve input for rest rules
		cin >> choice;
		switch (choice)
		{
			case 1: 
			cheatMode = true;
			cout << "\nRest rule is set to true\n";
			break;
			
			case 2: 
			cheatMode = false;
			cout << "\nRest rule is set to false\n";
			break;
			
			case 3: 
			cout << "\nThe option let's you see all the values for ant colonies instead of being hidden\n";
			cout << "\nIf you use this mode you will not get the hidden message when completing expert mode\n";
			break;
		
			default: 
			choice = 3;
			rests = false;
			cout << "\nInput is out of range try again\n";
			break;
		}
	}


}

int antsCapture(int difficulty, int handicap, int enemyAnts){
	
	if (difficulty == 0){
		//normal amount of captured ants
		return enemyAnts;
	} else if (difficulty == -4) {
		//easy mode amount of captured ants
		return (enemyAnts + handicap);
	} else if (difficulty == 5){
		//hard mode of enemy ants returned
		enemyAnts + handicap;
		if (enemyAnts < 0){
			enemyAnts = 0;
		}
		return enemyAnts;
	} else if (difficulty == 10) {
		//expert mode enemy ants captured
		return (enemyAnts / 2);
	}	else if (difficulty == 11) {
		//impossible mode enemy ants captured
		enemyAnts + handicap;
		return (enemyAnts / 4);
	} else {
		//default case
		return enemyAnts;
	}
}

void mainMenu(int &handicap, bool &rests, int &difficulty, int &restsNumber, bool &playing, bool &cheatMode, bool &load){
	//temp value
	int choice;
	
	do {
	//display main menu
	cout << "\t    +----------------------------------------------+\n";
	cout << "\t    |              World War Ants                  |\n";
	cout << "\t    |                 Main Menu                    |\n";
	cout << "\t    |   1. Play                                    |\n";
	cout << "\t    |   2. Options                                 |\n";
	cout << "\t    |   3. Load                                    |\n";
	cout << "\t    |   4. Quit                                    |\n";
	cout << "\t    +----------------------------------------------+\n";
	
	//get input
	cin >> choice;
	//compute choices
	switch (choice)
		{
			case 1:
			break;
			
			case 2:
			//options menu
			optionsMenu(handicap, rests, difficulty, restsNumber, cheatMode);
			break;
			
			case 3:
			//load the game
			load = true;
			break;
			break;
			
			case 4:
			cout << "\nHave a nice day\n";
			playing = false;
			break;
			
			default:
			cout << "\nThis is not a valid input try again\n";
			break;
		}
	} while (choice != 1 && choice != 4 && choice != 3);
}

void newGame(int** matrix, int &ants, int &currentColumn, int difficulty, int &enemyAnts, int &winLose){
	//reset column
	currentColumn = 0;
	
	//initialize enemy ants
	for (int i = 0; i < (SIZE + difficulty); i++){
		if(matrix[i][currentColumn+1] != -1) {
			enemyAnts += matrix[i][currentColumn+1];
		} 
	}
	
	//set winLose to neutral state
	winLose = 1;
	
	cout << "\nNow let's begin... Anthony's army is " << ants << " strong\n\n";
}

void takeRest(int &ants, int &restsNumber, int difficulty){
	//temp value
	int choice;
	
	//display rests options
		cout << "\n\n\t    +----------------------------------------------+\n";
		cout << "\t    |Do you wish to take a rest?                   |\n";
		cout << "\t    |You have " << restsNumber <<" remaining                          |\n";
		cout << "\t    |   1. Yes                                     |\n";
		cout << "\t    |   2. No                                      |\n";
		cout << "\t    +----------------------------------------------+\n";
	cin >> choice;
	
	//switch statement
	switch (choice) {
		case 1: 
		if(restsNumber > 0){
			//add rest number 
			cout << "\nYou have gained " << (SIZE + difficulty) <<" new soldiers\n";
			ants += (SIZE + difficulty);
			restsNumber --;
		} else {
			cout << "\nIt appears you have no rests remaining\n";
		}
		break;
		
		case 2:
		//no rest
		cout << "\nYou did not take a rest\n";
		break;
		
		default:
		//no rest
		cout << "\nYou did not take a rest\n";
		break;
	}
	
}

//save the game
void save(int ants, int enemyAnts, char colonyLetter, bool &playing, int currentColumn, int handicap, bool rests, int restsNumber, int difficulty, bool cheatMode, int** matrix){
	//stream class for file
	ofstream fout;
	
	//get file name from user
	string filename;
	string dummy;
	cout << "Please enter a file name to write: ";
	getline( cin, dummy );
	getline(cin, filename);
	
	//file operations
	fout.open(filename.c_str());
	
	//store game data in file
	fout << ants << "\n" << enemyAnts << "\n" << colonyLetter << "\n";
	fout << currentColumn << "\n" << handicap << "\n" << rests << "\n";
	fout << restsNumber << "\n" << difficulty << "\n" << cheatMode << "\n";
	
	//save the matrix
	for(int i = 0; i < (SIZE + difficulty); i++){
		for(int j = 0; j < (SIZE + difficulty); j++){
			fout << matrix[i][j] << "\t";
		}
		fout << endl;
	}
	
	//completion message
	cout << "\nThe game has been saved\n";
	
	//close file
	fout.close();
	
	//change game to be not playing
	playing = false;
}


int** loadGame(int &ants, int &enemyAnts, char &colonyLetter, int &currentColumn, int &handicap, bool &rests, int &restsNumber, int &difficulty, bool &cheatMode){
	//input stream
	ifstream fin;
	
	//cout << "\nStil Working 1\n";
	
	//variables
	string filename;
	
	//prompt user
	cout << "please enter the file name you wish to load: ";
	
	while (true) {
		//recieve input from user
		getline( cin, filename );
		
		//open file
		fin.open( filename.c_str() );
		
		//if file openes terminate loop
		if (fin) break;
		
		//error message
		cout << "Invalid file. Please enter a valid input file name\n";
	}
	
	//show response if it works
	cout << "openeing " << filename;
	cout << endl;
	
	//get data from file
	fin >> ants >> enemyAnts >> colonyLetter >> currentColumn >> handicap >> rests >> restsNumber >> difficulty >> cheatMode;
	
	// dynamic allocation for load
		int** matrix = new int*[(SIZE + difficulty)];
		for(int i = 0; i < (SIZE + difficulty); i++){
			matrix[i] = new int[(SIZE + difficulty)];
		}
	
	//get matrix from file
	for(int i = 0; i < (SIZE + difficulty); i++){
		for(int j = 0; j < (SIZE + difficulty); j++){
			fin >> matrix[i][j];
		}
	}
	
	//close file
	fin.close();
	
	return matrix;
}	





















