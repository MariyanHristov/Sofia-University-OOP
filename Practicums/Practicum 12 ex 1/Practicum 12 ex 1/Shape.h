#pragma once



class Shape
{
protected:
	struct Point
	{
		int x;
		int y;
	};

	Point point;
	char* colour;
	int* length;
	int lengthsCount;
	int* angles;
	int anglesCount;
public:
	Shape();
	Shape(const Shape& other);
	Shape& operator=(const Shape& other);
	~Shape();

	virtual void setPoint(const int x, const int y) = 0;
	virtual void setColour(const char* colour) = 0;
	virtual void setLength(const int* length) = 0;
	virtual void setAngles(const int* angles) = 0;

	virtual void showFigureInfo() = 0;
	virtual void showParametres() = 0;
	virtual double calculateArea() = 0;

private:
	void copyFrom(const Shape& other);
	void free();

};