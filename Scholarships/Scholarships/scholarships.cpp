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
	vector<string> sParsedLine;
	Scholarship scholars;			 // this object is initialized using default constructor

	// Open input and output files and test to make sure they openned correctly
	ifstream fin;
	ofstream fout;
	OpenFiles(fin, fout);
	scholars = readFile(sFileLine, sParsedLine, fin);
	writeFile(scholars, fout);
	
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

Scholarship readFile(string &sLine,
			  vector<string> &sParsed,
			  ifstream &fin)
	{
		getline(fin, sLine);
		stringstream lineStream(sLine);
		string field;

		while(getline(lineStream, field, ','))
		{
			sParsed.push_back(field);
		}
		return Scholarship(sParsed[0], stoi(sParsed[1]), sParsed[2],
							sParsed[3], sParsed[4], sParsed[5], sParsed[6]);
	}

void writeFile(Scholarship s, 
			   ofstream &fout)
{
	createReportHeadings(fout);
fout << s.getID() << setw(8) << s.getAmount() << setw(11) << s.getType() << setw(10)
		 << s.getLength() << setw(12) << s.getDate() << setw(7) << s.getFname() << setw(14)
		 << setw(19) << s.getLname();
}

void createReportHeadings(ofstream &fout)
{
	fout << "***********************Scholarships Report*****************************\n"
		 << "***********************************************************************\n\n"
		 << "ID     Amount  Type       Length    Starts      Last Name    First Name\n"
		 << "-----------------------------------------------------------------------\n";
}