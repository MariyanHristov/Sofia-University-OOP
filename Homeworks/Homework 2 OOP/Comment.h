#pragma once

class Comment
{
private:
	char* username;
	char* commentContent;

public:
	Comment();
	Comment(const char* username, const char* commentContent);
	Comment(const Comment& other);
	Comment& operator=(const Comment& other);
	~Comment();

	const char* getUsername() const;
	const char* getCommentContent() const;

	void setUsername(const char* username);
	void setCommentContent(const char* commentContent);

private:
	void copyFrom(const Comment& other);
	void free();
};
