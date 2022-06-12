#include <iostream>
#include <cstring>
#include <fstream>

#include "Book.h"
#include "User.h"
#include "Rating.h"
#pragma warning(disable : 4996)

const int BUFFER_SIZE = 512;

User::User()
{
	name = nullptr;
	password = nullptr;
	booksRead = nullptr;
	booksReadCount = 0;
	booksWritten = nullptr;
	booksWrittenCount = 0;
	loggedIn = false;
}

User::User(const char* name, const char* password)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	this->password = new char[strlen(password) + 1];
	strcpy(this->password, password);

	booksRead = nullptr;
	booksReadCount = 0;
	booksWritten = nullptr;
	booksWrittenCount = 0;
	loggedIn = false;
}

User::User(const User& other)
{
	copyFrom(other);
}

User& User::operator=(const User& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

User::~User()
{
	free();
}

const char* User::getName() const
{
	return name;
}

const char* User::getPassword() const
{
	return password;
}

Book* User::getBooksRead() const
{
	return booksRead;
}

Book* User::getBooksWritten() const
{
	return booksRead;
}

bool User::getLoggedIn() const
{
	return loggedIn;
}

void User::setName(const char* name)
{
	delete[]this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void User::setPassword(const char* password)
{
	delete[]this->password;
	this->password = new char[strlen(password) + 1];
	strcpy(this->password, password);
}

void User::setBooksRead(const Book* booksRead)
{
	delete[] this->booksRead;
	this->booksRead = new Book[booksReadCount];
	for (size_t i = 0; i < booksReadCount; i++)
	{
		this->booksRead[i] = booksRead[i];
	}
}

void User::setBooksWritten(const Book* booksWritten)
{
	delete[] this->booksWritten;
	this->booksWritten = new Book[booksWrittenCount];
	for (size_t i = 0; i < booksWrittenCount; i++)
	{
		this->booksWritten[i] = booksWritten[i];
	}
}

void User::setLoggedIn(const bool loggedIn)
{
	this->loggedIn = loggedIn;
}

void User::readBook(const Book& book)
{
	char* bookFileName = new char[strlen(book.getTitle()) + 6];
	strcpy(bookFileName, book.getTitle());
	strcat(bookFileName, ".txt");
	char temp[BUFFER_SIZE];

	std::ifstream readBook(bookFileName);
	while (readBook.good())
	{
		readBook.getline(temp, BUFFER_SIZE);
		std::cout << temp << std::endl;
	}

	delete[] bookFileName;
}

void User::writeBook()
{
	char title[BUFFER_SIZE];
	std::cout << "What will the name of the book be? : ";
	std::cin.getline(title, BUFFER_SIZE);
	Book book = Book(title);

	book.addBookToBooklist(title, this->name);

	std::cout << " The book is created, but stil empty! Use 'add page' to add page to the book." << std::endl;
}

void User::readPage(const Book& book, const Page& page)
{
	char* title = new char[strlen(book.getTitle()) + 5];
	title = (char*)book.getTitle();
	strcat(title, ".txt");

	//
	// 
	// 
}

void User::commentBook(const Book& book, const Comment& comment)
{
	bool exists = false;
	std::ifstream commentsList("Comments.txt");
	char temp[BUFFER_SIZE];

	char* existingComment = new char[strlen(comment.getUsername()) + strlen(book.getTitle())
		+ strlen(comment.getCommentContent()) + 13];
	strcpy(existingComment, book.getTitle());
	strcat(existingComment, ": ");
	strcat(existingComment, comment.getUsername());
	strcat(existingComment, " wrote: ");
	strcat(existingComment, comment.getCommentContent());

	while (commentsList.good())
	{
		commentsList.getline(temp, BUFFER_SIZE);
		if (strcmp(temp, existingComment) == 0)
		{
			exists = true;
			std::cout << "Comment already exists!";
			break;
		}
	}
	commentsList.close();

	if (!exists)
	{
		std::ofstream commentsListWrite("Comments.txt", std::ios::app);

		commentsListWrite << book.getTitle() << ": " << comment.getUsername() << " wrote: "
			<< comment.getCommentContent() << std::endl;
		std::cout << "Comment was successfully added!" << std::endl;
		commentsListWrite.close();
	}

	delete[] existingComment;
}

void User::viewComments(const Book& book)
{
	bool exists = false;
	char comments[BUFFER_SIZE];
	char temp[BUFFER_SIZE];
	std::ifstream commentsList("Comments.txt");

	size_t titleSize = strlen(book.getTitle()) + 1;
	while (commentsList.good())
	{
		commentsList.getline(temp, titleSize);
		commentsList.clear();
		if (strcmp(temp, book.getTitle()) == 0)
		{
			exists = true;
			commentsList.getline(comments, BUFFER_SIZE);
			std::cout << comments << std::endl;
		}
		if (temp[0] == '\0')
		{
			break;
		}
	}
	commentsList.close();

	if (!exists)
	{
		std::cout << "There are no comments about this book yet!" << std::endl;
	}
}

void User::addPageToBook(Book& book, const Page& page)
{
	int newPage = book.getPagesCount() + 1; 
	char temp[BUFFER_SIZE];
	strcpy(temp, book.getTitle());
	strcat(temp, ".txt");

	std::ofstream bookWrite(temp, std::ios::app);
	bookWrite << newPage << std::endl;
	bookWrite << page.getPageContent() << std::endl;
	bookWrite.close();
}

void User::rateBook(const Book& book, const Rating& rating)
{
	bool exists = false;
	std::ifstream ratingsList("Ratings.txt");
	char temp[BUFFER_SIZE];

	char* existingRating = new char[strlen(rating.getUsername()) + strlen(book.getTitle()) + 25];
	strcpy(existingRating, book.getTitle());
	strcat(existingRating, ": ");
	strcat(existingRating, rating.getUsername());
	strcat(existingRating, " rated with ");
	strcat(existingRating, rating.getRatingToString());
	strcat(existingRating, " stars.");

	while (ratingsList.good())
	{
		ratingsList.getline(temp, BUFFER_SIZE);
		if (strcmp(temp, existingRating) == 0)
		{
			exists = true;
			std::cout << "Rating already exists!";
			break;
		}
	}
	ratingsList.close();

	if (!exists)
	{
		std::ofstream ratingsListWrite("Ratings.txt", std::ios::app);

		ratingsListWrite << book.getTitle() << ": " << rating.getUsername() << " rated with "
			<< rating.getRatingToString() << " stars." << std::endl;
		std::cout << "Rating was successfully added!" << std::endl;
		ratingsListWrite.close();
	}

	delete[] existingRating;
}

void User::viewRatings(const Book& book)
{
	bool exists = false;
	char rating[BUFFER_SIZE];
	char temp[BUFFER_SIZE];
	std::ifstream ratingList("Ratings.txt");

	int titleSize = strlen(book.getTitle()) + 1;
	while (ratingList.good())
	{
		ratingList.getline(temp, titleSize);
		ratingList.clear();

		if (strcmp(temp, book.getTitle()) == 0)
		{
			exists = true;
			ratingList.getline(rating, BUFFER_SIZE);
			std::cout << rating << std::endl;
		}
		if (temp[0] == '\0')
		{
			break;
		}
	}
	ratingList.close();

	if (!exists)
	{
		std::cout << "There are no ratings about this book yet!" << std::endl;
	}
}

void User::changeRating(const Book& book)
{
	char rating[BUFFER_SIZE];
	char temp[BUFFER_SIZE];
	std::ifstream ratingList("Ratings.txt");

	int titleSize = strlen(book.getTitle()) + 1;
	while (ratingList.good())
	{
		ratingList.getline(temp, titleSize);
		ratingList.clear();

		if (strcmp(temp, book.getTitle()) == 0)
		{
			ratingList.getline(rating, BUFFER_SIZE);
			std::cout << rating << std::endl;
		}
	}
	ratingList.close();
}

void User::registerUser(const char* name, const char* password)
{
	char* existingUser = new char[strlen(name + 12)];
	strcpy(existingUser, "Username: ");
	strcat(existingUser, name);
	bool userExists = false;
	char tempUser[BUFFER_SIZE];

	std::ifstream usersListRead("UsersList.txt");

	while (usersListRead.good())
	{
		usersListRead.getline(tempUser, BUFFER_SIZE);
		if (strcmp(tempUser, existingUser) == 0)
		{
			userExists = true;
			std::cout << "Username is taken!";
			break;
		}
	}
	usersListRead.close();

	if (!userExists)
	{
		std::ofstream usersListWrite("UsersList.txt", std::ios::app);
		usersListWrite << "Username: " << name <<
			std::endl << "Password: " << password << std::endl;
		std::cout << "User was successfully registered!" << std::endl;

		usersListRead.close();
	}

	delete[] existingUser;
}

void User::viewBookList()
{
	if (loggedIn)
	{
		char book[BUFFER_SIZE];
		std::ifstream bookList("BookList.txt");
		while (bookList.good())
		{
			bookList.getline(book, BUFFER_SIZE);
			std::cout << book << std::endl;
		}
		bookList.close();
	}
	else
	{
		std::cout << "User is not logged in.";
	}
}

void User::addReadBook(const Book& readBook)
{
	Book* tempBooksRead = new Book[++booksReadCount];
	for (size_t i = 0; i < booksReadCount - 1; i++)
	{
		tempBooksRead[i] = booksRead[i];
	}
	tempBooksRead[booksReadCount - 1] = readBook;
	setBooksRead(tempBooksRead);

	delete[] tempBooksRead;
}

void User::addWrittenBook(const Book& writtenBook)
{
	Book* tempBooksWritten = new Book[++booksWrittenCount];
	for (size_t i = 0; i < booksWrittenCount - 1; i++)
	{
		tempBooksWritten[i] = booksWritten[i];
	}

	tempBooksWritten[booksWrittenCount - 1] = writtenBook;
	setBooksWritten(tempBooksWritten);

	delete[] tempBooksWritten;
}

void User::free()
{
	delete[] name;
	delete[] password;
	delete[] booksRead;
	booksReadCount = 0;
	delete[] booksWritten;
	booksWrittenCount = 0;
	loggedIn = false;
}

void User::copyFrom(const User& other)
{
	name = new char[strlen(other.name + 1)];
	strcpy(name, other.name);

	password = new char[strlen(other.password + 1)];
	strcpy(password, other.password);

	booksRead = new Book[other.booksReadCount];
	for (size_t i = 0; i < booksReadCount; i++)
	{
		booksRead[i] = other.booksRead[i];
	}

	booksWritten = new Book[other.booksWrittenCount];
	for (size_t i = 0; i < booksWrittenCount; i++)
	{
		booksWritten[i] = other.booksWritten[i];
	}

	loggedIn = other.loggedIn;
}
