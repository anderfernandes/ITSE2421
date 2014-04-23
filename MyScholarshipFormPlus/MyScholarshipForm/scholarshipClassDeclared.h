// ScholarshipClassDeclared.h
// This file contains all member variable 
//   and member functions declarations
//   and prototypes only.
// Function definitions are found in the 
//     scholarshipClassDefined.cpp file
// The member variables match the
//   scholarships.csv data file
#pragma once
#include "stdafx.h"
#include "address.h"
#include <string>
using namespace std;

class Scholarship
{
protected:
	string ID;
	int    Amount;
	string Type;
	string Length;
	string DateStarts;
	string Lname;
	string Fname;
	static int numScholarships;

public:
	Address stuAddress;

	Scholarship();					// default constructor
	Scholarship(string id,			// Initializing constructor
				int a, 
				string t, 
				string len, 
				string d, 
				string ln, 
				string fn);
	Scholarship(Scholarship &obj);	// default copy constructor
	~Scholarship();					// default destructor

	bool operator>(const Scholarship &right);
	bool operator<(const Scholarship &right);
	void operator+(int right);
	void operator-(int right);

	void setID(string id);			// Sets for private member variables
	void setAmount(int a);
	void setType(string t);
	void setLength(string len);
	void setDate(string d);
	void setLname(string ln);
	void setFname(string fn);

	string getID();			// Gets for private member variables
	int getAmount();
	int getNumScholarships();
	string getType();
	string getLength();
	string getDate();
	string getLname();
	string getFname();
};