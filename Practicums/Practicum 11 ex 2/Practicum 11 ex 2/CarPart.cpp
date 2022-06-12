#include "CarPart.h"
#include <cstring>

CarPart::CarPart()
{
	id = 0;
	manufacturer = new char[1];
	manufacturer[0] = '\0';
	description = new char[1];
	description[0] = '\0';
}

CarPart::CarPart(const CarPart& other)
{
	copyFrom(other);
}

CarPart& CarPart::operator=(const CarPart& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

CarPart::~CarPart()
{
	free();
}

void CarPart::copyFrom(const CarPart& other)
{
	id = other.id;
	
	delete[] manufacturer;
	manufacturer = new char[strlen(other.manufacturer) + 1];
	strcpy(manufacturer, other.manufacturer);

	delete[] description;
	description = new char[strlen(other.description) + 1];
	strcpy(description, other.description);
}

void CarPart::free()
{
	delete[] manufacturer;
	delete[] description;
	id = 0;
}

