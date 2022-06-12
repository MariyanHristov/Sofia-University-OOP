#include <cstring>
#include <cmath>

#include "Shape.h"

#pragma warning (disable : 4996)

using namespace std;

Shape::Shape()
{
	name = new char[1];
	stroke[0] = '\0';
	pointsCount = 1;
	points = new Point[pointsCount];
	stroke = new char[1];
	stroke[0] = '\0';
}

Shape::Shape(size_t size) 
{
	name = new char[1];
	name[0] = '\0';
	pointsCount = size;
	points = new Point[pointsCount];
	stroke = new char[1];
	stroke[0] = '\0';
}

Shape::Shape(size_t size, const char* name) 
{
	pointsCount = size;
	points = new Point[pointsCount];

	stroke = new char[1];
	stroke[0] = '\0';

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Shape::Shape(size_t size, const char* stroke, const char* name)
{
	pointsCount = size;
	points = new Point[pointsCount];

	this->stroke = new char[strlen(stroke) + 1];
	strcpy(this->stroke, stroke);

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
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

const char* Shape::getName() const
{
	return name;
}

const Shape::Point Shape::getPoint(size_t index) const
{
	return points[index];
}

const char* Shape::getStroke() const
{
	return stroke;
}

const size_t Shape::getPointsCount() const
{
	return pointsCount;
}

void Shape::setPoint(size_t index, const double x, const double y)
{
	points[index] = Point(x, y);
}

const double Shape::getDistanceBetween(Point a, Point b)
{
	return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

const double Shape::getArea() const
{
	return 0.0;
}

const double Shape::getPerimetre() const
{
	return 0.0;
}

const double Shape::getWidth() const
{
	return 0.0;
}

const double Shape::getHeight() const
{
	return 0.0;
}

const double Shape::getRadius() const
{
	return 0.0;
}

void Shape::copyFrom(const Shape& other)
{
	points = new Point[other.pointsCount];
	points = other.points;

	stroke = new char[strlen(other.stroke) + 1];
	strcpy(stroke, other.stroke);

	name = new char[strlen(other.name) + 1];
	strcpy(stroke, other.name);
}

void Shape::free()
{
	delete[] points;
	delete[] stroke;
	delete[] name;
}
