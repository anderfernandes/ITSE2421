/********************************
* Student: Anderson Fernandes	*
* Class: ITSE 2421				*
* Professor: Doug Edwards		*
* Assignment: Program 3         *
*********************************/

// File: DonationClassDeclared.h
// Description: Declares the Donations class

#pragma once
#include <string>
using namespace std;

class Donations
{
private:
	string giftID;
	string donorName;
	string phone;
	string poc;
	string itemDonated;
	string category;
	double value;

public:

	Donations(); // Default Constructor
	Donations(string gid, 
					string dn, 
					string ph, 
					string pofc, 
					string itd, 
					string cat, 
					double v); // Overloaded Constructor
	//~Donations(); // Destructor

	// Sets
	bool setGiftID(string gid);
	bool setDonorName(string dn);
	bool setPhone(string ph);
	bool setPoc(string pofc);
	bool setItemDonated(string itd);
	bool setCategory(string cat);
	bool setValue(double v);

	// Gets
	string getGiftID();
	string getDonorName();
	string getPhone();
	string getPoc();
	string getItemDonated();
	string getCategory();
	double getValue();
};