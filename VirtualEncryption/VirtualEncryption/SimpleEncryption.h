#pragma once

#include "stdafx.h"
#include "Encryption.h"

class SimpleEncryption : public Encryption
{
public:
	char transform(char ch) const
	{return ch + cKey;}
	SimpleEncryption(string inFileName, string outFileName)
		: Encryption(inFileName, outFileName)
	{}
};