#pragma once
#include "stdafx.h"
#include "scholarshipClassDeclared.h"
#include <string>
#include <iostream>
using namespace std;

class Football : Scholarship
{
private:
	string position;

public:
	void setPos(string);
	string getPos();
};