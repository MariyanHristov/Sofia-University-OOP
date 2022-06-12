#pragma once

class FuelTank
{
private:
	double totalCapacity;
	double actualCapacity;

public:
	void use(double toUse);
	void fill(double toFill);
};