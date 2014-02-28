#include "circle.h"
#include "rectangle.h"
#include "square.h"


/******************************************************************
 *                            main                                *
 ******************************************************************/
int main()
{
	Circle circle1,          // Define 2 Circle objects 
		   circle2; 

	circle1.setRadius(1);    // This sets circle1's radius to 1.0
	circle2.setRadius(2.5);  // This sets circle2's radius to 2.5

	// Get and display each circle's area
	cout << "The area of circle1 is " << circle1.getArea() << endl;
	cout << "The area of circle2 is " << circle2.getArea() << endl;

	Rectangle box;
	double boxLength, boxWidth;
	cout << "This part of the program will calculate "
				"the area of a rectangle.\n";
	cout << "What is the length? ";
	cin >> boxLength;
	cout << "What is the width? ";
	cin >> boxWidth;

	// Call member functions to set box dimensions
	box.setLength(boxLength);
	box.setWidth(boxWidth);

	// Call member functions to get box information to display
	cout << "\nHere is the retangle's data: \n";
	cout << "Length: " << box.getLength() << endl;
	cout << "Width: "  << box.getWidth()  << endl;
	cout << "Area : "  << box.getArea()   << endl;

	Square card;
	double cardSide;
	cout << "This aprt of the program will calculate "
				"the area of a rectangle.\n";
	cout << "What is the side of the triangle? ";
	cin >> cardSide;

	// Call member functions to set card dimensions
	card.setSquareSide(cardSide);

	// Call member functions to display card's information
	cout << "\nHere is the rectangle's data: \n";
	cout << "Side: " << card.getSquareSide() << endl;
	cout << "Area: " << card.getSquareArea() << endl;

	return 0;
}
