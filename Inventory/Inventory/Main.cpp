/********************************
* Student: Anderson Fernandes	*
* Class: ITSE2421				*
* Professor: Doug Edwards		*
* Date: 2/5/2014				*
*********************************/

/****************************************************
* File: Main.cpp                					*
* Description: This file containts the main function*
*              and a function that runs inventory.	*
*****************************************************/

#include "Inventory.h" // Including the Inventory class header file

// Prototype of the function that  runs the inventory
void runInventory(int a, int b, double c);

int main() // Beginning of main
{
	// Demonstrating the default constructor
	Inventory inventoryA;
	cout << "Demonstrating the default constructor...\n";
	// Run inventory
	runInventory(inventoryA.getItemNumber(), inventoryA.getQuantity(), inventoryA.getCost());
	
	// Demonstrating the overloaded constructor
	Inventory inventoryB(124, 12, 84.95);
	cout << "Demonstrating the overloaded constructor...\n";
	// Run inventory
	runInventory(inventoryB.getItemNumber(), inventoryB.getQuantity(), inventoryB.getCost());

	// Demonstrating set functions
	Inventory inventoryC;
	inventoryC.setItemNumber(243);
	inventoryC.setQuantity(50);
	inventoryC.setCost(9.5);

	cout << "Demonstrating the set functions...\n";
	// Run inventory
	runInventory(inventoryC.getItemNumber(), inventoryC.getQuantity(), inventoryC.getCost());
	
	// Demonstrating input validation
	Inventory inventoryD;
	int a = -1, b = -1; // a will hold item number, b will hold quantity
	double c= -1;       // c will hold cost

	cout << "Demonstrating the input validation functions..." << endl;
	// Ask the user to enter item number
	cout << "Item number must be 0 or greater. Please re-enter: ";
	cin >> a;
	// Pass item number to the proper mutator function
	inventoryD.setItemNumber(a);
	
	// Ask the user to enter quantity
	cout << "Quantity must be 0 or greater. Please re-enter: ";
	cin >> b;
	// Pass quantity to the proper mutator function
	inventoryD.setQuantity(b);
	
	// Ask the user to enter cost
	cout << "Cost must be 0 or greater. Please re-enter: ";
	cin >> c;
	// Pass cost to the proper mutator function
	inventoryD.setCost(c);
	
	cout << endl;

	// Run inventory
	runInventory(inventoryD.getItemNumber(), inventoryD.getQuantity(), inventoryD.getCost());
	
	return 0;
}

// Prototype of the function that  runs the inventory
void runInventory(int a, int b, double c)
{
	// Creating a generic object for the inventory
	Inventory genericInventory(a, b, c);
	// Display results
	cout << "Item number: " << setw(4) << genericInventory.getItemNumber() << endl;
	cout << "Quantity   : " << setw(4) << genericInventory.getQuantity() << endl;
	cout << "Cost       : " << setprecision(2) << fixed << setw(7) << genericInventory.getCost() << endl;
	cout << "Total Cost : " << setprecision(2) << setw(7) << genericInventory.getTotalCost() << endl << endl;
}

