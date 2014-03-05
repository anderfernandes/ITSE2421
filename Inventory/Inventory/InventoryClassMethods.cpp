#include "Inventory.h"

Inventory::Inventory() 
{
	itemNumber = 0;
	quantity = 0;
	cost = 0.0;
}

Inventory::Inventory(int iN = 0, int qt= 0, double co = 0.0)
{
	
	itemNumber = iN;
	quantity = qt;
	cost = co;
}

void Inventory::setItemNumber(int iN)
{
	if (iN >=0)
		itemNumber = iN;
	else
	{
		itemNumber = 1;
		cout << "Invalid item number. Using default value of 1\n";
	}
}

void Inventory::setQuantity(int qt)
{
	if (qt >=0)
		quantity = qt;
	else
	{
		quantity = 1;
		cout << "Invalid quantity. Using a default value of 1\n";
	}
}

void Inventory::setCost(double co)
{
	if (co >= 1.0)
		cost = co;
	else
	{
		cost = 1.0;
		cout << "Invalid value for cost. using a default value of 1.0\n";
	}
}

int Inventory::getItemNumber()
{
	return itemNumber;
}

int Inventory::getQuantity()
{
	return quantity;
}

double Inventory::getCost()
{
	return cost;
}

double Inventory::getTotalCost()
{
	return quantity * cost;
}