// This program finds the probability of winning a "mini" lottery when
// the user's set of numbers must exactly match the set drawn by the
// lottery organizers. In addition to main, it uses three functions.
#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	int pickFrom,         // The number of numbers to pick from
		numPicks;         // The number of numbers to select
	long int ways;         // The number of different possible
                          // ways to pick the set of numbers

	// Display information on what the program does
	cout << "This program will tell you your probability of "
		<< "winning \"Little Lotto\". \n";

	// Acquire the user input for Number of available numbers
	//  and how many to pick
	cout << "\nHow many numbers (1-12) are there to pick from? ";
	cin  >> pickFrom;
	while (pickFrom < 1 || pickFrom > 12)
	{  
		cout << "There must be between 1 and 12 numbers.\n"
			<< "How many numbers (1-12) are there to pick from? ";
		cin  >> pickFrom;
	}
	cout << "How many numbers must you pick to play? ";
	cin  >> numPicks;
	while (numPicks < 1 || numPicks > pickFrom)
	{  
		if (numPicks < 1)                         // too few picks
			cout << "You must pick at least one number.\n"; 
		else                                      // too many picks
			cout << "You must pick " << pickFrom << " or fewer numbers.\n";

		cout << "How many numbers must you pick to play? ";
		cin  >> numPicks;    
	}

	// Compute the number of ways numbers can be selected by performing the following calculation
	// Factorial of pickFrom
	long int factTotalPickFrom = 1;
	for (int count = pickFrom; count >= 1; count--)
	{
		factTotalPickFrom *= count;
	}
	// Factorial of numPicks
	long int factTotalNumPicks = 1;
	int count;
	for (int count = numPicks; count >= 1; count--)
	{
		factTotalNumPicks *= count;
	}
	// Factorial of pickFrom - numPicks
	long int factTotalPickFromMinusNumPicks = 1;
	for (int count = pickFrom - numPicks; count >= 1; count--)
	{
		factTotalPickFromMinusNumPicks *= count;
	}

	// ways = factorial(pickFrom) / factorial(numPicks) / factorial (pickFrom - numPicks)
	ways = factTotalPickFrom / factTotalNumPicks / factTotalPickFromMinusNumPicks;

	// Display ways and probability of winning (1 / ways) to the user
	cout << fixed << showpoint << setprecision(4);
	cout << "\nYour chance of winning the lottery is "
		 << "1 chance in " << ways << ".\n";
	cout << "This is a probability of " << (1.0 / ways)    << "\n"; 

	return 0;
}// End of main()

