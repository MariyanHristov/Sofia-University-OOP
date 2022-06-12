#pragma once

#include <iostream>
#include "CarPart.h"

class Tire : public CarPart
{
private:
	int width;
	int profile;
	int diametre;

public:
	friend std::ostream& operator<<(std::ostream& stream, const Tire& other);
};