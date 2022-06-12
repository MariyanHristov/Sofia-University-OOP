#include "NormalAccount.h";
#pragma warning(disable : 4996)

NormalAccount::NormalAccount(const int id, const char* name, const char* password)
	: Account(id, name, password)
{
}

const bool NormalAccount::withdraw(const double money) const
{
	bool enoughMoney = false;
	if (balance >= money)
	{
		enoughMoney = true;
	}

	return enoughMoney;
}

Account* NormalAccount::clone() const
{
	return new NormalAccount(*this);
}

