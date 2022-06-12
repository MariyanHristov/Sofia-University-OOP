#pragma once

#include <iostream>
#include "CarPart.h"

class Accumulator : public CarPart 
{
private:
	int amperHours;
	char* batteryId;

public:
	Accumulator();
	Accumulator(const Accumulator& other);
	Accumulator& operator=(const Accumulator& other);
	~Accumulator();
	friend std::ostream& operator<<(std::ostream stream, const Accumulator& other);

private:
	void copyFrom(const Accumulator& other);
	void free();
};


