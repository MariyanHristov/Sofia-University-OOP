#include <iostream>
#include <fstream>
#include <cstring>

#include "SVG.h"

#pragma warning (disable : 4996)
using namespace std;

const int MAX_SIZE = 60;

int main()
{
	SVG svg;
	char command[MAX_SIZE] = "";

	svg.getShapesDataFromFile();

	do
	{
		cout << ">Enter command: ";
		cin >> command;
		if (strcmp(command, "print") == 0)
			svg.print();
		else if (strcmp(command, "create") == 0)
			svg.create();
		else if (strcmp(command, "erase") == 0)
			svg.erase();
		else if (strcmp(command, "translate") == 0)
			svg.translate();
		else if (strcmp(command, "within") == 0)
			svg.within();
		else if (strcmp(command, "pointIn") == 0)
			svg.pointIn();
		else if (strcmp(command, "areas") == 0)
			svg.areas();
		else if (strcmp(command, "perimetres") == 0)
			svg.perimetres();
		else if (strcmp(command, "save") == 0)
			svg.saveFiles();
		else if (strcmp(command, "quit") == 0)
			break;
		else
			cout << "Invalid command!" << endl;
	} while (true);
}
