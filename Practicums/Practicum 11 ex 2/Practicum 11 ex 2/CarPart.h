#pragma once

class CarPart
{
protected:
	char* id;
	char* manufacturer;
	char* description;

public:
	CarPart();
	CarPart(const CarPart& other);
	CarPart& operator=(const CarPart& other);
	~CarPart();

private:
	void copyFrom(const CarPart& other);
	void free();
};
