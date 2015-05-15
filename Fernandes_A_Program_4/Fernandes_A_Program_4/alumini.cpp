// alumini.cpp

/************************************
*	Student: Anderson Fernandes		*
*	Class: ITSE 2421				*
*	Professor: Doug Edwards			*
*	Date: 4/5/2014					*
*	Assignment: Program 4			*
*************************************/

/********************************************************************
*	This file has the main function, as well as auxiliary functions	*
*	for the Alumini and HTMLTable classes.							*
*********************************************************************/

#include "alumini.h" // Required for the use of the Alumini Class
#include "HTMLTable.h" // Required for the use of the HTMLTable class

int main()
{
	mainMenu(); // Call main menu

	return 0;
}

// This function will open the file for read

void OpenFiles(ifstream &in)
{
	in.open("members.csv");
	if(!in)
	{
		cout << "Input file did not open. Program will exit." << endl;
		exit(0);
	}
}

// This function will read the file and return a vector with the data
// from whatever file the program opens

Alumini readFile(string &aLine,				// Pass in by reference to change string in main()
			  vector<string> &aParsed,		// Pass in by reference to change array in main()
			  ifstream &fin)				// Also pass in the input file buffer by ref to read from
{										 
	getline(fin,aLine);
	stringstream lineStream(aLine);			// A special string class for pre-output formatting
	string field;
	aParsed.clear();						// Empty the Parsed Line for reuse

    while(getline(lineStream,field,','))	// While there are fields between the ,
    {
        aParsed.push_back(field);			// Push them onto the string array vector
    }
	// return a Alumini object copy created with the initialization construction
	return Alumini(aParsed[0], aParsed[1], aParsed[2],
		               aParsed[3], aParsed[4], aParsed[5], aParsed[6],
					   aParsed[7], aParsed[8]);
}

// This function writes an HTML table with Boostrap HTML5 formatting

void writeTable(vector<Alumini> &aArray)
{
	string sTitle[] = {"Cow Town College Alumini", ""};
	string sHeaders[] = {"Last Name", "First Name", "Company", "Address", 
		"City", "State", "Zip", "Phone", "Email", ""};

	HTMLTable hTable;
	hTable.setTitle(StringVector(sTitle));
	hTable.setHeaders(StringVector(sHeaders));

	int arraySize = aArray.size();

	for(int i = 0; i < arraySize; i++)
	{
		string row[] = {aArray[i].getLastName(),
									aArray[i].getFirstName(),
									aArray[i].getCompanyName(),
									aArray[i].getAddress(),
									aArray[i].getCity(),
									aArray[i].getState(),
									aArray[i].getZip(),
									aArray[i].getPhone(),
									aArray[i].getEmail(),
										""};
		hTable.addRow(StringVector(row));
	}

	string fileName;
	cout << "File will be saved as HTML" << endl;
	cout << "Please name your file without the extension: ";
	cin >> fileName;

	ofstream fout(fileName + ".html");
	if(!fout)
	{
		cout << "Could not save file. " << endl;
		cout << "Do you have permission to write in this folder?"; 
		cout <<	"Program will exit."
			 << endl;
		exit(0);
	}
	cout << "File \"" + fileName + ".html\" saved successfully." << endl;
	fout << hTable;
	fout.close();
	system("PAUSE");
	system("CLS");
}

// This function is responsible for showing the user the main menu

void mainMenu()
{
	int option;

	do
	{
	    option = 0;

		cout << "	 	      Cow Town College Alumini Program               " << endl;
		cout << "=============================================================" << endl
			 << endl;
		cout << "      1: All Members by Natural Order of Input File          " << endl << endl;
		cout << "      2: All Members Sorted Ascending by Last Name           " << endl << endl;
		cout << "      3: Members in One State Only, sorted Ascending by City " << endl << endl;
		cout << "      0: Exit the program                                    " << endl << endl;
		cout << "Please select a report you wish to be run from menu above (1-3): ";
		cin >> option;
		cout << endl;

		runProgram(option);
	}
	while (option != 0);

}

// This function gets the option selected by the user and runs
// whatever report it needs to

void runProgram(int op)
{
	string aFileLine; // Read in each line of the file
	vector<string> aParsedLine; // Vector to hold the parsed line from file
	vector<Alumini> a; // Vector with Alumini information
	ifstream fin;

	OpenFiles(fin);

	while(!fin.eof())
		// Read a line from the file and push onto end of alumini object array
		a.push_back(readFile(aFileLine, aParsedLine, fin));

	int aSize = a.size(); // Get the size of the alumini array

	switch(op)
	{
		case 0: cout << "Closing program." << endl; exit(0);
		case 1: writeTable(a); break;
		case 2: sortAscendingLastName(a); break;
		case 3: sortStateAndCity(a); break;
	}
}

// Sort data ascending by last name

void sortAscendingLastName(vector<Alumini> &a)
{
	Alumini temp;
	bool swap;

	do
	{
		swap = false;
		for (int count = 0; count < long(a.size() - 1); count ++)
		{
			if (a[count].getLastName() > a[count + 1].getLastName())
			{
				temp = a[count];
				a[count] = a[count + 1];
				a[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);

	writeTable(a);
}

// Sort by State and City

void sortStateAndCity(vector<Alumini> &a)
{
	Alumini temp;
	bool swap;
	string state;

	vector<Alumini> b;

	cout << "Enter a state, two characters only: ";
	cin >> state;

	if (state.size() > 2)
	{
		cout << "Error: enter only two characters. Please try again" << endl;
		system("PAUSE");
	    system("CLS");
		return;
	}

	do
	{
		swap = false;
		for (int count = 0; count < long(a.size() - 1); count ++)
		{
			a[count].setState(state);
			if (a[count].getCity() > a[count + 1].getCity())
			{
				temp = a[count];
				a[count] = a[count + 1];
				a[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);

	writeTable(a); // Write HTML table
}