#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
private:
	double width;
	double height;

public:
	Rectangle();
	Rectangle(const Point a, const double width, const double height);
	Rectangle(const Point a, const double width, const double height, const char* stroke);

	const double getArea() const override;
	const double getPerimetre() const override;
	const double getWidth() const override;
	const double getHeight() const override;
	bool withinCircle(const Point cx, const double radius) override;
	bool withinRectangle(const Point a, const double width, const double height) override;
	bool pointIn(Point point) override;
	void writeToSVGFile(std::ofstream& fileSVG) override;
	void saveShapeInfoInFile(std::ofstream& file) override;

	Shape* clone() const override;
};
