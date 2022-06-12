#include "Account.h"
#include <cstring>
#include<iostream>

#pragma warning(disable : 4996)
using namespace std;

Account::Account()
{
	username = new char[1];
	username[0] = '\0';
	password = new char[1];
	password[0] = '\0';
	iban = new char[1];
	iban[0] = '\0';
	id = 0;
	balance = 0;

	setDateFormat();
}

void Account::setDateFormat()
{
	time_t t = time(0);
	tm* now = localtime(&t);
	dateOfCreation = new char[digitsCount(now->tm_mday) +
		digitsCount(now->tm_mon + 1) + digitsCount(now->tm_year + 1900) + 3];
	strcpy(dateOfCreation, numberToString(now->tm_mday));
	strcat(dateOfCreation, ".");
	strcat(dateOfCreation, numberToString(now->tm_mon + 1));
	strcat(dateOfCreation, ".");
	strcat(dateOfCreation, numberToString(now->tm_year + 1900));
}

Account::Account(const int id, const char* username, const char* password)
{
	this->username = new char[strlen(username) + 1];
	strcpy(this->username, username);

	this->password = new char[strlen(password) + 1];
	strcpy(this->password, password);

	iban = new char[digitsCount(id+1) + 3];
	strcpy(iban, "BG");
	strcat(iban, numberToString(id + 1));

	this->id = id;

	balance = 0;

	setDateFormat();
}

Account::Account(const Account& other)
{
	copyFrom(other);
}

Account& Account::operator=(const Account& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Account::~Account()
{
	free();
}

const char* Account::getUsername() const
{
	return username;
}

const char* Account::getPassword() const
{
	return password;
}

const char* Account::getIban() const
{
	return iban;
}

const int Account::getId() const
{
	return id;
}

const double Account::getBalance() const
{
	return balance;
}

const char* Account::getDateOfCreation() const
{
	return dateOfCreation;
}

void Account::setUsername(const char* username)
{
	delete[] this->username;
	this->username = new char[strlen(username) + 1];
	strcpy(this->username, username);
}

void Account::setPassword(const char* password)
{
	delete[] this->password;
	this->password = new char[strlen(password) + 1];
	strcpy(this->password, password);
}

void Account::setBalance(const double money)
{
	balance = money;
}

void Account::deposit(const double money)
{
	balance += money;
}

const bool Account::withdraw(double money) const
{
	bool enoughMoney = false;
	if (balance >= money)
	{
		enoughMoney = true;
	}
	return enoughMoney;
}

void Account::display()
{
	cout << "Account ID: " << id << endl;
	cout << "IBAN: " << iban << endl;
	cout << "Balance: " << balance << endl;
}

int Account::digitsCount(int id)
{
	int counter = 0;

	while (id != 0)
	{
		id /= 10;
		counter++;
	}

	return counter;
}

char* Account::numberToString(int number)
{
	char* numberToString = new char[digitsCount(number) + 1];
	numberToString[digitsCount(number)] = '\0';

	for (int i = digitsCount(number) - 1; i >= 0; i--)
	{
		numberToString[i] = number % 10 + '0';
		number /= 10;
	}

	return numberToString;
}

void Account::copyFrom(const Account& other)
{
	username = new char[strlen(other.username) + 1];
	strcpy(this->username, other.username);

	password = new char[strlen(other.password) + 1];
	strcpy(this->password, other.password);

	iban = new char[strlen(other.iban) + 1];
	strcpy(iban, other.iban);

	id = other.id;

	balance = other.balance;

	dateOfCreation = new char[strlen(other.dateOfCreation) + 1];
	strcpy(dateOfCreation, other.dateOfCreation);
}

void Account::free()
{
	delete[] username;
	delete[] password;
	delete[] iban;
	delete[] dateOfCreation;
}
