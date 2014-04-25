// address.h
//  Address class to hold individual addresses
#pragma once
#include "stdafx.h"
#include <string>
using namespace std;

class Address
{
private:
	string street;
	string city;
	string state;
	string zip;

public:
	Address(){};  // Default contructor
	Address(string str,			// Initializing constructor
				string c, 
				string st, 
				string z);

	void setStreet(string);
	void setCity(string);
	void setState(string);
	void setZip(string);

	string getStreet();
	string getCity();
	string getState();
	string getZip();
};