/********************************
* Student: Anderson Fernandes	*
* Class: ITSE2421				*
* Professor: Doug Edwards		*
* Date: 2/5/2014				*
*********************************/

/****************************************************
* File: InventoryClassMethods.cpp					*
* Description: This file containts all the member	*
*              methods of the Inventory class.		*
*****************************************************/

// Include class definition and prototypes of member methods
#include "Inventory.h"

// Default constructor
Inventory::Inventory() 
{
	itemNumber = 0;
	quantity = 0;
	cost = 0.0;
}

// Overloaded constructor
Inventory::Inventory(int iN = 0, int qt= 0, double co = 0.0)
{
	
	itemNumber = iN;
	quantity = qt;
	cost = co;
}

// *** MUTATOR METHODS *** //

// Item number mutator method
void Inventory::setItemNumber(int iN)
{
	// Do not assign values to class if item number is negative
	while(iN < 0)
	{
		cout << "Item number must be 0 or greater. Please re-enter: ";
		cin >> iN;
	}
	itemNumber = iN;
}

// Quantity mutator method
void Inventory::setQuantity(int qt)
{
	// Do not assign values to class if quantity is negative
	while(qt < 0)
	{
		cout << "Quantity must be 0 or greater. Please re-enter: ";
		cin >> qt;
	}
	quantity = qt;
}

// Cost mutator method
void Inventory::setCost(double co)
{
	// Do not assign values to class if cost is negative
	while(co < 0)
	{
		cout << "Cost must be 0 or greater. Please re-enter: ";
		cin >> co;
	}
	cost = co;
}
// *** ACCESSOR METHODS *** //

// Item number accessor method
int Inventory::getItemNumber()
{
	return itemNumber;
}

// Quantity accessor method
int Inventory::getQuantity()
{
	return quantity;
}

// Cost accessor method
double Inventory::getCost()
{
	return cost;
}

// *** OTHER METHODS *** //

// This method returns the total cost
double Inventory::getTotalCost()
{
	return quantity * cost;
}