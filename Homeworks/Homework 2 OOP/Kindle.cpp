#include <iostream>
#include <cstring>
#include <fstream>

#include "Kindle.h"
#include "User.h"
#include "Book.h"
#pragma warning(disable : 4996)

const int BUFFER_SIZE = 512;

Kindle::Kindle()
{
	users = nullptr;
	usersCount = 0;
	books = nullptr;
	booksCount = 0;
}

Kindle::Kindle(const Kindle& other)
{
	copyFrom(other);
}

Kindle& Kindle::operator=(const Kindle& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Kindle::~Kindle()
{
	free();
}

User* Kindle::getUsers() const
{
	return users;
}

Book* Kindle::getBooks() const
{
	return books;
}

void Kindle::setUsers(const User* users)
{
	delete[] this->users;
	users = new User[usersCount];
	for (size_t i = 0; i < usersCount; i++)
	{
		this->users[i] = users[i];
	}
}

void Kindle::setBooks(const Book* books)
{
	delete[] this->books;
	books = new Book[booksCount];
	for (size_t i = 0; i < booksCount; i++)
	{
		this->books[i] = books[i];
	}
}

void Kindle::logIn(User& user)
{
	bool exists = false;

	char* checkUsername = new char[strlen(user.getName()) + 12];
	strcpy(checkUsername, "Username: ");
	strcat(checkUsername, user.getName());

	char* checkPassword = new char[strlen(user.getPassword()) + 12];
	strcpy(checkPassword, "Password: ");
	strcat(checkPassword, user.getPassword());

	char tempUsername[BUFFER_SIZE];
	char tempPassword[BUFFER_SIZE];

	std::ifstream usersList("UsersList.txt");
	while (usersList.good())
	{
		usersList.getline(tempUsername, BUFFER_SIZE);
		usersList.getline(tempPassword, BUFFER_SIZE);
		if (strcmp(tempPassword, checkPassword) == 0
			&& strcmp(tempUsername, checkUsername) == 0)
		{
			std::cout << "You logged in successfully!" << std::endl;
			exists = true;
			user.setLoggedIn(exists);
			break;
		}
	}
	usersList.close();

	if (!exists)
	{
		std::cout << "Username or password is incorrect!" << std::endl;
	}

	delete[] checkPassword;
	delete[] checkUsername;
}

void Kindle::free()
{
	delete[] users;
	delete[] books;
}

void Kindle::copyFrom(const Kindle& other)
{
	users = new User[usersCount];
	for (size_t i = 0; i < usersCount; i++)
	{
		users[i] = other.users[i];
	}

	books = new Book[booksCount];
	for (size_t i = 0; i < booksCount; i++)
	{
		books[i] = other.books[i];
	}
}
