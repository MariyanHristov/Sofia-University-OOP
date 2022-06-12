#include <cstring>

#include "Rectangle.h"
#include "Circle.h"

#pragma warning (disable : 4996)

using namespace std;

const int MAX_SIZE = 512;

Rectangle::Rectangle() : Shape(4), width(0), height(0)
{
}

Rectangle::Rectangle(const Point a, const double width, const double height)
	: Shape(4, "rect"), width(width), height(height)
{
	setPoint(0, a.x, a.y);
	setPoint(1, a.x + width, a.y);
	setPoint(2, a.x + width, a.y - height);
	setPoint(3, a.x, a.y - height);
}

Rectangle::Rectangle(const Point a, const double width, const double height, const char* stroke)
	: Shape(4, stroke, "rect"), width(width), height(height)
{
	setPoint(0, a.x, a.y);
	setPoint(1, a.x + width, a.y);
	setPoint(2, a.x + width, a.y - height);
	setPoint(3, a.x, a.y - height);
}

const double Rectangle::getArea() const
{
	return width * height;
}

const double Rectangle::getPerimetre() const
{
	return 2 * (width + height);
}

const double Rectangle::getWidth() const
{
	return width;
}

const double Rectangle::getHeight() const
{
	return height;
}

bool Rectangle::withinCircle(const Point cx, const double radius)
{
	bool isIn = true;
	for (int i = 0; i < getPointsCount(); i++)
	{
		if (getDistanceBetween(getPoint(i), cx) > radius)
		{
			isIn = false;
			break;
		}
	}

	return isIn;
}

bool Rectangle::withinRectangle(const Point a, const double width, const double height)
{
	double upperX = a.x + width;
	double lowerX = a.x;
	double upperY = a.y;
	double lowerY = a.y - height;

	bool isIn = true;
	for (size_t i = 0; i < getPointsCount(); i++)
	{
		if (!(getPoint(i).x > lowerX && getPoint(i).x < upperX
			&& getPoint(i).y > lowerX && getPoint(i).y < lowerY))
		{
			isIn = false;
			break;
		}
	}
	return isIn;
}

bool Rectangle::pointIn(Point point)
{
	double upperX = getPoint(0).x + width;
	double lowerX = getPoint(0).x;
	double upperY = getPoint(0).y;
	double lowerY = getPoint(0).y - height;

	return (point.x > lowerX && point.x < upperX
		&& point.y > lowerY && point.y < upperY);
}

void Rectangle::writeToSVGFile(std::ofstream& fileSVG)
{
	fileSVG << "<" << getName() << " x=\"" << getPoint(0).x <<
		"\" y=\"" << getPoint(0).y << "\" width=\"" << getWidth() <<
		"\" height=\"" << getHeight() << "\" stroke=\"" << getStroke() <<
		"\" />" << endl;
}

void Rectangle::saveShapeInfoInFile(std::ofstream& file)
{
	file << getName() << " " << getPoint(0).x << " " << getPoint(0).y << " "
		<< getWidth() << " " << getHeight() << " " << getStroke() << endl;
}

Shape* Rectangle::clone() const
{
	return new Rectangle(*this);
}

