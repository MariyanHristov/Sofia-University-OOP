#include <iostream>
#include <fstream>

#include "Hippopotamus.h"

const int BUFFER_SIZE = 1024;

Hippopotamus::Hippopotamus()
{
	weightType = HEAVY;
	consumerType = HERBIVORE;
	name = "";
	sound = "Hrgh gh gh gh!";
	setFacts();
}

Hippopotamus::Hippopotamus(const String& name)
{
	weightType = HEAVY;
	consumerType = HERBIVORE;
	this->name = name;
	sound = "Hrgh gh gh gh!";
	setFacts();
}

bool Hippopotamus::setFacts()
{
	std::ifstream file("HippopotamusFacts.txt");
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

Animal* Hippopotamus::clone() const
{
	return new Hippopotamus(*this);
}

void Hippopotamus::makeSound()
{
	std::cout << getSound();
}

void Hippopotamus::print() const
{
	std::cout << "I'm a hippopotamus called " << name << "! " << sound;
}