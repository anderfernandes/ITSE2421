/********************************
* Student: Anderson Fernandes	*
* Class: ITSE2421				*
* Professor: Doug Edwards		*
* Date: 2/5/2014				*
*********************************/

/****************************************************
* File: Inventory.h									*
* Description: This file defines the Inventory class*
                and its methods' prototypes.		*
*****************************************************/

// Defining the header file
#ifndef INVENTORY_H 
#define INVENTORY_H

// Including  C++'s input/output stream library
#include <iostream>
// Including C++'s input/output manipulation library
#include <iomanip>
using namespace std; // Include standard namespace

// Defining class name
class Inventory
{
	private:            // Defining the class' data fields
		int itemNumber; // Will hold item number
		int quantity;   // Will hold quantity
		double cost;    // Will hold cost

	public:				
		// Defining constructors
		Inventory();	              // Default constructor
		Inventory(int iN, int qt, double co); // Overloaded constructor
		
		// Defining member method's prototypes
		void setItemNumber(int iN);	  // Item number mutator method
		void setQuantity(int qt);        // Quantity mutator method
		void setCost(double co);         // Cost mutator method
		int getItemNumber();          // Item number accessor method
		int getQuantity();            // Quantity accessor method
		double getCost();             // Quantity accessor method
		double getTotalCost();        // This method returns the total cost
};

#endif