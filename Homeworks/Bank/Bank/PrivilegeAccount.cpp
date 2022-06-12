#include "PrivilegeAccount.h"
#include <cstring>
#pragma warning(disable : 4996)

PrivilegeAccount::PrivilegeAccount(const int id, const char* name, const char* password, const double overdraft) : Account(id, name, password)
{
	this->overdraft = overdraft;
}

const bool PrivilegeAccount::withdraw(double const money) const
{
	bool enoughMoney = false;
	if (balance + overdraft >= money)
	{
		enoughMoney = true;
	}

	return enoughMoney;
}

Account* PrivilegeAccount::clone() const
{
	return new PrivilegeAccount(*this);
}
