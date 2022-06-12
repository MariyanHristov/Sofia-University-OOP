#include "Triangle.h"
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

void Triangle::showFigureInfo()
{
	cout << "~Traingle~ " << endl;
	cout << "Point : x = " << point.x << " y = " << point.y << endl;
	cout << "Colour : " << colour << endl;
	cout << "Lengths: ";
	for (int i = 0; i < lengthsCount; i++)
	{
		cout << length[i] << " ";
	}
	cout << endl << "Angles: ";
	for (int i = 0; i < anglesCount; i++)
	{
		cout << angles[i] << " ";
	}
	cout << endl;
}

void Triangle::showParametres()
{
	
}

double Triangle::calculateArea()
{
	return  1 / 2 * (double)length[0] * (double)length[1] * sin(angles[0]);
}

void Triangle::setAnglesAndLengthsCount()
{
	lengthsCount = 3;
	anglesCount = 3;
}

void Triangle::resizeAnglesAndLengths()
{
	setAnglesAndLengthsCount();

	delete[]length;
	length = new int[lengthsCount];

	delete[]angles;
	angles = new int[anglesCount];
}
