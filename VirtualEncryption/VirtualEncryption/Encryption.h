#pragma once

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Encryption
{
protected:
	ifstream inFile;
	ofstream outFile;
	char cKey;
public:
	Encryption(string inFileName, string outFileName);
	~Encryption();

	virtual char transform(char ch) const = 0;

	void encrypt();

	void decrypt();

	void setKey(char cK);
};
