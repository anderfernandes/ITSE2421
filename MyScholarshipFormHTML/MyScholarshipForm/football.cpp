// footbal.cpp file
//   defines Football class methods
#include "stdafx.h"
#include"football.h"

int Football::numFootballScholars = 0;

Football::Football(string id, string p)
{
	ID = id;
	position = p;
	numFootballScholars++;
}
// Football copy constructor
Football::Football(Football &obj)
	: Scholarship(obj)  // Call to base class 
	                    //  for rest of copy
{
	position = obj.position;
	obj.numFootballScholars++;
}
void Football::setPos(string s)
{ 
	position = s;
}
string Football::getPos()
{ 
	return position;
}