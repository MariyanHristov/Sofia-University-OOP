#include "Bank.h"
#include <iostream>
#include <cstring>

using namespace std;

const int MAX_SIZE = 512;

void displayMenu();

int main()
{
	displayMenu();

	Bank bank("Unecredit Bolbank", "Sofia");

	char command[MAX_SIZE] = "";

	while (true)
	{
		cout << ">Enter command:" << endl;
		cin.clear();
		//cin.ignore(strlen(command), '\n');
		cin.getline(command, MAX_SIZE);

		if (strcmp(command, "Add new customer") == 0) 
		{
			bank.addCustomer();
		}
		else if (strcmp(command, "Delete customer") == 0)
		{
			bank.deleteCustomer();
		}	
		else if (strcmp(command, "Add new account") == 0)
		{
			bank.addAccount();
		}	
		else if (strcmp(command, "Delete account") == 0) 
		{
			bank.deleteAccount();
		}	
		else if (strcmp(command, "List all customers") == 0) 
		{
			bank.listCustomers();
		}	
		else if (strcmp(command, "List all accounts") == 0) 
		{
			bank.listAccounts();
		}	
		else if (strcmp(command, "List customer account") == 0) 
		{
			bank.listCustomerAccount();
		}	
		else if (strcmp(command, "List log") == 0)
		{
			bank.listLog();
		}
		else if (strcmp(command, "Withdraw from account") == 0)
		{
			bank.withdraw();
		}
		else if (strcmp(command, "Deposit to account") == 0) 
		{
			bank.deposit();
		}
		else if (strcmp(command, "Transfer") == 0) 
		{
			bank.transfer();
		}
		else if (strcmp(command, "Display info for the bank") == 0) 
		{
			bank.display();
		}
		else if (strcmp(command, "Quit") == 0)
		{
			bank.quit();
			break;
		}
		else
		{
			cout << "Invalid command! (or just cin.getline does whatever it wants (didn't have time to fix it) :D )" << endl;
		}
	}
}

void displayMenu()
{
	cout << "1. Edit" << endl;
	cout << "	a.Customer" << endl;
	cout << "		i.Add new customer" << endl;
	cout << "		ii.Delete customer" << endl;
	cout << "	b.Account" << endl;
	cout << "		i.Add new account" << endl;
	cout << "		ii.Delete account" << endl;
	cout << "2. List" << endl;
	cout << "	a.List all customers" << endl;
	cout << "	b.List all accounts" << endl;
	cout << "	c.List customer account" << endl;
	cout << "	d.List log" << endl;
	cout << "3. Action" << endl;
	cout << "	a.Withdraw from account" << endl;
	cout << "	b.Deposit to account" << endl;
	cout << "	c.Transfer" << endl;
	cout << "4. Display info for the bank" << endl;
	cout << "5. Quit" << endl;
}