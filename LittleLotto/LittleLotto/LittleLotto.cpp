// This program finds the probability of winning a "mini" lottery when
// the user's set of numbers must exactly match the set drawn by the
// lottery organizers. In addition to main, it uses three functions.
#include <iostream>
#include <iomanip>
using namespace std;

// Function Prototypes
long int factorial(int n);
long int computeWays(int n, int k);
void getLoterryInfo(int&, int&);
void displayResults(long int w);


int main()
{
	int pickFrom,         // The number of numbers to pick from
		numPicks;         // The number of numbers to select

	// Compute the number of ways numbers can be selected by performing the following calculation
	getLoterryInfo(pickFrom, numPicks);

	// Display ways and probability of winning (1 / ways) to the user
	displayResults(computeWays(pickFrom, numPicks));

	return 0;

}// End of main()

/********************************************************************
*			Factorial												*
* Computes and returns the factorial of the non-negative integer	*
* passed to it. n! means n * (n-1) * (n-2) ... * 1					*
* 0! is a special case and is defined to be 1.						*
*********************************************************************/
long int factorial(int n)
{
	long int factTotal = 1;
	for (int i = n; i >= 1; i--)
	{
		factTotal *= i;
	}
	return factTotal;
} // End of factorial()

/****************************************************************
*			computeWays											*
*	Computes and returns the number of different possible sets	*
*   of k numbers that can be chosen from a set of n numbers.	*
*	The formula for this is n!									*
*							--------							*
*							k!(n-k)!							*
****************************************************************/
long int computeWays(int n, int k)
{
	return (factorial(n) / factorial(k) / factorial(n-k));
}// End of computeWays()

/********************************************************************
*						getLoterryInfo								*
* Gets and validates loterry info from user and places it in		*
* reference parameters referencing variables in the main function	*
*********************************************************************/
void getLoterryInfo(int &pickFrom, int &numPicks)
{
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
}

void displayResults(long int w)
{
	cout << fixed << showpoint << setprecision(4);
	cout << "\nYour chance of winning the lottery is "
		 << "1 chance in " << w << ".\n";
	cout << "This is a probability of " << (1.0 / w)    << "\n";
}