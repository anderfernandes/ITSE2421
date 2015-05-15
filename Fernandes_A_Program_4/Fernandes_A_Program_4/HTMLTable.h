// HTMLTable.h

/************************************
*	Student: Anderson Fernandes		*
*	Class: ITSE 2421				*
*	Professor: Doug Edwards			*
*	Date: 4/5/2014					*
*	Assignment: Program 4			*
*************************************/

// This file has the declaration of the StringVector and
// HTMLTable classes

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class StringVector : public vector<string>
{
public:
	StringVector(string s[])
	{
		int k = 0;
		while (s[k].length() !=0)
		{
			this->push_back(s[k]);
			k++;
		}
	}
};

class HTMLTable
{
private:
	vector<string> title;
	vector<string> headers;
	vector<vector<string> > rows;

	void writeRow(ostream &out, string tag, vector<string> row);

public:
	void setTitle(const vector<string> &title)
	{ this->title = title; }
	void setHeaders(const vector<string> &headers)
	{ this->headers = headers; }
	void addRow(const vector<string> &row)
	{ rows.push_back(row); }
	friend ostream & operator<<(ostream & out, HTMLTable htmlTable);
};