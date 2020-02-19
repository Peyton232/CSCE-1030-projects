/*
will hold the include directives for the necessary libraries, any
global constants, any enumerated data types, any type definitions, any
structure definitions, and the list of function prototypes (i.e., function
declarations).
*/

#include <iostream>
#include <fstream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;


#ifndef pwt0013HW4_h
#define pwt0013HW4_h
//size of the matrix
const int SIZE = 10;

//function to display department information
void displayDepartment();

//display the information about the game
void displayInstructions();

//populate the matrix initially 
void initializeMatrix(int** matrix, int &ants, int difficulty, int handicap);

//Display the matrix
void displayMatrix(int** matrix,int taken, int difficulty,bool cheatMode);

//check if a colony is found
bool checkColony(int** matrix, int &currentColumn, int userInput);

//patrol calculations and prompt
void patrolAttack(int** matrix,int &ants,int &enemyAnts, int currentColumn, int userInput, int difficulty);

//main menu options, I added this
void mainMenu(int &handicap, bool &rests, int &difficulty, int &restsNumber, bool &playing, bool &cheatMode, bool &load);

//function to calculate how many ants are captured
int antsCapture(int difficulty, int handicap, int enemyAnts);

//new game initialize
void newGame(int** matrix, int &ants, int &currentColumn, int difficulty, int &enemyAnts, int &winLose);

//rest function
void takeRest(int &ants, int &restsNumber, int difficulty);

//Save function
void save(int ants, int enemyAnts, char colonyLetter, bool &playing, int currentColumn, int handicap, bool rests, int restsNumber, int difficulty, bool cheatMode, int** matrix);

//load function
int** loadGame(int &ants, int &enemyAnts, char &colonyLetter, int &currentColumn, int &handicap, bool &rests, int &restsNumber, int &difficulty, bool &cheatMode);
#endif
