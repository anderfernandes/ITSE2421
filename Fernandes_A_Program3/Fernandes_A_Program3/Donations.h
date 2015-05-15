/********************************
* Student: Anderson Fernandes	*
* Class: ITSE 2421				*
* Professor: Doug Edwards		*
* Assignment: Program 3         *
*********************************/

// File: Donations.h
// Description: Contains prototypes for functions in "Donations.cpp"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <string>
#include "DonationClassDeclared.h"
using namespace std;

void mainMenu();
void runProgram(int &op);
void openFiles(ifstream &in, ofstream &out);
Donations readFile(string &sLine, vector<string> &sParsed, ifstream &fin);
void createReportHeadings(ofstream &fout);
string addCommas(int num);
void createReportSummary(vector<Donations> sArray, ofstream &fout);
void writeFile(Donations d, ofstream &fout);
int search(vector<Donations> d, string sLookFor);
//void bubbleSort(vector<Donations> &d);
//void bubbleSort(Donations *d, int iSize);

//Report Functions
void nameSort(vector<Donations> &d);
void donorSortAsc(vector<Donations> &d);
void donorSortDes(vector<Donations> &d);
void categorySortAsc(vector<Donations> &d);
void idSortAsc(vector<Donations> &d);
void donorSortOneDonorByValue(vector<Donations> &d); 
