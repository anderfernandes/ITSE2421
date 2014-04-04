// scholarshipClassDefined.cpp
// Member Function definitions for the Scholarship class
#include "stdafx.h"
#include "scholarshipClassDeclared.h"

int Scholarship::numScholarships = 0;

Scholarship::Scholarship()					// default constructor
{
	ID = "";
	Amount = 0;
	Type = "";
	Length = "";
	DateStarts = "";
	Lname = "";
	Fname = "";

}
Scholarship::Scholarship(string id,			// Initializing constructor
						 int a, 
						 string t, 
						 string len, 
						 string d, 
						 string ln, 
						 string fn)
{
	ID = id;
	Amount = a;
	Type = t;
	Length = len;
	DateStarts = d;
	Lname = ln;
	Fname = fn;

}

void Scholarship::setID(string id)		// Sets for private member variables
{
	ID = id;

}
void Scholarship::setAmount(int a)
{
	Amount = a;
}
void Scholarship::setType(string t)
{
	Type = t;
}
void Scholarship::setLength(string len)
{
	Length = len;
}
void Scholarship::setDate(string d)
{
	DateStarts = d;
}
void Scholarship::setLname(string ln)
{
	Lname = ln;
}
void Scholarship::setFname(string fn)
{
	Fname = fn;
}

string Scholarship::getID()			// Gets for private member variables
{
	return ID;
}
int Scholarship::getAmount()
{
	return Amount;
}
string Scholarship::getType()
{
	return Type;
}
string Scholarship::getLength()
{
	return Length;
}
string Scholarship::getDate()
{
	return DateStarts;
}
string Scholarship::getLname()
{
	return Lname;
}
string Scholarship::getFname()
{
	return Fname;
}

int Scholarship::getNumScholarships()
{
	numScholarships++;
	return numScholarships;
}

bool Scholarship::operator<(const Scholarship &right)
{
	if(this->Lname < right.Lname)
		return true;
	else
		return false;
}

bool Scholarship::operator>(const Scholarship &left)
{
	if(this->Lname < left.Lname)
		return true;
	else
		return false;
}

Scholarship::Scholarship(Scholarship &obj)					// default constructor
{
	ID = obj.ID;
	Amount = obj.Amount;
	Type = obj.Type;
	Length = obj.Length;
	DateStarts = obj.DateStarts;
	Lname = obj.Lname;
	Fname = obj.Fname;
	obj.numScholarships++;

}

Scholarship::~Scholarship()
{
	numScholarships--;
}

