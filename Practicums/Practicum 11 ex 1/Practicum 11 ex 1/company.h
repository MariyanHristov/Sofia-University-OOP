#pragma once

#include "worker.h"

class Company
{
private: 
	Worker* workers;

public:
	Company();
	Company(const Company& other);
	Company& operator=(const Company& other);
	~Company();

private:
	void copyFrom(const Company& other);
	void free();

};