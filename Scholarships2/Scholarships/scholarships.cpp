// Scholarships.cpp
// This program tutorial demonstrates arrays using vectors
// It also demonstrates file I/O techniques with vectors
//  and making arrays of objects
// The Datafile used in a CSV (Comma Seperated Values) file
//  named Scholarships.csv
// The structor of the data file is:
//  ID, Amount Awarded, Scholarship Type, Length of Scholarship, Date Starts, Last Name, First Name

#include "scholarships.h"


int main()
{
	string sFileLine;				 // a string to read in each line of the file
	vector<string> sParsedLine;      // array to hold the parsed line from file
	vector<Scholarship> scholars;			 // this object is initialized using default constructor

	// Open input and output files and test to make sure they openned correctly
	ifstream fin;
	ofstream fout;
	OpenFiles(fin, fout);

	while(!fin.eof())
		scholars.push_back(readFile(sFileLine, sParsedLine, fin));
	
	int sArraySize = scholars.size();
	for(int i = 0; i < sArraySize; i++)
		writeFile(scholars[i], fout);		// Write a line to the output file


	return 0;
}
void OpenFiles(ifstream &in, ofstream &out)  // must be passed in by reference
{
	in.open("Scholarships.csv");
	if(!in)
	{
		cout << "Input file did not open. Program will exit." << endl;
		exit(0);
	}

	out.open("ScholarshipsReport.dat");
	if(!out)
	{
		cout << "Output file did not open. Program will exit." << endl;
		exit(0);
	}

}

Scholarship readFile(string &sLine,           // Pass in by reference to change string in main()
			  vector<string> &sParsed, // Pass in by reference to change array in main()
			  ifstream &fin)           // Also pass in the input file buffer by ref to read from
{										 
	getline(fin,sLine);
	stringstream lineStream(sLine);    // A special string class for pre-output formatting
	string field;
	sParsed.clear();                  // Empty the Parsed Line for reuse

    while(getline(lineStream,field,','))  // While there are fields between the ,
    {
        sParsed.push_back(field);        // Push them onto the string array vector
    }
	// return a Scholarship object copy created with the initialization construction
	return Scholarship(sParsed[0], stoi(sParsed[1]), sParsed[2],
		               sParsed[3], sParsed[4], sParsed[5], sParsed[6]);
}

void writeFile(Scholarship s,    // Pass in by value- no need to change string in main()
			   ofstream &fout)  // Also pass in the output file buffer by ref to write to
{
	static int lineCount = 60;
	if(lineCount == 60)
	{
		fout << endl;
		createReportHeadings(fout);
		lineCount = 0;
	}
	fout << s.getID() << right << setw(10) << addCommas(s.getAmount())
		 << "  " << left << setw(12) << s.getType() 
		 << setw(10) << s.getLength() << right << setw(10) << s.getDate() 
		 << "  " << left << setw(15) << s.getFname() << s.getLname() << endl;
	lineCount++;
}

void createReportHeadings(ofstream &fout)
{
	fout << "**************************Scholarships Report******************************\n"
		 << "***************************************************************************\n\n"
		 << "ID      Amount    Type      Length     Starts     Last Name      First Name\n"
		 << "---------------------------------------------------------------------------\n";
}

string addCommas(int num)
{
	string s = to_string(num);
	int sSize = s.size();
	if (sSize > 3)
		for (int i = (sSize - 3); i > 0; i -= 3)
			s.insert(i,",");

	return s;
}