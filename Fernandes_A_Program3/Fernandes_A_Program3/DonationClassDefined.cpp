/********************************
* Student: Anderson Fernandes	*
* Class: ITSE 2421				*
* Professor: Doug Edwards		*
* Assignment: Program 3         *
*********************************/

// File: DonationClassDefined.cpp
// Description: This file declares the Donation class.

#include "DonationClassDeclared.h"

// Default Constructor
Donations::Donations()
{
	giftID = "";
	donorName = "";
	phone = "";
	poc = "";
	itemDonated = "";
	category = "";
	value = 0.00;
}

// Overloaded Constructor
Donations::Donations(string gid, 
					string dn, 
					string ph, 
					string pofc, 
					string itd, 
					string cat, 
					double v) 
{
	setGiftID(gid);
	setDonorName(dn);
	setPhone(ph);
	setPoc(pofc);
	setItemDonated(itd);
	setCategory(cat);
	setValue(v);
}

// Sets for private member variables

bool Donations::setGiftID(string gid)
{
	if (gid.empty())
	{
		giftID = "invalid";
		return false;
	}
	giftID = gid;
	return true;
}

bool Donations::setDonorName(string dn)
{
	if(dn.empty())
	{
		donorName = "invalid";
		return false;
	}
	donorName = dn;
	return true;
}

bool Donations::setPhone(string ph)
{
	if(ph.empty())
	{
		phone = "invalid";
		return false;
	}
	phone = ph;
	return true;
}

bool Donations::setPoc(string pofc)
{
	if(pofc.empty())
	{
		poc = "invalid";
		return false;
	}
	poc = pofc;
	return true;
}

bool Donations::setItemDonated(string itd)
{
	if (itd.empty())
	{
		itemDonated = "invalid";
		return false;
	}
	itemDonated = itd;
	return true;
}

bool Donations::setCategory(string cat)
{
	if (cat.empty())
	{
		category = "invalid";
		return true;
	}
	category = cat;
	return true;
}

bool Donations::setValue(double v)
{
	if (v < 0)
	{
		value = 0.00;
		return false;
	}
	value = v;
	return true;
}

// Gets for private member variables

string Donations::getGiftID()
{
	return giftID;
}

string Donations::getDonorName()
{
	return donorName;
}

string Donations::getPhone()
{
	return phone;
}

string Donations::getPoc()
{
	return poc;
}

string Donations::getItemDonated()
{
	return itemDonated;
}

string Donations::getCategory()
{
	return category;
}

double Donations::getValue()
{
	return value;
}