#pragma once

#include "Page.h"
#include "Rating.h";
#include "Comment.h"

class Book
{
private:
	char* title;
	char* authorName;
	Rating* ratings;
	size_t ratingsCount;
	Page* pages;
	size_t pagesCount;
	Comment* comments;
	size_t commentsCount;

public:
	Book();
	Book(const char* title);
	Book(const Book& other);
	Book& operator=(const Book& other);
	~Book();

	const char* getTitle() const;
	const char* getAuthorName() const;
	const Rating* getRatings() const;
	const Page* getPages() const;
	const Comment* getComments() const;
	const size_t getPagesCount() const;

	void setTitle(const char* title);
	void setAuthorName(const char* author);
	void setRatings(const Rating* rating);
	void setPages(const Page* pages);
	void setComments(const Comment* comments);
	void setPagesCount(const size_t pagesCount);

	void addPage(const Page& page); 
	void addRating(const Rating& rating);
	void addComment(const Comment& comment);
	void addBookToBooklist(const char* title, const char* authorName) const;

private:
	void free();
	void copyFrom(const Book& other);
};

