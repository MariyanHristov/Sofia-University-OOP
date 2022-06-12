#pragma once

#include "Animal.h"
#include "String.h"

class Penguin : public Animal
{
public:
	Penguin();
	Penguin(const String&);

	bool setFacts() override;
	Animal* clone() const override;
	void makeSound() override;
	void print() const override;
};