#pragma once

#include <iostream>
#include "CarPart.h"

class Engine : public CarPart
{
private:
	int horsePower;

public:
	friend std::ostream& operator<<(std::ostream&, const Engine& other);
};