#pragma once

#include "Account.h";
#include <cstring>

class NormalAccount : public Account
{
public:

	NormalAccount(const int id, const char* name, const char* password);
	const bool withdraw(const double money) const override;
	Account* clone() const override;
};