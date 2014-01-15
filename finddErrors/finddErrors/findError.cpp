 // findErrors.cpp
 // This program has several syntax and logic errors.
 
#include <iostream>
using namespace std;         
 
int main()
{
	// Changed "doubl" in line below to "double". (Anderson Fernandes)
	double  length = 0,        // Length of a room in feet
	        width = 0,         // Width of a room in feet
	        area = 0;          // Area of the room in sq. ft.
 
	// Get the room dimensions
	cout << "Enter room length (in feet): ";
	cin  >> length;

	cout << "Enter room width (in feet): ";
	cin  >> width;

	// Compute and display the area
	area = length * width;
	cout << "The area of the room is " << area << " square feet. " << endl;

	return 0;
}