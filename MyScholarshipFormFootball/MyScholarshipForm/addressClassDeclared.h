#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class Address
{
public:
	Address();
private:
	string street;
	string city;
	string state;
	string zip;
public:
	void setCity(string);
	void setStreet(string);
	void setState(string);
	void setZip(string);

	string getStreet();
	string getCity();
	string getState();
	string getZip();
};

