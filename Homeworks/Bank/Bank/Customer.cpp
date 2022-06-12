#include "Customer.h"
#include <cstring>
#pragma warning(disable : 4996)

Customer::Customer()
{
	id = 0;
	name = new char[1];
	name[0] = '\0';
	address = new char[1];
	address[0] = '\0';
}

Customer::Customer(const int id, const char* name, const char* address)
{
	this->id = id;

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	this->address = new char[strlen(address) + 1];
	strcpy(this->address, address);
}

Customer::Customer(const Customer& other)
{
	copyFrom(other);
}

Customer& Customer::operator=(const Customer& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Customer::~Customer()
{
	free();
}

const int Customer::getId() const
{
	return id;
}

const char* Customer::getName() const
{
	return name;
}

const char* Customer::getAddress() const
{
	return address;
}

void Customer::copyFrom(const Customer& other)
{
	id = other.id;

	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	address = new char[strlen(other.address) + 1];
	strcpy(address, other.address);
}

void Customer::free()
{
	delete[] name;
	delete[] address;
}
