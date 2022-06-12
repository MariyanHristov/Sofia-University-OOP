#include <cstring>
#include <iostream>

#include "Rating.h"
#pragma warning(disable : 4996)


Rating::Rating()
{
	username = nullptr;
	rating = 0;
	for (int i = 0; i < 3; i++)
	{
		ratingToString[i] = '0';
	}
}

Rating::Rating(const char* username, int rating)
{
	this->username = new char[strlen(username) + 1];
	strcpy(this->username, username);

	this->rating = rating;

	for (int i = 0; i < 3; i++)
	{
		ratingToString[i] = '0';
	}
}
Rating::Rating(const Rating& other)
{
	copyFrom(other);
}

Rating& Rating::operator=(const Rating& other)
{
	free();
	if (this != &other)
	{
		copyFrom(other);
	}

	return *this;
}

Rating::~Rating()
{
	free();
}

const char* Rating::getUsername() const
{
	return username;
}

int Rating::getRating() const
{
	return rating;
}

void Rating::setUsername(const char* username)
{
	delete[] this->username;
	this->username = new char[strlen(username) + 1];
	strcpy(this->username, username);
}

void Rating::setRating(int rating)
{
	this->rating = rating;
}

void Rating::setRatingToString(const char ratingToString[3])
{
	strcpy(this->ratingToString, ratingToString);
}

const char* Rating::getRatingToString() const
{
	char ratingToString[3];
	if (rating <= 9)
	{
		ratingToString[0] = rating + '0';
		ratingToString[1] = '\0';
	}
	else
	{
		ratingToString[0] = '1';
		ratingToString[1] = '0';
		ratingToString[2] = '\0';
	}
	
	strcpy((char*)this->ratingToString, ratingToString);

	return this->ratingToString;
}

void Rating::copyFrom(const Rating& other)
{
	username = new char[strlen(other.username) + 1];
	strcpy(username, other.username);

	rating = other.rating;
}

void Rating::free()
{
	delete[] username;
}
