// circle.h - Circle class specification file
#ifndef CIRCLE_H
#define CIRCLE_H
// This program demonstrates a simple class with member functions
// defined outside the class declaration.
#include <iostream>
#include <cmath>
using namespace std;

// Circle class declaration
class Circle
{  private:
      double radius;            // This is a member variable.
		
   public:
      void  setRadius(double);  // These are just prototypes 
      double getArea();         // for the member functions.
};
#endif
