#include <iostream>
#include <fstream>
#include <cstring>

#include "SVG.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"

#pragma warning (disable : 4996)
using namespace std;

const int MAX_SIZE = 512;

SVG::SVG()
{
	count = 0;
	capacity = 2;
	shapes = new Shape * [capacity];
}

SVG::SVG(const SVG& other)
{
	copyFrom(other);
}

SVG& SVG::operator=(const SVG& other)
{
	if (this != &other)
	{
		copyFrom(other);
		free();
	}
	return *this;
}

SVG::~SVG()
{
	free();
}

void SVG::print() const
{
	ifstream readFile("figuresInfo.txt");
	if (!readFile)
	{
		cout << "File could not be opened! " << endl;
	}

	char readLine[MAX_SIZE];
	int index = 1;
	while (readFile.good())
	{
		readFile.getline(readLine, MAX_SIZE);
		if (strcmp(readLine, "") == 0)
		{
			break;
		}
		cout << index << ". " << readLine << endl;
		index++;
	}
	readFile.close();
}

void SVG::create()
{
	char temp[MAX_SIZE];
	cout << "What figure do you want to add: ";
	cin >> temp;

	if (strcmp(temp, "rectangle") == 0)
	{
		addRectangle();
	}
	else if (strcmp(temp, "circle") == 0)
	{
		addCircle();
	}
	else if (strcmp(temp, "line") == 0)
	{
		addLine();
	}
}

void SVG::erase()
{
	int index;

	Shape** temp = new Shape * [capacity];

	for (;;)
	{
		cout << "Which shape do you want to erase (insert ID): "; cin >> index;
		if (index > count)
		{
			cout << "Shape with this index doesn't exist. " << endl;
		}
		else
		{
			break;
		}
	}

	index--;
	count--;
	for (size_t i = 0; i < count; i++)
	{
		if (i < index)
		{
			temp[i] = shapes[i];
		}
		else
		{
			temp[i] = shapes[i + 1];
		}
	}

	delete[]shapes;

	shapes = temp;
}

void SVG::translate()
{
	int id;
	for (;;)
	{
		cout << "Which shape do you want to translate (insert ID) (insert 0 if you want to translate all shapes): ";
		cin >> id;
		if (id > count)
		{
			cout << "Shape with this index doesn't exist. " << endl;
		}
		else
		{
			break;
		}
	}

	double moveX, moveY;
	cout << "Move x with (insert value): "; cin >> moveX;
	cout << "Move y with (insert value): "; cin >> moveY;

	if (id == 0)
	{
		for (size_t i = 0; i < count; i++)
		{
			for (size_t j = 0; j < shapes[i]->getPointsCount(); j++)
			{
				shapes[i]->setPoint(j, moveX + shapes[i]->getPoint(j).x, moveY + shapes[i]->getPoint(j).y);
			}
		}
	}
	else
	{
		for (size_t i = 0; i < shapes[id - 1]->getPointsCount(); i++)
		{
			shapes[id - 1]->setPoint(i, moveX + shapes[id - 1]->getPoint(i).x, moveY + shapes[id - 1]->getPoint(i).y);
		}
	}

	cout << "Translation was successful!" << endl;
}

void SVG::within() const
{
	char temp[MAX_SIZE];
	cout << "Within circle or rectangle? : "; cin >> temp;

	if (strcmp(temp, "circle") == 0)
	{
		Shape::Point a;
		double radius;
		cout << "cx = "; cin >> a.x;
		cout << "cy = "; cin >> a.y;
		cout << "radius = "; cin >> radius;
		for (int i = 0; i < count; i++)
		{
			if (shapes[i]->withinCircle(a, radius))
			{
				cout << i + 1 << ". " << shapes[i]->getName() << endl;
			}
		}
	}
	else if (strcmp(temp, "rectangle") == 0)
	{

		Shape::Point a;
		double width, height;
		cout << "x = "; cin >> a.x;
		cout << "y = "; cin >> a.y;
		cout << "width = "; cin >> width;
		cout << "height = "; cin >> height;
		Rectangle rectangle(a, width, height);

		for (int i = 0; i < count; i++)
		{
			if (shapes[i]->withinRectangle(a, width, height))
			{
				cout << i + 1 << ". " << shapes[i]->getName() << endl;
			}
		}
	}
}

void SVG::pointIn() const
{
	Shape::Point a;
	cout << "x = "; cin >> a.x;
	cout << "y = "; cin >> a.y;

	for (int i = 0; i < count; i++)
	{
		if (shapes[i]->pointIn(a))
		{
			cout << i + 1 << ". " << shapes[i]->getName() << endl;
		}
	}
}

void SVG::areas() const
{
	for (size_t i = 0; i < count; i++)
	{
		cout << i + 1 << "." << shapes[i]->getName() << " " << shapes[i]->getArea() << endl;
	}
}

void SVG::perimetres() const
{
	for (size_t i = 0; i < count; i++)
	{
		cout << i + 1 << "." << shapes[i]->getName() << " " << shapes[i]->getPerimetre() << endl;
	}
}

void SVG::addRectangle()
{
	Shape::Point a;
	double  width, height;
	char stroke[MAX_SIZE];

	cout << "x = "; cin >> a.x;
	cout << "y = "; cin >> a.y;
	cout << "width = "; cin >> width;
	cout << "height = "; cin >> height;
	cout << "stroke = "; cin >> stroke;

	if (count >= capacity)
	{
		resize();
	}
	shapes[count++] = new Rectangle(a, width, height, stroke);

	cout << "Rectangle successfully added!" << endl;
}

void SVG::addCircle()
{
	Shape::Point a;
	double  radius;
	char stroke[MAX_SIZE];

	cout << "cx = "; cin >> a.x;
	cout << "cy = "; cin >> a.y;
	cout << "radius = "; cin >> radius;
	cout << "stroke = "; cin >> stroke;

	if (count >= capacity)
	{
		resize();
	}
	shapes[count++] = new Circle(a, radius, stroke);

	cout << "Circle successfully added!" << endl;
}

void SVG::addLine()
{
	Shape::Point a;
	Shape::Point b;
	char stroke[MAX_SIZE];

	cout << "x1 = "; cin >> a.x;
	cout << "y1 = "; cin >> a.y;
	cout << "x2 = "; cin >> b.x;
	cout << "y2 = "; cin >> b.y;
	cout << "stroke = "; cin >> stroke;

	if (count >= capacity)
	{
		resize();
	}
	shapes[count++] = new Line(a, b, stroke);

	cout << "Line successfully added!" << endl;
}

void SVG::getShapesDataFromFile()
{
	ifstream file("figuresInfo.txt");
	Shape::Point a, b;
	char name[MAX_SIZE], stroke[MAX_SIZE];
	double width, height, radius;

	while (file.good())
	{
		file >> name;
		if (strcmp(name, "rect") == 0)
		{
			file >> a.x >> a.y >> width >> height >> stroke;
			if (count >= capacity)
			{
				resize();
			}
			shapes[count++] = new Rectangle(a, width, height, stroke);
		}
		else if (strcmp(name, "circle") == 0)
		{
			file >> a.x >> a.y >> radius >> stroke;
			if (count >= capacity)
			{
				resize();
			}
			shapes[count++] = new Circle(a, radius, stroke);
		}
		else if (strcmp(name, "line") == 0)
		{
			file >> a.x >> a.y >> b.x >> b.y >> stroke;
			if (count >= capacity)
			{
				resize();
			}
			shapes[count++] = new Line(a, b, stroke);
		}
	}
	file.close();

	cout << "Shapes successfully loaded from file!" << endl;
}

void SVG::saveFiles() const
{
	ofstream fileSVG("figures.svg");
	fileSVG << "<?xml version = \"1.0\" standalone = \"no\"?>" << endl;
	fileSVG << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"" << endl;
	fileSVG << "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">" << endl;
	fileSVG << "<svg>" << endl;

	for (int i = 0; i < count; i++)
	{
		shapes[i]->writeToSVGFile(fileSVG);
	}

	fileSVG << "</svg>" << endl;
	fileSVG.close();

	ofstream file("figuresInfo.txt");
	for (int i = 0; i < count; i++)
	{
		shapes[i]->saveShapeInfoInFile(file);
	}
	file.close();

	cout << "Files successfully saved!" << endl;
}

void SVG::copyFrom(const SVG& other)
{
	shapes = new Shape * [other.capacity];
	for (size_t i = 0; i < other.count; i++)
	{
		shapes[i] = other.shapes[i]->clone();
	}

	count = other.count;
	capacity = other.capacity;
}

void SVG::free()
{
	for (size_t i = 0; i < count; i++)
	{
		delete shapes[i];
	}
	delete[] shapes;
}

void SVG::resize()
{
	Shape** temp = new Shape * [capacity *= 2];
	for (size_t i = 0; i < count; i++)
	{
		temp[i] = shapes[i];
	}

	delete[] shapes;

	shapes = temp;
}

