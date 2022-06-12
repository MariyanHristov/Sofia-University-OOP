#include <iostream>
#include "Zoopark.h"
#include "Turtle.h"
#include "Penguin.h"
#include "Hippopotamus.h"

const int BUFFER_SIZE = 1024;

Zoopark::Zoopark()
{
	std::cout << "What is the name of the zoopark? ";
	char* nameT = new char[BUFFER_SIZE];
	std::cin.getline(nameT, BUFFER_SIZE);
	name = nameT;
	delete[] nameT;
	//test
}

void Zoopark::clean()
{
	bool dirtyCages = false;
	for (size_t i = 0; i < animals.getSize(); i++)
	{
		if (!animals[i]->isClean())
		{
			dirtyCages = true;
			std::cout << animals[i]->getName() << "'s cage was successfully cleaned!" << std::endl;
			animals[i]->isClean(true);
		}
	}
	if (!dirtyCages)
	{
		std::cout << "Everything is already clean!";
	}
}

bool Zoopark::feed()
{
	bool found = false;
	std::cout << "Which animal do you want to feed? ";
	String input; std::cin >> input;
	for (size_t i = 0; i < animals.getSize(); i++)
	{
		if (animals[i]->getName() == input.getStr())
		{
			if (animals[i]->isClean())
			{
				std::cout << animals[i]->getName() << " was successfully fed with "
					<< animals[i]->getFoodQuantity() << " kg of " << animals[i]->getFoodType() << "!" << std::endl;
				animals[i]->isClean(false);
			}
			else
			{
				std::cout << "You can't feed " << animals[i]->getName() << " before cleaning its cage!" << std::endl;
			}
			found = true;
			break;
		}
	}
	return found;
}

bool Zoopark::addAnimal()
{
	std::cout << "What animal do you want to add? ";
	String input;  std::cin >> input;

	if (input == "turtle")
	{
		addTurtle();
	}
	else if (input == "penguin") {
		addPenguin();
	}
	else if (input == "hippopotamus") {
		addHippopotamus();
	}
	else {
		return false;
	}
	return true;
}

void Zoopark::addTurtle()
{
	std::cout << "How do you want to call your turtle? ";
	String name; std::cin >> name;
	Animal* animal = new Turtle(name);
	animals.pushBack(animal->clone());
	std::cout << "The animal was successfully added!" << std::endl;
}

void Zoopark::addPenguin()
{
	std::cout << "How do you want to call your penguin? ";
	String name; std::cin >> name;
	Animal* animal = new Penguin(name);
	animals.pushBack(animal->clone());
	std::cout << "The animal was successfully added!" << std::endl;
}


void Zoopark::addHippopotamus()
{
	std::cout << "How do you want to call your hippopotamus? ";
	String name; std::cin >> name;
	Animal* animal = new Hippopotamus(name);
	animals.pushBack(animal->clone());
	std::cout << "The animal was successfully added!" << std::endl;
}


void Zoopark::menu()
{
	printCommands();
	while (true) {
		std::cout << "> ";
		String cmd;
		std::cin >> cmd;
		if (cmd == "cmd") {
			printCommands();
			std::cout << std::endl;
		}
		else if (cmd == "clean") {
			clean();
			std::cout << std::endl;
		}
		else if (cmd == "feed") {
			if (!feed())
				std::cout << "Could not find that animal!";
			std::cout << std::endl;
		}
		else if (cmd == "add")
		{
			if (!addAnimal())
				std::cout << "That animal is not supported!";
			std::cout << std::endl;
		}
		else if (cmd == "remove")
		{
			if (!removeAnimal())
				std::cout << "Could not find that animal!";
			std::cout << std::endl;
		}
		else if (cmd == "printFacts")
		{
			if (!printFacts())
				std::cout << "Could not find that animal!";
			std::cout << std::endl;
		}
		else if (cmd == "printAll") {
			printAll();
			std::cout << std::endl;
		}
		else if (cmd == "exit") {
			break;
		}
		else {
			std::cout << "Could not find that command!" << std::endl;
		}
	}
}

void Zoopark::printCommands() const
{
	std::cout << "\tcmd - lists all commands" << std::endl;
	std::cout << "\tclean - cleans all cages if dirty" << std::endl;
	std::cout << "\tfeed - feeds a certain animal" << std::endl;
	std::cout << "\tadd - adds a new animal" << std::endl;
	std::cout << "\tremove - removes an animal" << std::endl;
	std::cout << "\tprintFacts - prints facts about a certain animal's species" << std::endl;
	std::cout << "\tprintAll - prints all animals in the zoo" << std::endl;
}

bool Zoopark::printFacts() const
{
	bool found = false;
	std::cout << "Which animal do you want to get facts for? ";
	String input; std::cin >> input;

	for (unsigned int i = 0; i < animals.getSize(); i++)
	{
		if (animals[i]->getName() == input.getStr())
		{
			std::cout << animals[i]->getFacts();
			std::cout << std::endl;
			found = true;
			break;
		}
	}
	return found;
}

bool Zoopark::removeAnimal()
{
	bool found = false;

	std::cout << "What animal do you want to remove? ";
	String input;  std::cin >> input;

	for (unsigned int i = 0; i < animals.getSize(); i++)
	{
		if (animals[i]->getName() == input.getStr())
		{
			animals.popAt(i);
			found = true;
			std::cout << "The animal was successfully removed!" << std::endl;
			break;
		}
	}
	return found;
}

void Zoopark::printAll()
{
	for (unsigned int i = 0; i < animals.getSize(); i++) {
		std::cout << "\t" << i + 1 << ".";
		animals[i]->print();
		std::cout << std::endl;
	}
}