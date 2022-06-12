#pragma once
#include "Animal.h"
#include "String.h"

class Zoopark
{
private:
	String name;
	Array<Animal*> animals;
	Array<String*> log;

public:
	Zoopark();

	void clean();
	bool feed();
	bool addAnimal();
	void menu();
	void printCommands() const;
	bool printFacts() const;
	bool removeAnimal();
	void printAll();
private:
	void addTurtle();
	void addPenguin();
	void addHippopotamus();
};