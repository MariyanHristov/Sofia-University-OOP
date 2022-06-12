#pragma once
#include <fstream>

class Shape
{
public:
	struct Point
	{
		double x;
		double y;

		Point() :x(0), y(0) {}
		Point(double x, double y) :x(x), y(y) {}
	};
private:
	char* name;
	Point* points;
	size_t pointsCount;
	char* stroke;

public:
	Shape();
	Shape(size_t size);
	Shape(size_t size, const char* name);
	Shape(size_t size, const  char* stroke, const char* name);
	Shape(const Shape& other);
	Shape& operator=(const Shape& other);
	virtual ~Shape();

	const char* getName() const;
	const Point getPoint(size_t index) const;
	const size_t getPointsCount() const;
	const char* getStroke() const;

	void setPoint(size_t index, const double x, const double y);
	const double getDistanceBetween(Point a, Point b);

	virtual const double getArea() const;
	virtual const double getPerimetre() const;
	virtual const double getWidth() const;
	virtual const double getHeight() const;
	virtual const double getRadius() const;
	
	virtual bool withinCircle(const Point point, const double radius) = 0;
	virtual bool withinRectangle(const Point a, const double width, const double height) = 0;
	virtual bool pointIn(Point point) = 0;
	virtual void writeToSVGFile(std::ofstream& fileSVG) = 0;
	virtual void saveShapeInfoInFile(std::ofstream& file) = 0;

	virtual Shape* clone() const = 0;

private:
	void copyFrom(const Shape& other);
	void free();
};
