#pragma once
// Scholarships.h
// This file contains prototypes of functions used in main program
// This program tutorial demonstrates arrays using vectors
// It also demonstrates file I/O techniques with vectors
//  and making arrays of objects
// The Datafile used in a CSV (Comma Seperated Values) file
//  named Scholarships.csv
// The structor of the data file is:
//  ID, Amount Awarded, Scholarship Type, Length of Scholarship, Date Starts, Last Name, First Name
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <string>
#include "scholarshipClassDeclared.h"
#include "football.h"
using namespace std;


void OpenFiles(ifstream &in, ofstream &out, ifstream &inA, ifstream &inF, ofstream &outT);
Address readFile(string &sLine, vector<string> &sParsed, ifstream &fin,string sID);
Football readFile(string &sLine, vector<string> &sParsed, ifstream &fin,char c);
Scholarship readFile(string &sLine, vector<string> &sParsed, ifstream &fin);
void createReportHeadings(ofstream &fout);
string addCommas(int num);
void createReportSummary(vector<Scholarship> sArray, ofstream &fout);
bool saveFile(vector<Scholarship> *s);
string removeCommas(string sAmount);
void writeFile(Scholarship s, ofstream &fout);
void writeFile(Scholarship s, ofstream &fout, string sType);
void writeFile(vector<Scholarship> &sArray, ofstream &fout);
void writeTable(vector<Scholarship> &sArray);
