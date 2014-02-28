// Functions for class Square
#include "square.h"
// Square::setSquareSide
// Sets the square's side
void Square::setSquareSide(double sqS)
{
	if (sqS >= 0.0)
		squareSide = sqS;
	else
	{
		squareSide = 1.0;
		cout << "Invalid length. Using a default value of 1.0\n";
	}
}
// Square::getSquareSide
// Gets the square's side
double Square::getSquareSide()
{
	return squareSide;
}
// Square::getSquareArea
// Calcualtes and returns square's area
double Square::getSquareArea()
{
	return (squareSide * squareSide);
}