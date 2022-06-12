#pragma once
#include "Shape.h"

class Line : public Shape
{
public:
	Line();
	Line(const Point a, const Point b, const char* stroke);

	bool withinCircle(const Point cx, const double radius) override;
	bool withinRectangle(const Point a, const double width, const double height) override;
	bool pointIn(Point point) override;
	void writeToSVGFile(std::ofstream& file) override;
	void saveShapeInfoInFile(std::ofstream& file) override;

	Shape* clone() const override;
};