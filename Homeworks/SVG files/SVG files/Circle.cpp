#include <cstring>

#include "Circle.h"

#pragma warning (disable : 4996)

using namespace std;

const int MAX_SIZE = 512;
const double PI = 3.14159265359;

Circle::Circle() : Shape(), radius(0)
{
}

Circle::Circle(const Point a, const double radius) : Shape(1, "circle"), radius(radius)
{
	setPoint(0, a.x, a.y);
}

Circle::Circle(const Point a, const double radius, const char* stroke)
	: Shape(1, stroke, "circle"), radius(radius)
{
	setPoint(0, a.x, a.y);
}

const double Circle::getArea() const
{
	return PI * radius * radius;
}

const double Circle::getPerimetre() const
{
	return 2 * PI * radius;
}

const double Circle::getRadius() const
{
	return radius;
}

bool Circle::withinCircle(const Point cx, const double radius)
{
	return getDistanceBetween(getPoint(0), cx) + this->radius < radius;
}

bool Circle::withinRectangle(const Point a, const double width, const double height)
{
	Point cornerPoints[4];
	cornerPoints[0] = Point(getPoint(0).x, getPoint(0).y + radius);
	cornerPoints[1] = Point(getPoint(0).x, getPoint(0).y - radius);
	cornerPoints[2] = Point(getPoint(0).x + radius, getPoint(0).y);
	cornerPoints[3] = Point(getPoint(0).x - radius, getPoint(0).y);

	double upperX = a.x + width;
	double lowerX = a.x;
	double upperY = a.y;
	double lowerY = a.y - width;

	bool isIn = true;
	for (size_t i = 0; i < getPointsCount(); i++)
	{
		if (!(cornerPoints[i].x > lowerX && cornerPoints[i].x < upperX 
			&& cornerPoints[i].y > lowerX && cornerPoints[i].y < upperY))
		{
			isIn = false;
			break;
		}
	}
	return isIn;
}

bool Circle::pointIn(Point point)
{
	return getDistanceBetween(getPoint(0), point) < radius;
}

void Circle::writeToSVGFile(std::ofstream& fileSVG)
{
	fileSVG << "<" << getName() << " cx=\"" << getPoint(0).x <<	"\" cy=\"" << getPoint(0).y 
		<< "\" r=\"" << getRadius() 	<< "\" stroke=\"" << getStroke() << "\" />" << endl;
}

void Circle::saveShapeInfoInFile(std::ofstream& file)
{
	file << getName() << " " << getPoint(0).x << " " << getPoint(0).y << " " << getRadius() << " " << getStroke() << endl;
}

Shape* Circle::clone() const
{
	return new Circle(*this);
}