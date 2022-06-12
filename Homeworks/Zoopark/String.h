#pragma once
#include <fstream>

class String {
private:
	char* str;
	size_t size;
public:
	String();
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	~String();

	void concat(const String&);
	void concat(const char*);
	void concat(const char);
	String& operator+=(const String&);
	String& operator+=(const char*);
	String& operator+=(const char);
	char operator[](size_t) const;
	bool operator==(const char*) const;

	double transformToNum();
	char* getStr() const;
	size_t getSize() const;

	friend std::istream& operator>>(std::istream&, String&);
	friend std::ostream& operator<<(std::ostream&, const String&);
	String* clone() const;

private:
	void copy(const String&);
	void free();
};