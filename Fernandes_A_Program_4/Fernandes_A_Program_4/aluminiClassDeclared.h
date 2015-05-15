// aluminiClassDeclared.h

/************************************
*	Student: Anderson Fernandes		*
*	Class: ITSE 2421				*
*	Professor: Doug Edwards			*
*	Date: 4/5/2014					*
*	Assignment: Program 4			*
*************************************/

/**************************************************************** 
*   This file contains all member variable and member functions *
*   declarations and prototypes only. Function definitions are  *
*   found in the aluminiClassDefined.cpp file The member	    *
*   variables match the members.csv data file			    	*
****************************************************************/

#pragma once
#include <string>
using namespace std;

class Alumini
{
	protected:
		string lastName;
		string firstName;
		string companyName;
		string address;
		string city;
		string state;
		string zip;
		string phone;
		string email;

	public:
		Alumini();
		Alumini(string lName, string fName,
						string cName,
						string add,
						string ci,
						string st,
						string z,
						string ph,
						string e);
		Alumini(Alumini &obj);


		// Mutator Functions for private members
		bool setLastName(string lName);
		bool setFirstName(string fName);
		bool setCompanyName(string cName);
		bool setAddress(string add);
		bool setCity(string ci);
		bool setState(string st);
		bool setZip(string z);
		bool setPhone(string ph);
		bool setEmail(string e);

		// Acessor Functions
		string getLastName();
		string getFirstName();
		string getCompanyName();
		string getAddress();
		string getCity();
		string getState();
		string getZip();
		string getPhone();
		string getEmail();
};