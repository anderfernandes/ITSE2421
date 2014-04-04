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
#include <string>
using namespace std;

class Scholarship
{
private:
	string ID;
	int    Amount;
	string Type;
	string Length;
	string DateStarts;
	string Lname;
	string Fname;
	static int numScholarships;

public:
	Scholarship();					// default constructor
	Scholarship(string id,			// Initializing constructor
				int a, 
				string t, 
				string len, 
				string d, 
				string ln, 
				string fn);

	void setID(string id);			// Sets for private member variables
	void setAmount(int a);
	void setType(string t);
	void setLength(string len);
	void setDate(string d);
	void setLname(string ln);
	void setFname(string fn);

	string getID();			// Gets for private member variables
	int getAmount();
	string getType();
	string getLength();
	string getDate();
	string getLname();
	string getFname();
	int getNumScholarships();

	Scholarship(Scholarship &obj);
	bool operator<(const Scholarship &right);
	bool operator>(const Scholarship &left);
	~Scholarship();
	
};