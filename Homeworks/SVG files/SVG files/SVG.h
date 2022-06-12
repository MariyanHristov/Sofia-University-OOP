#pragma once
#include "Shape.h"

class SVG
{
private:
	Shape** shapes;
	size_t count;
	size_t capacity;

public:
	SVG();
	SVG(const SVG& other);
	SVG& operator=(const SVG& other);
	~SVG();

	void print() const;
	void create();
	void erase();
	void translate();
	void within() const;
	void pointIn() const;
	void areas() const;
	void perimetres() const;

	void addRectangle();
	void addCircle();
	void addLine();
	void getShapesDataFromFile();
	void saveFiles() const;

private:
	void copyFrom(const SVG& other);
	void free();
	void resize();
};