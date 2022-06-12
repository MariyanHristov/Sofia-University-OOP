#pragma once
#include "Account.h"

class SavingsAccount : public Account
{
private:
	double insertRate;

public:

	SavingsAccount(const int id, const char* name, const char* password, const double insertRate);
	const bool withdraw(const double money) const override;
	Account* clone() const override;
};