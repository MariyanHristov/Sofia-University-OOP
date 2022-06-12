#pragma once

class Page
{
private:
	char* pageContent;
	int pageNumber;

public:
	Page();
	Page(const char* pageContent);
	Page(const Page& other);
	Page& operator=(const Page& other);
	~Page();

	const char* getPageContent() const;
	int getPageNumber() const;

	void setPageContent(const char* pageContent);
	void setPageNumber(const int pageNumber);

private:
	void free();
	void copyFrom(const Page& other);
};