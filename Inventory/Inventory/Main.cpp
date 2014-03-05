#include "Inventory.h"

int main()
{
	Inventory inventoryA;

	cout << "Demonstrating the overloaded constructor...\n";
	cout << "Item number: " << inventoryA.getItemNumber() << endl;
	cout << "Quantity   : " << inventoryA.getQuantity() << endl;
	cout << "Cost       : " << setprecision(2) << fixed << inventoryA.getCost() << endl;
	cout << "Total Cost : " << setprecision(2) << inventoryA.getTotalCost() << endl << endl;

	Inventory inventoryB(124, 12, 84.95);

	cout << "Demonstrating the default constructor...\n";
	cout << "Item number: " << setw(4) << inventoryB.getItemNumber() << endl;
	cout << "Quantity   : " << setw(4) << inventoryB.getQuantity() << endl;
	cout << "Cost       : " << setprecision(2) << setw(7) << inventoryB.getCost() << endl;
	cout << "Total Cost : " << setprecision(2) << setw(7) << inventoryB.getTotalCost() << endl << endl;

	Inventory inventoryC;
	inventoryC.setItemNumber(243);
	inventoryC.setQuantity(50);
	inventoryC.setCost(9.5);

	cout << "Demonstrating the set functions...\n";
	cout << "Item number: " << setw(3) << inventoryC.getItemNumber() << endl;
	cout << "Quantity   : " << setw(3) << inventoryC.getQuantity() << endl;
	cout << "Cost       : " << setprecision(2) << setw(6) << inventoryC.getCost() << setw(4) << endl;
	cout << "Total Cost : " << setprecision(2) << setw(6) << inventoryC.getTotalCost() << endl;

	return 0;
}

void validateInput(double)
{

}