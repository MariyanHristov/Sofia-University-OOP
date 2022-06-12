#pragma once

#include "Animal.h"
#include "String.h"

class Turtle : public Animal
{
public:
	Turtle();
	Turtle(String);

	bool setFacts() override;
	Animal* clone() const  override;
	void makeSound() override;
	void print() const override;
};