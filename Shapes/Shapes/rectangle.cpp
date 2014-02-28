// rectangle.cpp - Member function implementation file
#include "rectangle.h"
// Rectangle::setLenght
// Sets the value of a member variable length
void Rectangle::setLength(double len)
{
	if (len >= 0.0)
		length = len;
	else
	{
		length = 1.0;
		cout << "Invalid length. Using a default value of 1.0\n";
	}
}
// Rectangle::setWidth
// This function sets the value of the member variable width.
void Rectangle::setWidth(double w)
{
	if (w >= 0.0)
		width = w;
	else
	{
		width = 1.0;
		cout << "Invalid width. Using a default value of 1.0.\n";
	}
}
// Rectangle::getLength
// This function returns the value in member variable length
double Rectangle::getLength()
{
	return length;
}
// Rectangle:getWidth
// Returns value in member variable width
double Rectangle::getWidth()
{
	return width;
}
// Rectangle::getArea
// This function calculates and returns the area of the rectangle
double Rectangle::getArea()
{
	return length * width;
}