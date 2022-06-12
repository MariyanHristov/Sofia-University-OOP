#pragma once
#include "Shape.h"

class Circle : public Shape
{
private:
	double radius;

public:
	Circle();
	Circle(const Point a,const double radius);
	Circle(const Point a, const double radius, const char* stroke);


	const double getArea() const override;
	const double getPerimetre() const override;
	const double getRadius() const override;
	bool withinCircle(const Point cx, const double radius) override;
	bool withinRectangle(const Point a, const double width, const double height) override;
	bool pointIn(Point point) override;
	void writeToSVGFile(std::ofstream& fileSVG) override;
	void saveShapeInfoInFile(std::ofstream& file) override;

	Shape* clone() const override;
};