// football.h
//  Football class to hold individual addresses
#pragma once
#include "stdafx.h"
#include "scholarshipClassDeclared.h"
#include <string>
using namespace std;

class Football : public Scholarship
{
private:
	string position;
	static int numFootballScholars;

public:
	Football()
	{ numFootballScholars++; }
	Football(string id, string p);
	Football(Football &obj);
	~Football()
	{ numFootballScholars--; }
	void setPos(string);
	string getPos();
	int getNumFs()
	{ return numFootballScholars; }
};
