#include <iostream>
#include <cstring>
#include <fstream>

#include "Book.h"
#pragma warning(disable : 4996)

Book::Book()
{
	title = nullptr;
	authorName = nullptr;
	ratings = nullptr;
	ratingsCount = 0;
	pages = nullptr;
	pagesCount = 0;
	comments = nullptr;
	commentsCount = 0;
}

Book::Book(const char* title)
{
	this->title = new char[strlen(title) + 1];
	strcpy(this->title, title);

	authorName = nullptr;
	ratings = nullptr;
	ratingsCount = 0;
	pages = nullptr;
	pagesCount = 0;
	comments = nullptr;
	commentsCount = 0;
}

Book::Book(const Book& other)
{
	copyFrom(other);
}

Book& Book::operator=(const Book& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Book::~Book()
{
	free();
}

const char* Book::getTitle() const
{
	return title;
}

const char* Book::getAuthorName() const
{
	return authorName;
}

const Rating* Book::getRatings() const
{
	return ratings;
}

const Page* Book::getPages() const
{
	return pages;
}

const Comment* Book::getComments() const
{
	return comments;
}

const size_t Book::getPagesCount() const
{
	return pagesCount;
}

void Book::addPage(const Page& page)
{
	Page* tempPages = new Page[++pagesCount];
	for (size_t i = 0; i < pagesCount - 1; i++)
	{
		tempPages[i] = pages[i];
	}
	tempPages[pagesCount - 1] = page;
	setPages(tempPages);

	delete[] tempPages;
}

void Book::addRating(const Rating& rating)
{
	Rating* tempRatings = new Rating[++ratingsCount];
	for (size_t i = 0; i < ratingsCount - 1; i++)
	{
		tempRatings[i] = ratings[i];
	}
	tempRatings[ratingsCount - 1] = rating;
	setRatings(tempRatings);

	delete[] tempRatings;
}

void Book::addComment(const Comment& comment)
{
	Comment* tempComments = new Comment[++commentsCount];
	for (size_t i = 0; i < commentsCount - 1; i++)
	{
		tempComments[i] = comments[i];
	}
	tempComments[commentsCount - 1] = comment;
	setComments(tempComments);

	delete[] tempComments;
}

void Book::addBookToBooklist(const char* title, const char* authorName) const
{
	bool bookExists = false;
	char* existingBook = new char[strlen(title) + strlen(authorName) + 6];
	strcpy(existingBook, title);
	strcat(existingBook, " by ");
	strcat(existingBook, authorName);
	char temp[512];

	std::ifstream bookList("BookList.txt");
	while (bookList.good())
	{
		bookList.getline(temp, 512);
		if (strcmp(temp, existingBook) == 0)
		{
			bookExists = true;
			std::cout << "Book already exists!";
			break;
		}
	}
	bookList.close();

	if (!bookExists)
	{
		std::ofstream bookListWrite("BookList.txt", std::ios::app);
		bookListWrite << title << " by " << authorName << std::endl;
		bookListWrite.close();

		strcpy(temp, title);
		strcat(temp, ".txt");
		std::ofstream bookWrite(temp);
		bookWrite.close();

		std::ofstream bookTitlesWrite("BookTitles.txt", std::ios::app);
		bookTitlesWrite << title << std::endl;
		bookTitlesWrite.close();

		std::cout << "Book was added successfully to the list!";
	}

	delete[] existingBook;
}

void Book::setTitle(const char* title)
{
	delete[] this->title;
	this->title = new char[strlen(title) + 1];
	strcpy(this->title, title);
}

void Book::setAuthorName(const char* author)
{
	delete[] this->authorName;
	this->authorName = new char[strlen(author + 1)];
	strcpy(this->authorName, author);
}

void Book::setRatings(const Rating* rating)
{
	delete[] this->ratings;
	this->ratings = new Rating[ratingsCount];
	for (size_t i = 0; i < ratingsCount; i++)
	{
		this->ratings[i] = ratings[i];
	}
}

void Book::setPages(const Page* pages)
{
	delete[] this->pages;
	this->pages = new Page[pagesCount];
	for (size_t i = 0; i < pagesCount; i++)
	{
		this->pages[i] = pages[i];
	}
}

void Book::setComments(const Comment* comments)
{
	delete[] this->comments;
	this->comments = new Comment[commentsCount];
	for (size_t i = 0; i < pagesCount; i++)
	{
		this->pages[i] = pages[i];
	}
}

void Book::setPagesCount(const size_t pagesCount)
{
	this->pagesCount = pagesCount;
}

void Book::free()
{
	delete[] title;
	delete[] authorName;
	delete[] ratings;
	ratingsCount = 0;
	delete[] pages;
	pagesCount = 0;
	delete[] comments;
	commentsCount = 0;
}

void Book::copyFrom(const Book& other)
{
	title = new char[strlen(other.title) + 1];
	strcpy(this->title, other.title);

	authorName = new char[strlen(other.authorName) + 1];
	strcpy(this->authorName, other.authorName);

	ratings = new Rating[other.ratingsCount];
	for (int i = 0; i < ratingsCount; i++)
	{
		ratings[i] = other.ratings[i];
	}

	ratingsCount = other.ratingsCount;

	pages = new Page[other.pagesCount];
	for (int i = 0; i < pagesCount; i++)
	{
		pages[i] = other.pages[i];
	}

	pagesCount = other.pagesCount;

	comments = new Comment[other.commentsCount];
	for (int i = 0; i < commentsCount; i++)
	{
		comments[i] = other.comments[i];
	}

	commentsCount = other.commentsCount;

}