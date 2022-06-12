#include <iostream>
#include <fstream>

using namespace std;

const int NAME_LENGTH = 25;

struct jobOffer
{
	char name[NAME_LENGTH];
	int programmers;
	int vacationDays;
	long long salary;
};

void saveRequests(ofstream& offers, char* name, int programmers, int vacationDays, long long salary)
{
	offers.open("offers.dat", ios_base::app);
	if (!offers.is_open())
	{
		cout << "File didn't open!";
	}

	offers << name << endl << programmers << endl << vacationDays << endl << salary << endl << endl;

	offers.close();
}

void filterOffers(const char* filePath, long long minSalary)
{

}

int main()
{
	int n;
	cin >> n;

	jobOffer examples;
	ofstream offers("offers.dat");

	while (n > 0)
	{
		cin.getline(examples.name, NAME_LENGTH);
		cin.clear();
		cin.ignore(255, '\n');
		cin >> examples.programmers;
		cin >> examples.salary;
		cin >> examples.vacationDays;
		saveRequests(offers, examples.name, examples.programmers, examples.salary, examples.vacationDays);
		n--;
	}
}