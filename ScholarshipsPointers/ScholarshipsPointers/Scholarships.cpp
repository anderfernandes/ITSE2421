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
	vector<Scholarship> scholars;    // This array of objects is initialized using 
	                                 //   the default constructor

	// Open input and output files and test to make sure they openned correctly
	ifstream fin;
	ofstream fout;
	OpenFiles(fin, fout);

	while(!fin.eof())
		// Read a line from the file and push onto end ofscholars object array
		scholars.push_back(readFile(sFileLine, sParsedLine, fin));

	bubbleSort(scholars);

	int sArraySize = scholars.size();       // Get the size of the array
	for(int i = 0; i < sArraySize; i++)
		writeFile(scholars[i], fout);		// Write a line to the output file

	// Write the summary report to the end of the outut file by calling the
	//  summary function and passing both the array of objects and the 
	//  file handle to the function
	createReportSummary(scholars, fout);

	cout << "Address of the scholars array in hexadecimal is:     x"
		 << &scholars << endl << endl;

	cout << "Address of the output file in hexadecimal is:        x"
		 << fout << endl << endl;

	cout << "Address of the pointer variable that is pointing " << endl
		 << "to the output file handler in hexadecimal is:        x"
		 << &fout << endl << endl;

	cout << "Address of the variable sArraySize is: x"
		<< &sArraySize << endl << endl;

	int *ptr; // Pointer variable, can point to an int
	ptr = &sArraySize; // Store the address of sArraySize in ptr
	cout << "The value in sArraySize is: " << sArraySize << endl;
	cout << "The address of sArraySize in hex is:                 x"
		    << ptr << endl << endl;

	cout << "The value in sArraySize is: " << *ptr << endl;
	*ptr = 100;
	cout << "The value in sArraySize is: " << *ptr << endl;
	*ptr +=1;
	cout << "The value in sArraySize is: " << *ptr << endl;

	Scholarship *sPtr; // Pointer variable, can point to a Scholarship object
	sPtr = &scholars[0]; // Store the address of scholars' 1st element in sPtr
	cout << endl << "The value in scholars' 1st record is: "
		<< scholars[0].getID() << endl;
	cout << "The address of scholars' 1st record in hex is:       x"
		<< sPtr << endl << endl;

	Scholarship sArray[10];
	for(int i = 0; i< 10; i++)
			sArray[i] = scholars[i];
	cout << endl << "The value of sArrays' 1st record in hex is   x:"
		 << sArray[0].getID() << endl;
	cout << "The address of sArray's beginning in hex is:         x"
		 << &sArray[0] << endl << endl;

	// Use the indirection operator to gain access to the contents of sArray
	cout << endl << "The value of sArray's 1st record in hex is: "
		 << sPtr[0].getID() << endl << endl;

	cout << endl << "The value of sArray's 1st record in hex is: "
		 << sPtr->getID() << endl << endl;

	bubbleSort(sArray, 10); // Call the overloaded bubbleSort using a pointer 
	fout.close(); 
	fout.open("sArrayReport.dat"); 
	if(!fout) 
	{ 
		cout << "Output file did not open. Program will exit." << endl; 
		exit(0); 
	} 
	createReportHeadings(fout); 
	for(int i = 0; i < 10; i++) 
		writeFile(sArray[i], fout); // Write a line to the output file

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
	if(lineCount == 60) // Ready for next page
	{
		fout << endl; // 
		createReportHeadings(fout);
		lineCount = 0;
	}
	fout << s.getID() <<  right << setw(10) << addCommas(s.getAmount()) 
		 << "    " << left <<  setw(12) << s.getType() 
		 << setw(10) << s.getLength() << right << setw(10) << s.getDate() 
		 << "   " << left <<  setw(15) << s.getFname() << s.getLname() << endl;
	lineCount++;
}

void createReportHeadings(ofstream &fout)
{
	fout << "******************************Scholarships Report*****************************\n"
		 << "******************************************************************************\n\n"
		 << "ID      Amount      Type      Length      Starts     First Name     Last Name\n"
		 << "------------------------------------------------------------------------------\n";
}
string addCommas(int num)  // Adds commas to any number for formatted output to report files
{
   string s = to_string(num);  // convert the nuber to string to hold the formatted number
   // insert comma's from right (at implied decimal point) to left
   int sSize = s.size(); // index to last digit
   if (sSize > 3)
      for (int i = (sSize - 3);  i > 0;  i -= 3)
         s.insert(i,",");  // look up the string's insert() method to see how it works
                           //  it is found on page 816 of the textbook or using "help"

   return s;
}
void createReportSummary(vector<Scholarship> sArray,  // Pass by value (copy) the entire array
						ofstream &fout)              // Pass the output file by reference
{
	int total = 0;                          // Accumulator for total amount
	int sArraySize = sArray.size();         // Get the size of the array
	// Accumulators for type totals
	int baseTotal = 0, baskTotal = 0, dTotal = 0, fTotal = 0, gTotal = 0, softTotal = 0,
		swimTotal = 0, tTotal = 0, vTotal = 0;
	
	// Loop through the array to accumulate the total amount of all scholarships
	for(int i = 0; i < sArraySize; i++)
	{
		total += sArray[i].getAmount();		// Add the Amount of each scholarship to the total
		string sType = sArray[i].getType(); // Get the type of scholarship for this record
		// Add the Type's Amount to the appropriate accumulator
		if(sType == "Baseball") baseTotal += sArray[i].getAmount();
		else if(sType == "Basketball") baskTotal += sArray[i].getAmount();
		else if(sType == "Diving") dTotal += sArray[i].getAmount();
		else if(sType == "Football") fTotal += sArray[i].getAmount();
		else if(sType == "Golf") gTotal += sArray[i].getAmount();
		else if(sType == "Softball") softTotal += sArray[i].getAmount();
		else if(sType == "Swimming") swimTotal += sArray[i].getAmount();
		else if(sType == "Track") tTotal += sArray[i].getAmount();
		else if(sType == "Volleyball") vTotal += sArray[i].getAmount();
	}

	// Write the summary report output line
	fout << "\n\nSummary Report \n" 
		 <<     "--------------\n"
		 << "        Total Number of Scholarships: " 
		 << right << setw(12) << sArraySize << endl
		 << "        Baseball:                    $ " 
		 << setw(11) << addCommas(baseTotal) << endl
		 << "        Basketball:                    " 
		 << setw(11) << addCommas(baskTotal) << endl
		 << "        Diving:                        " 
		 << setw(11) << addCommas(dTotal) << endl
		 << "        Football:                      " 
		 << setw(11) << addCommas(fTotal) << endl
		 << "        Golf:                          " 
		 << setw(11) << addCommas(gTotal) << endl
		 << "        Softball:                      " 
		 << setw(11) << addCommas(softTotal) << endl
		 << "        Swimming:                      " 
		 << setw(11) << addCommas(swimTotal) << endl
		 << "        Track:                         " 
		 << setw(11) << addCommas(tTotal) << endl
		 << "        Volleyball:                    " 
		 << setw(11) << addCommas(vTotal) << endl
		 << "        ===========================================\n"
		 << "        Total Scholarship Amount:    $ " 
		 << setw(11) << addCommas(total); 
}
// Overloaded function for report of specific type of scholarship
void writeFile(Scholarship s,    // Pass in by value- no need to change string in main()
			   ofstream &fout,  // Also pass in the output file buffer by ref to write to
			   string sType)    // Pass in by value the type of scholarship
{
	static int lineCount = 60;
	if(lineCount == 60) // Ready for next page
	{
		fout << endl; // 
		createReportHeadings(fout);
		lineCount = 0;
	}
	if(sType == s.getType())
	{
		fout << s.getID() <<  right << setw(10) << addCommas(s.getAmount()) 
			 << "    " << left <<  setw(12) << s.getType() 
			 << setw(10) << s.getLength() << right << setw(10) << s.getDate() 
			 << "   " << left <<  setw(15) << s.getFname() << s.getLname() << endl;
		lineCount++;
	}
}
/**********************************************************
 *                         search                         *
 * This function performs a linear search on an array of  *
 * Scholarship objects, using ID as the key field.        *
 * If the desired code is found, its array subscript is   *
 * returned. Otherwise, -1 is returned.                   *
 **********************************************************/
int search(vector<Scholarship> s, // Pass by value (copy) the entire array
		    string sLookFor)      // ID to lookfor
{
   int index = 0;         // Used as a subscript to search array 
   int position = -1;     // Used to record position of search value 
   bool found = false;    // Flag to indicate if the value was found 

   while (index < long(s.size()) && !found)
   {
      if (s[index].getID() == sLookFor) // If the value is found
      {
         found = true;          // Set the flag 
         position = index;      // Record the value's subscript 
      }
      index++;                  // Go to the next element 
   }
   return position;             // Return the position, or -1 
} // End search 
// Send report headings to console
void createReportHeadings()
{
	cout << "******************************Scholarships Report*****************************\n"
		 << "******************************************************************************\n\n"
		 << "ID      Amount      Type      Length      Starts     First Name     Last Name\n"
		 << "------------------------------------------------------------------------------\n";
}
void writeFile(Scholarship s)   // Pass in by value- no need to change string in main()
{
	static int lineCount = 60;
	if(lineCount == 60) // Ready for next page
	{
		cout << endl; // New page
	    createReportHeadings();
    	lineCount = 0;
	}
	cout << s.getID() <<  right << setw(10) << addCommas(s.getAmount()) 
		 << "    " << left <<  setw(12) << s.getType() 
		 << setw(10) << s.getLength() << right << setw(10) << s.getDate() 
		 << "   " << left <<  setw(15) << s.getFname() << s.getLname() << endl;
	lineCount++;
}
/********************************************************
 *                     bubbleSort                       *
 * This function performs a bubble sort on Sholarship   *
 * objects, arranging them in ascending Last Name order.*
 ********************************************************/
void bubbleSort(vector<Scholarship> &s)
{
   Scholarship temp;    // Holds Scholarship object
   bool swap;

   do
   {  swap = false;
      for (int count = 0; count < long(s.size() - 1); count++)
      {
         if (s[count].getLname() > s[count + 1].getLname())
         {
            temp = s[count];
            s[count] = s[count + 1];
            s[count + 1] = temp;
            swap = true;
         }
      }
   } while (swap);
}// End bubbleSort

void bubbleSort(Scholarship *s, int iSize)
{
	Scholarship temp; // Holds Scholarship object
	bool swap;
	do
	{ 
		swap = false;
		for (int count = 0; count < iSize-1; count++)
		{
			if (s[count].getLname() < s[count + 1].getLname())
			{
				temp = s[count];
				s[count] = s[count + 1];
				s[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}// End bubbleSort

