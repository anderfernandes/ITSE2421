#include "stdafx.h"
#include "addressClassDeclared.h"


Address::Address()
{
	city = "";
	street = "";
	state = "";
	zip = "";
}

void Address::setCity(string c)
{
	if (city.empty())
	{
		city = "Invalid";
		cout << "Error: name of the city cannot be empty." << endl;
	}
	city = c;
}


void Address::setStreet(string str)
{
	if (street.empty())
	{
		street = "Invalid";
		cout << "Error: name of the street cannot be empty." << endl;
	}
	street = str;
}


void Address::setState(string sta)
{
	if (state.empty())
	{
		state = "Invalid";
		cout << "Error: name of the state cannot be empty." << endl;
	}
	else if (state.length() !=2)
	{
		city = "Invalid";
		cout << "Error: name of the state should have only two characters." << endl;
	}
	state = sta;
}


void Address::setZip(string z)
{
	if (zip.empty())
	{
		zip = "Invalid";
		cout << "Error: zip cannot be empty." << endl;
	}
	else if (zip.length() !=5)
	{
		city = "Invalid";
		cout << "Error: zip should have 5 characters." << endl;
	}
	zip = z;
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