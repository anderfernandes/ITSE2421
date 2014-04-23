// footbal.cpp file
//   defines Football class methods
#include "stdafx.h"
#include"football.h"

int Football::numFootballScholars = 0;

// Football copy constructor
Football::Football(Football &obj) 
	: Scholarship(obj)
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