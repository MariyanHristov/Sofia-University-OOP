#pragma once

class Customer
{
private:
	int id;
	char* name;
	char* address;

public:
	Customer();
	Customer(const int id, const char* name, const char* address);
	Customer(const Customer& other);
	Customer& operator=(const Customer& other);
	~Customer();

	const int getId() const;
	const char* getName() const;
	const char* getAddress() const;

private:
	void copyFrom(const Customer& other);
	void free();
};