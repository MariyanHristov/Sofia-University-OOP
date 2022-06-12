#include <cstring>

#include "Line.h"
#include "Circle.h"
#pragma warning (disable : 4996)

using namespace std;

const int MAX_SIZE = 512;

Line::Line() : Shape(2)
{
}

Line::Line(const Point a, const Point b, const char* stroke) : Shape(2, stroke, "line")
{
	setPoint(0, a.x, a.y);
	setPoint(1, b.x, b.y);
}

bool Line::withinCircle(const Point cx, const double radius)
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

bool Line::withinRectangle(const Point a, const double width, const double height)
{
	double upperX = a.x + width;
	double lowerX = a.x;
	double upperY = a.y;
	double lowerY = a.y - width;

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

bool Line::pointIn(Point point)
{
	return false;
}

void Line::writeToSVGFile(std::ofstream& fileSVG)
{
	fileSVG << "<" << getName() << " x1=\"" << getPoint(0).x << "\" y1=\"" << getPoint(0).y << "\" x2=\""
		<< getPoint(1).x << "\" y2 =\"" << getPoint(1).y << "\" stroke=\"" << getStroke() << "\" />" << endl;
}

void Line::saveShapeInfoInFile(std::ofstream& file)
{
	file << getName() << " " << getPoint(0).x << " " << getPoint(0).y << " "
		<< getPoint(1).x << " " << getPoint(1).y << " " << getStroke() << endl;
}

Shape* Line::clone() const
{
	return new Line(*this);
}
