/********************************
* Name: Anderson Fernandes		*
* Date: 2/10/2014				*
* Class: ITSE 2421				*
* Professor: Douglas Edwards	*
*********************************/

/****************************************************
* File: Fernandes_A_Program_1.cpp					*
*													*
* Description: This is the only source file for the *
			   Programming Project 1. This program  *
			   aks the user what kind of medium and *
			   how long it took for sound to travel *
			   a distance, which what we calculate. *
*****************************************************/

#include <iostream> // Including default C++ input/output stream library
using namespace std; // Including standard namespace

// This function will show only the menu choices
void showMenu()
{
	cout    << "--------------------------------"			<< endl
			<< "          Select a gas:         "   		<< endl
			<< "--------------------------------"			<< endl
			<< "1 - CARBON DIOXIDE"							<< endl
			<< "2 - AIR"									<< endl
			<< "3 - HELIUM"									<< endl
			<< "4 - HYDROGEN"								<< endl
			<< "Or enter anything else end the program: ";
}

int main()
{
	// Defining speeds, in meters per second
	double CARBON_DIOXIDE = 258.0;
	double AIR = 331.5;
	double HELIUM   = 972.0;
	double HYDROGEN = 1270.0;
	double travelTime, distance;
	int gasSelected = 0;

	bool loop = true;   // This variable will control loop. True value will make
						// the program repeat itself. False will make it stop.

	while (loop) // While loop is true
	{ 
		showMenu(); // Show the menu

		cin >> gasSelected; // Get the gas selected by the user

		if (gasSelected >=1 && gasSelected <=4)
		{
			// Ask the user travel time
			cout << endl << "What is the travel time in seconds? ";
			// Get a value for travel time
			cin >> travelTime;
		
			if (travelTime >=0 && travelTime <=30)
			{
				// This switch statement is based on the gas selected
				switch (gasSelected)
				{
					// Case option 1 is choosen, calculate and display results
					case 1:
					{
						distance = CARBON_DIOXIDE * travelTime;
						cout << "The source of the sound was " << distance 
								<< " meters away." << endl << endl;
						break;
					}
					// Case option 2 is choosen, calculate and display results
					case 2:
					{
						distance = AIR * travelTime;
						cout << "The source of the sound was " << distance 
								<< " meters away." << endl << endl;
						break;
					}
					// Case option 3 is choosen, calculate and display results
					case 3:
					{
						distance = HELIUM * travelTime;
						cout << "The source of the sound was " << distance 
								<< " meters away." << endl << endl;
						break;
					}
					// Case option 4 is choosen, calculate and display results
					case 4:
					{
						distance = HYDROGEN * travelTime;
						cout << "The source of the sound was " << distance 
								<< " meters away." << endl << endl;
						break;
					}
					// There was no need for a "default" because condition
					// would never make it here being 0, it would be caught
					// by the last else statement.
				} // End of switch block
			} // End of if statement travel time
			else // if the input for travel time isn't between 0 and 30
			{
				// Show the user
				cout << "Please enter a number between 0 and 30." << endl << endl;
			}
		} // End of if statement for gas selection
		else
			return 0; // End program if option selected by user is not in menu
	}
	return 0;
}