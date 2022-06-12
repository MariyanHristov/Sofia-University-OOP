#pragma once

#include "Animal.h"
#include "String.h"

class Hippopotamus : public Animal
{
public:
	Hippopotamus();
	Hippopotamus(const String&);

	bool setFacts() override;
	Animal* clone() const override;
	void makeSound() override;
	void print() const override;
};