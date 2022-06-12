#include <iostream>
#include <cstring>

#include "Comment.h"
#pragma warning(disable : 4996)

Comment::Comment()
{
	username = nullptr;
	commentContent = nullptr;
}

Comment::Comment(const char* username, const char* commentContent)
{
	/*this->username = new char[strlen(username) + 1];
	strcpy(this->username, username);

	this->commentContent = new char[strlen(commentContent) + 1];
	strcpy(this->commentContent, commentContent);*/

	setUsername(username);
	setCommentContent(commentContent);
}

Comment::Comment(const Comment& other)
{
	copyFrom(other);
}

Comment& Comment::operator=(const Comment& other)
{	
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Comment::~Comment()
{
	free();
}

const char* Comment::getUsername() const
{
	return username;
}

const char* Comment::getCommentContent() const
{
	return commentContent;
}

void Comment::setUsername(const char* username)
{
	delete[] this->username;
	this->username = new char[strlen(username) + 1];
	strcpy(this->username, username);
}

void Comment::setCommentContent(const char* commentContent)
{
	delete[] this->commentContent;
	this->commentContent = new char[strlen(commentContent) + 1];
	strcpy(this->commentContent, commentContent);
}

void Comment::copyFrom(const Comment& other)
{
	username = new char[strlen(other.username) + 1];
	strcpy(username, other.username);

	commentContent = new char[strlen(other.commentContent) + 1];
	strcpy(commentContent, other.commentContent);
}

void Comment::free()
{
	delete[] username;
	delete[] commentContent;
}
