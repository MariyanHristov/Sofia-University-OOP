#pragma once
#include "Customer.h"
#include "Account.h"

class Bank
{
private:
	char* name;
	char* address;
	Customer* customers;
	size_t customersCount;
	size_t customersCapacity;
	Account** accounts;
	size_t accountsCount;
	size_t accountsCapacity;

public:
	Bank();
	Bank(const char* name, const char* address);
	Bank(const Bank& other);
	Bank& operator=(const Bank& other);
	~Bank();

	void addAccount();
	void addPrivilegeAccount();
	void addSavingAccount();
	void addNormalAccount();
	void addCustomer();
	void deleteCustomer();

	void listLog() const;
	void deleteAccount();
	void listCustomers() const;
	void listAccounts() const;
	void listCustomerAccount() const;
	void quit() const;
	void withdraw();
	void deposit();
	void transfer();
	void display() const;

private:
	void copyFrom(const Bank& other);
	void free();
	void resizeAccount();
	void resizeCustomer();
};
