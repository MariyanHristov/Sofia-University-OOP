#pragma once
#include <ctime>

class Account
{
protected:
	char* username;
	char* password;
	char* iban;
	int id;
	double balance;
	char* dateOfCreation;

public:
	Account();
	Account(const int id, const char* username, const char* password);
	Account(const Account& other);
	Account& operator=(const Account& other);
	~Account();

	void setDateFormat();

	const char* getUsername() const;
	const char* getPassword() const;
	const char* getIban() const;
	const int getId() const;
	const double getBalance() const;
	const char* getDateOfCreation() const;

	void setUsername(const char* username);
	void setPassword(const char* password);
	void setBalance(const double money); 

    void deposit(const double money);
	virtual const bool withdraw(const double money) const = 0;
    void display();

	int digitsCount(int id);
	char* numberToString(int id);

	virtual Account* clone() const = 0;
private:
	void copyFrom(const Account& other);
	void free();
};