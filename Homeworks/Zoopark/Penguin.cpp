#include <iostream>
#include <fstream>
#include "Penguin.h"

const int BUFFER_SIZE = 1024;

Penguin::Penguin()
{
	weightType = LIGHT;
	consumerType = CARNIVORE;
	name = "";
	sound = "Piu Piu!";
	setFacts();
}

Penguin::Penguin(const String& name)
{
	weightType = LIGHT;
	consumerType = CARNIVORE;
	this->name = name;
	sound = "Piu Piu!";
	setFacts();
}

bool Penguin::setFacts()
{
	std::ifstream file("PenguinFacts.txt");
	if (!file.is_open())
	{
		return false;
	}

	char temp[BUFFER_SIZE];
	while (file.getline(temp, BUFFER_SIZE))
	{
		facts += temp;
		facts += "\n";
	}
	file.close();

	return true;
}

Animal* Penguin::clone() const
{
	return new Penguin(*this);
}

void Penguin::makeSound()
{
	std::cout << getSound();
}

void Penguin::print() const
{
	std::cout << "I'm a penguin called " << name << "! " << sound;
}