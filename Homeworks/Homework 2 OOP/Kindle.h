#pragma once

#include "User.h"
#include "Book.h"

class Kindle
{
private:
	User* users;
	size_t usersCount;
	Book* books;
	size_t booksCount;

public:
	Kindle();
	Kindle(const Kindle& other);
	Kindle& operator=(const Kindle& other);
	~Kindle();

	User* getUsers() const;
	Book* getBooks() const;

	void setUsers(const User* users);
	void setBooks(const Book* books);

	void logIn(User& user);

private:
	void free();
	void copyFrom(const Kindle& other);
};