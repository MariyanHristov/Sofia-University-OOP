#include <iostream>
#include "Accumulator.h"
#include "CarPart.h"

std::ostream& operator<<(std::ostream stream, const Accumulator& other)
{
	stream << other.id << " by " << other.manufacturer << " - "
		<< other.description << " - " << other.amperHours << "Ah" << std::endl;

	return stream;
}

Accumulator::Accumulator()
{
	amperHours = 0;
	batteryId = new char[1];
	batteryId[0] = '\0';
}

Accumulator::Accumulator(const Accumulator& other) : CarPart(other)
{
	copyFrom(other);
}

Accumulator& Accumulator::operator=(const Accumulator& other) 
{
	if (this != &other)
	{
		CarPart::operator=(other);
		free();
		copyFrom(other);
	}

	return *this;
}

Accumulator::~Accumulator()
{
	free();
}

void Accumulator::copyFrom(const Accumulator& other)
{
	amperHours = other.amperHours;
	
	delete[] batteryId;
	batteryId = new char[strlen(other.batteryId) + 1];
	strcpy(batteryId, other.batteryId);
}

void Accumulator::free()
{
	delete[] batteryId;
	amperHours = 0;
}
