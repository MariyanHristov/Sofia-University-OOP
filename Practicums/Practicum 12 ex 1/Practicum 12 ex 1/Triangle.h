#pragma once
#include "Shape.h"

class Triangle : public Shape
{
public:

	void setPoint(const int x, const int y) override;
	void setColour(const char* colour) override;
	void setLength(const int* length) override;
	void setAngles(const int* angles) override;

	void showFigureInfo() override;
	void showParametres() override;
	double calculateArea() override;

	void setAnglesAndLengthsCount();
	void resizeAnglesAndLengths();
};