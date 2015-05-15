// alumini.h

/************************************
*	Student: Anderson Fernandes		*
*	Class: ITSE 2421				*
*	Professor: Doug Edwards			*
*	Date: 4/5/2014					*
*	Assignment: Program 4			*
*************************************/

/********************************************************************
*	This file has the has the prototypes for  auxiliary functions	*
*	for the Alumini and HTMLTable classes.							*
*********************************************************************/

#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <string>
#include "aluminiClassDeclared.h"

using namespace std;

void OpenFiles(ifstream &in);
Alumini readFile(string &aLine, vector<string> &aParsed, ifstream &fin);
void writeTable(vector<Alumini> &aArray);
void mainMenu();
void runProgram(int op);
void sortAscendingLastName(vector<Alumini> &a);
int search(vector<Alumini> &a, string aLookFor);
void sortStateAndCity(vector<Alumini> &a);