#include <iostream>
#include "FuelTank.h"

using namespace std;

void FuelTank::use(double toUse)
{
	
	if (toUse <= actualCapacity)
	{
		actualCapacity -= toUse;
	}
	else
	{
		cout << "Insufficent fuel!" << endl;
	}
}

void FuelTank::fill(double toFill)
{
	if (toFill + actualCapacity > totalCapacity)
	{
		actualCapacity = totalCapacity;
	}
	else
	{
		actualCapacity += toFill;
	}
}
