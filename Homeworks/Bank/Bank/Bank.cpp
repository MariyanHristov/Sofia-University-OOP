#include "Bank.h"
#include "NormalAccount.h"
#include "SavingsAccount.h"
#include "PrivilegeAccount.h"
#include <iostream>
#include <cstring>
#include <fstream>

#pragma warning(disable : 4996)

using namespace std;

const int MAX_SIZE = 512;

Bank::Bank()
{
	name = new char[1];
	name[0] = '\0';
	address = new char[1];
	address[0] = '\0';
	customersCount = 0;
	customersCapacity = 2;
	customers = new Customer[customersCapacity];
	accountsCount = 0;
	accountsCapacity = 2;
	accounts = new Account * [accountsCapacity];
}

Bank::Bank(const char* name, const char* address)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	this->address = new char[strlen(address) + 1];
	strcpy(this->address, address);

	customersCount = 0;
	customersCapacity = 2;
	customers = new Customer[customersCapacity];
	accountsCount = 0;
	accountsCapacity = 2;
	accounts = new Account * [accountsCapacity];
}

Bank::Bank(const Bank& other)
{
	copyFrom(other);
}

Bank& Bank::operator=(const Bank& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Bank::~Bank()
{
	free();
}

void Bank::addAccount()
{
	char option[MAX_SIZE];
	cout << "What account type do you want to add? (insert savings/privilege/normal) :";
	cin >> option;

	if (strcmp(option, "savings") == 0)
	{
		addSavingAccount();
	}
	else if (strcmp(option, "privilege") == 0)
	{
		addPrivilegeAccount();
	}
	else if (strcmp(option, "normal") == 0)
	{
		addNormalAccount();
	}
}

void Bank::addPrivilegeAccount()
{
	double overdraft;
	char name[MAX_SIZE], password[MAX_SIZE];

	cout << "name = "; cin >> name;
	cout << "password = "; cin >> password;
	cout << "overdraft = "; cin >> overdraft;

	if (customersCount >= customersCapacity)
	{
		resizeCustomer();
	}
	accounts[accountsCount++] = new PrivilegeAccount(accountsCount, name, password, overdraft);

	cout << "Privilege account successfully added!" << endl;

	ofstream file("log.txt", ios::app);
	file << "Privilege account was created with name: " << name << " password: " << password << " overdraft: " << overdraft << endl;
	file.close();
}

void Bank::addSavingAccount()
{
	double insertRate;
	char name[MAX_SIZE], password[MAX_SIZE];

	cout << "name = "; cin >> name;
	cout << "password = "; cin >> password;
	cout << "insertRate = "; cin >> insertRate;

	if (customersCount >= customersCapacity)
	{
		resizeCustomer();
	}
	accounts[accountsCount++] = new SavingsAccount(accountsCount, name, password, insertRate);

	cout << "Savings account successfully added!" << endl;

	ofstream file("log.txt", ios::app);
	file << "Savings account was created with name: " << name << " password: " << password << " Insert rate: " << insertRate << endl;
	file.close();
}

void Bank::addNormalAccount()
{
	char name[MAX_SIZE], password[MAX_SIZE];

	cout << "name = "; cin >> name;
	cout << "password = "; cin >> password;

	if (customersCount >= customersCapacity)
	{
		resizeCustomer();
	}
	accounts[accountsCount++] = new NormalAccount(accountsCount, name, password);

	cout << "Customer successfully added!" << endl;

	ofstream file("log.txt", ios::app);
	file << "Normal account was created with name: " << name << " password: " << password << " Insert rate: " << endl;;
	file.close();
}

void Bank::addCustomer()
{
	char name[MAX_SIZE], address[MAX_SIZE];

	cout << "name = "; cin >> name;
	cout << "password = "; cin >> address;

	if (customersCount >= customersCapacity)
	{
		resizeCustomer();
	}
	customers[customersCount++] = Customer(customersCount, name, address);

	cout << "Customer successfully added!" << endl;

	ofstream file("log.txt", ios::app);
	file << "Customer was created with name: " << name << " address: " << address << endl;
	file.close();
}

void Bank::deleteCustomer()
{
	int id;
	for (;;)
	{
		cout << "Which customer do you want to delete? (insert ID): "; cin >> id;
		if (id > customersCount)
		{
			cout << "Customer with this index doesn't exist. " << endl;
		}
		else
		{
			break;
		}
	}

	Customer* tempCustomers = new Customer[customersCapacity];

	customersCount--;
	id--;
	for (int i = 0; i < customersCount; i++)
	{
		if (i < id)
		{
			tempCustomers[i] = customers[i];
		}
		else
		{
			tempCustomers[i] = customers[i + 1];
		}
	}
	delete[] customers;
	customers = tempCustomers;

	cout << "Customer successfully deleted!" << endl;

	ofstream file("log.txt", ios::app);
	file << "Customer with id " << id + 1 << " was deleted" << endl;;
	file.close();
}

void Bank::listLog()const
{
	char temp[MAX_SIZE];
	ifstream file("log.txt");
	while (file.good())
	{
		file.getline(temp, MAX_SIZE);
		cout << temp << endl;
	}
	file.close();
}

void Bank::deleteAccount()
{
	int id;
	for (;;)
	{
		cout << "Which customer do you want to delete? (insert ID): "; cin >> id;
		if (id > accountsCount)
		{
			cout << "Customer with this index doesn't exist. " << endl;
		}
		else
		{
			break;
		}
	}

	Account** tempAccounts = new Account * [accountsCapacity];

	accountsCount--;
	id--;
	for (int i = 0; i < accountsCount; i++)
	{
		if (i < id)
		{
			tempAccounts[i] = accounts[i];
		}
		else
		{
			tempAccounts[i] = accounts[i + 1];
		}
	}
	delete[] accounts;
	accounts = tempAccounts;

	cout << "Account successfully deleted!" << endl;

	ofstream file("log.txt", ios::app);
	file << "Account with id " << id + 1 << " was deleted" << endl;
	file.close();
}

void Bank::listCustomers() const
{
	for (size_t i = 0; i < customersCount; i++)
	{
		cout << customers[i].getId() << ". " << customers[i].getName() << " " << customers[i].getAddress() << endl;
	}
}

void Bank::listAccounts() const
{
	for (size_t i = 0; i < accountsCount; i++)
	{
		cout << accounts[i]->getId() + 1 << ". " << accounts[i]->getUsername() << " " << accounts[i]->getIban() <<
			" " << accounts[i]->getBalance() << " lv " << accounts[i]->getDateOfCreation() << endl;
	}
}

void Bank::listCustomerAccount() const
{
	int id;
	for (;;)
	{
		cout << "Which customer do you want to view? (insert ID): "; cin >> id;
		if (id > customersCount)
		{
			cout << "Customer with this index doesn't exist. " << endl;
		}
		else
		{
			id--;
			break;
		}
	}

	cout << customers[id].getId() + 1 << ". " << customers[id].getName() << " " << customers[id].getAddress() << endl;
}

void Bank::quit() const
{
	ofstream file("log.txt");
	file.close();
}

void Bank::withdraw()
{
	double money;
	char iban[MAX_SIZE];
	cout << "Withdraw from IBAN: "; cin >> iban;
	cout << "How much money will be withdrawn? : "; cin >> money;

	bool existingIban = false;
	size_t ibanIndex;
	for (size_t i = 0; i < accountsCount; i++)
	{
		if (accounts[i]->getIban() == iban)
		{
			existingIban = true;
			ibanIndex = i;
		}
	}

	if (existingIban)
	{
		if (accounts[ibanIndex]->withdraw(money))
		{
			accounts[ibanIndex]->setBalance(accounts[ibanIndex]->getBalance() - money);

			ofstream file("log.txt", ios::app);
			file << "Withdrawn " << money << " lv from IBAN " << iban;
			file.close();
		}
	}
	else
	{
		cout << "Either the iban doesn't exist or withdraw is impossible!" << endl;
	}
}

void Bank::deposit()
{
	double money;
	char iban[MAX_SIZE];
	cout << "Deposit to IBAN: "; cin >> iban;
	cout << "How much money will be deposited? : "; cin >> money;

	bool existingIban = false;
	size_t ibanIndex;
	for (size_t i = 0; i < accountsCount; i++)
	{
		if (strcmp(accounts[i]->getIban(), iban) == 0)
		{
			existingIban = true;
			ibanIndex = i;
		}
	}

	if (existingIban)
	{
		accounts[ibanIndex]->setBalance(accounts[ibanIndex]->getBalance() + money);

		ofstream file("log.txt", ios::app);
		file << "Deposited " << money << " lv to IBAN " << iban;
		file.close();
	}
	else
	{
		cout << "This iban doesn't exist!" << endl;
	}
}

void Bank::transfer()
{
	double money;
	char fromIban[MAX_SIZE], toIban[MAX_SIZE];
	cout << "Transfer from: "; cin >> fromIban;
	cout << "Transfer to: "; cin >> toIban;
	cout << "How much money will be transfered? : "; cin >> money;

	bool existingFromIban = false;
	bool existingToIban = false;
	size_t fromIbanIndex, toIbanIndex;
	for (size_t i = 0; i < accountsCount; i++)
	{
		if (accounts[i]->getIban() == fromIban)
		{
			existingFromIban = true;
			fromIbanIndex = i;
		}
		else if (accounts[i]->getIban() == toIban)
		{
			existingToIban = true;
			toIbanIndex = i;
		}
	}

	if (existingFromIban || existingToIban)
	{
		if (accounts[fromIbanIndex]->withdraw(money))
		{
			accounts[fromIbanIndex]->setBalance(accounts[fromIbanIndex]->getBalance() - money);
			accounts[toIbanIndex]->setBalance(accounts[toIbanIndex]->getBalance() + money);

			ofstream file("log.txt", ios::app);
			file << "Transfered " << money << " lv from IBAN " << accounts[fromIbanIndex]->getIban() << "to IBAN" << accounts[toIbanIndex]->getIban();
			file.close();
		}
		else
		{
			cout << "Not possible transaction." << endl;
		}
	}
	else
	{
		cout << "Not existing Iban/s." << endl;
	}
}

void Bank::display() const
{
	cout << name << endl << address << endl;
	cout << "Customers: " << customersCount << endl;
	cout << "Accounts: " << accountsCount << endl;
}

void Bank::copyFrom(const Bank& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	address = new char[strlen(other.address) + 1];
	strcpy(address, other.address);

	customers = new Customer[other.customersCapacity];
	customers = other.customers;

	accounts = new Account * [other.accountsCapacity];
	for (size_t i = 0; i < other.accountsCount; i++)
	{
		accounts[i] = other.accounts[i]->clone();
	}
}

void Bank::free()
{
	delete[] name;
	delete[] address;
	delete[] customers;
	for (size_t i = 0; i < accountsCount; i++)
	{
		delete accounts[i];
	}
	delete[] accounts;
}

void Bank::resizeAccount()
{
	Account** temp = new Account * [accountsCapacity *= 2];

	for (size_t i = 0; i < accountsCount; i++)
	{
		temp[i] = accounts[i];
	}

	delete[] accounts;
	accounts = temp;
}

void Bank::resizeCustomer()
{
	Customer* temp = new Customer[customersCapacity *= 2];

	for (size_t i = 0; i < accountsCount; i++)
	{
		temp[i] = customers[i];
	}

	delete[] customers;
	customers = temp;
}
