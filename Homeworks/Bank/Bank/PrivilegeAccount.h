#pragma once
#include "Account.h"

class PrivilegeAccount : public Account
{
private:
	double overdraft;

public:

	PrivilegeAccount(const int id, const char* name, const char* password, const double overdraft);
	const bool withdraw(double const money) const override;
	Account* clone() const override;
};