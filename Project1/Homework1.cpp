#include <iostream>
#include <math.h>
using namespace std;

int main( )
{
	/*
	Author: Peyton Thibodeaux (Peytonthibodeaux@my.unt.edu)
	Date:   9/12/2019
	Instructor: Shrestha,Pradhumna Lal
	Description: This program will compute the time for an object to hit the ground and the energy the object hits the ground with
	*/

	//variables
	int height;
	double mass, time, velocity, heightMeters, kineticEnergy;

	//constants
	const double FEET_TO_METER = 0.3048;
	const double GRAVITY = 9.8;

	//prompt and user input
	cout << "Enter the height (in feet) which the object is dropped:";
	cin >> height;
	cout << endl << "Enter the mass (in Kg) of the object:";
	cin >> mass;

	//convert feet to meters
	//height *= FEET_TO_METER; // this code does not work because you can't store the conversion isnide and int value
	heightMeters = height * FEET_TO_METER;

	//compute time
	time = sqrt(2.0 * (heightMeters / GRAVITY));


	//compute Velocity
	velocity = GRAVITY * time;

	//compute kinetic energy
	kineticEnergy = (mass/2.0) * pow(velocity, 2.0);

	//display settings
	cout.setf(ios::fixed); // fixed point notation
	cout.setf(ios::showpoint); // decimal points will be displayed 

	//display results
	cout.precision(3); //amount of decimal places shown
	cout << endl << "The time taken by the object to reach the ground is " << time << " seconds" << endl;
	cout.precision(2); // amount of decimal places shown
	cout <<  "The velocity at which the object strikes the ground is " << velocity << " meters per second." << endl;
	cout.precision(4); //amount of decimal places shown
	cout << "The kinetic energy at the moment of impact with the ground is " << kineticEnergy << " Joules." << endl;
    return 0;
}
