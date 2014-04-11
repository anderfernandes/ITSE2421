#include "stdafx.h"
#include "football.h"

void Football::setPos(string p)
{
	if (position.empty())
	{
		position = "Invalid";
		cout << "Error: Position cannot be empty." << endl;
	}
	 position = p;
}

string Football::getPos()
{
	return position;
}