// address.cpp file
//   defines Address class methods
#include "stdafx.h"
#include"address.h"

Address::Address(string str,	// Initializing constructor
				 string c, 
				 string st, 
				 string z)
{
	street = str;
	city = c;
	state = st;
	zip = z;
}

void Address::setStreet(string s)
{
	street = s;
}
void Address::setCity(string s)
{
	city = s;
}
void Address::setState(string s)
{
	state = s;
}
void Address::setZip(string s)
{
	zip = s;
}

string Address::getStreet()
{
	return street;
}
string Address::getCity()
{
	return city;
}
string Address::getState()
{
	return state;
}
string Address::getZip()
{
	return zip;
}