#include "Shape.h"
#include <cstring>

Shape::Shape()
{
	point.x = 0;
	point.y = 0;
	colour = new char[1];
	colour[0] = '\0';
	length = new int[1];
	length[0] = 0;
	lengthsCount = 1;
	angles = new int[1];
	angles[0] = 0;
	anglesCount = 1;
}

Shape::Shape(const Shape& other)
{
	copyFrom(other);
}

Shape& Shape::operator=(const Shape& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Shape::~Shape()
{
	free();
}

const Point& Shape::getPoint() const
{
	return point;
}

const char* Shape::getColour() const
{
	return colour;
}

const int* Shape::getLength() const
{
	return length;
}

void Shape::copyFrom(const Shape& other)
{
	point = other.point;

	delete[] colour;
	colour = new char[strlen(other.colour) + 1];
	strcpy(colour, other.colour);

	delete[] length;
	length = new int[other.lengthsCount];
	for (int i = 0; i < other.lengthsCount; i++)
	{
		length[i] = other.length[i];
	}

	delete[] angles;
	angles = new int[other.anglesCount];
	for (int i = 0; i < other.anglesCount; i++)
	{
		angles[i] = other.angles[i];
	}
}

void Shape::free()
{
	delete[] colour;
	delete[] length;
}
