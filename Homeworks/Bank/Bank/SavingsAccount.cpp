#include "SavingsAccount.h"
#include <cstring>

#pragma warning(disable : 4996)

SavingsAccount::SavingsAccount(const int id, const char* name, const char* password, const double insertRate) : Account(id, name, password)
{
	this->insertRate = insertRate;
}

const bool SavingsAccount::withdraw(const double money) const
{
	return false;
}

Account* SavingsAccount::clone() const
{
	return new SavingsAccount(*this);
}
