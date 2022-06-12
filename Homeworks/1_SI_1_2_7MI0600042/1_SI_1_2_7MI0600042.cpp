#include <iostream>
#include <fstream>

using namespace std;

size_t getFileSize(ifstream& file);
void printHexRepresentation(const size_t& symbolsCount, char* symbols);
void convertCharToHex(char  hexValue[3], int& symbolToInt);
void manageFileOptions(size_t& symbolsCount, char* symbols, char fileName[80]);
void printCharRepresentation(int size, char* symbols);
bool isLetter(char symbol);
int strCmp(const char* s1, const char* s2);

int main()
{
	char fileName[80];

	cout << "Enter a path to a binary file: ";
	cin >> fileName;
	ifstream readFile(fileName);
	if (!readFile.is_open())
	{
		cout << "File couldn't load!";
	}
	else
	{
		cout << "File loaded successfully!";
	}

	size_t symbolsCount = getFileSize(readFile); //taken from Nikola's GitHub
	cout << "File size: " << symbolsCount << " bytes" << endl;

	char* symbols = new char[symbolsCount + 1];
	readFile.read(symbols, symbolsCount);
	readFile.close();

	manageFileOptions(symbolsCount, symbols, fileName);
	delete[]symbols;
}

void manageFileOptions(size_t& symbolsCount, char* symbols, char fileName[80])
{
	char option[40];
	do
	{
		cin.getline(option, 40);

		if (strCmp(option, "view") == 0)
		{
			cout << "Char representation: " << endl;
			printCharRepresentation(symbolsCount, symbols);

			cout << "Hex representation: " << endl;
			printHexRepresentation(symbolsCount, symbols);
			cout << endl;
		}
		else if (strCmp(option, "remove") == 0)
		{
			symbolsCount--;

			cout << "Last byte was removed successfully!" << endl;
		}
		else if (strCmp(option, "add") == 0)
		{
			symbolsCount++;
			cout << "Write down (a single) character you want to add: ";
			cin >> symbols[symbolsCount - 1];

			cout << "A byte was added at the end successfully!" << endl;
		}
		else if (strCmp(option, "change") == 0)
		{
			cout << "Choose index of the byte you want to change: ";
			int x;
			cin >> x;

			cout << "Enter the value you want to assign to it (in hex): ";
			char hexValue[3];
			cin >> hexValue;

			int symbolToInt;

			convertCharToHex(hexValue, symbolToInt);
			symbols[x] = (char)symbolToInt;
		}
	} while (strCmp(option, "save") != 0 && strCmp(option, "save as") != 0);

	if (strCmp(option, "save") == 0)
	{
		ofstream saveFile(fileName);
		saveFile.write(symbols, symbolsCount);
		cout << "File saved!";
		saveFile.close();
	}
	else if (strCmp(option, "save as") == 0)
	{
		char newFile[80];
		cout << "How do you want to call the new file (include the file type as well)?: ";
		cin >> newFile;
		ofstream saveAsFile(newFile);
		saveAsFile.write(symbols, symbolsCount);
		cout << "File saved as '" << newFile << "'!";
		saveAsFile.close();
	}
}

void convertCharToHex(char  hexValue[3], int& symbolToInt)
{
	switch (hexValue[0])
	{
	case '0': symbolToInt = 0 * 16;
		break;
	case '1': symbolToInt = 1 * 16;
		break;
	case '2': symbolToInt = 2 * 16;
		break;
	case '3': symbolToInt = 3 * 16;
		break;
	case '4': symbolToInt = 4 * 16;
		break;
	case '5': symbolToInt = 5 * 16;
		break;
	case '6': symbolToInt = 6 * 16;
		break;
	case '7': symbolToInt = 7 * 16;
		break;
	case '8': symbolToInt = 8 * 16;
		break;
	case '9': symbolToInt = 9 * 16;
		break;
	case 'A': symbolToInt = 10 * 16;
		break;
	case 'B': symbolToInt = 11 * 16;
		break;
	case 'C': symbolToInt = 12 * 16;
		break;
	case 'D': symbolToInt = 13 * 16;
		break;
	case 'E': symbolToInt = 14 * 16;
		break;
	case 'F': symbolToInt = 15 * 16;
		break;
	}

	switch (hexValue[1])
	{
	case '0': symbolToInt += 0;
		break;
	case '1': symbolToInt += 1;
		break;
	case '2': symbolToInt += 2;
		break;
	case '3': symbolToInt += 3;
		break;
	case '4': symbolToInt += 4;
		break;
	case '5': symbolToInt += 5;
		break;
	case '6': symbolToInt += 6;
		break;
	case '7': symbolToInt += 7;
		break;
	case '8': symbolToInt += 8;
		break;
	case '9': symbolToInt += 9;
		break;
	case 'A': symbolToInt += 10;
		break;
	case 'B': symbolToInt += 11;
		break;
	case 'C': symbolToInt += 12;
		break;
	case 'D': symbolToInt += 13;
		break;
	case 'E': symbolToInt += 14;
		break;
	case 'F': symbolToInt += 15;
		break;
	}
}

void printHexRepresentation(const size_t& symbolsCount, char* symbols)
{
	int* symbolsToInt = new int[symbolsCount + 1];

	for (int i = 0; i < symbolsCount; ++i)
	{
		symbolsToInt[i] = (int)symbols[i];
	}

	for (int i = 0; i < symbolsCount; i++)
	{
		if (symbolsToInt[i] / 16 < 10)
		{
			cout << symbolsToInt[i] / 16;
		}
		else
		{
			switch (symbolsToInt[i] / 16)
			{
			case 10: cout << 'A';
				break;
			case 11: cout << 'B';
				break;
			case 12: cout << 'C';
				break;
			case 13: cout << 'D';
				break;
			case 14: cout << 'E';
				break;
			case 15: cout << 'F';
				break;
			}
		}

		if (symbolsToInt[i] % 16 < 10)
		{
			cout << symbolsToInt[i] % 16;
		}
		else
		{
			switch (symbolsToInt[i] % 16)
			{
			case 10: cout << 'A';
				break;
			case 11: cout << 'B';
				break;
			case 12: cout << 'C';
				break;
			case 13: cout << 'D';
				break;
			case 14: cout << 'E';
				break;
			case 15: cout << 'F';
				break;
			}
		}

		cout << " ";
	}
	delete[]symbolsToInt;
}

size_t getFileSize(ifstream& file) //taken fron Nikola's GitHub
{
	size_t currentPosition = file.tellg();
	file.seekg(0, ios::end);
	size_t size = file.tellg();

	file.seekg(currentPosition);
	return size;
}

void printCharRepresentation(int size, char* symbols)
{
	for (int i = 0; i < size; i++)
	{
		if (isLetter(symbols[i]))
		{
			cout << symbols[i] << " ";
		}
		else
		{
			cout << ". ";
		}
	}
	cout << endl;
}

bool isLetter(char symbol)
{
	return ((symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z'));
}

int strCmp(const char* s1, const char* s2) //taken from StackOverflow
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}	return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

