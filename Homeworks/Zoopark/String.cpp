#include "String.h"
#include <cstring>
#pragma warning (disable: 4996)

const int BUFFER_SIZE = 10000;

String::String()
{
	size = 0;
	str = new char[1];
	str[0] = '\0';
}

String::String(const char* other)
{
	size = strlen(other);
	str = new char[size + 1];
	str[size] = '\0';
	for (size_t i = 0; i < size; i++)
		str[i] = other[i];
}

String::String(const String& other)
{
	copy(other);
}

String& String::operator=(const String& other)
{
	if (this != &other) {
		free();
		copy(other);
	}
	return *this;
}

String::~String()
{
	free();
}

void String::concat(const String& other)
{
	size = size + other.size;
	char* temp = new char[size + 1];
	strcpy(temp, str);
	strcat(temp, other.str);

	delete[] str;
	str = temp;
}

void String::concat(const char* str)
{
	size = size + strlen(str);
	char* temp = new char[size + 1];
	strcpy(temp, this->str);
	strcat(temp, str);
	delete[] this->str;
	this->str = temp;
}

void String::concat(const char str)
{
	size = size + 1;
	char* strN = new char[2];
	strN[0] = str;
	strN[1] = '\0';
	char* temp = new char[size + 1];
	strcpy(temp, this->str);
	strcat(temp, strN);
	delete[] this->str;
	delete[] strN;
	this->str = temp;
}

String& String::operator+=(const String& other)
{
	concat(other);
	return *this;
}

String& String::operator+=(const char* str)
{
	concat(str);
	return *this;
}

char String::operator[](size_t pos) const
{
	if (pos > size || pos <= 0)
		throw "Incorrect size";
	return str[pos];
}

bool String::operator==(const char* other) const
{
	return strcmp(str, other) == 0;
}

String& String::operator+=(const char str)
{
	concat(str);
	return *this;
}

char* String::getStr() const
{
	return str;
}

double String::transformToNum()
{
	double num = 0;
	size_t index = getSize() - 1;
	bool marker = false;

	for (size_t i = 0; i < getSize(); i++) {
		if (str[i] == '-') {
			marker = true;
			i++;
		}
		if (str[i] != '.')
			num = num * 10 + str[i] - 48;
		else {
			index = i;
			break;
		}
	}
	double tail = 0;
	for (size_t i = getSize() - 1; i >= index + 1; i--) {
		tail = tail / 10 + str[i] - 48;
	}
	tail /= 10;
	num += tail;
	if (marker)
		num = -num;
	return num;
}

size_t String::getSize() const {
	return size;
}

String* String::clone() const
{
	return new String(*this);
}

void String::copy(const String& other)
{
	size = other.size;
	str = new char[size + 1];
	strcpy(str, other.str);
}

void String::free()
{
	delete[] str;
}

std::istream& operator>>(std::istream& input, String& s)
{
	char buffer[BUFFER_SIZE];
	input >> buffer;

	s.free();
	s.size = strlen(buffer);
	s.str = new char[s.size + 1];
	strcpy(s.str, buffer);

	return input;
}

std::ostream& operator<<(std::ostream& out, const String& s)
{
	out << s.str;
	return out;
}