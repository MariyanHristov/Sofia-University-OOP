#pragma once

#include "Book.h";

class User
{
private:
	char* name;
	char* password;
	Book* booksRead;
	size_t booksReadCount;
	Book* booksWritten;
	size_t booksWrittenCount;
	bool loggedIn;

public:
	User();
	User(const char* name, const char* password);
	User(const User& other);
	User& operator=(const User& other);
	~User();

	const char* getName() const;
	const char* getPassword() const;
	Book* getBooksRead() const;
	Book* getBooksWritten() const;
	bool getLoggedIn() const;

	void setName(const char* name);
	void setPassword(const char* password);
	void setBooksRead(const Book* booksRead);
	void setBooksWritten(const Book* booksWritten);
	void setLoggedIn(const bool loggedIn);

	void readBook(const Book& book);
	void writeBook();
	void readPage(const Book& book, const Page& page); //didn't have time for this :D
	void commentBook(const Book& book, const Comment& comment);
	void viewComments(const Book& book);
	void addPageToBook(Book& book, const Page& page); 
	void rateBook(const Book& book, const Rating& rating);
	void viewRatings(const Book& book);
	void changeRating(const Book& book); //didn't have time for this :D

	void registerUser(const char* name, const char* password);
	void viewBookList();
	void addReadBook(const Book& readBook);
	void addWrittenBook(const Book& writtenBook);

private:
	void free();
	void copyFrom(const User& other);
};