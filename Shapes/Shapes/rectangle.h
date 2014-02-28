#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
using namespace std;

// Rectangle class declaration
class Rectangle
{
private:
	double length;
	double width;
public:
	void setLength(double);
	void setWidth(double);
	double getLength();
	double getWidth();
	double getArea();
};
#endif