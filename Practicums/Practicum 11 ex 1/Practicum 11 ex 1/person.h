#pragma once

class Person
{
private: 
	char* name;
	int age;

public:
	Person();
	Person(const char* name, int age);
	Person(const Person& other);
	Person& operator=(const Person& other);
	~Person();

	const char* getName() const;
	const int getAge() const;

	void setName(const char* name);
	void setAge(const int age);

private:
	void copyFrom(const Person& other);
	void free();
};