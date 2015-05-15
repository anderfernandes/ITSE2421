// aluminiClassDefined.cpp

/************************************
*	Student: Anderson Fernandes		*
*	Class: ITSE 2421				*
*	Professor: Doug Edwards			*
*	Date: 4/5/2014					*
*	Assignment: Program 4			*
*************************************/

// This file contains member function definitions for the Alumini class

#include "aluminiClassDeclared.h"

Alumini::Alumini() // Default Constructor
{
	lastName    = "";
	firstName   = "";
	companyName = "";
	address     = "";
	city        = "";
	state       = "";
	zip         = "";
	phone       = "";
	email       = "";
}

// Overloaded constructor

Alumini::Alumini(string lName, string fName,
						string cName,
						string add,
						string ci,
						string st,
						string z,
						string ph,
						string e)
{
	firstName   = lName;
	lastName    = fName;
	companyName = cName;
	address     = add;
	city        = ci;
	state       = st;
	zip         = z;
	phone       = ph;
	email       = e;
}

// Copy constructor

Alumini::Alumini(Alumini &obj)
{
	lastName    = obj.lastName;
	firstName   = obj.firstName;
	companyName = obj.companyName;
	address     = obj.address;
	city        = obj.city;
	state       = obj.state;
	zip         = obj.zip;
	phone       = obj.phone;
	email       = obj.email;
}

// Set functions with data validation

bool Alumini::setLastName(string lName)
{
	if(lName.empty())
	{
		lastName = "invalid";
		return false;
	}
	lastName = lName;
	return true;
}

bool Alumini::setFirstName(string fName)
{
	if(fName.empty())
	{
		firstName = "invalid";
		return false;
	}
	firstName = fName;
	return true;
}

bool Alumini::setCompanyName(string cName)
{
	if(cName.empty())
	{
		companyName = "invalid";
		return false;
	}
	companyName = cName;
	return true;
}

bool Alumini::setAddress(string add)
{
	if(add.empty())
	{
		address = "invalid";
		return false;
	}
	address = add;
	return true;
}

bool Alumini::setCity(string ci)
{
	if(ci.empty())
	{
		address = "invalid";
		return false;
	}
	city = ci;
	return true;
}

bool Alumini::setState(string st)
{
	if(st.empty())
	{
		state = "invalid";
		return false;
	}
	state = st;
	return true;
}

bool Alumini::setZip(string z)
{
	if(z.empty())
	{
		zip = "invalid";
		return false;
	}
	zip = z;
	return true;
}

bool Alumini::setPhone(string ph)
{
	if(ph.empty())
	{
		phone = "invalid";
		return false;
	}
	phone = ph;
	return true;
}

bool Alumini::setEmail(string e)
{
	if(e.empty())
	{
		email = "invalid";
		return false;
	}
	email = e;
	return true;
}

// Get Functions

string Alumini::getLastName()
{
	return lastName;
}

string Alumini::getFirstName()
{
	return firstName;
}

string Alumini::getCompanyName()
{
	return companyName;
}

string Alumini::getAddress()
{
	return address;
}

string Alumini::getCity()
{
	return city;
}

string Alumini::getState()
{
	return state;
}

string Alumini::getZip()
{
	return zip;
}

string Alumini::getPhone()
{
	return phone;
}

string Alumini::getEmail()
{
	return email;
}
