#include <iostream>
#include <cstring>

#include "person.h"

Person::Person()
{
	name = new char[1];
	name[0] = '/0';
	age = 0;
}

Person::Person(const char* name, int age)
{
	setName(name);
	setAge(age);
}

Person::Person(const Person& other)
{
	copyFrom(other);
}

Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Person::~Person()
{
	free();
}

const char* Person::getName() const
{
	return name;
}

const int Person::getAge() const
{
	return age;
}

void Person::setName(const char* name)
{
	delete[] name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Person::setAge(const int age)
{
	this->age = age;
}

void Person::copyFrom(const Person& other)
{
	delete[] name;
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
	
	this->age = other.age;
}

void Person::free()
{
	delete[] name;
}




