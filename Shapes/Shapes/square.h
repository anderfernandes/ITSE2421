// Definition for class Square

#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
using namespace std;

class Square
{
	private:
		double squareSide; // Squares have the same size, no need for length and width
	public:
		void setSquareSide(double);
		double getSquareSide();
		double getSquareArea();
};
#endif