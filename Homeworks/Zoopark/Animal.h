#pragma once
#include "String.h"
#include "Array.h"

class Animal
{
protected:

	enum Weight
	{
		LIGHT, MEDIUM, HEAVY
	}weightType;

	enum Consumer
	{
		HERBIVORE, CARNIVORE, OMNIVORE
	}consumerType;

	String name;
	String sound;
	String facts;
	bool clean;

public:

	Animal::Weight getWeight() const;
	Animal::Consumer getConsumer() const;
	String getName() const;
	String getSound() const;
	String getFacts() const;
	String getFoodType() const;
	bool isClean() const;
	double getFoodQuantity() const;

	void isClean(const bool);

	virtual bool setFacts() = 0;
	virtual Animal* clone() const = 0;
	virtual void makeSound() = 0;
	virtual void print() const = 0;
};