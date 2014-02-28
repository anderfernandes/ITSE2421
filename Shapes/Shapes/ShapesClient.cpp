// ShapesClient.cpp client file
// main client program
#include <iostream>
#include "circle.h"
using namespace std;

// circle.cpp - Circle class implementation file
// The member function implementation section follows. It contains the
// actual function definitions for the Circle class member functions. 

/******************************************************************
 *                      Circle::setRadius                         *
 * This function copies the argument passed into the parameter to *
 * the private member variable radius.                            *
 ******************************************************************/
void Circle::setRadius(double r)
{	radius = r; 
}
                
/******************************************************************
 *                        Circle::getArea                         *
 * This function calculates and returns the Circle object's area. *
 * It does not need any parameters because it already has access  *
 * to the member variable radius.                                 *
 ******************************************************************/
double Circle::getArea()
{	return 3.14 * pow(radius, 2); 
}


