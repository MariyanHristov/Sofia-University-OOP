#pragma once

class Rating 
{
private:
	char* username;
	int rating;
	char ratingToString[3];

public:
	Rating();
	Rating(const char* username, int rating);
	Rating(const Rating& other);
	Rating& operator=(const Rating& other);
	~Rating();

	const char* getUsername() const;
	int getRating() const;
	const char* getRatingToString() const;

	void setUsername(const char* username);
	void setRating(int rating);
	void setRatingToString(const char ratingToString[3]);
	
private:
	void copyFrom(const Rating& other);
	void free();
};