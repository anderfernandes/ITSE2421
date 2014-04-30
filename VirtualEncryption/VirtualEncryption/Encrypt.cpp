#include "stdafx.h"
#include "Encryption.h"

Encryption::Encryption(string inFileName, string outFileName)
{
	inFile.open(inFileName);
	outFile.open(outFileName);
	if (!inFile)
	{
		cout << "The file " << inFileName
			 << " cannot be opened.";
		exit(1);
	}
}

Encryption::~Encryption()
{
	inFile.close();
	outFile.close();
}

void Encryption::encrypt()
{
	char ch;
	char transCh;
	inFile.get(ch);
	while (!inFile.fail())
	{
		transCh = transform(ch);
		outFile.put(transCh);
		inFile.get(ch);
	}
}

void Encryption::decrypt()
{
	char ch;
	char transCh;
	inFile.get(ch);
	while (!inFile.fail())
	{
		transform(ch) = transCh;
		outFile.put(transCh);
		inFile.get(ch);
	}
}

void Encryption::setKey(char cK)
{
	cKey = cK;
}