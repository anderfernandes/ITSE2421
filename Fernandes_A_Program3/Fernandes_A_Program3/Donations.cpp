/********************************
* Student: Anderson Fernandes	*
* Class: ITSE 2421				*
* Professor: Doug Edwards		*
* Assignment: Program 3         *
*********************************/

// File: Donations.cpp
// Description: Contains main, sort and search functions

#include "Donations.h"

int main()
{
	mainMenu();
}

void mainMenu()
{
	int option;

	do
	{
	    option = 0;

		cout << "United Cause Relief Agency daily Donations Reports Menu" << endl;
		cout << "=======================================================" << endl
			 << endl;

		cout << "      1: All by Company Name                 " << endl << endl;
		cout << "      2: All by Donor, Ascending             " << endl << endl;
		cout << "      3: All by Donor, Descending            " << endl << endl;
		cout << "      4: All by Category, Ascending          " << endl << endl;
		cout << "      5: All by Gift ID, Ascending           " << endl << endl;
		cout << "      6: One Donor only by Value, Descending " << endl << endl;
		cout << "      0: Exit the program                    " << endl << endl;
		cout << "Please select a report you wish to be run from menu above (1-5): ";
		cin >> option;
		cout << endl;

		runProgram(option);
	}
	while (option != 0);

}

void runProgram(int &op)
{
	string dFileLine;
	vector<string> dParsedLine;
	vector<Donations> donors;
	string selectDonor;

	// Open input and output files
	ifstream fin;
	ofstream fout;
	openFiles(fin, fout);

	while(!fin.eof())
		// Read a line from the file and push onto end of array
			donors.push_back(readFile(dFileLine, dParsedLine, fin));
	

	switch (op)
		{
			case 0: cout << "Closing program." << endl; exit(0);
			case 1: nameSort(donors); break;
			case 2: donorSortAsc(donors); break;
			case 3: donorSortDes(donors); break;
			case 4: categorySortAsc(donors); break;
			case 5: idSortAsc(donors); break;
			case 6: donorSortOneDonorByValue(donors); break;
			default: cout << "Invalid option, please try again." << endl;  system("PAUSE"); system("CLS"); break;
		}

	int dArraySize = donors.size();
	for(int i = 0; i < dArraySize; i++)
		writeFile(donors[i], fout);
	
	// Write report summary
	createReportSummary(donors, fout);

}

void openFiles(ifstream &in, ofstream &out)
{
	string outputFileName;
	int fileChecker = 0;
	char overwriteOption;
	
	in.open("Donations.csv");
	if(!in)
	{
		cout << "input file did not open. Program will exit." << endl;
		exit(0);
	}

	cout << "Please enter the filename without extension: ";
	cin >> outputFileName;
	out.open(outputFileName + ".dat");
	cout << "File \"" + outputFileName + ".dat\" created and saved sucessfully with your report.\n";
	system("PAUSE");
	system("CLS");
}

Donations readFile(string &sLine, 
	               vector<string> &sParsed, 
				   ifstream &fin)
{
	getline(fin,sLine);
	stringstream lineStream(sLine);
	string field;
	sParsed.clear();

	while(getline(lineStream, field, ','))
	{
		sParsed.push_back(field);
	}

	return Donations(sParsed[0], sParsed[1], sParsed[2],
						sParsed[3], sParsed[4], sParsed[5], stoi(sParsed[6]));
}

void createReportHeadings(ofstream &fout)
{
	fout << "			                          United Cause Relief Agency Daily Donations                                                \n"
		 << "			                          ------------------------------------------                                                \n"
		 << "Gift ID     Company                          Phone             POC         Item Donated            Category               Value\n"
		 << "===============================================================================================================================\n";
		 
}

string addCommas(int num)
{
	string s = to_string(num);
	int sSize = s.size();
	if (sSize > 3)
	{
		for (int i = (sSize - 3); i > 0; i-=3)
			s.insert(i, ",");
	}
	return s;
}

void createReportSummary(vector<Donations> dArray, ofstream &fout)
{
	int total = 0;
	double dArraySize = dArray.size();
	// Accumulators for type totals
	int clothingTotal = 0; int movieTheaterTotal = 0; int miscTotal = 0; int foodTotal = 0;
		int softwareTotal = 0; int theaterTotal = 0; int booksTotal = 0; int musicTotal = 0;
	for(int i = 0; i < dArraySize; i++)
	{
		total += dArray[i].getValue();
		string dType = dArray[i].getCategory();
		// Add the Type's Amount to the appropriate accumulator
		if(dType == "Clothing") clothingTotal += dArray[i].getValue();
		else if(dType == "Movie Theater") movieTheaterTotal += dArray[i].getValue();
		else if(dType == "Misc") miscTotal += dArray[i].getValue();
		else if(dType == "Food Total") foodTotal += dArray[i].getValue();
		else if(dType == "Software") softwareTotal += dArray[i].getValue();
		else if(dType == "Theater") theaterTotal += dArray[i].getValue();
		else if(dType == "Books") booksTotal += dArray[i].getValue();
		else if(dType == "Music") musicTotal += dArray[i].getValue();
	}

	// Write summary report

	fout << right << setw(3) << addCommas(clothingTotal) 
							 << setw(3) << addCommas(movieTheaterTotal)
		                     << setw(3) << addCommas(miscTotal) 
							 << setw(3) << addCommas(foodTotal) 
							 << setw(3) << addCommas(softwareTotal)
		                     << setw(3) << addCommas(theaterTotal) 
							 << setw(3) << addCommas(booksTotal) 
							 << setw(3) << addCommas(musicTotal)
		                     << setw(3) << addCommas(total);
}


void writeFile(Donations d, ofstream &fout)
{
	static int lineCount = 30;
	if(lineCount == 30) // Ready for next page
	{
		fout << endl;
		createReportHeadings(fout);
		lineCount = 0;
	}
	
	fout << left << setw(12) << d.getGiftID() << setw(33) << d.getDonorName() << setw(18)
		    << d.getPhone() << setw(12)
			<< d.getPoc() << setw(24) << d.getItemDonated() << setw(17) << d.getCategory() 
			<< setw(6) << "$ " << setprecision(2) << fixed << right << d.getValue() << endl;
	lineCount++;
	
}
// This function performs a linear search by Gift ID
int search(vector<Donations> d, string sLookFor)
{
	int index = 0;
	int position = -1;
	bool found = false;

	while (index < long(d.size()) && !found)
	{
		if (d[index].getGiftID() == sLookFor)
		{
			found = true;
			position = index;
		}
		index++;
	}
	return position;
} // End search

void bubbleSort(vector<Donations> &d)
{
	Donations temp; // Holds Donations object
	bool swap;
	do
	{
		swap = false;
		for (int count = 0; count < long(d.size() - 1); count ++)
		{
			if (d[count].getDonorName() > d[count + 1].getDonorName())
			{
				temp = d[count];
				d[count] = d[count + 1];
				d[count + 1] = temp;
				swap = true;
			}
		}
	} while(swap);
} // End bubble sort

void bubbleSort(Donations *d, int iSize)
{
	Donations temp;
	bool swap;
	do
	{
		swap = false;
		for (int count = 0; count < iSize - 1; count++)
		{
			if (d[count].getDonorName() < d[count + 1].getDonorName())
			{
				temp = d[count];
				d[count] = d[count + 1];
				d[count + 1] = temp;
				swap = true;
			}
		}
	} while(swap);
}// End bubleSort

void nameSort(vector<Donations> &d)
{
   Donations temp;    // Holds Scholarship object
   bool swap;

   do
   {  swap = false;
      for (int count = 0; count < long(d.size() - 1); count++)
      {
		  if (d[count].getDonorName() > d[count + 1].getDonorName())
         {
            temp = d[count];
            d[count] = d[count + 1];
            d[count + 1] = temp;
            swap = true;
         }
      }
   } while (swap);
}// End bubbleSort  donorSort(donors)

void donorSortAsc(vector<Donations> &d)
{
   Donations temp;    // Holds Scholarship object
   bool swap;

   do
   {  swap = false;
      for (int count = 0; count < long(d.size() - 1); count++)
      {
         if (d[count].getPoc() > d[count + 1].getPoc())
         {
            temp = d[count];
            d[count] = d[count + 1];
            d[count + 1] = temp;
            swap = true;
         }
      }
   } while (swap);
}// End bubbleSort by Donor Ascending

void donorSortDes(vector<Donations> &d)                                    //********************
{
   Donations temp;    // Holds Scholarship object
   bool swap;

   do
   {  swap = false;
      for (int count = d.size() - 1; count > 0; count--)     // count <long(s.size() - 1)
      {
         if (d[count].getPoc() > d[count - 1].getPoc())
         {
            temp = d[count];
            d[count] = d[count - 1];
            d[count - 1] = temp;
            swap = true;
         }
      }
   } while (swap);
}// End bubbleSort Donors Sort Descending

void categorySortAsc(vector<Donations> &d)                                    //********************
{
   Donations temp;    // Holds Scholarship object
   bool swap;

   do
   {  swap = false;
      for (int count = 0; count < long(d.size() - 1); count++)
      {
		  if (d[count].getCategory() > d[count + 1].getCategory())
         {
            temp = d[count];
            d[count] = d[count + 1];
            d[count + 1] = temp;
            swap = true;
         }
      }
   } while (swap);
}// End bubbleSort Category Sort Ascending

void idSortAsc(vector<Donations> &d)                                    //********************
{
   Donations temp;    // Holds Scholarship object
   bool swap;

   do
   {  swap = false;
      for (int count = 0; count < long(d.size() - 1); count++)
      {
		  if (d[count].getGiftID() > d[count + 1].getGiftID())
         {
            temp = d[count];
            d[count] = d[count + 1];
            d[count + 1] = temp;
            swap = true;
         }
      }
   } while (swap);
}// End bubbleSort Gift ID Sort Category

void donorSortOneDonorByValue(vector<Donations> &d)                                    
{
   Donations temp;    // Holds Scholarship object
   bool swap;
   string selectDonor;

   cout << "What donor would you like to sort? ";
   cin >> selectDonor;

   cout << 

   search(d, selectDonor);


   do
   {  swap = false;
      for (int count = d.size() - 1; count > 0; count--)
      {



         if (d[count].getPoc() > d[count - 1].getPoc())
         {
			 
			 

            temp = d[count];
            d[count] = d[count - 1];
            d[count - 1] = temp;
            swap = true;
         }
      }
   } while (swap);
}// End bubbleSort Sort Donor By Value

